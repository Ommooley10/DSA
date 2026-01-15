#include <bits/stdc++.h>
using namespace std;

/*You are given an absolute path for a Unix-style file system, which always begins with a slash '/'. 
Your task is to transform this absolute path into its simplified canonical path.

The rules of a Unix-style file system are as follows:

A single period '.' represents the current directory.
A double period '..' represents the previous/parent directory.
Multiple consecutive slashes such as '//' and '///' are treated as a single slash '/'.
Any sequence of periods that does not match the rules above should be treated as a valid directory or file name. 
For example, '...' and '....' are valid directory or file names.
The simplified canonical path should follow these rules:

The path must start with a single slash '/'.
Directories within the path must be separated by exactly one slash '/'.
The path must not end with a slash '/', unless it is the root directory.
The path must not have any single or double periods ('.' and '..') used to denote current or parent directories.
Return the simplified canonical path.

Example 1:
Input: path = "/home/"
Output: "/home"
Explanation:
The trailing slash should be removed.

Example 2:
Input: path = "/home//foo/"
Output: "/home/foo"
Explanation:
Multiple consecutive slashes are replaced by a single one.

Example 3:
Input: path = "/home/user/Documents/../Pictures"
Output: "/home/user/Pictures"
Explanation:
A double period ".." refers to the directory up a level (the parent directory).

Example 4:
Input: path = "/../"
Output: "/"
Explanation:
Going one level up from the root directory is not possible.

Example 5:
Input: path = "/.../a/../b/c/../d/./"
Output: "/.../b/d"
Explanation:
"..." is a valid name for a directory in this problem.*/

//TOKENIZATION USING DELIMETERS IS THE KEY TO SOLVE THIS PROBLEM (Stringstream use case)

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> tokens;

        stringstream ss(path);
        string token;
        while(getline(ss, token, '/')){ //tokenization
            tokens.push_back(token);
        }

        stack<string> stk;

        for(auto token: tokens){
            if(token == ".."){
                if(!stk.empty()) stk.pop();
            }else if(token.empty() || token == "."){
                continue;
            }else{
                stk.push(token);
            }
        }

        if(stk.empty()) return "/";

        vector<string> dirs;
        while (!stk.empty()) {
            dirs.push_back(stk.top());
            stk.pop();
        }

        reverse(dirs.begin(), dirs.end());

        string result = "/";
        for (int i = 0; i < dirs.size(); i++) {
            result += dirs[i];
            if (i != dirs.size() - 1)
                result += "/";
        }

        return result;
    }
};