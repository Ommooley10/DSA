#include <bits/stdc++.h>
using namespace std;

//NOTE: This code also works for subset II problem (leetcode 90)


//LEETCODE: 78
/*Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:
Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

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
        sort(nums.begin(),nums.end()); //sort in order distinguish vector (for eg, [1,2] & [2,1] will be considered as different vectors by the set)
        vector<int> temp;
        solve(0, nums,temp);
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};