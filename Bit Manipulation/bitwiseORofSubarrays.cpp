#include <bits/stdc++.h>
using namespace std;

/*Given an integer array arr, return the number of distinct bitwise ORs of all the non-empty subarrays of arr.
The bitwise OR of a subarray is the bitwise OR of each integer in the subarray. 
The bitwise OR of a subarray of one integer is that integer.

A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:
Input: arr = [0]
Output: 1
Explanation: There is only one possible result: 0.

Example 2:
Input: arr = [1,1,2]
Output: 3
Explanation: The possible subarrays are [1], [1], [2], [1, 1], [1, 2], [1, 1, 2].
These yield the results 1, 1, 2, 1, 3, 3.
There are 3 unique values, so the answer is 3.

Example 3:
Input: arr = [1,2,4]
Output: 6
Explanation: The possible results are 1, 2, 3, 4, 6, and 7.*/

/**INTUITION**
Take eg. [1,5,3,9,7,8]
Here at each index that we are standing, we need to OR it with all the elements behind that index, meaning that
if we are standing at index 1 (value: 5), then we need to find the OR of 5 with 1 and itself, similarly at index 2
(value: 3) the combination would be 3 itself, 5 OR 3, 5 OR 3 OR 1, so here we need to keep a track of the prev ORs
as well as the current ORs (which we are calculating through index i) and also we need to insert all the calculated 
ORs into a set to avoid duplication and return set.size(). 
*/
//1. OPTIMAL SOLN: 
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> prev;
        unordered_set<int> curr;
        unordered_set<int> result;

        //insert the first element onto set
        prev.insert(arr[0]);
        result.insert(arr[0]);

        if(arr.size() == 1) return result.size();

        for(int i=1;i<arr.size();i++){

            //combination with the prev set (calculating ORs with the previous elements)
            for(auto num: prev){
                curr.insert(num | arr[i]);
                result.insert(num | arr[i]);
            }
            
            //calculating or with itself
            curr.insert(arr[i]);
            result.insert(arr[i]);

            prev = curr;
            curr.clear();
        }
        return result.size();
    }
};