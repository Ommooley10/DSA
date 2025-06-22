#include <bits/stdc++.h>
using namespace std;

/*Given an array of intervals intervals where intervals[i] = [starti, endi], 
return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.
Note that intervals which only touch at a point are non-overlapping. For example, [1, 2] and [2, 3] are non-overlapping.

//CONSIDER THIS TEST CASE HERE: 
[ [0,3], [1,2], [2,4], [5,7], [8,10] ]

Example 1:
Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.

Example 2:
Input: intervals = [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.

Example 3:
Input: intervals = [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.*/


class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int count = 0;
        int n = intervals.size();
        int i = 0;
        int j = 1;

        while (j < n) {
            if (intervals[i][1] > intervals[j][0]) {
                // Overlapping: remove the interval with larger end
                if (intervals[i][1] > intervals[j][1]) {
                    i = j;  // Keep the one with smaller end
                }
                count++;
            } else {
                i = j;  // No overlap
            }
            j++;
        }

        return count;
    }
};
