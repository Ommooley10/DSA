#include <bits/stdc++.h>
using namespace std;

/*Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. 
If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

All the visited cells of the path are 0.
All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
The length of a clear path is the number of visited cells of this path.*/


/***INTUITION***:
Here we can either of the two algorithms: BFS and DIJKSTRA.
We can use BFS here as ever cell in the grid has a value of 1, meaning that the cost of travelling to a particular
cell is 1 always (there is no path to the cost), so in these cases we can use the BFS to solve the problems.

In this problem we need to find the shortest path to the last node, so we need to explore each level and on a 
particular level we need to explore only those cells which have the value '0'. And we can move in 8 directions:
left, right, top, bottom, bottom left, bottom right, top left, top right.

Although moving up the level (in case of top left and top right) may seem wrong first but it doesnt matter as they
would be already flagged or visited before and we are keeping track of the visited cells).

As soon as a cell is pushed to the deque, mark it as visited by changing its value to 1.

At last if we reach the goal cell (i.e the last cell), we will level + 1 (+1 because the goal cell will the last level and the level is not updated yet).
*/

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] != 0) return -1;

        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> directions = {{0,-1},{0,1},{-1,0},{1,0},{-1,-1},{-1,1},{1,-1},{1,1}}; //directions to move
        deque<pair<int,int>> dq;
        int level = 0;

        auto isSafe = [&](int x, int y){ //lambda isSafe function to check if the cell (point) is safe to be pushed into deque.
            if(x >= 0 && x < m && y >= 0 && y < n) return true;
            else return false;
        };

        dq.push_back({0,0}); //push the starting cell into deque
        grid[0][0] = 1;  //mark the starting cell as visited by changing its value to 1

        while(!dq.empty()){
            int N = dq.size();

            while(N--){
                auto curr = dq.front(); //current cell
                dq.pop_front();

                int x = curr.first;
                int y = curr.second;

                if(x == m-1 && y == n-1) return level + 1; //if the current cell coordinates = goal corrdinates, return level + 1

                for(auto dir: directions){ //check the neighbouring corrdinates to push onto deque by travelling in all possible directions, including diagonals
                    int x_ = x + dir[0];
                    int y_ = y + dir[1];

                    if(isSafe(x_,y_) && grid[x_][y_] == 0){ //push onto stack only if the neighbouring coordinates is safe(not out of bounds) and value == 0
                        dq.push_back({x_,y_});
                        grid[x_][y_] = 1; //mark the neighbouring coordinate as visited by making it 1
                    }
                }
            }
            level++; //increment the level 
        }
        return -1; //if the goal cell is not found return -1
    }
};