#include <bits/stdc++.h>
using namespace std;

/*Given two positive integers n and x.
Return the number of ways n can be expressed as the sum of the xth power of unique positive integers, 
in other words, the number of sets of unique integers [n1, n2, ..., nk] where n = n1x + n2x + ... + nkx.
Since the result can be very large, return it modulo 109 + 7.

For example, if n = 160 and x = 3, one way to express n is n = 2^3 + 3^3 + 5^3.

Example 1:
Input: n = 10, x = 2
Output: 1
Explanation: We can express n as the following: n = 3^2 + 1^2 = 10.
It can be shown that it is the only way to express 10 as the sum of the 2nd power of unique integers.

Example 2:
Input: n = 4, x = 1
Output: 2
Explanation: We can express n in the following ways:
- n = 4^1 = 4.
- n = 3^1 + 1^1 = 4.*/


class Solution {
public:

    int M = 1e9+7;
    int t[301][301];

    int solve(int n, int num, int x) {
        if(n == 0)
            return 1;
        
        if(n < 0)
            return 0;
        
        int currPowerValue = pow(num, x);
        if(currPowerValue > n) {
            return 0;
        }

        if(t[n][num] != -1) {
            return t[n][num];
        }

        int take = solve(n-currPowerValue, num+1, x);
        int skip = solve(n, num+1, x);

        return t[n][num] = (take+skip)%M;
    }
    int numberOfWays(int n, int x) {
        memset(t, -1, sizeof(t));
        return solve(n, 1, x);
    }
};