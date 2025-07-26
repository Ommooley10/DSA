#include <bits/stdc++.h>
using namespace std;

/*You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. 
If this is impossible, return -1.

Example 1:
Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4

Example 2:
Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten,
 because rotting only happens 4-directionally.

Example 3:
Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.*/


/***INTUITION ***
Here note that each minute, all the rotten oranges are doing their job to rot other fresh orange, meaning
that if at the start there are 2 oranges in the grid which are rotten, then in the 1st minute, both of them
will rot their neighbouring oranges in that every minute and not one after other eg, consider the example 
[[2,1,1,2],[1,1,1,1],[0,0,1,1],[0,0,0,0]], here the two rotten oranges will rot their neighbours in a single minute
(and not one orange rotting in one minute and other rotting in second minute.)

BRIEF: At a given time, all the rotten oranges will rot their neighbours. 
This gives us a hint of "MULTISOURCE BFS"

*/

class Solution {
public:
    //check of the neighbours/points/cell is not out of bound
    bool isSafe(int x, int y, int m, int n) {
        if (x >= 0 && x < m && y >= 0 && y < n)
            return true;
        else
            return false;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int time = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}}; //4 directionally adjacent
        deque<pair<int, int>> dq;

        //finding all the rotten oranges and pushing them onto deque
        /*Note that this differs from the classic BFS in the way that in the classic one we just push the
        intial starting point onto queue but here we have multiple starting point i.e the rotten oranges at a given minute/instance
        so we need to push all of them to process them at once in a single minute
        */
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    dq.push_back({i, j});
                }
            }
        }

        // BFS : This is same as the classic BFS template
        while (!dq.empty()) {
            int N = dq.size();
            bool isRotted = false; //IMP: isRotted is taken to keep a track whether any fresh orange was rotten in this timeframe/ minute,
            //because their might be a possibility that no orange was rotten in this time
            while (N--) {
                auto curr = dq.front();
                dq.pop_front();

                int x = curr.first;
                int y = curr.second;

                for (auto dir : directions) {
                    int x_ = x + dir[0];
                    int y_ = y + dir[1];

                    if (isSafe(x_, y_, m, n) && grid[x_][y_] == 1) {
                        dq.push_back({x_, y_});
                        grid[x_][y_] = 2;
                        isRotted = true; //if the orange was rotten make it true
                    }
                }
            }
            if(isRotted) time++; //if the orange was rotten increase the time
        }

        // check for any leftover fresh oranges, if there are then return -1 else return the time required
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return time;
    }
};