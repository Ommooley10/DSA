#include <bits/stdc++.h>
using namespace std;

/*Given an n x n grid containing only values 0 and 1, where 0 represents water and 1 represents land, 
find a water cell such that its distance to the nearest land cell is maximized, and return the distance. 
If no land or water exists in the grid, return -1.

The distance used in this problem is the Manhattan distance: 
the distance between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.

Example 1:
Input: grid = [[1,0,1],[0,0,0],[1,0,1]]
Output: 2
Explanation: The cell (1, 1) is as far as possible from all the land with distance 2.

Example 2:
Input: grid = [[1,0,0],[0,0,0],[0,0,0]]
Output: 4
Explanation: The cell (2, 2) is as far as possible from all the land with distance 4.*/


/***INTUITION*** : MULTISOURCE BFS AGAIN!! (or maybe not?)
Think of it as traversing from all the initially available land cells to their respective neighbours 
who have water cell i.e 0 AT ONCE or ONE BY ONE (doesnt matter if you use multisource BFS or nor). 
(btw this grid is 4 directionally connected).

As you traverse through each land cell to the neighbouring water cell, increase the count of the water cell by 1,
and push the neighbouring water cell onto queue,this will act as a distance from that land cell to the water cell, 
and similarly when you visit another water cell from that water cell, again add +1 to it, and in between keep track
of the maximum distance encountered til now, at end your ans will be maxDist-1 (because initially you started with distance 1
(land cell)and incremented the distance by 1 whereas it should have been 0)
*/

class Solution {
public:
    bool isSafe(int x, int y, int m, int n) {
        if (x >= 0 && x < m && y >= 0 && y < n)
            return true;
        else
            return false;
    }

    bool allLand(vector<vector<int>>& grid,int m, int n){
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 0) return false;
            }
        }
        return true;
    }

    bool allWater(vector<vector<int>>& grid,int m, int n){
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1) return false;
            }
        }
        return true;
    }

    int maxDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxDist = INT_MIN;
        if(allLand(grid,m,n) || allWater(grid,m,n)) return -1; //if allLand or allWater return -1

        vector<vector<int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}}; 
        deque<pair<int,int>> dq;

        //initially pushing all the land cells onto queue
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1) dq.push_back({i,j});
            }
        }

        //BFS
        while(!dq.empty()){
            int N = dq.size();

            while(N--){ //note that the code will execute even if you do not use this while loop 
                auto curr = dq.front();
                dq.pop_front();

                int x = curr.first;
                int y = curr.second;

                for(auto dir: directions){
                    int x_ = x + dir[0];
                    int y_ = y + dir[1];

                    if(isSafe(x_,y_,m,n) && grid[x_][y_] == 0){
                        dq.push_back({x_,y_});
                        grid[x_][y_] = grid[x][y] + 1;
                        maxDist = max(maxDist, grid[x_][y_]);
                    }
                }
            }
        }
        return maxDist - 1;
    }
};