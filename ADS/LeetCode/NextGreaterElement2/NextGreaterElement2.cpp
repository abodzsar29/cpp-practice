#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
vector<int> nextGreaterElements(vector<int>& nums) {
    stack<int> st;
    unordered_map<int, int> map; // value -> next greater

    for(int num : nums) {
        while(!st.empty() && st.top() < num) {
            map[st.top()] = num;
            st.pop();
        }
        st.push(num);
    }

    vector<int> result;
    for (int i = 0; i < nums.size();) {
        if(nums[i] > st.top() && !st.empty()) {
            map[st.top()] = nums[i];
            st.pop();
        } else {
            i++;
        }
    }

    for (int num: nums) {
        if (map[num]) {
            result.push_back(map[num]);
        } else {
            result.push_back(-1);
        }
    }

    return result;
    }
};
