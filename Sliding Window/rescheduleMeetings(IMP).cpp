#include<bits/stdc++.h>
using namespace std;


//NOTE: The intuition here is to find how many freeTimes can be merged and what will be the maximum freeTime (maxFreetime), 
//sliding window is used as the order of meeting cannot be changed, first store the free time we get and apply sliding window.

/*You are given an integer eventTime denoting the duration of an event, where the event occurs from time t = 0 to time t = eventTime.
You are also given two integer arrays startTime and endTime, each of length n. 
These represent the start and end time of n non-overlapping meetings, where the ith meeting occurs during the time [startTime[i], endTime[i]].
You can reschedule at most k meetings by moving their start time while maintaining the same duration, 
to maximize the longest continuous period of free time during the event.
The relative order of all the meetings should stay the same and they should remain non-overlapping.
Return the maximum amount of free time possible after rearranging the meetings.

Note that the meetings can not be rescheduled to a time outside the event.

Example 1:
Input: eventTime = 5, k = 1, startTime = [1,3], endTime = [2,5]
Output: 2
Explanation:
Reschedule the meeting at [1, 2] to [2, 3], leaving no meetings during the time [0, 2].

Example 2:
Input: eventTime = 10, k = 1, startTime = [0,2,9], endTime = [1,4,10]
Output: 6
Explanation
Reschedule the meeting at [2, 4] to [1, 3], leaving no meetings during the time [3, 9].

Example 3:
Input: eventTime = 5, k = 2, startTime = [0,1,2,3,4], endTime = [1,2,3,4,5]
Output: 0
Explanation:
There is no time during the event not occupied by meetings.*/

class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int> freeTimes;
        int freetimeSum = 0;
        int maxFreetimeSum = INT_MIN;

        freeTimes.push_back(startTime[0] - 0);  //storing the free times we get during meetings 
        for(int i=1;i<startTime.size();i++){
            freeTimes.push_back(startTime[i] - endTime[i-1]);
        }
        freeTimes.push_back(eventTime - endTime[endTime.size()-1]);

        int l=0;
        int r=0;
        int maxFreetimeMerged = k+1;
        while(r < freeTimes.size()){ 
            if(r-l == maxFreetimeMerged){ // if the number of freeTimes i.e (k+1) is exceeded then remove that freetime
                freetimeSum -= freeTimes[l];
                l++;
            }
            freetimeSum += freeTimes[r];
            maxFreetimeSum = max(maxFreetimeSum, freetimeSum);
            r++;
        }
        return maxFreetimeSum;
    }
};