#include <bits/stdc++.h>
using namespace std;

class Solution
{

/*ALGO: First mark the entire boolean array as true. then iterate over the array and mark the multiples of the element at the index in the array as false.
then again iterate over the array and insert the elements which are left true in the ans array.*/
public:
    vector<int> sieveOfEratosthenes(int N){  //WATCH CODESTORYWITHMIK VIDEO FOR UNDERSTANDING THE ALGORITHM
        vector<int> ans;
        
        vector<bool> isPrime(N+1,true);
        isPrime[0] = false;
        isPrime[1] = false;
        
        for(int i=2;i<=N;i++){
            if(isPrime[i] == true){
                for(int j=2;j*i<=N;j++){
                    isPrime[i*j] = false;
                }
            }
        }
        
        for(int i=0;i<=N;i++){
            if(isPrime[i] == true) ans.push_back(i);
        }
        
        return ans;
    }
};

int main() {
    Solution sol;
    int N;
    cout << "Enter the value of N: ";
    cin >> N;
    
    vector<int> primes = sol.sieveOfEratosthenes(N);
    
    cout << "Prime numbers up to " << N << " are: ";
    for(int prime : primes) {
        cout << prime << " ";
    }
    cout << endl;
    
    return 0;
}