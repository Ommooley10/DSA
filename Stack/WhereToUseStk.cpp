//Leetcode 3174: Clear digit problem

//GREAT PROBLEM TO UNDERSTAND THE USE OF STACK
// Jevha pan "shifting" kevha "eka sobat dusra delete karaycha ahe" tevha stack cha prayog karun pahicha

#include <iostream>
#include <stack>
#include <algorithm>
#include <cctype>
using namespace std;

class Solution {
    public:
        string clearDigits(string s) {
            stack<int>stk;
            string ans;
    
            for(auto ch: s){
                if(isdigit(ch)){
                    stk.pop();
                }else{
                    stk.push(ch);
                }
            }
    
            while(!stk.empty()){
                ans.push_back(stk.top());
                stk.pop();
            }
            reverse(ans.begin(),ans.end());
            return ans;
        }
    };

    int main() {
        Solution solution;
        std::string input = "a1b2c3";
        std::string result = solution.clearDigits(input);
        std::cout << "Result: " << result << std::endl;
        return 0;
    }