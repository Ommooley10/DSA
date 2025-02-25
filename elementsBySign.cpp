#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> res(nums.size()); // Initialize the result vector with the same size as nums
        int j = 0; // Pointer for even indices
        int k = 1; // Pointer for odd indices
        
        // Iterate over the nums array and place positive and negative numbers accordingly
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0){
                res[j] = nums[i];
                j += 2;
            } else if(nums[i] < 0){
                res[k] = nums[i];
                k += 2;
            }
        }
        return res; // Return the rearranged array
    }
};

int main() {
    Solution solution;
    vector<int> nums = {3, 1, -2, -5, 2, -4}; // Sample input
    
    vector<int> result = solution.rearrangeArray(nums); // Call the rearrangeArray function
    
    // Print the result
    for(int i : result) {
        cout << i << " ";
    }
    
    return 0;
}
