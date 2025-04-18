#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/*
This is the solution for the problem "Fibonacci Number", classed "Easy" on LeetCode. It is found under:
https://leetcode.com/problems/fibonacci-number/description/
It uses dynamic programming with memoization to efficiently calculate Fibonacci numbers.
Time Complexity: O(n), where n is the input number. Each Fibonacci number is calculated exactly once.
Space Complexity: O(n), as we store all calculated Fibonacci numbers in a hash map.
*/

// Define the Solution class
class Solution {
public:
    int fib(int n) {
        unordered_map<int, int> hashMap = {
            {0,0},
            {1,1}
        };
        return fibDP(n, hashMap);
    }
    int fibDP(int n, unordered_map<int, int>& hashMap) {
        if (hashMap.find(n) != hashMap.end()) {
            return hashMap[n];
        }
        hashMap[n] = fibDP(n-1, hashMap) + fibDP(n-2, hashMap);
        return hashMap[n];
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solution;
    
    // Test cases
    std::vector<int> testCases = {
        0,    // Expected output: 0
        1,    // Expected output: 1
        2,    // Expected output: 1
        3,    // Expected output: 2
        4,    // Expected output: 3
        5,    // Expected output: 5
        10,   // Expected output: 55
        20,   // Expected output: 6765
        30    // Expected output: 832040
    };
    
    // Iterate through test cases
    for (const auto& n : testCases) {
        // Print the input
        std::cout << "n = " << n << "\n";
        
        // Call the fib function and print the output
        int result = solution.fib(n);
        std::cout << "F(" << n << ") = " << result << "\n\n";
    }
    
    // Explanation of the solution
    std::cout << "Solution Explanation:\n";
    std::cout << "--------------------\n";
    std::cout << "This solution uses dynamic programming with memoization to calculate Fibonacci numbers.\n";
    std::cout << "The Fibonacci sequence is defined as F(0) = 0, F(1) = 1, and F(n) = F(n-1) + F(n-2) for n > 1.\n";
    std::cout << "Rather than recalculating values multiple times in a naive recursive approach, we store\n";
    std::cout << "each calculated Fibonacci number in a hash map for fast lookup when needed again.\n";
    std::cout << "This optimization reduces the time complexity from O(2^n) to O(n).\n";
    
    return 0;
}
