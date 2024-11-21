#include <iostream>
#include <vector>
using namespace std;

static int twoPointerRemoveDupes(vector<int>& nums) {
    // For Edge Cases
    if (nums.size() == 0) {
        return 0;
    }

    // Initialise Attributes
    int left = 0;
    
    for (int right = 1; right < nums.size(); ++right) {
        if (nums[right] != nums[left]) {
            ++left;
            nums[left] = nums[right];
        }
    }
    
    return left + 1;
}

int prefixSumArray(int l, int r) {
    int baseArray[8] = { 2, 4, 6, 8, 10, 12, 14, 16 };
    int sumArray[8] = { 0 };
    sumArray[0] = baseArray[0];
    for (int i = 1; i < 8; i++) {
        sumArray[i] = sumArray[i - 1] + baseArray[i];
    }

    // Display original array and prefix sum array
    cout << "Original array: ";
    for (int num : baseArray) {
        cout << num << " ";
    }
    cout << "\nPrefix sum array: ";
    for (int sum : sumArray) {
        cout << sum << " ";
    }
    cout << endl;
    cout << "The sum of the subarray between elements " << l << " and " << r << " (inclusive) is: ";
    if (l == 0) {
        return sumArray[r];
    }
    else {
        return sumArray[r] - sumArray[l - 1];
    }
};



int main() {
    cout << "Static Arrays: " << endl;
    //  One integer is 4 bytes, so an array of 5 will be 20 bytes
    int arr[5];
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;
    arr[4] = 5;
    cout << "Size of array: " << sizeof(arr) << endl;
    cout << "Size of one integer in the array: " << sizeof(arr[0]) << endl << endl;

    cout << "Initialising an array with unspecified bounds:" << endl;
    // Or you can initialise an array with unspecified 
    int arr2[] = { 1,2,3,4,5,6,7,8,9,10 };
    cout << endl;

    cout << "Unitialised members are replaced by 0s: " << endl;
    // If not all elements have been initialised in the array, those will be replaced by 
    int arr3[10] = { 1,2,3,4,5,6,7 };
    cout << "The 8th element is not initialised, so it's: " << arr3[7] << endl;
    cout << "The 9th element is not initiliased, so it's: " << arr3[8] << endl;
    cout << "The 10th element is not initialised, so it's: " << arr3[9] << endl;
    cout << endl;

    cout << "Using a for loop to populate array: " << endl;
    // Using a for loop to populate
    int arr4[10];
    for (int x = 0; x < 10; x++) {
        arr4[x] = x * 2;
        cout << arr4[x] << endl;
    }
    cout << endl;

    cout << "Using a for each loop to display members: " << endl;
    //  Foreach loop in 
    for (int i : arr3) {
        cout << i << " ";
    }
    cout << endl << endl;

    cout << "Variable Sized Arrays on the heap determined in the runtime" << endl;
    //  Variable sized array
    int x;
    cout << "Enter size: " << endl;
    cin >> x;

    //  Not possible:
    //  int arr6[x] = {1,2,3,4,5}

    //  Possible: Dynamic arrays:
    int* arr5 = new int[x];
    for (int i = 0; i < x; i++) {
        arr5[i] = i * 2;
        cout << arr5[i] << " ";
    }
    delete[] arr5;
    cout << endl << endl;

    cout << "Vector data structure: " << endl;
    // Dynamic arrays by using the <vector> data structure
    vector<int> arr6 = {};
    arr6.push_back(4);
    for (int i : arr6) {
        cout << i << " ";
    };

    cout << "Static Multi-dimensional arrays: " << endl;
    int staticMDArray[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    for (int i = 0; i < 3; ++i) {
        cout << endl;
        for (int j = 0; j < 3; ++j) {
            cout << staticMDArray[i][j] << " ";
        }
    };
    cout << endl << endl;

    cout << "Dynamic Multi-dimensional arrays: " << endl;
    int** dynamicMDArray = new int* [3];

    for (int i = 0; i < 3; ++i) {
        dynamicMDArray[i] = new int[3];
    };

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            dynamicMDArray[i][j] = 1;
        }
    };

    // Print the elements of the 2D array
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << dynamicMDArray[i][j] << " ";
        }
        std::cout << std::endl;
    };

    // Deallocate the memory
    for (int i = 0; i < 3; ++i) {
        delete[] dynamicMDArray[i];
    }
    delete[] dynamicMDArray;


    cout << endl << endl;

    // Prefix Sum & Range Sum Problems Solution:
    cout << prefixSumArray(1,4);

    cout << endl;
    // Two Pointer Pattern:
    vector<int> nums = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
    int nuOfDiffNums = twoPointerRemoveDupes(nums);
    cout << "Number of unique elements in nums array: " << nuOfDiffNums <<  ", these are: " << endl;
    for (int i = 0; i < nuOfDiffNums; ++i) {
        cout << nums[i] << " ";
    };
    cout << endl;


    // Sliding Window Pattern:
    return 0;
}
