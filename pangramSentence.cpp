//3] Check if given sentence is pangram, solve it by passing the sentence through a set, as set only takes 
//unique value, the total length of the string should be 26.
#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char> letters;
        for (char c : sentence) {
            if (isalpha(c)) { // Only consider alphabetic characters
                letters.insert(tolower(c)); // Insert the lowercase version to handle case insensitivity
            }
        }
        return letters.size() == 26; // Check if we have exactly 26 unique letters
    }
};

int main() {
    Solution solution;
    string sentence = "The quick brown fox jumps over the lazy dog"; // Example input
    bool result = solution.checkIfPangram(sentence);

    cout << "Is the sentence a pangram? " << (result ? "Yes" : "No") << endl;

    return 0;
}
