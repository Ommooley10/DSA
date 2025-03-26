#include <bits/stdc++.h>
using namespace std;

/*You are given a 2D integer grid of size m x n and an integer x. 
In one operation, you can add x to or subtract x from any element in the grid.
A uni-value grid is a grid where all the elements of it are equal.
Return the minimum number of operations to make the grid uni-value. If it is not possible, return -1.

Example 1:
Input: grid = [[2,4],[6,8]], x = 2
Output: 4
Explanation: We can make every element equal to 4 by doing the following: 
- Add x to 2 once.
- Subtract x from 6 once.
- Subtract x from 8 twice.
A total of 4 operations were used.

Example 2:
Input: grid = [[1,5],[2,3]], x = 1
Output: 5
Explanation: We can make every element equal to 3.

Example 3:
Input: grid = [[1,2],[3,4]], x = 2
Output: -1
Explanation: It is impossible to make every element equal.*/

class Solution {
    public:
        int minOperations(vector<vector<int>>& grid, int x) {
            int m = grid.size();
            int n = grid[0].size();
            vector<int> arr;
    
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    arr.push_back(grid[i][j]);
                }
            }
            sort(arr.begin(),arr.end());
            
            long long target = arr[arr.size()/2];
            long long count = 0;
            for(int i = 1; i < arr.size(); i++) {
                if ((arr[i] - arr[0]) % x != 0) return -1; 
            }
            
            for(int i = 0; i < arr.size(); i++) {
                count += abs(arr[i] - target) / x; 
            }
            return count;
        }
    };