//GOOD QUESTION FOR UNDERSTANDING STRING FORMATTING

//1] BRUTE FORCE (self made):
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    string replaceWord(vector<string>& arr, string word) {
        string shortestRoot = word;
        for (auto root : arr) {
            int n = root.size();
            if (word.substr(0, n) == root && n < shortestRoot.size()) {
                shortestRoot = root;
            }
        }
        return shortestRoot;
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        vector<string> words;
        vector<string> ans;
        stringstream ss(sentence);
        string word;
        while (ss >> word) {
            words.push_back(word);
        }

        for (auto word : words) {
            string replacedWord = replaceWord(dictionary, word);
            ans.push_back(replacedWord);
        }

        ostringstream oss;
        for (size_t i = 0; i < ans.size(); ++i) {
            oss << ans[i];
            if (i < ans.size() - 1) {
                oss << " ";
            }
        }

        return oss.str();
    }
};

//2] OPTIMAL SOLUTION
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_set>
#include <sstream>

using namespace std;

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> roots;
        vector<string> words;
        vector<string> ans;

        for (const auto& root : dictionary) {
            roots.insert(root);
        }

        stringstream ss(sentence);
        string word;
        while (ss >> word) {
            words.push_back(word);
        }

        for (const auto& word : words) {
            string replacedWord = word; // Start with the original word
            for (int i = 1; i <= word.size(); i++) {
                string findRoot = word.substr(0, i);
                if (roots.find(findRoot) != roots.end()) {
                    replacedWord = findRoot; // Update to the found root
                    break; // Stop searching once we find the shortest root
                }
            }
            ans.push_back(replacedWord); // Add the replaced word (root or original)
        }

        ostringstream oss;
        for (size_t i = 0; i < ans.size(); ++i) {
            oss << ans[i];
            if (i < ans.size() - 1) {
                oss << " ";
            }
        }

        return oss.str();
    }
};

int main() {
    Solution solution;
    vector<string> dictionary = {"cat", "bat", "rat"};
    string sentence = "the cattle was rattled by the battery";
    string result = solution.replaceWords(dictionary, sentence);
    cout << result << endl; // Output: "the cat was rat by the bat"
    return 0;
}