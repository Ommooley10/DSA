#include <bits/stdc++.h>
using namespace std;

/*you are given a binary array nums.
You can do the following operation on the array any number of times (possibly zero):
Choose any 3 consecutive elements from the array and flip all of them.
Flipping an element means changing its value from 0 to 1, and from 1 to 0.
Return the minimum number of operations required to make all elements in nums equal to 1. 
If it is impossible, return -1.

Example 1:
Input: nums = [0,1,1,1,0,0]
Output: 3
Explanation:
We can do the following operations:
Choose the elements at indices 0, 1 and 2. The resulting array is nums = [1,0,0,1,0,0].
Choose the elements at indices 1, 2 and 3. The resulting array is nums = [1,1,1,0,0,0].
Choose the elements at indices 3, 4 and 5. The resulting array is nums = [1,1,1,1,1,1].

Example 2:
Input: nums = [0,1,1,1]
Output: -1
Explanation:
It is impossible to make all elements equal to 1.*/

//1] Solution may not be a typical sliding window problem but can be solved using that too
// Solution is as easy as it gets, just a care to be taken is that don't overthink about the problem you know, just write the code with the flow!!!
class Solution {
    public:
    
        void flip(vector<int>& nums, int i){
            if(nums[i] == 0) nums[i] = 1;
            else nums[i] = 0;
        }
    
        int minOperations(vector<int>& nums) {
            int n = nums.size();
            int count = 0;
            for(int i=0;i<=n-3;i++){
                if(nums[i] == 0){
                    count++;
                    flip(nums,i);
                    flip(nums,i+1);
                    flip(nums,i+2);
                }
            }
            if(nums[n-1] == 0 || nums[n-2] == 0) return -1;
            else return count; 
        }
    };