#include <bits/stdc++.h>
using namespace std;

//NOTE: The example no 3 is sufficient to build the logic for the code.

/*You start with an initial power of power, an initial score of 0, 
and a bag of tokens given as an integer array tokens, where each tokens[i] denotes the value of tokeni.

Your goal is to maximize the total score by strategically playing these tokens. 
In one move, you can play an unplayed token in one of the two ways (but not both for the same token):

**Face-up: If your current power is at least tokens[i], you may play tokeni, losing tokens[i] power and gaining 1 score.
**Face-down: If your current score is at least 1, you may play tokeni, gaining tokens[i] power and losing 1 score.
Return the maximum possible score you can achieve after playing any number of tokens.

Example 1:
Input: tokens = [100], power = 50
Output: 0
Explanation: 
Since your score is 0 initially, you cannot play the token face-down. You also cannot play it face-up since your power (50) is less than tokens[0] (100).

Example 2:
Input: tokens = [200,100], power = 150
Output: 1
Explanation: 
Play token1 (100) face-up, reducing your power to 50 and increasing your score to 1.
There is no need to play token0, since you cannot play it face-up to add to your score. The maximum score achievable is 1.

Example 3:
Input: tokens = [100,200,300,400], power = 200
Output: 2
Explanation: 
Play the tokens in this order to get a score of 2:
Play token0 (100) face-up, reducing power to 100 and increasing score to 1.
Play token3 (400) face-down, increasing power to 500 and reducing score to 0.
Play token1 (200) face-up, reducing power to 300 and increasing score to 1.
Play token2 (300) face-up, reducing power to 0 and increasing score to 2.
The maximum score achievable is 2.*/

/*INTUITION:
**Sorting -> We need to know the smallest and largest value in the tokens vector.
**Greedy -> When the current power is too low compared to token[i]'s power, 
we need to use the power with the highest value in the tokens vector to refill the current power
**Two pointer -> Take two variables (lets say i and j) where initially i = 0 and j = n - 1.
Use i for increasing the score by using up the tokens[i] power, 
use j for increasing the power whenever the current power is smaller than tokens[i].
*/
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int maxScore = 0;
        int score = 0;
        if(tokens.size() == 0) return maxScore;

        sort(tokens.begin(),tokens.end());

        int i = 0;
        int j = tokens.size()-1;

        while(i <= j){
            if(score == 0 && power < tokens[i]) return maxScore;
            else if(score > 0 && power < tokens[i]){
                power += tokens[j];
                score--;
                j--;
            }else if(power >= tokens[i]){
                power -= tokens[i];
                score++;
                i++;
            }
            maxScore = max(score, maxScore);
        }
        return maxScore;
    }
};