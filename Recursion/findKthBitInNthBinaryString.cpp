#include <bits/stdc++.h>
using namespace std;

/*Given two positive integers n and k, the binary string Sn is formed as follows:

S1 = "0"
Si = Si - 1 + "1" + reverse(invert(Si - 1)) for i > 1
Where + denotes the concatenation operation, reverse(x) returns the reversed string x, 
and invert(x) inverts all the bits in x (0 changes to 1 and 1 changes to 0).

For example, the first four strings in the above sequence are:

S1 = "0"
S2 = "011"
S3 = "0111001"
S4 = "011100110110001"
Return the kth bit in Sn. It is guaranteed that k is valid for the given n.

Example 1:
Input: n = 3, k = 1
Output: "0"
Explanation: S3 is "0111001".
The 1st bit is "0".

Example 2:
Input: n = 4, k = 11
Output: "1"
Explanation: S4 is "011100110110001".
The 11th bit is "1".*/

/*INTUITION:
Classic recursion problem, do as directed
1. revinv function -> reverses the string and inverts the bits of the reversed string.
2. findSeq -> finds the nth sequence using recursion, follow a simple recursive approach
eg. if the n = 3, therefore to find the sequence that corresponds to S3 (or n=3) we initiate findSeq(3):
    findSeq(3)
        |
    findSeq(2) + '1' + revinv(seq)
        |
    findSeq(1) + '1' + revinv(seq)

    And the value of findSeq(1) is "0", so when we reach n = 1 we return the seq = "0" which is the intial
    sequence. And we update the "seq" string to the newly built string and pass that to the recursion
*/

class Solution {
public:
    string seq = "0";

    string revinv(string s){ //reverse and flip the bits logic
        reverse(s.begin(), s.end());
        for (char& c : s) {
        c = c ^ '0' ^ '1'; 
        }
        return s;
    }

    string findSeq(int n){ //main recursion logic
        if(n == 1){
            return seq;
        }

        string newString  = findSeq(n-1) + '1' + revinv(seq); //building the new string
        seq = newString;  //changing the initial seq string to the newString for that to be used for next recursions
        return newString; //return the newly built string 
    }

    char findKthBit(int n, int k) {
        string sequence = findSeq(n);

        return sequence[k-1];
    }
};