#include <bits/stdc++.h>
using namespace std;

/*Given string num representing a non-negative integer num, and an integer k, 
return the smallest possible integer after removing k digits from num.

Example 1:
Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.

Example 2:
Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.

Example 3:
Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.*/


//NOTE:
/*Build intuition from the logic that if we are given some digits for eg 1,4,2,3 and 
we have to form the smallest number using these digits, 
so we would naturally arrange these digits in increasing order right?? 
i.e "1234" so thats the case here to, we need to maintain an increasing order in the stack/string,
 is a certain digit disobeys it, pop it from the stack and decrease the k (mark as deleted) OR 
 if the digit is not disturbing the order (increasing order) then push in onto the stack.*/

/*At last retrive the elements from the stack and check for an edge case which is: 
What if the given number has the digits already in the sorted order? 
eg "112"& k="1" here there would be no popping of any element from the stack and we would get the element as it is, 
but we still need to remove k=1 element from stack, 
so in this case delete the digits present at the end of the number i.e in this case delete "2". 
And repeat this till k != 0 or k > 0.
*/

class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.size() == k) return "0";
        if(num.size() == 1){
            if(k==0) return num;
            else return "0";
        }  
        string ans;
        stack<char> stk;

        stk.push(num[0]);

        for(int i=1;i<num.size();i++){
            while(!stk.empty() && stk.top() > num[i] && k>0){
                stk.pop();
                k--;
            }
            stk.push(num[i]);
        }
        while(!stk.empty() && k > 0){  //what if the string is already sorted i.e num = "112" and k="1" so in this case we need to remove the elements from back i.e top of the stack.
            stk.pop();
            k--;
        }

        while(!stk.empty()){
            ans.push_back(stk.top());
            stk.pop();
        }
        reverse(ans.begin(),ans.end());

        while(ans[0] == '0') ans.erase(0,1); //remove the leading zeroes (if they exist), eg. "0200" becomes "200"

        if(ans.size() == 0) return "0";
        return ans;
    }
};