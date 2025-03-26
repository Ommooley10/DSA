#include <iostream>
#include <vector>
#include <algorithm>  // For the max function

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int temp = 0;
        int count = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 1) {
                count++;
            } else {
                temp = max(temp, count);
                count = 0;
            }
        }
        
        // Handle the case where the array ends with a sequence of 1's
        return max(temp, count);
    }
};

int main() {
    // Example usage:
    Solution sol;
    vector<int> nums = {1, 1, 0, 1, 1, 1};
    int max_consecutive_ones = sol.findMaxConsecutiveOnes(nums);
    cout << "Max Consecutive Ones: " << max_consecutive_ones << endl;
    return 0;
}
