#include <bits/stdc++.h>
using namespace std;

/*You are given an integer array nums and an integer k. 
You want to find a subsequence of nums of length k that has the largest sum.
Return any such subsequence as an integer array of length k.
A subsequence is an array that can be derived from another array 
by deleting some or no elements without changing the order of the remaining elements.

Example 1:
Input: nums = [2,1,3,3], k = 2
Output: [3,3]
Explanation:
The subsequence has the largest sum of 3 + 3 = 6.

Example 2:
Input: nums = [-1,-2,3,4], k = 3
Output: [-1,3,4]
Explanation: 
The subsequence has the largest sum of -1 + 3 + 4 = 6.

Example 3:
Input: nums = [3,4,3,3], k = 2
Output: [3,4]
Explanation:
The subsequence has the largest sum of 3 + 4 = 7. 
Another possible subsequence is [4, 3].*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<vector<int>> copy;
        vector<vector<int>> ans;
        vector<int> result;

        // Step 1: Store value and index pairs
        for (int i = 0; i < nums.size(); i++) {
            copy.push_back({nums[i], i});
        }

        // Step 2: Sort by value descending to pick top k elements
        sort(copy.begin(), copy.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0]; // Sort by value descending
        });

        // Step 3: Take top k elements
        for (int i = 0; i < k; ++i) {
            ans.push_back(copy[i]);
        }

        // Step 4: Sort the selected k elements by original index to preserve order
        sort(ans.begin(), ans.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1]; // Sort by index ascending
        });

        // Step 5: Extract the values in correct order
        for (const auto& v : ans) {
            result.push_back(v[0]);
        }

        return result;
    }
};