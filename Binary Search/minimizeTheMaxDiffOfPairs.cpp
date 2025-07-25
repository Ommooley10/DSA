#include <bits/stdc++.h>
using namespace std;
// *SUCH TYPES OF QUESTION COME IN THE TYPE: "BINARY SEARCH ON THE ANSWER"**
// answer vartich binary search lavaycha
//How To identify:minimum of maximum or maximize the minimum

/*You are given a 0-indexed integer array nums and an integer p.
Find p pairs of indices of nums such that the maximum difference amongst all the pairs is minimized. 
Also, ensure no index appears more than once amongst the p pairs.
Note that for a pair of elements at the index i and j, the difference of this pair is |nums[i] - nums[j]|,
 where |x| represents the absolute value of x.
Return the minimum maximum difference among all p pairs. We define the maximum of an empty set to be zero.

Example 1:
Input: nums = [10,1,2,7,1,3], p = 2
Output: 1
Explanation: The first pair is formed from the indices 1 and 4, and the second pair is formed from the indices 2 and 5. 
The maximum difference is max(|nums[1] - nums[4]|, |nums[2] - nums[5]|) = max(0, 1) = 1. Therefore, we return 1.

Example 2:
Input: nums = [4,2,1,2], p = 1
Output: 0
Explanation: Let the indices 1 and 3 form a pair. 
The difference of that pair is |2 - 2| = 0, which is the minimum we can attain.*/

class Solution {
public:
    int countValidPairs(const vector<int>& nums, int mid) {
        int count = 0;
        int i = 1;
        int n = nums.size();

        while (i < n) {
            if (nums[i] - nums[i - 1] <= mid) {
                count++;
                i += 2;  // skip next index to avoid overlap
            } else {
                i++;
            }
        }
        return count;
    }

    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums[nums.size()-1] - nums[0]; // max possible difference
        int result = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int count = countValidPairs(nums, mid);

            if (count >= p) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return result;
    }
};
