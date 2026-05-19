#include<bits/stdc++.h>
using namespace std;

/*You are given a circular array nums and an array queries.

For each query i, you have to find the following:

The minimum distance between the element at index queries[i] and any other index j in the circular array, 
where nums[j] == nums[queries[i]]. If no such index exists, the answer for that query should be -1.
Return an array answer of the same size as queries, where answer[i] represents the result for query i.

Example 1:
Input: nums = [1,3,1,4,1,3,2], queries = [0,3,5]
Output: [2,-1,3]

Explanation:
Query 0: The element at queries[0] = 0 is nums[0] = 1. The nearest index with the same value is 2, and the distance between them is 2.
Query 1: The element at queries[1] = 3 is nums[3] = 4. No other index contains 4, so the result is -1.
Query 2: The element at queries[2] = 5 is nums[5] = 3. The nearest index with the same value is 1, and the distance between them is 3 (following the circular path: 5 -> 6 -> 0 -> 1).

Example 2:
Input: nums = [1,2,3,4], queries = [0,1,2,3]
Output: [-1,-1,-1,-1]

Explanation:
Each value in nums is unique, so no index shares the same value as the queried element. This results in -1 for all queries.*/


//SOLUTION 1: BRUTE FORCE (Not using Bianry search)
class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> ans;
        unordered_map<int, vector<int>> mpp;

        // Creating map and storing occurrence indices
        for(int i = 0; i < nums.size(); i++){
            mpp[nums[i]].push_back(i);
        }

        int n = nums.size();

        for(auto i : queries){
            int number = nums[i];

            vector<int> digits = mpp[number];
            bool flag = false;
            int mini = INT_MAX;

            //here we are iterating over all occurances of the element, which has O(n) complexity
            //this can be optimised using binary search
            for(int digit : digits){
                if(digit != i){
                    int diff = abs(digit - i);
                    diff = min(diff, n - diff); //circular distance
                    mini = min(mini, diff);
                    flag = true;
                }
            }

            if(flag) ans.push_back(mini);
            else ans.push_back(-1);
        }

        return ans;
    }
};