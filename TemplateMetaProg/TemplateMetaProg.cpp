#include <iostream>
#include <utility>
#include <tuple>
#include <type_traits>

// Defining the struct to hold the integral_constant objects
template<typename ...Args>
struct type_list {};

// Defining & Implementing the template which checks whether an integer is even
template<typename T>
constexpr bool is_even_v = (T::value % 2 == 0);

// Defining the template which counts the number of even integral_constant objects
template<typename ...Args>
constexpr int count_even(type_list<Args...>)
{
	static_assert(sizeof...(Args) > 0);
	return (0 + ... + is_even_v<Args>);
}



int main() {

	using namespace std;
	using my_list = type_list <
		integral_constant<int, 2>,
		integral_constant<int, 5>,
		integral_constant<int, 10>,
		integral_constant<int, 7>
	>;
	using my_list2 = type_list<>;
	return 0;
}