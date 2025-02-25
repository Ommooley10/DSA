//OPTIMAL SOLUTION CAN BE FOUND USING THE KMP ALGORITHM

//BRUTE FORCE:
#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        set<string> ans;
        int i = 0;
        while(i < words.size()) {
            string target = words[i];
            for(int j = 0; j < words.size(); j++) {
                if(i != j && words[j].find(target) != string::npos) { //STRING NPOS DENOTES THE END OF THE STRING
                    ans.insert(target);
                }
            }
            i = i + 1;
        }
        return vector<string>(ans.begin(), ans.end());
    }
};

int main() {
    Solution solution;
    vector<string> words = {"mass", "as", "hero", "superhero"};
    vector<string> result = solution.stringMatching(words);
    for (const auto& str : result) {
        cout << str << endl;
    } //expected ans is [as, hero]
    return 0;
}