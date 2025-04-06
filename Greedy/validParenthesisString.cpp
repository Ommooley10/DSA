#include <bits/stdc++.h>
using namespace std;

/*Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

The following rules define a valid string:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "(*)"
Output: true
Example 3:

Input: s = "(*))"
Output: true

Input: s = "((((()(()()()*()(((((*)()*(**(())))))(())()())(((())())())))))))(((((())*)))()))(()((*()*(*)))(*)()"
Output: true*/

class Solution {
    public:
        bool checkValidString(string s) {
            int min = 0;
            int max = 0;
    
            for(auto ch: s){
                if(ch == '('){
                    min += 1;
                    max += 1;
                }else if(ch == ')'){
                    min -= 1;
                    max -= 1;
                }else{
                    min -= 1;
                    max += 1;
                }
                if(min < 0) min = 0;
                if(max < 0) return false;
            }
            return (min == 0);
        }
    };