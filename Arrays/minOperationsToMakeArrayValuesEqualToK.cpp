#include <bits/stdc++.h>
using namespace std;

//Leetcode 3375

class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            int ans = 0;
            unordered_map<int, int> M;
            for (int a : nums) {
                // If any number is less than k, operation can't proceed
                if (a < k) {
                    return -1;
                }
                M[a]++;
                // Count only the first appearance of elements greater than k
                if(a != k && M[a] == 1){
                    ans++;
                }
            }
            return ans;
        }
    };