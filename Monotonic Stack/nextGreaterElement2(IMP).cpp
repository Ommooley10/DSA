#include <bits/stdc++.h>
using namespace std;

//NOTE: This question also explains the use of "circular array" and its implementation.

/*Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), 
return the next greater number for every element in nums.
The next greater number of a number x is the first greater number to its traversing-order next in the array,
which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.

Example 1:
Input: nums = [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2; 
The number 2 can't find next greater number. 
The second 1's next greater number needs to search circularly, which is also 2.

Example 2:
Input: nums = [1,2,3,4,3]
Output: [2,3,4,-1,4]*/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> stk;

        ans[n - 1] = -1;
        stk.push(nums[n - 1]);

        for (int i = 2 * n - 1; i >= 0; i--) {
            while (!stk.empty() && stk.top() <= nums[i % n]) {
                stk.pop();
            }

            if (i < n) { /*This condition is very important as we want to find the next greater element of the elements present only in the original given array 
                and not the array we have assumed by extending the indexes, rest the template is same*/
                if (stk.empty()) {
                    ans[i] = -1;
                }else{
                    ans[i] = stk.top();
                }
            }

            stk.push(nums[i % n]);
        }

        return ans;
    }
};
