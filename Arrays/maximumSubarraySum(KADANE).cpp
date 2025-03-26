#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    // Function to find the maximum subarray sum using Kadane's Algorithm
    int maxSubArray(vector<int>& nums) {
        int sum = 0;  // To store the current subarray sum
        int maxi = INT_MIN;  // To store the maximum subarray sum

        // Iterate through the array
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];  // Add the current element to the sum

            // Update the maximum sum if the current sum is greater
            if (sum > maxi) {
                maxi = sum;
            }

            // If the sum becomes negative, reset it to 0
            if (sum < 0) {
                sum = 0;
            }
        }
        return maxi;  // Return the maximum subarray sum found
    }
};

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};  // Example array
    Solution sol;  // Create an instance of the Solution class
    int result = sol.maxSubArray(nums);  // Find the maximum subarray sum
    cout << "Maximum Subarray Sum: " << result << endl;  // Output the result
    return 0;
}
