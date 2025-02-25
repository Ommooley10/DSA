#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        long long dividePlayers(vector<int>& skill) {
            int n = skill.size();
            int noOfGrp = n / 2;
            long long sum = 0;
            long long reqSum;
            long long result = 0;
    
            for (int i = 0; i < n; i++) {
                sum = sum + skill[i];
            }
    
            if (sum % noOfGrp != 0) {
                return -1;
            } else {
                if (n == 2) {
                    result = skill[0] * skill[1];
                } else {
                    sort(skill.begin(), skill.end());
                    reqSum = sum / noOfGrp;
    
                    int left = 0;
                    int right = n - 1;
    
                    while (left < right) {
                        if (skill[left] + skill[right] != reqSum) {
                            return -1;
                        }
    
                        int pairMul = skill[left] * skill[right];
                        result = result + pairMul;
                        left++;
                        right--;
                    }
                }
            }
            return result;
        }
    };

    int main() {
        Solution sol;
        vector<int> skill = {1, 2, 3, 4}; // Example input
        long long result = sol.dividePlayers(skill);
        cout << "Result: " << result << endl;
        return 0;
    }