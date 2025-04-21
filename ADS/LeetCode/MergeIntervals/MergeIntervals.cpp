#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
This is the solution for the problem "Merge Intervals", classed as "Medium" on LeetCode. It is found under:
https://leetcode.com/problems/merge-intervals/description/

It uses the Greedy algorithm approach:
1. First sort all intervals based on starting time
2. Initialize the first interval's start and end times as reference points
3. Iterate through all intervals:
   - If current interval's start time is greater than our reference end time, 
     add the reference interval to result and update reference to current interval
   - Otherwise, if current interval's end time extends beyond reference end time,
     update the reference end time

Time Complexity: O(n log n), where n is the number of intervals. The sorting operation takes O(n log n) time.
Space Complexity: O(n) for storing the result array.
*/

// Define the Solution class
class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        std::vector<std::vector<int>> ans;
        
        // Sort intervals by their start times
        sort(begin(intervals), end(intervals));
        
        // Initialize reference points from the first interval
        int a = intervals[0][0], b = intervals[0][1];
        
        // Iterate through all intervals
        for(auto v : intervals) {
            // If current interval starts after reference ends, no overlap
            if(v[0] > b) {
                // Add the reference interval to result
                ans.push_back({a, b});
                // Update reference to current interval
                a = v[0];
                b = v[1];
            }
            // If current interval extends the reference, update end point
            else if(v[1] > b) {
                b = v[1];
            }
        }
        
        // Add the last merged interval
        ans.push_back({a, b});
        
        return ans;
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solution;
    
    // Test cases
    std::vector<std::vector<std::vector<int>>> testCases = {
        {{1, 3}, {2, 6}, {8, 10}, {15, 18}},           // Expected output: [[1,6],[8,10],[15,18]]
        {{1, 4}, {4, 5}},                              // Expected output: [[1,5]]
        {{1, 4}, {0, 4}},                              // Expected output: [[0,4]]
        {{1, 4}, {2, 3}},                              // Expected output: [[1,4]]
        {{1, 3}, {5, 7}, {2, 4}, {6, 8}, {9, 10}},     // Expected output: [[1,4],[5,8],[9,10]]
        {{1, 10}, {2, 3}, {4, 5}, {6, 7}, {8, 9}},     // Expected output: [[1,10]]
        {}                                             // Expected output: []
    };
    
    // Iterate through test cases
    for (auto& intervals : testCases) {
        // Print the input
        std::cout << "Input intervals: [";
        for (size_t i = 0; i < intervals.size(); ++i) {
            std::cout << "[" << intervals[i][0] << "," << intervals[i][1] << "]";
            if (i != intervals.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]\n";
        
        // Handle edge case for empty intervals array
        if (intervals.empty()) {
            std::cout << "Merged intervals: []\n\n";
            continue;
        }
        
        // Call the merge function and get the result
        std::vector<std::vector<int>> result = solution.merge(intervals);
        
        // Print the output
        std::cout << "Merged intervals: [";
        for (size_t i = 0; i < result.size(); ++i) {
            std::cout << "[" << result[i][0] << "," << result[i][1] << "]";
            if (i != result.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]\n\n";
    }
    
    return 0;
}

