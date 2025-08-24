#include <bits/stdc++.h>
using namespace std;

/*Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

Example 1:
Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation: 
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.

Example 2:
Input: matrix = 
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
Output: 7
Explanation: 
There are 6 squares of side 1.  
There is 1 square of side 2. 
Total number of squares = 6 + 1 = 7.
*/

class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& matrix){
        int m = matrix.size();
        int n = matrix[0].size();

        if(i >= m || j >= n){
            return 0;
        }

        if(matrix[i][j] == 0){
            return 0;
        }

        int right = solve(i, j+1, matrix);
        int down = solve(i+1, j, matrix);
        int diagonal = solve(i+1, j+1, matrix);

        return 1 + min({right, down, diagonal});
    }

    int countSquares(vector<vector<int>>& matrix) {
        int result = 0;

        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                result += solve(i, j, matrix); 
            }
        }
        return result;
    }
};
