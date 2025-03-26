#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        // Ensure s1 is the longer sentence
        if (s1.length() < s2.length()) {
            swap(s1, s2);
        }

        vector<string> vec1, vec2;
        stringstream ss1(s1), ss2(s2);
        string token;

        // Split s1 into words
        while (ss1 >> token) {
            vec1.push_back(token);
        }

        // Split s2 into words
        while (ss2 >> token) {
            vec2.push_back(token);
        }

        // Initialize two pointers for the beginning and end of each sentence
        int i = 0, j = vec1.size() - 1; // Pointers for vec1 (s1)
        int k = 0, l = vec2.size() - 1; // Pointers for vec2 (s2)

        // Compare the words from the start (prefix comparison)
        while (k < vec2.size() && i < vec1.size() && vec2[k] == vec1[i]) {
            k++;
            i++;
        }

        // Compare the words from the end (suffix comparison)
        while (l >= k && vec2[l] == vec1[j]) {
            j--;
            l--;
        }

        // If all words in vec2 have been compared, the sentences are similar
        return l < k;
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    string s1 = "My name is John Doe";
    string s2 = "My name";
    cout << (sol.areSentencesSimilar(s1, s2) ? "True" : "False") << endl;

    return 0;
}


//using deque INSERTIONS AND DELETIONS FROM FRONT AND BACK ARE EASIER
/*class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        if(s1.length() < s2.length()) {
            swap(s1, s2);
        }

        deque<string> deq1, deq2;
        stringstream ss1(s1);
        string token;
        while(ss1 >> token) {
            deq1.push_back(token);
        }

        stringstream ss2(s2);
        while(ss2 >> token) {
            deq2.push_back(token);
        }

        while(!deq1.empty() && !deq2.empty() && deq1.front() == deq2.front()) {
            deq1.pop_front();
            deq2.pop_front();
        }

        while(!deq1.empty() && !deq2.empty() && deq1.back() == deq2.back()) {
            deq1.pop_back();
            deq2.pop_back();
        }
        
        return deq2.empty();

    }
};*/