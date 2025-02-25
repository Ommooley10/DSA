#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> result;

    void solve(int current, int target, vector<int>& candidates, vector<int>& temp) {
        if (target == 0) {
            result.push_back(temp);
            return;
        }
        if (current >= candidates.size() || target < 0)
            return;

        // Pick current and explore next
        temp.push_back(candidates[current]);
        solve(current + 1, target - candidates[current], candidates, temp);

        // Not pick and explore next (Backtrack)
        temp.pop_back();
        solve(current + 1, target, candidates, temp);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;

        sort(candidates.begin(), candidates.end());
        solve(0, target, candidates, temp);

        set<vector<int>> st;  //using set to remove the duplicates in the result vector
        for (auto arr : result) {
            st.insert(arr);
        }

        vector<vector<int>> vec(st.begin(), st.end());
        return vec;
    }
};

int main() {
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;

    Solution sol;
    vector<vector<int>> result = sol.combinationSum2(candidates, target);

    cout << "Unique combinations:\n";
    for (const auto& combination : result) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
