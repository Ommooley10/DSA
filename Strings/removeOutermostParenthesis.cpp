#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<int>stk;
        string ans;
        for(auto ch: s){
            if(ch == '(' && stk.empty()) stk.push(ch);
            else if(ch == '(' && !stk.empty()){
                stk.push(ch);
                ans.push_back(ch);
            }else if(ch == ')'){
                stk.pop();
                if(!stk.empty()){
                    ans.push_back(ch);
                }
            }
        }
        return ans;
    }
};


int main() {
    Solution solution;
    string input = "(()())(())";
    string output = solution.removeOuterParentheses(input);
    cout << "Input: " << input << endl;
    cout << "Output: " << output << endl;
    return 0;
} // Expexted ans is ()()()