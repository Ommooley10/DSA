#include <bits/stdc++.h>
using namespace std;

/*Given a string s, remove duplicate letters so that every letter appears once and only once. 
You must make sure your result is the smallest in lexicographical order among all possible results.

Example 1:
Input: s = "bcabc"
Output: "abc"

Example 2:
Input: s = "cbacdcbc"
Output: "acdb"*/

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();

        vector<bool> visited(26, false);
        vector<int> lastOccurence(26, 0);

        for (int i = 0; i < n; i++) { //store the last occurence of every character
            lastOccurence[s[i] - 'a'] = i;
        }

        string ans;

        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (visited[ch - 'a']) continue; //if not visited continue


            //this while checks 3 conditions:
            //1. check if the current character is not eliglbe to fit in,(lexicographical order maintain)
            //2. if not fitting in, then check if the last occurence of the last character of ans string is greater than the current index
            // i.e check if the last character of the ans string occurs later in the given string s

            //3. If it does, then pop it from the stack
            while (!ans.empty() && ch < ans.back() && lastOccurence[ans.back() - 'a'] > i) {
                visited[ans.back() - 'a'] = false;
                ans.pop_back();
            }

            ans.push_back(ch); //at last push if everything is ok
            visited[ch - 'a'] = true;
        }
        return ans;
    }
};
