#include <bits/stdc++.h>
using namespace std;

//NOTE: There are 3 solutions below, 2 of them are valid, just one requires more space. and the 3rd one is brute force

/*Given an m x n grid of characters board and a string word, return true if word exists in the grid.
The word can be constructed from letters of sequentially adjacent cells, 
where adjacent cells are horizontally or vertically neighboring. 
The same letter cell may not be used more than once.

Example 1:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true

Example 2:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true

Example 3:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
 */


//CODE 1: Using an extra space to mark the visited cells
class Solution {
public:
    int m, n;

    bool solve(vector<vector<char>>& board, string& word, int i, int j, int index, vector<vector<bool>>& visited) {
        if (index == word.size()) return true;

         //this line ensures that we are exploring a valid cell
        if (i < 0 || i >= m || j < 0 || j >= n ||
            visited[i][j] || board[i][j] != word[index]) { 
                /*Also the board[i][j] != word[index] ensures that we are exploring only that path though which we can get answer, not unnecessarilt exploring all paths.
                    board[i][j] != word[index] checks is the current letter we are checking is same as the letter in the word at the same index.
                */
            return false;
        }

        visited[i][j] = true; //mark the current cell as visited to avoid choosing that cell next time

        bool found = solve(board, word, i + 1, j, index + 1, visited) ||
                     solve(board, word, i - 1, j, index + 1, visited) ||
                     solve(board, word, i, j + 1, index + 1, visited) ||
                     solve(board, word, i, j - 1, index + 1, visited);

        visited[i][j] = false;  //BACKTRACK: Resetting the cell to its default state
        return found;  //return the final answer
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));


        //Important
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (solve(board, word, i, j, 0, visited)) {
                    return true;  
                }
            }
        }

        return false;
    }
};


//CODE 2: Without using extra space
class Solution {
public:
    int m, n;

    bool solve(vector<vector<char>>& board, string& word, int i, int j, int index) {
        if (index == word.size()) return true;

        if (i < 0 || i >= m || j < 0 || j >= n ||
            board[i][j] == '$' || board[i][j] != word[index]) {
            return false;
        }

        //instead of using a different vector for visited nodes, just mark the current node with some special character (i.e '$')
        char temp = board[i][j];
        board[i][j] = '$';

        bool found = solve(board, word, i + 1, j, index + 1) ||
                     solve(board, word, i - 1, j, index + 1) ||
                     solve(board, word, i, j + 1, index + 1) ||
                     solve(board, word, i, j - 1, index + 1);

        board[i][j] = temp; //backtrack

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (solve(board, word, i, j, 0)) {
                    return true;  
                }
            }
        }

        return false;
    }
};


/*CODE 3: Kinda brute force approach as we are first sotring all possibilities in a set and then finding 
if the word exists in the set.
*/
class Solution {
public:
    unordered_set<string> st;
    vector<vector<bool>> visited;

    void solve(string wordFormed, string& word, int i, int j, int m, int n, vector<vector<char>>& board) {
        // boundary checks
        if (i < 0 || i >= m || j < 0 || j >= n) return;
        if (visited[i][j]) return;

        wordFormed += board[i][j];

        if (wordFormed.size() > word.size()) return;

        if (wordFormed == word) {
            st.insert(wordFormed);
            return; // no need to go deeper
        }

        visited[i][j] = true;

        solve(wordFormed, word, i+1, j, m, n, board); // down
        solve(wordFormed, word, i-1, j, m, n, board); // up
        solve(wordFormed, word, i, j+1, m, n, board); // right
        solve(wordFormed, word, i, j-1, m, n, board); // left

        visited[i][j] = false; // backtrack
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                solve("", word, i, j, m, n, board);
                if (st.count(word)) return true;
            }
        }

        return false;
    }
};




