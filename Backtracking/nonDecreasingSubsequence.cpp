#include <bits/stdc++.h>
using namespace std;

/*Given an integer array nums, return all the different possible non-decreasing subsequences of the given array with at least two elements. You may return the answer in any order.

Example 1:
Input: nums = [4,6,7,7]
Output: [[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]

Example 2:
Input: nums = [4,4,3,2,1]
Output: [[4,4]]*/

class Solution {
public:
    vector<vector<int>> ans;
    set<vector<int>> st;

    void solve(int current, vector<int>& temp, vector<int>& nums){
        if(temp.size() >= 2 && st.find(temp) == st.end()){
            ans.push_back(temp);
            st.insert(temp);
        }

        if(current >= nums.size()) return;

        if(temp.empty() || temp.back() <= nums[current]){
            temp.push_back(nums[current]);
            solve(current + 1, temp, nums);

            temp.pop_back();
        }
        solve(current + 1, temp, nums);
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> temp;
        int current;

        solve(current, temp, nums);
        return ans;
    }
};