#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;

    void combineSum(int current, int target, vector<int>& candidates, vector<int>& temp) {
        if (target == 0) {
            result.push_back(temp);
            return;
        }
        if (current >= candidates.size() || target < 0) return; // Check for out of bounds or negative target

        // Include the current candidate
        temp.push_back(candidates[current]);
        combineSum(current, target - candidates[current], candidates, temp); // Not incrementing current

        // Exclude the current candidate  /////BACKTRACKING
        temp.pop_back();
        combineSum(current + 1, target, candidates, temp); // Incrementing current to move to the next candidate
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        combineSum(0, target, candidates, temp);
        return result;
    }
};

int main() {
    // Input: candidates and target
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    // Create an instance of Solution
    Solution solution;

    // Get the result from the combinationSum method
    vector<vector<int>> result = solution.combinationSum(candidates, target);

    // Output the result
    cout << "Combinations that sum up to " << target << ":" << endl;
    for (const auto& combination : result) {
        cout << "[ ";
        for (int num : combination) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
