#include <bits/stdc++.h>
using namespace std;

/*On a social network consisting of m users and some friendships between users, two users can communicate with each other if they know a common language.

You are given an integer n, an array languages, and an array friendships where:

There are n languages numbered 1 through n,
languages[i] is the set of languages the i​​​​​​th​​​​ user knows, and
friendships[i] = [u​​​​​​i​​​, v​​​​​​i] denotes a friendship between the users u​​​​​​​​​​​i​​​​​ and vi.
You can choose one language and teach it to some users so that all friends can communicate with each other. Return the minimum number of users you need to teach.

Note that friendships are not transitive, meaning if x is a friend of y and y is a friend of z, this doesn't guarantee that x is a friend of z.
 

Example 1:

Input: n = 2, languages = [[1],[2],[1,2]], friendships = [[1,2],[1,3],[2,3]]
Output: 1
Explanation: You can either teach user 1 the second language or user 2 the first language.
Example 2:

Input: n = 3, languages = [[2],[1,3],[1,2],[3]], friendships = [[1,4],[1,2],[3,4],[2,3]]
Output: 2
Explanation: Teach the third language to users 1 and 3, yielding two users to teach.*/


/*INTUITION*/
/*
1. First find all the users who are unable to talk to their friends from the friendships pair and store the users in a set to avoid duplication.

2. Find the most talked language among the sad users in the set, use a map for this to store the frequency of the languages and then iterate through the map to find the most talked language

3. subtract the total sad users (i.e the size of the set) with the most talked langauage found above
i.e sadUsers.size() - mostTalkedLanguage
*/

class Solution {
public:

    //check if the two friends are happy i.e they share a common language       between them or not, here the vectors v1 and v2 refer to the language vectors of the two friends and this functions checks if they are happy or not, otherwise they are sad and thus the 2 users will be added to thr sadUsers set
    bool areHappy(vector<int>& v1, vector<int>& v2) {
        unordered_set<int> elements(v1.begin(), v1.end());

        for (int x : v2) {
            if (elements.count(x)) {
                return true;
            }
        }
        return false;
    }

    int minimumTeachings(int n, vector<vector<int>>& languages,
                         vector<vector<int>>& friendships) {
        int mostTalkedLanguage = 0;

        // finding sad users (users who are not able to talk with each others)
        // here we need only single entry for user who is sad, therefore set
        // used
        unordered_set<int> sadUsers;
        for (int i = 0; i < friendships.size(); i++) {
            auto arr = friendships[i];
            if (!areHappy(languages[arr[0] - 1], languages[arr[1] - 1])) {
                for (auto it : arr) {
                    sadUsers.insert(it);
                }
            }
        }
        if(sadUsers.size() == 0) return 0;
        
        // finding the most talked language among the sad users
        unordered_map<int, int> mpp;
        for (int user : sadUsers) {
            for (int lang : languages[user - 1]) {
                mpp[lang]++;
            }
        }

        // finding the most talked language among the sad users
        for (auto it : mpp) {
            mostTalkedLanguage = max(mostTalkedLanguage, it.second);
        }

        // minimum number of users to teach
        int result = sadUsers.size() - mostTalkedLanguage;
        return result;
    }
};