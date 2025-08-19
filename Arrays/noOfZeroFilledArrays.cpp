#include <bits/stdc++.h>
using namespace std;

/*Given an integer array nums, return the number of subarrays filled with 0.
A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:
Input: nums = [1,3,0,0,2,0,0,4]
Output: 6
Explanation: 
There are 4 occurrences of [0] as a subarray.
There are 2 occurrences of [0,0] as a subarray.
There is no occurrence of a subarray with a size more than 2 filled with 0. Therefore, we return 6.

Example 2:
Input: nums = [0,0,0,2,0,0]
Output: 9
Explanation:
There are 5 occurrences of [0] as a subarray.
There are 3 occurrences of [0,0] as a subarray.
There is 1 occurrence of [0,0,0] as a subarray.
There is no occurrence of a subarray with a size more than 3 filled with 0. Therefore, we return 9.

Example 3:
Input: nums = [2,10,2019]
Output: 0
Explanation: There is no subarray filled with 0. Therefore, we return 0.*/

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        vector<int> temp;
        long long totalCount = 0;

        for(int i = 0;i < nums.size();i++){
            if(nums[i] == 0){
                temp.push_back(0);
            }else if(temp.size() > 0){
                long long n = temp.size();
                long long increment = (n*(n+1)) / 2;
                totalCount += increment;
                temp.clear();
            }else{
                continue;
            }
        }
        if(temp.size() > 0){ //for any remaining trailing zeroes (can easily be unserstood in dry run)
            long long n = temp.size();
            long long increment = (n*(n+1)) / 2;
            totalCount += increment;
        }
        return totalCount;
    }
};