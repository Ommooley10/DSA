#include <bits/stdc++.h>
using namespace std;

/*Given an array of strings strs, group the anagrams together. You can return the answer in any order.

Example 1:
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Explanation:
There is no string in strs that can be rearranged to form "bat".
The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.

Example 2:
Input: strs = [""]
Output: [[""]]

Example 3:
Input: strs = ["a"]
Output: [["a"]]*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;

        if(strs.empty()){
            return ans;
        }else if(strs.size() == 1){
            ans.push_back(strs);
            return ans;
        }

        unordered_map<string, vector<string>> mpp;

        for(auto str: strs){
            string original = str;
            sort(str.begin(), str.end());

            mpp[str].push_back(original); 
        }


        for(auto it: mpp){
            ans.push_back(it.second);
        }

        return ans;
    }
};