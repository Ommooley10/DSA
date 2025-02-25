//EFFICIENT USE OF MAP 
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> ans;
        map<int, int> mpp;
        int n = A.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            mpp[A[i]]++;
            if (mpp[A[i]] == 2) {
                count++;
            }

            mpp[B[i]]++;
            if (mpp[B[i]] == 2) {
                count++;
            }

            ans.push_back(count);
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> A = {1, 3, 2, 4};
    vector<int> B = {3, 1, 2, 4};

    vector<int> result = solution.findThePrefixCommonArray(A, B);

    cout << "Prefix Common Array: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}