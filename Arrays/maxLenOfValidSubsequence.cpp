#include <bits/stdc++.h>
using namespace std;

/*You are given an integer array nums.
A subsequence sub of nums with length x is called valid if it satisfies:

(sub[0] + sub[1]) % 2 == (sub[1] + sub[2]) % 2 == ... == (sub[x - 2] + sub[x - 1]) % 2.
Return the length of the longest valid subsequence of nums.

A subsequence is an array that can be derived from another array by deleting some or no elements without 
changing the order of the remaining elements.

Example 1:
Input: nums = [1,2,3,4]
Output: 4
Explanation:
The longest valid subsequence is [1, 2, 3, 4].

Example 2:
Input: nums = [1,2,1,1,2,1,2]
Output: 6
Explanation:
The longest valid subsequence is [1, 2, 1, 2, 1, 2].

Example 3:
Input: nums = [1,3]
Output: 2
Explanation:
The longest valid subsequence is [1, 3].*/


                            /**INTUITION:**/
/*first check the equation given in the question for valid subsequence, 
for each sum of adjacent numbers the output will be either 0 or 1, 
so from here we can observe that 0 can be the sum if:
CASE 1:  Both the adjacent numbers are even or both are odd (so first check by taking all even numbers in nums and then check odd numbers in sum, 
whichever has the largest length, store it)

CASE 2: One number is odd and other is even and vice versa. (i.e of different parity)
Check the length by considering case 2 and finally compare the length obtained by case 1 and case 2 
(i.e evenCount, oddCount, alternateParityCount) and return the largest count as ans.
*/

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int maxLen = 0;
        int evenCount = 0;
        int oddCount = 0;

        //CASE 1: Taking all even and odd numbers in the subsequence
        for(auto num: nums){
            if(num % 2 == 0) evenCount++;
            else oddCount++;
        }

        //CASE 2: Checking the alternate combinations in the subsequence (i.e even-odd, odd-even)
        int parity = nums[0] % 2;
        int alternateParityCount = 1; //1 because the first number of nums is already taken above
        for(auto num: nums){
            int currParity = num % 2;
            if(currParity != parity){
                alternateParityCount++;
                parity = currParity;
            }
        }
        return max({evenCount, oddCount, alternateParityCount});
    }
};