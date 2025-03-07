#include <bits/stdc++.h>
using namespace std;

/*QUESTION*/
/*Input: left = 10, right = 19
Output: [11,13]
Explanation: The prime numbers between 10 and 19 are 11, 13, 17, and 19.
The closest gap between any pair is 2, which can be achieved by [11,13] or [17,19].
Since 11 is smaller than 17, we return the first pair.*/


//USING SEIVE OF ERATOSTHENES ALGO
class Solution {
    public:
        vector<int> closestPrimes(int left, int right) {
            vector<int> result = {-1,-1};

            //SIEVE OF ERATOSTHENES
           vector<bool> isPrime(right+1,true);
           isPrime[0] = false;
           isPrime[1] = false;
    
            for(int i = 2;i<=right;i++){
                if(isPrime[i] == true){
                    for(int j=2; j*i <= right;j++){
                        isPrime[i*j] = false;
                    }
                }
            }
    
            // EXTRACTING THE PRIME NUMBERS FROM THE isPrime VECTOR (calculated above) AND INSERTING THEM INTO ans VECTOR
            vector<int> ans;
            for(int i = left; i<=right; i++){
                if(isPrime[i] == true) ans.push_back(i);
            }
            
            //calculations for the result vector (insertion of the two elements with the minimum difference)
            if(ans.size() == 1) return result;
    
            int minDiff = INT_MAX;
            for(int i=1; i<ans.size();i++){
                int diff = ans[i] - ans[i-1];
                if(diff < minDiff){
                    result[0] = ans[i-1];
                    result[1] = ans[i];
                    minDiff = diff;
                }
            }
            return result;
        }
    };
