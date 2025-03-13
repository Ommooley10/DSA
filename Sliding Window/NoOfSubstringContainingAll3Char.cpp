#include<bits/stdc++.h>
using namespace std;
//Question:
/*Given a string s consisting only of characters a, b and c.
Return the number of substrings containing at least one occurrence of all these characters a, b and c.
Example 1:
Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c are 
"abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again)*/

//BRUTE FORCE:
class Solution {
    public:
    
        bool isValid(string str){
            map<char,int> mpp;
            for(int i=0;i<str.size();i++){
                mpp[str[i]]++;
            }
    
            // Check if all characters 'a', 'b', and 'c' are present
            return mpp['a'] > 0 && mpp['b'] > 0 && mpp['c'] > 0;
        }
    
        int numberOfSubstrings(string s) {
            int count = 0;
            for(int i=0;i<s.size();i++){
                for(int j=i+2;j<s.size();j++){
                    string str = s.substr(i,j-i+1);
                    if(isValid(str) == true) count++;
                }
            }
            return count;
        }
    };

//OPTIMAL (USING SLIDING WINDOW TECHNIQUE):
class Solution {
    public:
        int numberOfSubstrings(string s) {
            int n = s.size();
            int count = 0;
    
            vector<int> mp(3,0);
            int i=0;
            int j=0;
            while(j<n){
                char ch = s[j];
                mp[ch - 'a']++;
                while(mp[0]>0 && mp[1]>0 && mp[2]>0){ //watch codestorywithmik video
                    count = count + (n-j);
                    mp[s[i] - 'a']--;
                    i++;
                }
                j++;
            }
            return count;
        }
    };