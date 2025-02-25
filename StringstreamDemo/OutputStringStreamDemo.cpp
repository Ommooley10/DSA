#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        vector<string> ans;

        stringstream ss(s);
        string word;
        while (ss >> word) {
            ans.push_back(word);
        }

        ostringstream oss;
        for (int i = ans.size() - 1; i >= 0; i--) {
            oss << ans[i] << " ";
        }

        string reversed = oss.str(); //FOR REMOVING TRALING SPACE
        if (!reversed.empty()) {
            reversed.pop_back(); // Remove the last space
        }
        return reversed;
    }
};

int main() {
    Solution solution;
    string input = "Hello this is john";
    string output = solution.reverseWords(input);
    
    cout << "Reversed words: \"" << output << "\"" << endl; // Output: "john is this Hello"

    return 0;
}