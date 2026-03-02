#include <bits/stdc++.h>
using namespace std;

/*Given an n x n binary grid, in one step you can choose two adjacent rows of the grid and swap them.
A grid is said to be valid if all the cells above the main diagonal are zeros.
Return the minimum number of steps needed to make the grid valid, or -1 if the grid cannot be valid.
The main diagonal of a grid is the diagonal that starts at cell (1, 1) and ends at cell (n, n).

Example 1:
Input: grid = [[0,0,1],[1,1,0],[1,0,0]]
Output: 3

Example 2:
Input: grid = [[0,1,1,0],[0,1,1,0],[0,1,1,0],[0,1,1,0]]
Output: -1
Explanation: All rows are similar, swaps have no effect on the grid.

Example 3:
Input: grid = [[1,0,0],[1,1,0],[1,1,1]]
Output: 0*/

/*INTUITION:
The trick here is to identify the trailing zeroes in each row, and calculate the number of zeroes it requires
to satisfy the criteria, (use a vector to store the trailing zeroes in each row and then use that vector
to see if the upcoming number of zeroes satisfy the criteria, if they do then calculate the number of swaps
and increase the swap count accordingly)

Use codestorywithmik video for reference if needed
*/

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> endZeroes(0,n);

        for(auto arr: grid){
            int n = arr.size();
            int count = 0;

            for(int i = n-1; i >= 0; i--){
                if(arr[i] == 1){
                    break;
                }else{
                    count++;
                }
            }
            endZeroes.push_back(count);
        }

        int swaps = 0;
        for(int i = 0; i < n; i++){
            int need = n - i - 1;
            int j = i;

            while(j < n && endZeroes[j] < need){
                j++;
            }

            if(j == n){
                return -1;
            }

            swaps += j - i;

            while(j > i){
                swap(endZeroes[j], endZeroes[j-1]);
                j--;
            }
        }

        return swaps;
    }
};