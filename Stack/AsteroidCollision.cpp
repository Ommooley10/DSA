#include <bits/stdc++.h>
using namespace std;

/*How to build intuition that this ques will use stack?
-> If you look closely, this problem is very much similar to "Valid parenthesis" problem where we have to remove 
the unbalanced ones by comparing with valid ones in the stack, if pop from stack untill a valid one is found, 
same logic here.
*/

/*NOTE: By finding sum of the two adjacent asteroids we can conclude which one will be destroyed and which one will carry on
1. if sum == 0 both will cancel out each other, pop from stk
2. if sum > 0 the larger one will live, no changes in stack
3. if sum < 0 the, pop from stack till the sum is positive or 0


IMPORTANT TIP TO SOLVE THE PROBLEM: 
In addition to the question description.
Assume the asteroids index is there position in space and negative signed asteroids are moving towards 0th index and positive asteroids are moving towards lasts index.
for example :-

[1,-2,10,-5]
here, 1 and -2 will collide and 10 and -5 will collide but -2 and 10 wont collide.
result -> [-2, 10]
[-4, 6]
here, -4 will move left and 6 to its right and will never collide
result -> [-4, 6]
but in
[4, -6] 4 and -6 will collide and stronger asteroids will remain, as 6 is stronger than 4 , so -6 will remain resulting [-6].

*/


/*We are given an array asteroids of integers representing asteroids in a row. 
The indices of the asteriod in the array represent their relative position in space.

For each asteroid, the absolute value represents its size,
and the sign represents its direction (positive meaning right, 
negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, 
the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

Example 1:
Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.

Example 2:
Input: asteroids = [8,-8]
Output: []
Explanation: The 8 and -8 collide exploding each other.

Example 3:
Input: asteroids = [10,2,-5]
Output: [10]
Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.*/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        
        for(int &a : asteroids) {
            
            while(!st.empty() && a < 0 && st.top() > 0) {
                int sum = a + st.top();
                if(sum < 0) {
                    st.pop();
                } else if(sum > 0) {
                    a = 0;
                    break;
                } else {
                    st.pop();
                    a = 0;
                }
            }
            
            if(a != 0)
                st.push(a);
            
        }
        
        int s = st.size();
        
        vector<int> result(s);
        int i = s-1;
        while(!st.empty()) {
            result[i] = st.top();
            st.pop();
            i--;
        }
        
        return result;
    }
};