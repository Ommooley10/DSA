#include <bits/stdc++.h>
using namespace std;


/*Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.

In one move, you can increment n - 1 elements of the array by 1.

Example 1:
Input: nums = [1,2,3]
Output: 3
Explanation: Only three moves are needed (remember each move increments two elements):
[1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]

Example 2:
Input: nums = [1,1,1]
Output: 0*/

/*** NOTE ***/
//Check the intuition from the image file provided in the same folder

//HINT: think about calculating the sums of the initial array and the final array obtained with equal elements.

class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int totalMovesReq = 0;

        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        int minElement = nums[0];
        totalMovesReq = sum - minElement*n;

        return totalMovesReq;
    }
};