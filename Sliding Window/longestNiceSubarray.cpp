#include <bits/stdc++.h>
using namespace std;

/*You are given an array nums consisting of positive integers.
We call a subarray of nums nice if the bitwise AND of every pair of elements that are in different positions in the subarray is equal to 0.
Return the length of the longest nice subarray.
A subarray is a contiguous part of an array.
Note that subarrays of length 1 are always considered nice.

Example 1:
Input: nums = [1,3,8,48,10]
Output: 3
Explanation: The longest nice subarray is [3,8,48]. This subarray satisfies the conditions:
- 3 AND 8 = 0.
- 3 AND 48 = 0.
- 8 AND 48 = 0.
It can be proven that no longer nice subarray can be obtained, so we return 3.

Example 2:
Input: nums = [3,1,5,11,13]
Output: 1
Explanation: The length of the longest nice subarray is 1. Any subarray of length 1 can be chosen.*/

//1] BRUTE FORCE:
class Solution {
    public:
        bool isNice(vector<int> &nums, int i, int j){
            for(int x=i;x<=j;x++){
                for(int y=x+1;y<=j;y++){
                    if((nums[x] & nums[y]) != 0){
                        return false;
                    }
                }
            }
            return true;
        }
    
        int longestNiceSubarray(vector<int>& nums) {
            int maxLen = 1;
            for (int i = 0; i < nums.size(); i++) {
                for (int j = i + 1; j < nums.size(); j++) {
                    if (isNice(nums, i, j)){
                        int len = j-i+1;
                        maxLen = max(maxLen,len);
                    }
                }
            }
            return maxLen;
        }
    };

//2] BETTER SOLUTION (USING 2 POINTERS): The better solution in this case is also optimal soln for leetcode.
class Solution {
    public:
        bool isNice(vector<int> &nums, int i, int j){
            for(int x=i;x<=j;x++){
                for(int y=x+1;y<=j;y++){
                    if((nums[x] & nums[y]) != 0){
                        return false;
                    }
                }
            }
            return true;
        }
    
        int longestNiceSubarray(vector<int>& nums) {
            int n = nums.size();
    
            int maxLen = 1;
            int len = 1;
            int i=0;
            int j=1;
    
            while(i<n){
                if(j<n && isNice(nums,i,j)){
                    len++;
                    j++;
                }else{
                    maxLen = max(len,maxLen);
                    len = 1;
                    i++;
                    j=i+1;    
                }
            }
            return maxLen;
        }
    };

//3] OPTIMAL SOLUTION (USING SLIDING WINDOW):