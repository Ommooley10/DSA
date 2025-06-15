#include <bits/stdc++.h>
using namespace std;

/*You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starting. 
You are also given an interval newInterval = [start, end] that represents the start and end of another interval.
Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).
Return intervals after the insertion.

Note that you don't need to modify intervals in-place. You can make a new array and return it.

Example 1:
Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]

Example 2:
Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].*/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        intervals.push_back({newInterval[0],newInterval[1]});
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());

        ans.push_back({intervals[0][0],intervals[0][1]});

        int i=0;
        int j=1;
        while(j<n){
            if(ans[i][1] >= intervals[j][0]){
                ans[i][1] = max(ans[i][1],intervals[j][1]);
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