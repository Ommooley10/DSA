#include <bits/stdc++.h>
using namespace std;

/*You are given a string s consisting only of characters 'a' and 'b'​​​​.
You can delete any number of characters in s to make s balanced. 
s is balanced if there is no pair of indices (i,j) such that i < j and s[i] = 'b' and s[j]= 'a'.
Return the minimum number of deletions needed to make s balanced.

Example 1:
Input: s = "aababbab"
Output: 2
Explanation: You can either:
Delete the characters at 0-indexed positions 2 and 6 ("aababbab" -> "aaabbb"), or
Delete the characters at 0-indexed positions 3 and 6 ("aababbab" -> "aabbbb").

Example 2:
Input: s = "bbaaaaabb"
Output: 2
Explanation: The only solution is to delete the first two characters.*/

class Solution {
public:
    int minimumDeletions(string s) {
        stack<char> stk;
        int count = 0;

        int i = 0;
        while(i < s.size()){
            if(s[i] == 'a' && !stk.empty() && stk.top() == 'b'){
                stk.pop();
                count++;
            }else{
                stk.push(s[i]);
            }
            i++;
        }
        return count;
    }
};