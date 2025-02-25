/*INTUITION OF THE ALGO: VERY IMPPPPPP
    1] Find the break point (ind)
    2] find an element just greater than ind, but the smallest in rest of the array so that u stay close
    3] reverse the remaining element after the element at the ind index
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int ind = -1;
        int n = nums.size();

        // Step 1: Find the break point (ind) in the array, if no such ind is found then return the reversed array coz this might be the case of maximum permutation eg(5,4,3,2,1)
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                ind = i;
                break;
            }
        }

        // Step 2: Swap the ind with an element JUST greater than the ind (in order to find the just greater number than the number given in the nums)
        if (ind != -1) {
            for (int i = n - 1; i > ind; i--) {
                if (nums[i] > nums[ind]) {
                    swap(nums[i], nums[ind]);
                    break;
                }
            }
        }

        // Step 3: Reverse the remaining element in order to get an array just greater than the nums array
        reverse(nums.begin() + ind + 1, nums.end());
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2, 1, 5, 4, 3, 0, 0};

    // Display the original array
    cout << "Original array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    // Call the nextPermutation function
    solution.nextPermutation(nums);

    // Display the next permutation of the array
    cout << "Next permutation: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
