#include <bits/stdc++.h>
using namespace std;

/*Given a binary array nums, you should delete one element from it.
Return the size of the longest non-empty subarray containing only 1's in the resulting array. 
Return 0 if there is no such subarray.

Example 1:
Input: nums = [1,1,0,1]
Output: 3
Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.

Example 2:
Input: nums = [0,1,1,1,0,1,1,0,1]
Output: 5
Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].

Example 3:
Input: nums = [1,1,1]
Output: 2
Explanation: You must delete one element.*/

class Solution {
public:
    bool allOnes(vector<int>& nums){
        for(auto num: nums){
            if(num == 0){
                return false;
            }
        }
        return true;
    }

    int longestSubarray(vector<int>& nums) {
        if(allOnes(nums)) return nums.size()-1;
        int maxLen = INT_MIN;
        int left = 0;
        int right = 0;
        int zeroes = 0;
        int ones = 0;

        while(right < nums.size()){
            if(nums[right] == 0){
                zeroes++;
            }else ones++;

            while(zeroes > 1){
                if(nums[left] == 0) zeroes--;
                else ones--;
                left = left + 1;
            }
            maxLen = max(maxLen, ones);
            right = right + 1;
        }
        return maxLen;
    }
};