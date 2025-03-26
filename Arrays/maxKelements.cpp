/*1. Brute-Force Approach (with computeMax)
In this approach, we repeatedly find the maximum element by scanning the entire array,
which has a time complexity of O(k⋅n).*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to compute the index of the max element
    int computeMax(vector<int>& arr) {
        int maxIndex = 0;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] > arr[maxIndex]) {
                maxIndex = i;
            }
        }
        return maxIndex;
    }

    // Function to compute the maximum score by selecting 'k' max elements
    long long maxKelements(vector<int>& nums, int k) {
        long long maxScore = 0;  // Initialize maxScore

        while (k > 0) {
            // Find the index of the maximum element
            int maxInd = computeMax(nums);

            // Get the max element and add it to the score
            long long num = nums[maxInd];
            maxScore += num;

            // Update the max element by replacing it with ceil(num / 3)
            nums[maxInd] = ceil((double)nums[maxInd] / 3);

            // Decrease k
            k--;
        }

        // Return the total score after processing 'k' elements
        return maxScore;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 45, 54, 71, 76, 12};  // Example input
    int k = 3;  // Number of operations

    long long result = sol.maxKelements(nums, k);
    cout << "Max Score: " << result << endl;  // Output the result

    return 0;
}



/*2. Optimized Approach (Using Max-Heap / Priority Queue)*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to compute the maximum score by selecting 'k' max elements
    long long maxKelements(vector<int>& nums, int k) {
        // Create a max heap (priority queue)
        priority_queue<long long> pq(nums.begin(), nums.end());

        long long maxScore = 0;

        // Process the largest element 'k' times
        while (k > 0) {
            // Extract the maximum element
            long long num = pq.top();
            pq.pop();

            // Add the max element to the score
            maxScore += num;

            // Divide the element by 3 and apply ceil, then push it back to the heap
            pq.push(ceil((double)num / 3));

            // Decrease k
            k--;
        }

        return maxScore;  
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 45, 54, 71, 76, 12};  // Example input
    int k = 3;  // Number of operations

    long long result = sol.maxKelements(nums, k);
    cout << "Max Score: " << result << endl;  // Output the result

    return 0;
}
