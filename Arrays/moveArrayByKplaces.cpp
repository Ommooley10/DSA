#include <iostream>
#include <vector>
#include <algorithm> // Include algorithm for reverse function

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;  // Handle cases where k is greater than the size of the array
        if (k == 0) return;  // No rotation needed if k is 0
        
        // Reverse the first n - k elements
        reverse(nums.begin(), nums.begin() + n - k);
        
        // Reverse the last k elements
        reverse(nums.begin() + n - k, nums.end());
        
        // Reverse the entire array
        reverse(nums.begin(), nums.end());
    }
};

int main() {
    // Example usage:
    Solution solution;
    
    // Define a vector of integers
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    
    // Define the number of positions to rotate
    int k = 3;
    
    // Print original array
    cout << "Original array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    
    // Call the rotate function
    solution.rotate(nums, k);
    
    // Print rotated array
    cout << "Rotated array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
