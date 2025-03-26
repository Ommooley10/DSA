//Sliding window problem
#include <bits/stdc++.h>
using namespace std;
int longestSubarrayWithSumK(vector<int>a,long long k){
    int left=0,right=0;
    int maxLength=0;
    int sum=a[0];
    int n=a.size();
    
    while(right<n){
        while(left<=right && sum>k){
            sum=sum-a[left];
            left++;
        }
        if(sum==k){
            maxLength=max(maxLength, right - left + 1);
        }
        right++;
        if(right<n){
            sum=sum+a[right];
        }
    }
    return maxLength;
}

int main() {
    vector<int> nums={1,2,3,1,1,1,1};
    int result = longestSubarrayWithSumK(nums , 3);
    cout << result;
    return 0;
}