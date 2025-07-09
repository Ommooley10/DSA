#include <bits/stdc++.h>
using namespace std;

/*Given an array of integers temperatures represents the daily temperatures, 
return an array answer such that answer[i] is the number of 
days you have to wait after the ith day to get a warmer temperature. 
If there is no future day for which this is possible, keep answer[i] == 0 instead.

Example 1:
Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]

Example 2:
Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]

Example 3:
Input: temperatures = [30,60,90]
Output: [1,1,0]*/


// BRUTE FORCE: Searching all possibilities
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans;
        int n = temperatures.size();
        int i = 0;
        int j = 0;

        while (i < n && j <= n) {
            if (j >= n) {
                ans.push_back(0);
                i++;
                j = i;
            } else {
                if (temperatures[j] > temperatures[i]) {
                    ans.push_back(j - i);
                    i++;
                    j = i;
                } else {
                    j++;
                }
            }
        }
        return ans;
    }
};


// OPTIMAL: Using "Monotonic stack"
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n);
        stack<pair<int, int>> stk;

        stk.push({temperatures[n - 1], n - 1});
        ans[n - 1] = 0;

        for (int i = n - 2; i >= 0; i--) {
            
            while (!stk.empty() && stk.top().first <= temperatures[i]) 
                stk.pop(); 

            if (stk.empty()) {
                ans[i] = 0;
            } else {  
                ans[i] = stk.top().second - i; 
            }

            stk.push({temperatures[i], i}); 
        }

        return ans;
    }
};
