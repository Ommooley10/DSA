#include <bits/stdc++.h>
using namespace std;

/*There are n cars on an infinitely long road. 
The cars are numbered from 0 to n - 1 from left to right and each car is present at a unique point.

You are given a 0-indexed string directions of length n. directions[i] can be either 
'L', 'R', or 'S' denoting whether the ith car is moving towards the left, towards the right, 
or staying at its current point respectively. Each moving car has the same speed.

The number of collisions can be calculated as follows:

When two cars moving in opposite directions collide with each other, the number of collisions increases by 2.
When a moving car collides with a stationary car, the number of collisions increases by 1.
After a collision, the cars involved can no longer move and will stay at the point where they collided. 
Other than that, cars cannot change their state or direction of motion.

Return the total number of collisions that will happen on the road.

Example 1:
Input: directions = "RLRSLL"
Output: 5
Explanation:
The collisions that will happen on the road are:
- Cars 0 and 1 will collide with each other. Since they are moving in opposite directions, the number of collisions becomes 0 + 2 = 2.
- Cars 2 and 3 will collide with each other. Since car 3 is stationary, the number of collisions becomes 2 + 1 = 3.
- Cars 3 and 4 will collide with each other. Since car 3 is stationary, the number of collisions becomes 3 + 1 = 4.
- Cars 4 and 5 will collide with each other. After car 4 collides with car 3, it will stay at the point of collision and get hit by car 5. The number of collisions becomes 4 + 1 = 5.
Thus, the total number of collisions that will happen on the road is 5. 

Example 2:
Input: directions = "LLRR"
Output: 0
Explanation:
No cars will collide with each other. Thus, the total number of collisions that will happen on the road is 0.*/


/*NOTE:*/
/*Here the one edge case we need to keep in mind id regarding the leading R's
for eg int the test case directions = "RRLL", we would normally get the no of collisions as 2 i.e (the collision of R & L at index 1 & 2 and the last L at index 3)
But notice that there is a leading R at index 0 which will also collide after the collision of R and L (at index 1 & 2), so we need to keep a track of the leading R's here
So, the correct ans is 3
*/

class Solution {
public:
    int countCollisions(string directions) {
        int noOfCollisions = 0;
        if (directions.size() == 1) return noOfCollisions;

        stack<char> stk;
        int numOfR = 0;
        if(directions[0] == 'R') numOfR = 1;
        stk.push(directions[0]);

        for (int i = 1; i < directions.size(); i++) {
            char direction = directions[i];
            if(direction == 'R') numOfR++;
            
            if (stk.top() == 'R' && direction == 'L') {
                stk.pop();
                stk.push('S');
                noOfCollisions += 2;

                int leadingR = numOfR - 1; //keep track of the leading R when collision occurs
                while(leadingR != 0) {
                    noOfCollisions++;
                    leadingR--;
                }
                numOfR = 0;
            } else if (stk.top() == 'R' && direction == 'S') {
                stk.pop();
                stk.push('S');
                noOfCollisions += 1;

                int leadingR = numOfR - 1; //keep track of the leading R when collision occurs
                while(leadingR != 0) {
                    noOfCollisions++;
                    leadingR--;
                }
                numOfR = 0;
            } else if (stk.top() == 'S' && direction == 'L') {
                noOfCollisions += 1;
            } else {
                stk.push(direction);
            }
        }
        return noOfCollisions;
    }
};