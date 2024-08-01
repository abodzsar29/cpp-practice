#include <iostream>
#include <utility>
#include <tuple>
#include <type_traits>

// Defining the struct to hold the integral_constant objects
template<typename ...Args>
struct type_list {};

// Defining & Implementing the function template which checks whether an integer is even
template<typename T>
constexpr bool is_even_v = (T::value % 2 == 0);

// Defining the function template which counts the number of even integral_constant objects
template<typename ...Args>
constexpr int count_even(type_list<Args...>)
{
	static_assert(sizeof...(Args) > 0, "The list of types must not be empty.");  // compile-time assertion mechanism that checks the number of template arguments is greater than zero
	return (0 + ... + is_even_v<Args>);  // Binary left fold 
}

// Binary right fold with a boolean is_odd_v 
template<typename T>
constexpr bool is_odd_v = (T::value % 2 != 0);

template<typename... Args>
constexpr int count_odd(type_list<Args...>) {
	static_assert(sizeof...(Args) > 0, "The list of types must not be empty.");
	return (is_odd_v<Args> + ... + 0);
}

// Binary left fold with +
template<typename... Args>
constexpr int sum(Args... args) {
	static_assert(sizeof...(Args) > 1, "Has to have min 2 arguments");
	return (0 + ... + args);
}

// Binary left fold + with types as arguments instead of values:
template<typename... Args>
constexpr int sumWithTypes(type_list<Args...>) {
	static_assert(sizeof...(Args) > 0, "Has to have min 1 argument");
	return (0 + ... + Args::value);
}

// Binary left fold with AND operator
template<typename... Args>
constexpr bool binaryLeftFoldAnd(Args... args) {
	static_assert(sizeof...(Args) > 1, "Has to have min 2 arguments");
	return (true && ... && args);
}

// Binary left fold with -, 
template<typename... Args>
constexpr auto binaryLeftFoldMinus(Args... args) {
	static_assert(sizeof...(Args) > 1, "Has to have min 2 arguments");
	return (100 - ... - args);
}

// Function template that returns the first argument
template<typename T, typename... Args>
constexpr auto front(type_list<T, Args...>) {
	return T{};
}

// Function template that returns the last argument
template<typename T, typename... Args>
constexpr auto back(type_list<T, Args...> tl) {  // Parameter name 'tl' is added as instance of type_list<T, Args...>
	if constexpr (sizeof...(Args) > 0) {
		return back(type_list<Args...>{});  // Recursively calls func, omitting the type at the tail each time
	}
	else {  // If Args size is 0, T has the element of the head of the initial type_list
		return T{};  // Returns a default-constructed object
	}
}

// Function template that returns each type as a default-constructed instance
template<typename... Args>
constexpr auto unzip(type_list<Args...>) {
	return std::tuple<Args...>{};
}

// Function template that return the value of the passed in integral_constant
template<typename T>
constexpr auto returnVal(type_list<T>) {
	return T::value;
}



int main() {
	using namespace std;
	using ex1 = type_list <
		integral_constant<int, 2>,
		integral_constant<int, 5>,
		integral_constant<int, 10>,
		integral_constant<int, 7>
	>;

	using Even1 = integral_constant<int, 2>;
	using Odd1 = integral_constant<int, 3>;
	using Even2 = integral_constant<int, 5>;
	using ex2 = type_list<Even1, Odd1, Even2>;

	// Counting odds and evens
	cout << "Number of even in ex1: " << count_even(ex1{}) << "\n";
	cout << "Number of odd in ex1: " << count_odd(ex1{}) << "\n";
	cout << "Number of even in ex2: " << count_even(ex2{}) << "\n";
	cout << "Number of odd in ex2: " << count_odd(ex2{}) << "\n";
	cout << "Number of odd in integral_constant<5>: " << count_odd(type_list<integral_constant<int, 5>>{}) << "\n" << "\n"; // {} Creates an instance of type_list containing integral_constant<int, 5>

	// Folding
	cout << "Sum of numbers 1,2,3: " << sum(1,2,3) << "\n";
	cout << boolalpha << "Binary Left Fold with AND: " << binaryLeftFoldAnd(true, false, true, false, true) << "\n";
	cout << "Sum with types: " << sumWithTypes(ex1{}) << "\n" << "\n";

	// Returning first and last elements
	cout << "First element of arguments (2, 5, 10, 7): " << front(ex1{}) << "\n";
	cout << "Last elemnent of arguments (2, 5, 10, 7): " << back(ex1{}) << "\n" << "\n";

	// Unzipping types:
	type_list<int, double, char> tl;
	auto unzipped = unzip(tl);
	cout << "First element (int): " << get<0>(unzipped) << "\n";
	std::cout << "Second element (double): " << get<1>(unzipped) << "\n";
	std::cout << "Third element (char): " << static_cast<int>(get<2>(unzipped)) << "\n" << "\n";

	// Unzipping values
	type_list<integral_constant<int, 1>,
		integral_constant<int, 2>,
		integral_constant<int, 3>
	> tl2;

	auto unzippedVals = unzip(tl2);
	cout << "First element: " << get<0>(unzippedVals) << "\n";
	std::cout << "Second element:" << get<1>(unzippedVals) << "\n";
	std::cout << "Third element: " << static_cast<int>(get<2>(unzippedVals)) << "\n" << "\n";

	// Returning the value of the argument
	type_list<integral_constant<int, 1>> tl3;
	cout << "Returning the value by using returnVal: " << returnVal(tl3) << "\n";

	return 0;
}



