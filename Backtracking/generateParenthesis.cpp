#include <bits/stdc++.h>
using namespace std;

/*Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Example 1:
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

Example 2:
Input: n = 1
Output: ["()"]
*/

class Solution {
public:
    vector<string>result;

    //code for checking if the obtained parenthesis is valid or not
    bool isValid(string temp){
        int count = 0;
        for(auto ch: temp){
            if(ch == '(') count+=1;
            else count-=1;
            if(count < 0){
                return false;
                break;
            }
        }
        if(count == 0) return true;
        else return false;
    }

    //MAIN RECURSION LOGIC:
    // at each step, we have to choices, either to take '(' or to take ')'
    void solve(string temp, int tot){
        if(tot == 0){  //if tot is 0, then maximum length of the parenthesis is reached and if valid, it can be appended in the result vector
            if(isValid(temp) == true){
                result.push_back(temp);
            }
            return;
        }
       
       temp.push_back('('); //do: take '('
       solve(temp, tot-1); //explore

       temp.pop_back(); //undo [not take '(']
       solve(temp + ')', tot-1);   //take ')'
    }

    vector<string> generateParenthesis(int n) {
        string temp;
        int tot = 2*n; //as the total number of combinations would be double that of n
        solve(temp,tot);
        return result;
    }
};