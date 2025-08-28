#include <bits/stdc++.h>
using namespace std;

/*Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. 
Since the answer may be large, return the answer modulo 109 + 7.

Example 1:
Input: arr = [3,1,2,4]
Output: 17
Explanation: 
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.

Example 2:
Input: arr = [11,81,94,43,3]
Output: 444*/

/*INTUITION*/
/*For each element in the array, look for how many subarrays that element is the smallest element. 
And refer to codesotrywithmik video for in depth intuition and how stack is useful here*/

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int MOD = 1e9 + 7;

        vector<int> NSL;
        vector<int> NSR(n);
        stack<int> stk1; //for filling NSL
        stack<int> stk2; //for filling NSR
        long long totalCount = 0;

        //Creating the NSL (next shortest to left) array
        for(int i = 0; i<n; i++){
            while(!stk1.empty() && arr[i] <= arr[stk1.top()]){
                stk1.pop();
            }

            if(stk1.empty()){
                NSL.push_back(-1);
                stk1.push(i);
            }else{
                NSL.push_back(stk1.top());
                stk1.push(i);
            }
        }


        //Creating the NSR (next shortest to right) array
        for(int i = n - 1; i >= 0; i--){
            while(!stk2.empty() && arr[i] < arr[stk2.top()]){
                stk2.pop();
            }

            if(stk2.empty()){
                NSR[i] = n;
                stk2.push(i);
            }else{
                NSR[i] = stk2.top();
                stk2.push(i);
            }
        }

        /*MAIN LOGIC: here we have to just find the index of the next smaller integer to the left of i and the next smaller integer to the right of i.
        at last we need to subtract the next smaller integer from left (i.e NSL) from i i.e ls = i - NSL[i], 
        and same with NSR i.e rs = NSR[i] - right;
        then we need to multiply these to get the number of subarrays having arr[i] as the smallest element and finally we need to multiply the noOfSubarrayCount with arr[i] to get the count and add it to totalcount*/
        for(int i = 0; i < n; i++){
            int ls = i - NSL[i];
            int rs = NSR[i] - i;
            long long countOfSubarrays = ls*rs;

            totalCount += arr[i]*countOfSubarrays;
        }
        return totalCount % MOD;
    }
};