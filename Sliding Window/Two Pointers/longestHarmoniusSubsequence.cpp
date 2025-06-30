#include <bits/stdc++.h>
using namespace std;

//NOTE: in the subsequence problems, if there is "MIN" and "MAX" involved, then the order of elements doesn't matter, don't think much for it.

/*We define a harmonious array as an array where the difference between its maximum value and its minimum value is exactly 1.
Given an integer array nums, return the length of its longest harmonious subsequence among all its possible subsequences.

Example 1:
Input: nums = [1,3,2,2,5,2,3,7]
Output: 5
Explanation:
The longest harmonious subsequence is [3,2,2,2,3].

Example 2:
Input: nums = [1,2,3,4]
Output: 2
Explanation:
The longest harmonious subsequences are [1,2], [2,3], and [3,4], all of which have a length of 2.

Example 3:
Input: nums = [1,1,1,1]
Output: 0
Explanation:
No harmonic subsequence exists.*/

class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int maxLen = 0;

        int i=0;
        int j=1;
        while(j<nums.size()){
            if(nums[j]-nums[i] == 1) {  //the brute force solution here would be to use 2 for loops and check all possible combinations
                maxLen = max(maxLen,j-i+1);
                j++;
            }else if(nums[j] - nums[i] < 1){
                j++;
            }else if(nums[j] - nums[i] > 1){
                i++;
            }
        }
        return maxLen;
    }
};