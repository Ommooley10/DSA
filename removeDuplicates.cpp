//1] BRUTE FORCE SOLUTION 
/*use of sets -> sets only store unique values, so iterate through the nums array (in ques) and insert the 
value of nums array into the set*/

//2] Optimal solution 
//using two pointer technique
#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0; // Edge case for empty vector
    
    int i = 0; // Pointer to track the position of the last unique element
    for (int j = 1; j < nums.size(); j++) {
        if (nums[j] != nums[i]) {
            i++;
            nums[i] = nums[j]; // Place the next unique element in the correct position
        }
    }
    return i + 1; // The length of the array without duplicates
}

int main() {
    vector<int> nums = {1, 1, 2}; // Example input
    int newLength = removeDuplicates(nums);
    
    cout << "New length: " << newLength << endl;
    cout << "Array after removing duplicates: ";
    for (int i = 0; i < newLength; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    
    return 0;
}


