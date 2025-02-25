//SOMETIMES IT IS WAY SIMPLE THAN WE THINK IT IS


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);  // Convert number to string to manipulate digits
        int n = s.length();

        // Vector to store the index of the maximum element to the right of each digit
        vector<int> maxRight(n);

        // Initialize the last element to be its own maximum
        maxRight[n-1] = n-1;

        // Traverse from the second last element to the first to fill maxRight array
        for (int i = n-2; i >= 0; i--) {
            int rightMaxIdx = maxRight[i+1];
            int rightMaxElement = s[rightMaxIdx];

            // If current digit is larger than or equal to the rightmost maximum, update maxRight[i]
            maxRight[i] = (s[i] > rightMaxElement) ? i : rightMaxIdx;
        }

        // Now check for the first position where swapping will result in a larger number
        for (int i = 0; i < n; i++) {
            int maxRightIdx = maxRight[i];
            int maxRightElement = s[maxRightIdx];
            
            // If we find a digit smaller than the maximum on its right, swap them
            if (s[i] < maxRightElement) {
                swap(s[i], s[maxRightIdx]);
                return stoi(s);  // Convert string back to integer after swap
            }
        }

        // If no swap was made, return the original number
        return num;
    }
};

int main() {
    Solution sol;
    int num = 2736;  // Example input

    // Output the maximum swapped number
    cout << "Maximum number after swap: " << sol.maximumSwap(num) << endl;

    return 0;
}
