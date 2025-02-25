//GREAT EXAMPLE FOR UNDERSTANDING CUSTOM SORT (LAMBDA FUNCTION)
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std; 

class Solution {
public:
    string frequencySort(string s) {
        map<char,int>mpp;
        vector<pair<char,int>>freq;
        string ans;

        for(int i=0;i<s.size();i++){ //counting the frequency of each character and inserting it into the map
            mpp[s[i]]++; //eg (t,1),(r,1),(e,2)
        }

        for(auto it: mpp){  //inserting the key value pair obtained in the map into the vector
            freq.push_back(it);
        }

//sorting the vector accroding to the frequency of the characters i.e the second element of the pair, custom comparator function is used
        sort(freq.begin(),freq.end(),[](auto a ,auto b){
            return a.second > b.second;
        });

        for(auto it: freq){
            for(int i=0;i<it.second;i++){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    string s = "tree";
    cout << solution.frequencySort(s) << endl; //expected ans is eert
    return 0;
}
