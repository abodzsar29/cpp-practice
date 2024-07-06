#include <iostream>
using namespace std;

int main() {
//  One integer is 4 bytes, so an array of 5 will be 20 bytes
    int arr[5];
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;
    arr[4] = 5;
    cout << "Size of array: " << sizeof(arr) << endl;
    cout << "Size of one integer in the array: " << sizeof(arr[0]) << endl;

// Or you can not pre-set size of array
    int arr2[] = {1,2,3,4,5,6,7,8,9,10};
    cout << "The size of not preset array is 10 * 4= " << sizeof(arr2) << endl;

// If not all elements have been initialised in the array, those will be replaced by 0s
    int arr3[10] = {1,2,3,4,5,6,7};
    cout << "The 8th element is not initialised, so it's: " << arr3[7] << endl;
    cout << "The 9th element is not initiliased, so it's: " << arr3[8] << endl;
    cout << "The 10th element is not initialised, so it's: " << arr3[9] << endl;

// Using a for loop to populate
    int arr4[10];
    for(int x = 0; x<10; x++) {
        arr4[x] = x*2;
        cout << arr4[x] << endl;
    }

//  Foreach loop in C++:
//  It iterates through the array or any iterable and assigns the value of the current element 
//  to the variable iterator declared inside the loop
    for(int i : arr3) {
        cout << i << " ";
    }

//  Variable sized array:
    int x;
    cin >> x;
    cout << "Enter size: ";
//  Not possible:
//  int arr6[x] = {1,2,3,4,5}
//  Possible:
    int arr6[x];
    cout << sizeof(arr6) << endl;
    for(int i = 0; i < x; i++) {
        arr6[i] = i;
        cout << arr6[i] << endl;
    }

//  Size specified by the amount of initialisers provided
    int arr7[] = {1,2,3,4,5,6};

//  Dynamic arrays:
    int* arr = new int[4];





    return 0;
}