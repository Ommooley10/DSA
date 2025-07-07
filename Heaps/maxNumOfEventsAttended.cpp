#include <bits/stdc++.h>
using namespace std;

/*You are given an array of events where events[i] = [startDayi, endDayi]. 
Every event i starts at startDayi and ends at endDayi.
You can attend an event i at any day d where startTimei <= d <= endTimei.
You can only attend one event at any time d.
Return the maximum number of events you can attend.

Example 1:
Input: events = [[1,2],[2,3],[3,4]]
Output: 3
Explanation: You can attend all the three events.
One way to attend them all is as shown.
Attend the first event on day 1.
Attend the second event on day 2.
Attend the third event on day 3.

Example 2:
Input: events= [[1,2],[2,3],[3,4],[1,2]]
Output: 4
 */

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());  // Sort by start time
        priority_queue<int, vector<int>, greater<int>> pq; // min-heap based on end time
        int i = 0, n = events.size(), count = 0;

        // Find the max day among all events to loop through
        int lastDay = 0;
        for (auto& e : events) lastDay = max(lastDay, e[1]);

        for (int day = 1; day <= lastDay; ++day) {
            // Push events that start today
            while (i < n && events[i][0] == day) {
                pq.push(events[i][1]);
                ++i;
            }

            // Remove expired events
            while (!pq.empty() && pq.top() < day) {
                pq.pop();
            }

            // Attend event with earliest end day
            if (!pq.empty()) {
                pq.pop();
                count++;
            }
        }
        return count;
    }
};
