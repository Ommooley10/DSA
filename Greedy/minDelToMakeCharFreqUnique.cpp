#include <bits/stdc++.h>
using namespace std;

//SIMILAR TO LEETCODE QUESTION:3085 "min deletions to make string k special"
//in such type of questions the brute force is the optimal way, need to check an element with respect to another element

/*A string s is called good if there are no two different characters in s that have the same frequency.
Given a string s, return the minimum number of characters you need to delete to make s good.
The frequency of a character in a string is the number of times it appears in the string. 
For example, in the string "aab", the frequency of 'a' is 2, while the frequency of 'b' is 1.

Example 1:
Input: s = "aab"
Output: 0
Explanation: s is already good.

Example 2:
Input: s = "aaabbbcc"
Output: 2
Explanation: You can delete two 'b's resulting in the good string "aaabcc".
Another way it to delete one 'b' and one 'c' resulting in the good string "aaabbc".

Example 3:
Input: s = "ceabaacb"
Output: 2
Explanation: You can delete both 'c's resulting in the good string "eabaab".
Note that we only care about characters that are still in the string at the end (i.e. frequency of 0 is ignored).*/

class Solution {
public:
    int minDeletions(string s) {
        unordered_map<int,int>mpp;
        vector<int>freq;
        unordered_set<int> st;
        int count = 0;
    
        for(auto i: s){
            mpp[i]++;
        }

        for(auto it: mpp){
            freq.push_back(it.second);
        }

        st.insert(freq[0]);

        for(int i=1;i<freq.size();i++){
            while(st.find(freq[i]) != st.end() && freq[i] != 0){
                freq[i] -= 1;
                count += 1;
            }
            st.insert(freq[i]);
        }
        return count;
    }
};