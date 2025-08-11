#include <bits/stdc++.h>
using namespace std;

/*Given a positive integer n, there exists a 0-indexed array called powers, 
composed of the minimum number of powers of 2 that sum to n. The array is sorted in non-decreasing order, 
and there is only one way to form the array.
You are also given a 0-indexed 2D integer array queries, 
where queries[i] = [lefti, righti]. Each queries[i] represents a query where you have to 
find the product of all powers[j] with lefti <= j <= righti.

Return an array answers, equal in length to queries, where answers[i] is the answer to the ith query. 
Since the answer to the ith query may be too large, each answers[i] should be returned modulo 109 + 7.

Example 1:
Input: n = 15, queries = [[0,1],[2,2],[0,3]]
Output: [2,4,64]
Explanation:
For n = 15, powers = [1,2,4,8]. It can be shown that powers cannot be a smaller size.
Answer to 1st query: powers[0] * powers[1] = 1 * 2 = 2.
Answer to 2nd query: powers[2] = 4.
Answer to 3rd query: powers[0] * powers[1] * powers[2] * powers[3] = 1 * 2 * 4 * 8 = 64.
Each answer modulo 109 + 7 yields the same answer, so [2,4,64] is returned.

Example 2:
Input: n = 2, queries = [[0,0]]
Output: [2]
Explanation:
For n = 2, powers = [2].
The answer to the only query is powers[0] = 2. The answer modulo 109 + 7 is the same, so [2] is returned.*/

/**INTUITION**
the problem is pretty straightforward, we have to first fin the powers array and then we need to use the queries
array to find the product till the indexes given in each vector inside the queries.

So, if you look at the decription carefully, in order to find the powers array, all we have to do is to is to find
the binary representation of the number "n", like for eg n = 15, so fifteen in binary will be 1111 (i.e 2^0, 
2^1, 2^2,2^3, basically 2,5,8,1 or 8,4,2,1), so we need only the numbers which have the bit set to 1 to push_back
onto powers vector. 

Here for eg we took 4 bit integer but for coding, we need to take into account the 32 bit integer (15 in 32 bit is
0000000000000000000000000000111, basically we need to add leading zeroes) 

*/

class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;
        vector<int> answers;
        int M = 1e9 + 7;

        //STEP 1: To generate the power array
        for(int i=0;i<32;i++){
            if((n & (1 << i)) != 0){ //this will check if the bit at the ith index set to 1, if its, then push onto powers array
                powers.push_back(pow(2,i));
            }
        }

        for(auto query: queries){
            int i = query[0];
            int j = query[1];
            long long product = 1;
            for(int k = i;k<=j;k++){
                product = (product * powers[k]) % M;
            }
            answers.push_back(product);
        }
        return answers;
    }
};