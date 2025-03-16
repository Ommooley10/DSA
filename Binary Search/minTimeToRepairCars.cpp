#include <bits/stdc++.h>
using namespace std;
/* HANDS DOWN THE BEST QUESTION ON BINARY SEARCH ENCOUNTERED TILL NOW 

QUESTION:
You are given an integer array ranks representing the ranks of some mechanics. 
ranksi is the rank of the ith mechanic. 
A mechanic with a rank r can repair n cars in r * n2 minutes.
You are also given an integer cars representing the total number of cars waiting in the garage to be repaired.
Return the minimum time taken to repair all the cars.

Note: All the mechanics can repair the cars simultaneously. //IMPORTANT LINE 

Example 1:
Input: ranks = [4,2,3,1], cars = 10
Output: 16
Explanation: 
- The first mechanic will repair two cars. The time required is 4 * 2 * 2 = 16 minutes.
- The second mechanic will repair two cars. The time required is 2 * 2 * 2 = 8 minutes.
- The third mechanic will repair two cars. The time required is 3 * 2 * 2 = 12 minutes.
- The fourth mechanic will repair four cars. The time required is 1 * 4 * 4 = 16 minutes.
It can be proved that the cars cannot be repaired in less than 16 minutes.​​​​​

VERY VERY IMPORTANT:
NOTE: here the cars alloted to mechanic of each rank were [2,2,2,4], i if you notice there are many such combinations which can be considered but we have to select the combination requiring the minimum time.
This form the base of the problem, we have to find the minimum time of the given range of time, so whats the solution? BINARYYYYYY SEARCHHHHH

Example 2:
Input: ranks = [5,1,8], cars = 6
Output: 16
Explanation: 
- The first mechanic will repair one car. The time required is 5 * 1 * 1 = 5 minutes.
- The second mechanic will repair four cars. The time required is 1 * 4 * 4 = 16 minutes.
- The third mechanic will repair one car. The time required is 8 * 1 * 1 = 8 minutes.
It can be proved that the cars cannot be repaired in less than 16 minutes.​​​​​
*/

class Solution {
    public:
        long long carsProduced(vector<int> &ranks, long long time){ //method to compute the total number of cars which can be produced in a given time by all the mechanics based on their ranks
            long long totalCars = 0;
            for(auto rank: ranks){
                totalCars += sqrt(time/rank); //formula is slightly changed, whenever a question contains formula, looks for any modifications of transpose in that formula
            }
            return totalCars;
        }
    
        long long repairCars(vector<int>& ranks, int cars) {
            long long ans;
            long long max_rank  = *max_element(ranks.begin(),ranks.end());
    
            //binary search
            long long low = 1; //least time that is possible
            long long high = max_rank*cars*cars; //max time that is possible
    
            while(low <= high){
                long long mid = low + (high-low)/2; //time to be tested for validation
                long long totalCarsProduced = carsProduced(ranks, mid);
                if(totalCarsProduced < cars){ //increase the time if total cars produced is less than the required cars in that time
                    low = mid + 1;
                }else if(totalCarsProduced >= cars){ //decrease the time if total cars produced is more than the required cars in that time, and store the result in variable if exact number of total no of cars produced == cars;
                    ans = mid;
                    high = mid - 1;
                }
            }
            return ans;
        }
    };