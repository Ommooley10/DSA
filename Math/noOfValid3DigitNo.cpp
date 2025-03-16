#include <bits/stdc++.h>
using namespace std;

/*QUESTION:
You are given an array of digits called digits. 
Your task is to determine the number of distinct three-digit even numbers that can be formed using these digits.
Note: Each copy of a digit can only be used once per number, and there may not be leading zeros.

Example 1:
Input: digits = [1,2,3,4]
Output: 12
Explanation: The 12 distinct 3-digit even numbers that can be formed are 124, 132, 134, 142, 214, 234, 312, 314, 324, 342, 412, and 432. Note that 222 cannot be formed because there is only 1 copy of the digit 2.

Example 2:
Input: digits = [0,2,2]
Output: 2
Explanation: The only 3-digit even numbers that can be formed are 202 and 220. Note that the digit 2 can be used twice because it appears twice in the array.

Example 3:
Input: digits = [6,6,6]
Output: 1
Explanation: Only 666 can be formed.

Example 4:
Input: digits = [1,3,5]
Output: 0
Explanation: No even 3-digit numbers can be formed.
*/

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