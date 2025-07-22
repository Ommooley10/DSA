#include<bits/stdc++.h>
using namespace std;


/*You are given an array of positive integers nums and want to erase a subarray containing unique elements. 
The score you get by erasing the subarray is equal to the sum of its elements.

Return the maximum score you can get by erasing exactly one subarray.

An array b is called to be a subarray of a if it forms a contiguous subsequence of a, that is, if it is equal to a[l],a[l+1],...,a[r] for some (l,r).

Example 1:
Input: nums = [4,2,4,5,6]
Output: 17
Explanation: The optimal subarray here is [2,4,5,6].

Example 2:
Input: nums = [5,2,1,2,5,2,1,2,5]
Output: 8
Explanation: The optimal subarray here is [5,2,1] or [1,2,5].*/


//SOLUTION 1: USING SIMPLE IF ELSE TO SLIDE THE WINDOW
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int sum = 0;
        int maxSum = 0;
        int left = 0;
        int right = 0;
        unordered_set<int> seen;

        while(right < nums.size()){
            if(seen.find(nums[right]) == seen.end()){
                seen.insert(nums[right]);
                sum += nums[right];
                right++;
            }else{
                maxSum = max(maxSum, sum);
                sum -= nums[left];
                seen.erase(nums[left]);
                left++;
            }
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};


//SOLUTION 2: USING A WHILE LOOP TO SLIDE THE WINDOW
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int sum = 0;
        int maxSum = 0;
        int left = 0;
        int right = 0;
        unordered_set<int> seen;

        while(right < nums.size()){
            while(seen.find(nums[right]) != seen.end()){
                sum -= nums[left];
                seen.erase(nums[left]);
                left++;
            }
            
            seen.insert(nums[right]);
            sum += nums[right];
            
            maxSum = max(maxSum, sum);
            right++;
        }
        return maxSum;
    }
};