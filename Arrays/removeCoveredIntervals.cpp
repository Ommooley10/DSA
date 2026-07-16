#include <bits/stdc++.h>
using namespace std;

/*Given an array intervals where intervals[i] = [li, ri] represent the interval [li, ri), 
remove all intervals that are covered by another interval in the list.

The interval [a, b) is covered by the interval [c, d) if and only if c <= a and b <= d.
Return the number of remaining intervals.

Example 1:
Input: intervals = [[1,4],[3,6],[2,8]]
Output: 2
Explanation: Interval [3,6] is covered by [2,8], therefore it is removed.

Example 2:
Input: intervals = [[1,4],[2,3]]
Output: 1*/

//TIP: ANY "INTERVAL" PROBLEM COMES UP, TRY SORTING THE VECTOR BEFORE DOING ANYTHING

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int count = 0;

        if (intervals.size() == 1)
            return 1;


        //custom sort used: if the start of two intervals is same then sort them in descending order otherwise ascending order
        /*REASON: Take this test case [[1,2],[3,4],[1,4]] and apply the below algorithm on this*/

        sort(intervals.begin(), intervals.end(),
             [](vector<int>& a, vector<int>& b) {
                 if (a[0] == b[0])
                     return a[1] > b[1];
                 return a[0] < b[0];
             });
        int i = 0;
        int j = 1;

        while (j < intervals.size()) {
            if (i == j)
                j++;
            if (intervals[i][0] <= intervals[j][1] && intervals[i][1] >= intervals[j][1]) {
                count++;
                j++;
            } else {
                i = j;
                j++;
            }
        }
        return intervals.size() - count;
    }
};