// A CLASSIC PROBLEM OF BACKTRACKING: KHANDANI TEMPLATE
/* 1]DO
   2]EXPLORE
   3]UNDO
*/
// Given two integers n and k, return all possible combinations of k numbers out of the range [1, n].


#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> result; //array of arrays vaparla ahe to store the result

    void solve(int start, int n, int k, vector<int>& temp) {
        if (k == 0) {   // zar value sagle sample tar return karaycha aahe
            result.push_back(temp); // current selected element la temp array madhe store karaycha
            return;
        }
        if (start > n) return;

        temp.push_back(start); // pahile current element la include karaycha
        solve(start + 1, n, k - 1, temp); //mag tya current element la explore karaycha
        temp.pop_back();    // current element na gheta, tyala aadhi pop karaycha, karan apan dusra element explore krnar ahe
        solve(start + 1, n, k, temp); //dusra element pakdyacha ani mag tyala explore karaycha, 
        //notice how the k is altered in the above code
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        solve(1, n, k, temp);
        return result;
    }
};

#include <iostream>

int main() {
    Solution sol;
    int n = 4, k = 2;
    vector<vector<int>> combinations = sol.combine(n, k);

    for (const auto& combination : combinations) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}