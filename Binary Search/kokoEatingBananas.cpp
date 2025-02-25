//This solution gives memory limit exceed, correct solution is below this solution:
#include <vector>
#include <algorithm>
#include <cmath> // For ceil
#include <limits.h> // For INT_MAX

class Solution {
public:
    int maxElement(std::vector<int>& arr) {
        int n = arr.size();
        std::sort(arr.begin(), arr.end());
        return arr[n - 1];
    }

    int findTotalHours(std::vector<int>& arr, int k) {
        int totHrs = 0;
        for (int i : arr) {
            totHrs += std::ceil(i / static_cast<double>(k)); // Ensure proper division
        }
        return totHrs;
    }

    int minEatingSpeed(std::vector<int>& piles, int h) {
        std::vector<int> ans;
        int maxEle = maxElement(piles); // Get the maximum number of bananas in a pile

        // Fill the ans vector with possible speeds from 1 to maxEle
        for (int i = 1; i <= maxEle; i++) {
            ans.push_back(i);
        }

        int low = 0; // Start from the first index of ans
        int high = ans.size() - 1; // Last index of ans
        int res = INT_MAX; // Initialize result with maximum possible speed

        while (low <= high) {
            int mid = (low + high) / 2; // Midpoint of the current range

            int totalHours = findTotalHours(piles, ans[mid]); // Calculate total hours for current speed
            if (totalHours <= h) {
                res = std::min(res, ans[mid]); // Found a valid speed, try for a smaller one
                high = mid - 1; // Search in the lower half
            } else {
                low = mid + 1; // Increase speed
            }
        }
        return res; // Return the minimum speed found
    }
};

//

