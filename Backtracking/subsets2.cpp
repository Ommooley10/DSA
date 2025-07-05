#include <bits/stdc++.h>
using namespace std;

//NOTE: The code is same as the subsets 1 problem

/*Given an integer array nums of unique elements, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Example 2:
Input: nums = [0]
Output: [[],[0]]*/

class Solution {
public:
    set<vector<int>> st;

    void solve(int current, vector<int>& nums, vector<int>& temp) {
        if(temp.size() <= nums.size()) st.insert(temp);

        if(current >= nums.size()) return;
        temp.push_back(nums[current]);
        solve(current+1,nums,temp);

        temp.pop_back();
        solve(current+1,nums,temp);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> temp;
        solve(0, nums,temp);
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};