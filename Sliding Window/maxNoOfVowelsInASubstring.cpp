#include <bits/stdc++.h>
using namespace std;

/*Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.
Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.

Example 1:
Input: s = "abciiidef", k = 3
Output: 3
Explanation: The substring "iii" contains 3 vowel letters.

Example 2:
Input: s = "aeiou", k = 2
Output: 2
Explanation: Any substring of length 2 contains 2 vowels.

Example 3:
Input: s = "leetcode", k = 3
Output: 2
Explanation: "lee", "eet" and "ode" contain 2 vowels.*/

//2]] Using classic template of sliding window
class Solution {
    public:
        int maxVowels(string s, int k) {
            int left = 0;
            int right = 0;
            int maxVowels = INT_MIN;
            int vowels = 0;
            int count = 0;
    
            while(right < s.size()){
                if(s[right] == 'a' || s[right] == 'e' || s[right] == 'i' || s[right] == 'o' || s[right] == 'u') vowels++;
                count = count+1;
                while(count > k){
                    if(s[left] == 'a' || s[left] == 'e' || s[left] == 'i' || s[left] == 'o' || s[left] == 'u') vowels--;
                    count = count-1;
                    left = left + 1;
                }
                if(count == k) maxVowels = max(maxVowels,vowels);
                right = right+1;
            }
            return maxVowels;
        }
    };