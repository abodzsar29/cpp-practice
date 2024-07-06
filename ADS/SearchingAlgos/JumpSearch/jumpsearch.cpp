// Jump Search Algorithm:
/* 
A searching algorithm for sorted arrays. It checks fewer elements than linear search by jumping ahead 
by a fixed step size instead of searching all elements. For example, we have an array arr[] of size n
and a step size of m. Then, we search in the indexes arr[0], arr[m], arr[2m]…..arr[km], and so on. 
Once we find the interval (arr[km] < x < arr[(k+1)m]), we perform a linear search operation from the
index km to find the element x. Jump search is more efficient than linear search, but less efficient than
binary search.

Worst case:
- The total number of comparisons in the worst case is the sum of the number of jumps and the number
of linear search comparisons from the last jump: n/m + (m - 1)

Optimal jump size:
- The value for the optimal jump size is the value that minimises the equation for the worst case
- This is m = n^(1/2)

Conditions:
- The data structure must be sorted.
- Access to any element of the data structure takes constant time.

Time Complexity:
- Best Case: O(1)
- Average Case: O(n^(1/2))
- Worst Case: O(n^(1/2))

Auxiliary Space Complexity: O(1)
- (Assuming the input data is provided externally and doesn't need to be stored in the algorithm's memory space.

*/
#include <cmath>
#include <iostream>
using namespace std;

int jumpSearch(int array[], int desiredElement, int size) {
    int previousBlockIndex = 0;
    int jumpSize = sqrt(size);

    // Determine which block element is in
    while(array[min(jumpSize, size) - 1] < desiredElement) {
        previousBlockIndex = jumpSize;
        jumpSize += sqrt(size);
        if(previousBlockIndex >= size) {
            return -1;
        }
    }

    // Incrementing up to desired Element
    while(array[previousBlockIndex] < desiredElement) {
        previousBlockIndex++;
        if(previousBlockIndex >= min(jumpSize, size)) {
            return -1;
        }
    }

    if(array[previousBlockIndex] == desiredElement) {
        return previousBlockIndex;
    }

    return -1;
}


int main() {
    int arr[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21,
                34, 55, 89, 144, 233, 377, 610 };
    int x = 55;
    int n = sizeof(arr) / sizeof(arr[0]);
//  Find the index of 'x' using Jump Search
    int index = jumpSearch(arr, x, n);
    // Print the index where 'x' is located
    cout << "\nNumber " << x << " is at index " << index;
    return 0;
}

/*
Advantages:
- Better than a linear search for arrays where the elements are uniformly distributed
- Jump search has a lower time complexity compared to a linear search for large arrays
- The number of steps taken in jump search is proportional to the square root of the size 
of the array, making it more efficient for large arrays
- Jump search works well for arrays where the elements are in order and uniformly distributed,
as it can jump to a closer position in the array with each iteration
*/