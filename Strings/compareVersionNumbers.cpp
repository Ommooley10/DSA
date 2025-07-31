#include <bits/stdc++.h>
using namespace std;

/*Given two version strings, version1 and version2, compare them. 
A version string consists of revisions separated by dots '.'. 
The value of the revision is its integer conversion ignoring leading zeros.

To compare version strings, compare their revision values in left-to-right order. 
If one of the version strings has fewer revisions, treat the missing revision values as 0.

Return the following:
If version1 < version2, return -1.
If version1 > version2, return 1.
Otherwise, return 0.
 
Example 1:
Input: version1 = "1.2", version2 = "1.10"
Output: -
Explanation:
version1's second revision is "2" and version2's second revision is "10": 2 < 10, so version1 < version2.

Example 2:
Input: version1 = "1.01", version2 = "1.001"
Output: 0
Explanation:
Ignoring leading zeroes, both "01" and "001" represent the same integer "1".

Example 3:
Input: version1 = "1.0", version2 = "1.0.0.0
Output: 0
Explanation:
version1 has less revisions, which means every missing revision are treated as "0".*/

/*INTUITION : do as directed*/
class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1;
        vector<int> v2;

        // 1. INSERT version1 INTO v1 AS NUMBERS
        string s1;
        for(auto i: version1){
            if(i == '.'){
                int num = stoi(s1);
                v1.push_back(num);
                s1.clear();
            }else s1.push_back(i);
        }
        //add the last one if remaining
        if (!s1.empty()) {          
            v1.push_back(stoi(s1));
        }

        //2. INSERT version2 INTO v2 AS NUMBERS 
        string s2;
        for(auto i: version2){
            if(i == '.'){
                int num = stoi(s2);
                v2.push_back(num);
                s2.clear();
            }else s2.push_back(i);
        }
        //add the last one if remaining
        if (!s2.empty()) {           
            v2.push_back(stoi(s2));
        }


        //3. MAKE THE SIZES OF BOTH THE VECTORS SAME BY ADDING 0 TO THE VECTOR WITH SMALLER SIZE
        if(v1.size() > v2.size()){
            while(v2.size() != v1.size()){
                v2.push_back(0);
            }
        }else{
            while(v1.size() != v2.size()){
                v1.push_back(0);
            }
        }

        //4. CHECK THE CONDITION GIVEN IN QUESTION
        for(int i = 0; i < v1.size(); i++){
            if(v1[i] < v2[i]) return -1;
            if(v1[i] > v2[i]) return 1;
        }
        return 0;
    }
};