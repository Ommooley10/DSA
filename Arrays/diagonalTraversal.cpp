#include<bits/stdc++.h>
using namespace std;

/*Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order.

Example 1:
Input: mat = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,4,7,5,3,6,8,9]

Example 2:
Input: mat = [[1,2],[3,4]]
Output: [1,2,3,4]*/


/***INTUITION***/
/*These questions are about analyzing the patterns. 
For each cell of the matrix i.e mat[i][j], calculate the value of (i+j), you will notice that certain cells contain the same value of i+j, and those cells are to be returned together in a certain order, so one task is tackled here i.e grouping the elements which are to be returned together.

For storing the i+j and its corresponding value we can use a map (ordered map, since we need to maintain the order), where in the map the i+j would be the key and the corresponding values will be stored in an array as we traverse.

The second task is to return the elements in the order mentioned in the question which if if see carefully is to flip every alternate array in the map, so for that we will take a flag/flip variable and flip the alternate array and store the result in the result vector and finally return it
*/

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        //use ordered map here to maintain the order of numbers pushed onto the vector
        map<int, vector<int>> mpp;
        vector<int> result;

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                //this is how you insert the key (i+j) and it's value in the vector
                mpp[i+j].push_back(mat[i][j]);
            }
        }

        //we need to flip the alternate vectors therefore maintain a flip variable
        bool flip = true;
        for(auto it: mpp){
            auto arr = it.second;
            if(flip == true){
                reverse(arr.begin(), arr.end());
            }

            for(auto num: arr){
                result.push_back(num);
            }
            //flip the parity after operation is done
            flip = !flip;
        }
        return result;
    }
};