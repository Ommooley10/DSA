#include <bits/stdc++.h>
using namespace std;

/*You are given an array nums consisting of positive integers.
We call a subarray of an array complete if the following condition is satisfied:
The number of distinct elements in the subarray is equal to the number of distinct elements in the whole array.
Return the number of complete subarrays.
A subarray is a contiguous non-empty part of an array.

Example 1:
Input: nums = [1,3,1,2,2]
Output: 4
Explanation: The complete subarrays are the following: [1,3,1,2], [1,3,1,2,2], [3,1,2] and [3,1,2,2].

Example 2:
Input: nums = [5,5,5,5]
Output: 10
Explanation: The array consists only of the integer 5, so any subarray is complete. 
The number of subarrays that we can choose is 10.*/

class Solution {
    public:
        int countCompleteSubarrays(vector<int>& nums) {
            unordered_map<int,int> nums_map;
            unordered_map<int,int> subarray_map;
    
            for(auto num: nums){
                nums_map[num]++;
            }
            
            int left = 0;
            int right = 0;
            int count = 0;
            while(right < nums.size()){
                subarray_map[nums[right]]++;
                while(subarray_map.size() == nums_map.size()){
                    count = count + (nums.size()-right);
    
                    subarray_map[nums[left]]--;
                    if (subarray_map[nums[left]] == 0) { //erase the number from map if its frequency is 0
                        subarray_map.erase(nums[left]);
                    }
                    left = left + 1;
                }
                right = right + 1;
            }
            return count;
        }
    };