#include <bits/stdc++.h>
using namespace std;

/*You are given two positive integers low and high.
An integer x consisting of 2 * n digits is symmetric if the sum of the first n digits of x is equal to the sum of the last n digits of x. 
Numbers with an odd number of digits are never symmetric.
Return the number of symmetric integers in the range [low, high].

Example 1:
Input: low = 1, high = 100
Output: 9
Explanation: There are 9 symmetric integers between 1 and 100: 11, 22, 33, 44, 55, 66, 77, 88, and 99.

Example 2:
Input: low = 1200, high = 1230
Output: 4
Explanation: There are 4 symmetric integers between 1200 and 1230: 1203, 1212, 1221, and 1230.*/

class Solution {
    public:
        int countSymmetricIntegers(int low, int high) {
            int count = 0;
            for(int i = low;i<=high;i++){
                string num = to_string(i);
                if(num.size() % 2 == 0){
                    int leftSum = 0;
                    int rightSum = 0;
                    int half = num.size()/2;
    
                    for(int i=0;i<half;i++) leftSum += num[i] - '0'; //stoi won't work here as it cannot convert a single character to string therefore use this method.
    
                    for(int i=half;i<num.size();i++)  rightSum += num[i] - '0';
    
                    if(leftSum == rightSum) count++;
                }
            }
            return count;
        }
    };