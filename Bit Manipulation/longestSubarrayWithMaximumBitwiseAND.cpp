#include <bits/stdc++.h>
using namespace std;

/*You are given an integer array nums of size n.
Consider a non-empty subarray from nums that has the maximum possible bitwise AND.

In other words, let k be the maximum value of the bitwise AND of any subarray of nums. 
Then, only subarrays with a bitwise AND equal to k should be considered.
Return the length of the longest such subarray.

The bitwise AND of an array is the bitwise AND of all the numbers in it.
A subarray is a contiguous sequence of elements within an array.

Example 1:
Input: nums = [1,2,3,3,2,2]
Output: 2
Explanation:
The maximum possible bitwise AND of a subarray is 3.
The longest subarray with that value is [3,3], so we return 2.

Example 2:
Input: nums = [1,2,3,4]
Output: 1
Explanation:
The maximum possible bitwise AND of a subarray is 4.
The longest subarray with that value is [4], so we return 1.*/

/**INTUITION**
Always remember that AND operation of one number with the other will either remain the same or will deacrease,
so more numbers you add the more AND value of it will decrease, so in every array/subarray, the maximum AND which
you can obtain is the maximum value of the array, and adding any more element to it will only decrease the overall
AND value.

BRIEF: We have to find the consecutive occurences of the max element in the array in this problem, and not take
any number with the maximum number in the array is it will only decrease the overall value.
*/

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxEle = *max_element(nums.begin(),nums.end());
        int maxLen = 0;
        
        int streak = 0;

        for(auto num: nums){
            if(num == maxEle){
                streak++;
            }else{
                streak = 0;
            }
            maxLen = max(maxLen, streak);
        }
        return maxLen;
    }
};