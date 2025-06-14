#include <bits/stdc++.h>
using namespace std;

/*Given an array of intervals where intervals[i] = [starti, endi], 
merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

Example 1:
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

Example 2:
Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());

        ans.push_back({intervals[0][0],intervals[0][1]});

        int i=0;
        int j=1;
        while(j<n){
            if(ans[i][1] >= intervals[j][0]){
                ans[i][1] = max(ans[i][1],intervals[j][1]);  //for interval question always replace the upper bound or higher interval limit to max element
                j++;
            } else{
                ans.push_back({intervals[j][0],intervals[j][1]});
                i++;
                j++;
            }
        }
        return ans;
    }
};