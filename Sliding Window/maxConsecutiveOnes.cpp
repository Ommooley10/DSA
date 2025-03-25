#include <bits/stdc++.h>
using namespace std;

/*Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

Example 1:
Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

Example 2:
Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.*/

class Solution {
    public:
        int longestOnes(vector<int>& nums, int k) {
            int left = 0;
            int right = 0;
            int maxLen = 0;
            int zeroes = 0;
    
            //CLASSIC SLIDING WINDOW TEMPLATE
            while(right < nums.size()){
                if(nums[right] == 0){      //Check condition
                    zeroes++;
                }
    
                while(zeroes > k){    //Shring the window
                    if(nums[left] == 0){
                        zeroes = zeroes - 1;
                        left = left + 1;
                    }else{
                        left = left + 1;
                    }
                }
                maxLen = max(maxLen, right-left+1);  //analyze the max length
                right = right + 1;  //right pointer is always moving
            }
            return maxLen;
        }
    };