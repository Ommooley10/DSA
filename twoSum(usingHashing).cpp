#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mpp;  // Map to store the (element,index) of each number
        for (int i = 0; i < nums.size(); i++) {
            int moreNeeded = target - nums[i];  // The value needed to reach the target
            if (mpp.find(moreNeeded) != mpp.end()) {
                return {mpp[moreNeeded], i};  // Return the indices of the two numbers
            }
            mpp[nums[i]] = i;  // Store the index of the current number
        }
        return {-1, -1};  // Return {-1, -1} if no solution is found
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 7, 11, 15};  // Example array
    int target = 9;  // Target sum

    vector<int> result = sol.twoSum(nums, target);

    // Print the result
    if (result[0] != -1) {
        cout << "Indices: " << result[0] << " and " << result[1] << endl;
    } else {
        cout << "No two sum solution found" << endl;
    }

    return 0;
}
