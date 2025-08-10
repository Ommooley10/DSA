#include <bits/stdc++.h>
using namespace std;

/*You are given an integer n. We reorder the digits in any order (including the original order) such that the leading digit is not zero.
Return true if and only if we can do this so that the resulting number is a power of two.

Example 1:
Input: n = 1
Output: true

Example 2:
Input: n = 10
Output: false*/

class Solution {
public:
    string getSortedOrder(int n){
        string s = to_string(n);
        sort(s.begin(), s.end());

        return s;
    }

    bool reorderedPowerOf2(int n) {
        string s = getSortedOrder(n);

        for(int power = 0;power <= 29; power++){
            int num = 1 << power;  //pow(2, power) can also be used
            if(s == getSortedOrder(num)){
                return true;
            }
        }
        return false;
    }
};