// Linear Search Algorithm:
/* 
Sequential search algorithm that starts at one end and goes through each element of a list
until the desired element is found, otherwise the search continues till the end of the data set.

Time Complexity:
- Best Case: O(1) - Element is found at first inspected index
- Worst Case: O(N) - Element is found at last inspected index
- Average Case: O(N)
- Auxiliary Space Complexity: O(1) - Except for the variable to iterate through the list, no other variable is used
- (Assuming the input data is provided externally and doesn't need to be stored in the algorithm's memory space.
- In the case that it is counted in the memory's space complexity, it is O(n)).
*/
#include <iostream>
using namespace std;
// Function "search" returns the index where the desired integer is found
// Function "linearsearch" returns the desired integer

int search(int arr[], int N, int x)
{
    for (int i = 0; i < N; i++)
        if (arr[i] == x)
            return i;  // Returning index where desired integer is found
    return -1;
}


int linearsearch(int arr[], int size, int di) {
    for(int i = 0; i < size; i++) {
        if (arr[i] = di) {
            return arr[i];  // Returning the desired integer
        }
    }
    return -1;
}


int main() {
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int x = 2;
    int N = sizeof(arr) / sizeof(x);
    int result = search(arr, N, x);
    cout << ((result == -1) ? "Desired integer is not present" : "Desired integer is: " + to_string(result)) << endl;
    return 0;
}

/*
Applications:
- Unsorted Lists: Finding an element
- Small Data Sets: Linear Search is preferred when we have small data sets
- Searching Linked Lists: Each node is checked sequentially
- Simple Implementation: Easier to implement than Binary Search or Ternary Search

Advantages:
- Can be used whether the array is sorted or not 
- Can be used on arrays of any data type
- Does not require any additional memory
- Well-suited for small datasets

Disadvantages:
- Time complexity O(n) makes it slow for large datasets
*/