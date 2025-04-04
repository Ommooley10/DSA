#include <bits/stdc++.h>
using namespace std;

//question is same as "assign cookies" of leetcode, even the code is almost same
//leetcode 2410

class Solution {
    public:
        int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
            int m = players.size();
            int n = trainers.size();
    
            sort(players.begin(), players.end());
            sort(trainers.begin(), trainers.end());
            
            int left = 0;
            int right = 0; 
            int count = 0; 
        
            while (left < m && right < n) {
                if (players[left] <= trainers[right]) {
                    count++; 
                    left++; 
                }
                
                right++;
            }
            return count; 
        }
    };