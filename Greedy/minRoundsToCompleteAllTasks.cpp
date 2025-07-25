#include <bits/stdc++.h>
using namespace std;

//NOTE: This question is the same as 2244: Minimum Rounds to Complete All Tasks.

/*You are given a 0-indexed integer array tasks, where tasks[i] represents the difficulty level of a task. 
In each round, you can complete either 2 or 3 tasks of the same difficulty level.
Return the minimum rounds required to complete all the tasks, or -1 if it is not possible to complete all the tasks.

Example 1:
Input: tasks = [2,2,3,3,2,4,4,4,4,4]
Output: 4
Explanation: To complete all the tasks, a possible plan is:
- In the first round, you complete 3 tasks of difficulty level 2. 
- In the second round, you complete 2 tasks of difficulty level 3. 
- In the third round, you complete 3 tasks of difficulty level 4. 
- In the fourth round, you complete 2 tasks of difficulty level 4.  
It can be shown that all the tasks cannot be completed in fewer than 4 rounds, so the answer is 4.

Example 2:
Input: tasks = [2,3,3]
Output: -1
Explanation: There is only 1 task of difficulty level 2, 
but in each round, you can only complete either 2 or 3 tasks of the same difficulty level. 
Hence, you cannot complete all the tasks, and the answer is -1.*/

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        vector<int> freq;
        unordered_map<int, int> mpp;
        int minRounds = 0;
        for (auto i : tasks) {
            mpp[i]++;
        }

        for (auto it : mpp) {
            if (it.second == 1)
                return -1;
            freq.push_back(it.second);
        }

        for (auto num : freq) {
            if (num == 2)
                minRounds += 1;
            else {
                if (num % 3 == 0)
                    minRounds += num / 3;
                else {
                    if (num % 3 == 1) {
                        num = num - 4;
                        minRounds += num / 3;
                        minRounds += 2;
                    } else {
                        num = num - 2;
                        minRounds += num / 3;
                        minRounds += 1;
                    }
                }
            }
        }
        return minRounds;
    }
};