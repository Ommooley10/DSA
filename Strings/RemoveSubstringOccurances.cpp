#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
        string removeOccurrences(string s, string part) {
            while (s.find(part) != string::npos) { // Keep removing until part is no longer found
                s.erase(s.find(part), part.size()); //s.find(part) gives the initial index from where the string starts
            }
            return s;
        }
    };

    #include <iostream>
    #include <string>

    using namespace std;

    int main() {
        Solution solution;
        string s = "daabcbaabcbc";
        string part = "abc";
        string result = solution.removeOccurrences(s, part);
        cout << "Resulting string: " << result << endl;
        return 0;
    }