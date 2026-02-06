#include <bits/stdc++.h>
using namespace std;

/*You are given an integer array nums and an integer k.
An array is considered balanced if the value of its maximum element is at most k times the minimum element.
You may remove any number of elements from nums​​​​​​​ without making it empty.
Return the minimum number of elements to remove so that the remaining array is balanced.
Note: An array of size 1 is considered balanced as its maximum and minimum are equal, 
and the condition always holds true.

Example 1:
Input: nums = [2,1,5], k = 2
Output: 1
Explanation:
Remove nums[2] = 5 to get nums = [2, 1].
Now max = 2, min = 1 and max <= min * k as 2 <= 1 * 2. Thus, the answer is 1.

Example 2:
Input: nums = [1,6,2,9], k = 3
Output: 2
Explanation:
Remove nums[0] = 1 and nums[3] = 9 to get nums = [6, 2].
Now max = 6, min = 2 and max <= min * k as 6 <= 2 * 3. Thus, the answer is 2.

Example 3:
Input: nums = [4,6], k = 2
Output: 0
Explanation:
Since nums is already balanced as 6 <= 4 * 2, no elements need to be removed.*/

/**INTUITION:**
In other words this questions asks us to basically find the largest balanced array, and by subtracting the 
size of this largest balanced array, we can find the number of deletions.

//**IMP**
SIMPLE LOGIC: size of largest balanced array = least elements deleted
to find the no of elements deleted -> nums.size() - size(largest balanced array)
*/

class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        int minDeletions = INT_MAX;
        if(n == 1) return 0;

        sort(nums.begin(), nums.end());
        int i = 0;
        int j = 0;

        while(j < n){
            if(nums[j] <= (long long)nums[i]*k){
                int deletions = n - (j - i + 1); //the number of deletions made (we have to minimize this)
                minDeletions = min(minDeletions, deletions); //minimizing the number of deletions
                j++; //if one balanced array is found, try to maximize it therefore the j pointer moves ahead
            }else{
                i++; //if not then decrease the length of the array and try to find another balanced array
            }
        }

        return minDeletions;
    }
};