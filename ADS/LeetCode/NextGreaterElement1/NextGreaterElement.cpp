#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;


/*
This is the solution for the problem "Next Greater Element 1", classed "Easy" on LeetCode. It is found under:
https://leetcode.com/problems/next-greater-element-i/description/

For the Stack and Hash Map approach:
Time Complexity: O(n) where n is the lengths of nums2
Space Complexity: O(n) for the stack and hashmap

For the Two Pointer Approach:
Time Complexity: O(n * m)
Space Complexity: O(1) excluding result array, where n = nums1.size(), m = nums2.size()
*/


class Solution {
public:
    // Solution 1: Using Stack and HashMap
    vector<int> nextGreaterElement1(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map;
        stack<int> st;
        
        for(int num : nums2) {
            while(!st.empty() && st.top() < num) {
                map[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }
        
        while(!st.empty()) {
            map[st.top()] = -1;
            st.pop();
        }
        
        vector<int> result(nums1.size());
        for(int i = 0; i < nums1.size(); i++) {
            result[i] = map[nums1[i]];
        }
        
        return result;
    }
    
    // Solution 2: Two Pointer Approach
    vector<int> nextGreaterElement2(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result(nums1.size());
        
        for(int i = 0; i < nums1.size(); i++) {
            int j;
            for(j = 0; j < nums2.size(); j++) {
                if(nums2[j] == nums1[i]) break;
            }
            
            int nextGreater = -1;
            for(int k = j + 1; k < nums2.size(); k++) {
                if(nums2[k] > nums1[i]) {
                    nextGreater = nums2[k];
                    break;
                }
            }
            result[i] = nextGreater;
        }
        return result;
    }
};

// Helper function to print vector
void printVector(const vector<int>& vec) {
    cout << "[";
    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if(i < vec.size() - 1) cout << ",";
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;
    
    // Test Case 1
    vector<int> nums1_1 = {4,1,2};
    vector<int> nums2_1 = {1,3,4,2};
    cout << "Test Case 1:" << endl;
    cout << "nums1 = "; printVector(nums1_1);
    cout << "nums2 = "; printVector(nums2_1);
    cout << "Solution 1 output: "; 
    printVector(sol.nextGreaterElement1(nums1_1, nums2_1));
    cout << "Solution 2 output: "; 
    printVector(sol.nextGreaterElement2(nums1_1, nums2_1));
    cout << endl;
    
    // Test Case 2
    vector<int> nums1_2 = {2,4};
    vector<int> nums2_2 = {1,2,3,4};
    cout << "Test Case 2:" << endl;
    cout << "nums1 = "; printVector(nums1_2);
    cout << "nums2 = "; printVector(nums2_2);
    cout << "Solution 1 output: "; 
    printVector(sol.nextGreaterElement1(nums1_2, nums2_2));
    cout << "Solution 2 output: "; 
    printVector(sol.nextGreaterElement2(nums1_2, nums2_2));
    
    return 0;
}
