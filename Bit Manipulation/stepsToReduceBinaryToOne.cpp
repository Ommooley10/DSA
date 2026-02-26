#include <bits/stdc++.h>
using namespace std;

/*Given the binary representation of an integer as a string s, 
return the number of steps to reduce it to 1 under the following rules:
If the current number is even, you have to divide it by 2.
If the current number is odd, you have to add 1 to it.
It is guaranteed that you can always reach one for all test cases.

Example 1:
Input: s = "1101"
Output: 6
Explanation: "1101" corressponds to number 13 in their decimal representation.
Step 1) 13 is odd, add 1 and obtain 14. 
Step 2) 14 is even, divide by 2 and obtain 7.
Step 3) 7 is odd, add 1 and obtain 8.
Step 4) 8 is even, divide by 2 and obtain 4.  
Step 5) 4 is even, divide by 2 and obtain 2. 
Step 6) 2 is even, divide by 2 and obtain 1.  

Example 2:
Input: s = "10"
Output: 1
Explanation: "10" corresponds to number 2 in their decimal representation.
Step 1) 2 is even, divide by 2 and obtain 1. 

Example 3:
Input: s = "1"
Output: 0*/

/*INTUITION:
BRUTE:
The brute force solution would be to convert the binary representation to decimal and then so the operations
as required. But this solution won't work for test cases where the decimal representation is very large (i.e 
the number is very large).

OPTIMAL:
The optimal solution is perform the operation on the given binary string itself
1. NOTE: If the last digit of binary is '1' then the number is odd, if it is '0' then number is even.

2. if the last digit is 1, (num is odd): 
        i. we have to add 1 to it, so do it, adding 1 basically means that starting from the last digit of 
        the string we have to convert every digit to 0 until the digit itself is 0.
        eg. 11011 -> 11100 (11'011' - > 11'100')

        ii. now while turning the digits to 0, if the string now contains all zeroes then add 1 at the start.
        eg. WRONG => 111 (decimal is 7) -> 000 (as there was no '0' in string, all ones are converted to 0)
            RIGHT => 111 (decimal is 7) -> 1000 (adding 1 to start, now the decimal is 8)

3. if the last digit is 0 (num is even):
        i. We have to divide by 2 (eg if num = 6 then dividing by 2 we get num = 3)
        ii. Just pop the last digit.
        110 (decimal is 6) -> removing the last char/digit -> 11 (decimal is 3)

4. Continue this untill the num value is 1 [i.e while(s != '1')]
*/

class Solution {
public:
    bool allZeroes(string s){ //checks if all characters in the string are 0 or not
        for(char ch: s){
            if(ch == '1') return false;
        }
        return true;
    }

    int numSteps(string s) {
        int n = s.size();
        int count = 0;

        while(s != "1"){
            if(s[n-1] == '1'){  
                for(int i = n-1; i >= 0; i--){
                    if(s[i] == '0') {
                        s[i] = '1';
                        break;
                    }
                    s[i] = '0';
                }
                if(allZeroes(s)) {
                    s.insert(s.begin(), '1');
                }
                count++;
            }else{
                s.pop_back();
                n = s.size();
                count++;
            }
        }
        return count;
    }
};