#include<bits/stdc++.h>
using namespace std;

/*The DNA sequence is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T'.

For example, "ACGAATTCCG" is a DNA sequence.
When studying DNA, it is useful to identify repeated sequences within the DNA.

Given a string s that represents a DNA sequence, return all the 10-letter-long sequences 
(substrings) that occur more than once in a DNA molecule. You may return the answer in any order.

Example 1:
Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
Output: ["AAAAACCCCC","CCCCCAAAAA"]

Example 2:
Input: s = "AAAAAAAAAAAAA"
Output: ["AAAAAAAAAA"]*/

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> visited;
        unordered_set<string> ans;

        int i = 0;
        int j = 9;

        while(j < s.size()){
            string sub = s.substr(i, 10);

            if(visited.find(sub) != visited.end()){
                ans.insert(sub);
            }else{
                visited.insert(sub);
            }
            i++;
            j++;
        }
        vector<string> result(ans.begin(), ans.end());
        return result;
    }
};