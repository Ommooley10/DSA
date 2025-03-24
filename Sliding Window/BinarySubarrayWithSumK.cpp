#include<bits/stdc++.h>
using namespace std;

/*Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.
A subarray is a contiguous part of the array.

Example 1:
Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]

Example 2:
Input: nums = [0,0,0,0,0], goal = 0
Output: 15*/

//USE THE SLIDING WINDOW TEMPLATE AS GIVEN IN THE SLIDING WINDOWS'S "SlidingWindowSummary.txt"
class Solution {
    public:
        int noOfSubarray(vector<int> &nums, int goal){
            if(goal < 0) return 0;
            int left = 0;
            int right = 0;
            long long sum = 0;
            int count = 0;
    
            while(right < nums.size()){
                sum += nums[right];
    
                while(sum > goal){
                    sum -= nums[left];
                    left = left + 1;
                }
                count = count + (right-left+1);
                right = right + 1;
            }
            return count;
        }
    
        int numSubarraysWithSum(vector<int>& nums, int goal) {
            int a = noOfSubarray(nums,goal);  //count the no of subarray with sum <= goal
            int b = noOfSubarray(nums,goal-1); // count the no of subarray with sum <= goal-1
            return a-b; //subtract them 
        }
    };