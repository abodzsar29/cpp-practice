// Binary Search Algorithm:
/* 
used in a sorted array by repeatedly dividing the search interval in half. The idea of binary
search is to use the information that the array is sorted and reduce the time complexity to O(log N)

Conditions:
- The data structure must be sorted.
- Access to any element of the data structure takes constant time.

Time Complexity:
- Best Case: O(1)
- Average Case: O(log N)
- Worst Case: O(log N)

Auxiliary Space Complexity: O(1) - If the recursive call stack is considered then the auxiliary space will be O(logN)
- (Assuming the input data is provided externally and doesn't need to be stored in the algorithm's memory space.

*/
#include <iostream>
using namespace std;

// Iterative Solution
int binarySearch(int arr[], int low, int high, int x)
{
    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if x is present at mid
        if (arr[mid] == x)
            return mid;

        // If x greater, ignore left half
        if (arr[mid] < x)
            low = mid + 1;

        // If x is smaller, ignore right half
        else
            high = mid - 1;
    }

    // If we reach here, then element was not present
    return -1;
}

// Recursive Solution
int recursiveSolution(int arr[], int low, int high, int x) {
    if(low <= high) {
        int mid = low + (high - low) / 2;
        if(arr[mid] == x) {
            return mid;
        } else if(arr[mid] < x) {
            return recursiveSolution(arr, mid + 1, high, x);
        } else {
            return recursiveSolution(arr, low, mid - 1, x);
        }
    }
    return -1;
}


int main() {
    int array[10] = {1,2,3,4,5,6,7,8,9,10};
    int size = sizeof(array) / sizeof(array[0]);
    int desiredInteger = 8;
    int result = recursiveSolution(array, 0, size - 1, desiredInteger);
    (result == -1)
        ? cout << "Integer is not present"
        : cout << "Integer's position in the array is: " << result + 1 << "th element";
    return 0;
}

/*
Applications:
- Can be used as a building block for more complex algorithms, e.g. in machine learning

Advantages:
- Faster than linear search, especially for large arrays
- More efficient than other searching algorithms with a similar time complexity,
such as interpolation search or exponential search
- Well-suited for searching large datasets that are stored in external memory, e.g.: cloud

Disadvantages:
- Array should be sorted
- Data structure being searched needs to be stored in contiguous memory locations
*/