#include <bits/stdc++.h>
using namespace std;

/*NOTE: THE FORMULA TO wrap THE ASCII CHARACTER NUMBER around to stay within the valid printable lowercase letters IS 
'a' + (original - 'a' + shift) % 26*/

//TIP: THIS PROBLEM IS BEST FOR UNSERSTANDING "PREFIX/SUFFIX SUM".

/*You are given a string s of lowercase English letters and an integer array shifts of the same length.
Call the shift() of a letter, the next letter in the alphabet, (wrapping around so that 'z' becomes 'a').
For example, shift('a') = 'b', shift('t') = 'u', and shift('z') = 'a'.
Now for each shifts[i] = x, we want to shift the first i + 1 letters of s, x times.
Return the final string after all such shifts to s are applied.

Example 1:
Input: s = "abc", shifts = [3,5,9]
Output: "rpl"
Explanation: We start with "abc".
After shifting the first 1 letters of s by 3, we have "dbc".
After shifting the first 2 letters of s by 5, we have "igc".
After shifting the first 3 letters of s by 9, we have "rpl", the answer.

Example 2:
Input: s = "aaa", shifts = [1,2,3]
Output: "gfd"*/

class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        long long total = accumulate(shifts.begin(),shifts.end(),0LL); //instead of directly subtracting from total sum, we can maintain an array of suffix/prefix sum
        int n = shifts.size();
        char c = s[0];
        s[0] = (char)('a' + (c - 'a' + total) % 26);


        for(int i=1; i < n; i++){
            char ch = s[i];
            long long shiftsReq = total-shifts[i-1];
            total = total-shifts[i-1];
            s[i] = (char)('a' + (ch - 'a' + shiftsReq) % 26); 
        }
        return s;
    }
};
