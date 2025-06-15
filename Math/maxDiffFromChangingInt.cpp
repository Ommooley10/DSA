#include <bits/stdc++.h>
using namespace std;

/*THIS QUESTION IS SIMILAR TO LEETCODE 2566 "MAXIMUM DIFFERENCE BY REMAPPING A DIGIT", ONLY CHANGE IS THAT FOR
THE MINIMUM INTEGER LEADING ZEROS ARE NOT ALLOWED [eg. "000" is not a valid minimum integer in this ques]
(IT WAS ALLOWED IN THE LEETCODE 2566 PROBLEM)*/


/*You are given an integer num. You will apply the following steps to num two separate times:
Pick a digit x (0 <= x <= 9).
Pick another digit y (0 <= y <= 9). Note y can be equal to x.
Replace all the occurrences of x in the decimal representation of num by y.
Let a and b be the two results from applying the operation to num independently.
Return the max difference between a and b.

Note that neither a nor b may have any leading zeros, and must not be 0. //VERY VERY IMPORTANT

Example 1:
Input: num = 555
Output: 888
Explanation: The first time pick x = 5 and y = 9 and store the new integer in a.
The second time pick x = 5 and y = 1 and store the new integer in b.
We have now a = 999 and b = 111 and max difference = 888

Example 2:
Input: num = 9
Output: 8
Explanation: The first time pick x = 9 and y = 9 and store the new integer in a.
The second time pick x = 9 and y = 1 and store the new integer in b.
We have now a = 9 and b = 1 and max difference = 8*/

class Solution {
public:
    int maxDiff(int num) {
        if (num < 10) {
            return 8;
        }
        string number = to_string(num);
        string max = number;
        string min = number;
        int maxNum;
        int minNum;
        char maxDigit;
        for (int i = 0; i < number.size(); i++) {
            if (number[i] != '9') {
                maxDigit = number[i];
                break;
            }
        }

        for (int i = 0; i < max.size(); i++) {
            if (max[i] == maxDigit) {
                max[i] = '9';
            }
        }
        maxNum = stoi(max);

        char minDigit;
        if (min[0] != '1') {
            minDigit = number[0];
            for (int i = 0; i < min.size(); i++) {
                if (min[i] == minDigit) {
                    min[i] = '1';
                }
            }
        } else {
            for (int i = 0; i < min.size(); i++) {
                if (min[i] != '1' && min[i] != '0') {  //ONLY THIS PART IS CHANGED IN COMPARISON TO LEETCODE 2566, REST OF CODE IS SAME FOR BOTH QUES
                    minDigit = min[i];
                    break;
                }
            }
            for (int i = 0; i < min.size(); i++) {
                if (min[i] == minDigit)
                    min[i] = '0';
            }
        }
        minNum = stoi(min);

        return maxNum - minNum;
    }
};