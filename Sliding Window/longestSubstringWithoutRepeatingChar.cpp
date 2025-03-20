#include <bits/stdc++.h>
using namespace std;

/*Given a string s, find the length of the longest substring without duplicate characters.
Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.*/

//Classic sliding window problem involcing shrinking the window from left 
class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            unordered_set<char> seen;
            int maxLen = 0;
            int i = 0, j = 0;
            int n = s.size();
            
            while (j < n) {
                if (seen.find(s[j]) == seen.end()) { // Unique character found
                    seen.insert(s[j]);
                    maxLen = max(maxLen, j - i + 1);
                    j++;
                } else { // Duplicate found, shrink from left
                    seen.erase(s[i]);
                    i++;
                }
            }
            
            return maxLen;
        }
    };
    