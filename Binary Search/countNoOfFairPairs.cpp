#include<bits/stdc++.h>
using namespace std;

/*Given a 0-indexed integer array nums of size n and two integers lower and upper, 
return the number of fair pairs.
A pair (i, j) is fair if:
0 <= i < j < n, and
lower <= nums[i] + nums[j] <= upper
 
Example 1:
Input: nums = [0,1,7,4,4,5], lower = 3, upper = 6
Output: 6
Explanation: There are 6 fair pairs: (0,3), (0,4), (0,5), (1,3), (1,4), and (1,5).

Example 2:
Input: nums = [1,7,9,2,5], lower = 11, upper = 11
Output: 1
Explanation: There is a single fair pair: (2,3).*/

/*A PROBLEM INVOLVING THE USE OF UPPER AND LOWER BOUND
METHODOLOGY:
 int countX = no of pair with sum < lower
 int countY = no of pair with sum <= upper
int totalCount = countY - countX;
return totalCount*/


#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long totalCount = 0;
        int n = nums.size();
        
        for(int i = 0; i < n; ++i) {
            int left = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]) - nums.begin();
            int right = upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]) - nums.begin();
            totalCount += (right - left);
        }
        return totalCount;
    }
};
