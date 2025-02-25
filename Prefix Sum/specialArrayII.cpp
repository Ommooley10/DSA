//1] BRUTE FORCE SOLUTION
//iterating over each query and checking if the subarray is special or not

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isSpecial(vector<int>& nums, int from, int to) {
        // Check if the subarray from 'from' to 'to' is special
        for (int i = from; i < to; i++) {
            // Check if two consecutive numbers are both even or both odd
            if ((nums[i] % 2 == 0 && nums[i + 1] % 2 == 0) || 
                (nums[i] % 2 == 1 && nums[i + 1] % 2 == 1)) {
                return false;
            }
        }
        return true;
    }

    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<bool> ans;

        for (const auto& query : queries) {
            int from = query[0];
            int to = query[1];

            // Check if the subarray is special and push the result
            ans.push_back(isSpecial(nums, from, to));
        }
        return ans;
    }
};

#include <iostream>

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    vector<vector<int>> queries = {{0, 2}, {1, 3}, {2, 5}};

    vector<bool> results = solution.isArraySpecial(nums, queries);

    for (bool result : results) {
        cout << (result ? "True" : "False") << endl;
    }

    return 0;
} //EXPECTED OUTPUT: [True, False, True]


//OPTIMAL APPROACH
class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();

        vector<int> cumSum(n, 0);
        //cumSum[i] = total count of violating indices till index i
        cumSum[0] = 0;

        for(int i = 1; i < n; i++) {
            if(nums[i]%2 == nums[i-1]%2) { //violating index 
                cumSum[i] = cumSum[i-1]+1;
            } else {
                cumSum[i] = cumSum[i-1];
            }
        }

        vector<bool> result(m, false);
        int i = 0;
        for(vector<int>& query : queries) {
            int start = query[0];
            int end = query[1];

            if(cumSum[end] - cumSum[start] == 0) {
                result[i] = true;
            }
            i++;
        }

        return result;
    }
};
