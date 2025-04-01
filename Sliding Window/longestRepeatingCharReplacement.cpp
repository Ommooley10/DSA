#include<bits/stdc++.h>
using namespace std;

/*You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. 
You can perform this operation at most k times.
Return the length of the longest substring containing the same letter you can get after performing the above operations.

Example 1:
Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.

Example 2:
Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achieve this answer too.*/

class Solution {
    public:
        int characterReplacement(string s, int k) {
            int left = 0, right = 0, maxLen = 0, maxCount = 0;
            vector<int> freq(26, 0);
            
            while (right < s.size()) {
                freq[s[right] - 'A']++;
                maxCount = max(maxCount, freq[s[right] - 'A']);
                
                if ((right - left + 1) - maxCount > k) {
                    freq[s[left] - 'A']--;
                    left++;
                }
                
                maxLen = max(maxLen, right - left + 1);
                right++;
            }
            return maxLen;
        }
    };