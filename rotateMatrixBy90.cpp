#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to rotate the matrix 90 degrees clockwise
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        // Step 1: Transpose the matrix (swap elements across the diagonal)
        for (int i = 0; i <= n - 2; i++) {
            for (int j = i + 1; j <= n - 1; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        // Step 2: Reverse each row to get the rotated matrix
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

// Utility function to print the matrix
void printMatrix(vector<vector<int>>& matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    // Input matrix
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    // Creating an object of Solution class
    Solution sol;
    
    // Rotating the matrix
    sol.rotate(matrix);
    
    // Printing the rotated matrix
    cout << "Rotated Matrix: " << endl;
    printMatrix(matrix);

    return 0;
}
        