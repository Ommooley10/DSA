#include <bits/stdc++.h>
using namespace std;

/*You are given an array of integers nums, 
there is a sliding window of size k which is moving from the very left of the array to the very right. 
You can only see the k numbers in the window. Each time the sliding window moves right by one position.
Return the max sliding window.

Example 1:
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

Example 2:
Input: nums = [1], k = 1
Output: [1]*/

/*The intuition can be built in such a way that while iterating through each element in nums, we need to make sure the following things:
1. We need to maintain the maximum element

2. If the current element is already greater than the previously visited element, that is our maximum and the previously visited element should be deleted.

3. If the current element is smaller than the previously visited element, then it should be pushed onto the queue, as it may be the maximum element for the next window.

4. In this way we need to maintain a monotonic decreasing order of elements while
traversing and when the window length is reached we will have the maximum element as the starting elemen(dq.front()) and our ans for that particular window. 
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;
        int n = nums.size();

        for(int i=0;i<n;i++){
            //1. check if the current element fits the window
            while(!dq.empty() && dq.front() <= i-k) dq.pop_front();

            //2. maintain a monotonic decreasing order, pop any any element smaller than current element
            while(!dq.empty() && nums[i] > nums[dq.back()]) dq.pop_back();

            //3. push the element onto stack
            dq.push_back(i);

            //4. push the element into ans array
            if(i >= k-1){ //window banna start ho gya
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};