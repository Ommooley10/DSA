#include <bits/stdc++.h>
using namespace std;

/*You are given a 0-indexed string blocks of length n, where blocks[i] is either 'W' or 'B', representing the color of the ith block. The characters 'W' and 'B' denote the colors white and black, respectively.
You are also given an integer k, which is the desired number of consecutive black blocks.
In one operation, you can recolor a white block such that it becomes a black block.
Return the minimum number of operations needed such that there is at least one occurrence of k consecutive black blocks.

Example 1:
Input: blocks = "WBBWWBBWBW", k = 7
Output: 3
Explanation:
One way to achieve 7 consecutive black blocks is to recolor the 0th, 3rd, and 4th blocks
so that blocks = "BBBBBBBWBW". 
It can be shown that there is no way to achieve 7 consecutive black blocks in less than 3 operations.
Therefore, we return 3.

Example 2:
Input: blocks = "WBWBBBW", k = 2
Output: 0
Explanation:
No changes need to be made, since 2 consecutive black blocks already exist.
Therefore, we return 0.*/

//1] BRUTE FORCE
class Solution {
    public:
        int noOfWhites(string blocks, int left, int right){
            int count = 0;
            for(int i=left;i<=right;i++){
                if(blocks[i] == 'W') count++;
            }
            return count;
        }
    
        int minimumRecolors(string blocks, int k) {
            int left = 0;
            int right = k-1;
            int minWhites = INT_MAX;
            while(right < blocks.size()){
                int whites = noOfWhites(blocks,left,right);
                minWhites = min(minWhites,whites);
                left++;
                right++;
            }
            return minWhites;
        }
    };

//2] Use sliding window with khandani template: (the word "consecutive" is used so this gives and ides of using sliding window)
class Solution {
    public:
        int minimumRecolors(string blocks, int k) {
            int left = 0;
            int right = 0;
            int minWhites = INT_MAX;
            int whites = 0;
            int count = 0;
    
            while(right < blocks.size()){
                if(blocks[right] == 'W') whites++;
                count = count+1;
                while(count > k){
                    if(blocks[left] == 'W') whites--;
                    count = count-1;
                    left = left + 1;
                }
                if(count == k) minWhites = min(minWhites,whites);
                right = right+1;
            }
            return minWhites;
        }
    };

