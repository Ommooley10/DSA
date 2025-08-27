#include <bits/stdc++.h>
using namespace std;

/*Given an m x n binary matrix mat, return the number of submatrices that have all ones.

Example 1:
Input: mat = [[1,0,1],[1,1,0],[1,1,0]]
Output: 13
Explanation: 
There are 6 rectangles of side 1x1.
There are 2 rectangles of side 1x2.
There are 3 rectangles of side 2x1.
There is 1 rectangle of side 2x2. 
There is 1 rectangle of side 3x1.
Total number of rectangles = 6 + 2 + 3 + 1 + 1 = 13.

Example 2:
Input: mat = [[0,1,1,0],[0,1,1,1],[1,1,1,0]]
Output: 24
Explanation: 
There are 8 rectangles of side 1x1.
There are 5 rectangles of side 1x2.
There are 2 rectangles of side 1x3. 
There are 4 rectangles of side 2x1.
There are 2 rectangles of side 2x2. 
There are 2 rectangles of side 3x1. 
There is 1 rectangle of side 3x2. 
Total number of rectangles = 8 + 5 + 2 + 4 + 2 + 2 + 1 = 24.*/


class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int result = 0;

        //SR = startRow, ER = endRow
        for (int SR = 0; SR < m; SR++) {
            for (int ER = SR; ER < m; ER++) {
                if (SR == ER) {  //if there is only row
                    int consec = 0;
                    auto arr = mat[SR];
                    for (int num : arr) {
                        if (num == 0) {
                            result += (consec * (consec + 1)) / 2;
                            consec = 0;
                        } else {
                            consec++;
                        }
                    }
                    if (consec > 0)
                        result += (consec * (consec + 1)) / 2;
                } else {  //if there is a range between ro and column
                    vector<int> temp;

                    for (int col = 0; col < n; col++) {
                        int aggregate = 1;
                        for (int row = SR; row <= ER; row++) {
                            if (mat[row][col] == 0) {
                                aggregate = 0;
                                break;
                            }
                        }
                        temp.push_back(aggregate);
                    }
                    
                    int consec = 0;
                    for (int num : temp) {
                        if (num == 0) {
                            result += (consec * (consec + 1)) / 2;
                            consec = 0;
                        } else {
                            consec++;
                        }
                    }
                    if (consec > 0)
                        result += (consec * (consec + 1)) / 2;
                }
            }
        }
        return result;
    }
};