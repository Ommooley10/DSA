#include <bits/stdc++.h>
using namespace std;

/*You are given an integer num. 
Rearrange the digits of num such that its value is minimized and it does not contain any leading zeros.
Return the rearranged number with minimal value.

Note that the sign of the number does not change after rearranging the digits.

Example 1:
Input: num = 310
Output: 103
Explanation: The possible arrangements for the digits of 310 are 013, 031, 103, 130, 301, 310. 
The arrangement with the smallest value that does not contain any leading zeros is 103.

Example 2:
Input: num = -7605
Output: -7650
Explanation: Some possible arrangements for the digits of -7605 are -7650, -6705, -5076, -0567.
The arrangement with the smallest value that does not contain any leading zeros is -7650.*/

class Solution {
public:
    long long smallestNumber(long long num) {
        if (!num) return num;
        bool neg = num < 0;
        string s = to_string(neg ? -num : num);

        //FOR NEGATIVE NUMBER
        if (neg) {
            sort(s.begin(), s.end(), greater<char>());
            return -stoll(s); //alternative of stoi (used for long long and stoi gives integer)
        } 
        //FOR POSITIVE NUMBER
        else {
            sort(s.begin(), s.end());
            if (s[0] == '0') {
                for (int i = 1; i < s.length(); ++i) {
                    if (s[i] != '0') {
                        swap(s[0], s[i]);
                        break;
                    }
                }
            }
            return stoll(s); //alternative of stoi (used for long long and stoi gives integer)
        }
    }
};

