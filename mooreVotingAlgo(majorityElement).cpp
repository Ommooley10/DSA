#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;  // Initialize count to 0
        int ele = 0;  // Initialize element to 0 or any default value

        for(int i = 0; i < nums.size(); i++) {
            if(cnt == 0) {
                ele = nums[i];
                cnt = 1;
            } else if(nums[i] == ele) {
                cnt++;
            } else {
                cnt--;
            }
        }

        // Optional: Confirm that ele is indeed the majority element
        int cnt1 = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == ele) {
                cnt1++;
            }
        }

        if(cnt1 > nums.size() / 2) {
            return ele;
        }

        return -1; // Return -1 or any sentinel value if no majority element found
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    int result = sol.majorityElement(nums);
    cout << "The majority element is: " << result << endl;
    return 0;
}
