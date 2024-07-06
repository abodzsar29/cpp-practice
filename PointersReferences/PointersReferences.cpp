#include <iostream>
using namespace std;

// Passing pointers to functions - 5a
static void increment(int* p) {
	(*p)++;
}

// Returning pointers from a function - 5b
int* createArray(int size) {
	return new int[size];  // dynamically allocate an array and returns a pointer to an array of integers of the given size
}

// Pointer to a function taking an int and returning void - 10
void display(int a) {
	cout << "Value of a: " << a << endl;
}

// Pointer to a class member
class MyClass {
public:
	int var;
	void display() {
		cout << "Value of var: " << var << endl;
	}
};

int main() {
	// 1. Basic pointer declaration and initialisation
	/*
	int var = 42;
	int* ptr = &var;
	cout << "Value of var: " << var << endl;
	cout << "Address of var: " << &var << endl;
	cout << "Value of ptr (address of var): " << ptr << endl;
	cout << "Value pointed to by ptr: " << *ptr << endl;  // Use * to dereference when pointer points to address &
	*/

	// 2. Pointer to pointer
	/*
	int var = 42;
	int* ptr = &var;
	int** ptr2 = &ptr;  // ptr2 is a pointer to a pointer to int

	cout << "Value of var: " << var << endl;
	cout << "-----------" << endl;
	cout << "Address of Var" << &var << endl;
	cout << "Value of ptr (address of var): " << ptr << endl;
	cout << "-----------" << endl;
	cout << "Address of &ptr: " << &ptr << endl;
	cout << "Value of ptr2 (address of ptr): " << ptr2 << endl;
	cout << "-----------" << endl;
	cout << "ptr2 dereferenced by one * (address of var): " << *ptr2 << endl;
	cout << "Address of Var: " << &var << endl;
	cout << "-----------" << endl;
	cout << "ptr2 dereferenced by two *: " << **ptr2 << endl;*/

	// 3. Arrays and Pointers
	/*
	int arr[5] = {10, 20, 30, 40, 50};
	int* ptr = arr;  // ptr points to the first element of the array
	for (int i = 0; i < 5; i++) {
		cout << "arr[" << i << "] = " << arr[i] << ", *(ptr + " << i << ") = " << *(ptr + i) << endl;
	}
	*/

	// 4. Pointer Arithmetic
	/*
	int arr[5] = { 10, 20, 30, 40, 50 };
	int* ptr = arr;
	cout << "Original address: " << ptr << endl;
	cout << "After incrementing ptr: " << ++ptr << endl;
	cout << "Value at incremented ptr: " << *ptr << endl;
	cout << "After decrementing ptr: " << --ptr << endl;
	cout << "Value at decremented ptr: " << *ptr << endl;
	*/

	// 5a. Pointer Arithmetic: Passing Pointers to Functions
	/*
	int var = 10;
	cout << "Before increment: " << var << endl;
	increment(&var);
	cout << "After increment: " << var << endl;
	*/

	// 5b. Pointer Arithmetic: Returning Pointers from Functions
	/*
	int* arr = createArray(5); // arr is a pointer to an integer, which receives the pointer returned by createArray
	for (int i = 0; i < 5; i++) {
		arr[i] = i * 10;
	}
	for (int i = 0; i < 5; i++) {
		cout << "arr[" << i << "] = " << arr[i] << endl;
	}
	delete[] arr;  // free the dynamically allocated array
	*/

	// 6. Pointers to Const - You cannot change the value of where the pointer points if the "const" is first, before the data type
	/*
	int var = 42;
	const int* ptr = &var;  // pointer to const int
	// *ptr = 50; // Error: cannot modify a const int through ptr
	var = 50;  // Direct modification is allowed

	cout << "Value of var: " << var << endl;
	cout << "Value pointed to by ptr: " << *ptr << endl;
	*/

	// 7. Const Pointers - You cannot reassign the pointer if the "const" is second, before the variable name. The pointer becomes a constant
	/*
	int var1 = 42;
	int var2 = 72;
	int* const ptr = &var1;  // const pointer to int

	*ptr = 50;  // Allowed: modifying the value pointed to
	// ptr = &var2; // Error: ptr is a const pointer, cannot change address

	cout << "Value of var1: " << var1 << endl;
	cout << "Value pointed to by ptr: " << *ptr << endl;
	*/

	// 8. Const pointer to const
	/*
	int var = 42;
	const int* const ptr = &var;  // const pointer to const int

	// *ptr = 50; // Error: cannot modify the value pointed to
	// ptr = &var2; // Error: ptr is a const pointer, cannot change address

	cout << "Value of var: " << var << endl;
	cout << "Value pointed to by ptr: " << *ptr << endl;
	*/

	// 9. Void Pointers
	/*
	int var = 42;
	void* ptr = &var;  // ptr is a void pointer
	
	// cout << *ptr; // Error: cannot dereference a void pointer directly
	cout << "Address stored in void pointer: " << ptr << endl;
	cout << "Value pointed to by void pointer (after type casting): " << *(static_cast<int*>(ptr)) << endl;
	*/

	// 10. Function Pointers
	/*
	void (*funcPtr)(int) = display;  // funcPtr is a pointer to a function taking an int and returning void
	funcPtr(42);  // Calling the function using the pointer
	*/

	// 11. Pointer to Class Member
	MyClass obj;
	obj.var = 42;

	int MyClass::* ptr = &MyClass::var;  // pointer to class member
	void (MyClass::* funcPtr)() = &MyClass::display;  // pointer to class member function

	cout << "Value of obj.var using pointer to member: " << obj.*ptr << endl;
	(obj.*funcPtr)();  // calling member function using pointer to member function



	return 0;
}

