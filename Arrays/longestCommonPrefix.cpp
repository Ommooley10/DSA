#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // For std::min
using namespace std;

class Solution {
public:
    string common(string s1, string s2) {   //func to check two adjacent strings in the given array of strings
        int n = min(s1.size(), s2.size());
        string result;   //creating a new empty string
        for (int i = 0; i < n; i++) {
            if (s1[i] == s2[i]) {
                result += s1[i];    //we will append the character if it is the same in the passed two strings
            } else {
                break;
            }
        }
        return result; //return the resulting string obtained
    }

    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        string res = strs[0];
        
        for (int i = 1; i < strs.size(); i++) { //IMP IMPORTANT 
            res = common(res, strs[i]);   //VERY USEFUL STEP OF THE CODE:the code checks the two strings in the array of strings (given in ques) and updates the value of result accordingly.
            if (res.empty()) break; // Early exit if no common prefix
        }
        return res; //returns the result
    }
};

int main() {
    Solution sol;
    vector<string> strs = {"flower", "fly", "flight"};
    cout << "Longest Common Prefix: " << sol.longestCommonPrefix(strs) << endl;
    return 0;
}
