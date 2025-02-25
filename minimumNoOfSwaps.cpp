//BALLANCE PARENTHESIS EXTENSION

#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    int minSwaps(string s) {
        stack<char> stk;
        int result;

        // Traverse the string
        for(char ch: s) {
            // If an opening bracket is found, push it to the stack
            if(ch == '[') {
                stk.push(ch);
            }
            // If a closing bracket is found and the stack is not empty, pop the stack
            else if(!stk.empty()) {
                stk.pop();
            }
        }

        // The result is calculated as half of the remaining mismatched brackets
        // (since each swap fixes two mismatched brackets)
        result = (stk.size() + 1) / 2;
        return result;
    }
};

int main() {
    Solution sol;
    
    // Example input
    string s = "]]][[[";
    
    // Get the minimum number of swaps to balance the string
    int result = sol.minSwaps(s);
    
    // Output the result
    cout << "The minimum number of swaps required: " << result << endl;
    
    return 0;
}
