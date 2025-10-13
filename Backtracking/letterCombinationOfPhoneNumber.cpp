#include <bits/stdc++.h>
using namespace std;

/*Given a string containing digits from 2-9 inclusive, 
return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. 
Note that 1 does not map to any letters.

Example 1:
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

Example 2:
Input: digits = ""
Output: []

Example 3:
Input: digits = "2"
Output: ["a","b","c"]*/

class Solution {
public:
    unordered_map<char, string> mpp = {{'2', "abc"},{'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

    vector<string> result;
    void solve(int idx, string digits, string temp){  //idx is for the digit (eg "23")
        if(idx >= digits.size()){
            result.push_back(temp);
            return;
        }

        char ch = digits[idx]; //eg: '2'
        string str = mpp[ch];  // eg 2 -> "abc"

        for(int i = 0; i < str.size(); i++){ //iterate through str as we need to take/ not take each character
            temp.push_back(str[i]);
            solve(idx + 1, digits, temp); //now as there is idx + 1, the idx will now point to 3 i.e "def" as the second character should be from another number

            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return result;

        string temp = "";
        int idx = 0;
        solve(idx, digits, temp);
        return result;   
    }
};