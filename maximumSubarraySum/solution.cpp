#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        long long maxSum = 0, currentSum = 0;
        int left = 0;

        for (int right = 0; right < nums.size(); ++right) {
            freq[nums[right]]++;
            currentSum += nums[right];

            // Ensure all elements in the subarray are distinct
            while (freq[nums[right]] > 1) {
                freq[nums[left]]--;
                currentSum -= nums[left];
                left++;
            }

            // Check if the subarray length equals k
            if (right - left + 1 == k) {
                maxSum = max(maxSum, currentSum);
                // Shrink the window from the left
                freq[nums[left]]--;
                currentSum -= nums[left];
                left++;
            }
        }
        return maxSum;
    }
};

// Example usage:
int main() {
    Solution sol;
    vector<int> nums = {1, 5, 4, 2, 9, 9, 9};
    int k = 3;
    cout << sol.maximumSubarraySum(nums, k) << endl; // Output: 15
    return 0;
}