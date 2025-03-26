#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> mpp;

        // Count frequency of each number
        for (auto num : nums) {
            mpp[num]++;
        }

        // Store the elements along with their frequencies
        vector<pair<int, int>> freq_arr(mpp.begin(), mpp.end());

        // Custom sorting: Sort by frequency (ascending), then by value (descending)
        sort(freq_arr.begin(), freq_arr.end(), [](auto a, auto b) { 
            return a.second == b.second ? a.first > b.first : a.second < b.second;
        }); //CUSTOM COMPARATOR

        // Build the result array
        vector<int> result;
        for (auto& pair : freq_arr) {
            result.insert(result.end(), pair.second, pair.first);
        }
        return result;
    }
};