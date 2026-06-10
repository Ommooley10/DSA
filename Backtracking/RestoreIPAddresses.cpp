#include<bit/stdc++.h>
using namespace std;

/*A valid IP address consists of exactly four integers separated by single dots. Each integer is between 0 and 255 (inclusive) and cannot have leading zeros.

For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses, but "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses.
Given a string s containing only digits, return all possible valid IP addresses that can be formed by inserting dots into s. 
You are not allowed to reorder or remove any digits in s. You may return the valid IP addresses in any order.

Example 1:
Input: s = "25525511135"
Output: ["255.255.11.135","255.255.111.35"]

Example 2:
Input: s = "0000"
Output: ["0.0.0.0"]

Example 3:
Input: s = "101023"
Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]*/

class Solution {
public:
    unordered_set<string> visited;
    vector<string> address;

    //Function to check if the substring which will be added to the "curr" string contains leading zero and is valid or not (i.e greater than 255)
    bool isValid(string s){
        if(s[0] == '0') return false;
        int num = stoi(s);
        if(num > 255) return false;
        
        return true;
    }

    void solve(string s, int idx, int part, string curr){
        int n = s.size();

        //if idx == n and all 4 parts of the ip address are present then push that into the address vector
        if(part == 4 && idx == n){
            curr.pop_back(); //removing the '.' present at last
            address.push_back(curr);
            return;
        }

        if(idx+1 <= n){  //either take only one character (eg 2.)
            solve(s, idx+1, part+1, curr + s.substr(idx,1) + ".");
        }

        if(idx+2 <= n && isValid(s.substr(idx,2))){ //either take two characters (eg 25.)
            solve(s, idx+2, part+1, curr + s.substr(idx,2) + ".");
        }
        
        if(idx+3 <= n && isValid(s.substr(idx,3))){ //take three characters (eg 255.)
            solve(s, idx+3, part+1, curr + s.substr(idx,3) + ".");
        }
        
    }


    vector<string> restoreIpAddresses(string s) {
        if(s.size() > 12) return address;
        string curr;
        int idx = 0;
        int part = 0;
        solve(s, idx, part, curr);
        return address;
    }
};

