#include <bits/stdc++.h>
using namespace std;

int noOfValid3DigitNo(vector<int> &digits){  //FIRST CONTEST PROBLEM
    int n = digits.size();
    int count = 0;
    
    for(int i=0;i<n;i++){
        string num;
        for(int j=0;j<n;j++){
            if(i==j) continue;
            for(int k=0;k<n;k++){
                if(i!=k && j!=k){
                    int number = digits[i]*100 + digits[j]*10 + digits[k];
                    if(number >= 100 && number%2 == 0) count++;
                }
            }
        }
    }
    return count;
}


int main() {
    vector<int> arr = {1,2,3,4};
    
    int ans = noOfValid3DigitNo(arr);
    cout << ans << endl;
    
    return 0;
}