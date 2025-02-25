//1] BRUTE FORCE SOLUTION
/*class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int res;
        int maxRes=0;
        for (int i = 0; i < n; i++) {
            for (int j = n - 1; j >= i + 1; j--) {
                res=prices[j]-prices[i];
                maxRes=max(res,maxRes);
            }
        }
        return maxRes;
    }
};*/

//2] OPTIMAL SOLUTION   //Track the minimum element on the array
/*class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int mini=prices[0];
        int profit=0;
        int cost;
        for(int i=0;i<n;i++){
            cost=prices[i]-mini;
            profit=max(profit,cost);
            mini=min(mini,prices[i]);
        }
        return profit;
    }
};*/