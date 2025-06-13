#include <bits/stdc++.h>
using namespace std;

/*Given an array of distinct integers arr, 
find all pairs of elements with the minimum absolute difference of any two elements.
Return a list of pairs in ascending order(with respect to pairs), each pair [a, b] follows
a, b are from arr
a < b
b - a equals to the minimum absolute difference of any two elements in arr
 
Example 1:
Input: arr = [4,2,1,3]
Output: [[1,2],[2,3],[3,4]]
Explanation: The minimum absolute difference is 1. List all pairs with difference equal to 1 in ascending order.

Example 2:
Input: arr = [1,3,6,10,15]
Output: [[1,3]]

Example 3:
Input: arr = [3,8,-10,23,19,-4,-14,27]
Output: [[-14,-10],[19,23],[23,27]]*/

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        int minDiff = INT_MAX;

        for (int i = 1; i < arr.size(); i++) {
            int diff = abs(arr[i] - arr[i - 1]);
            minDiff = min(minDiff, diff);
        }

        for (int i = 1; i < arr.size(); i++) {
            if (abs(arr[i] - arr[i - 1]) == minDiff) {
                ans.push_back({arr[i - 1], arr[i]});   //THIS IS HOW YOU PASS A VEC INSIDE A VEC (vector<vector<int>>)
            }
        }
        return ans;
    }
};