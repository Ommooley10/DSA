#include <bits/stdc++.h>
using namespace std;

/*You are given a 0-indexed string array words, where words[i] consists of lowercase English letters.

In one operation, select any index i such that 0 < i < words.length and words[i - 1] and words[i] are anagrams, 
and delete words[i] from words. Keep performing this operation as long as you can select an index that satisfies the conditions.

Return words after performing all operations. 
It can be shown that selecting the indices for each operation in any arbitrary order will lead to the same result.

An Anagram is a word or phrase formed by rearranging the letters of a 
different word or phrase using all the original letters exactly once. 
For example, "dacb" is an anagram of "abdc".

Example 1:
Input: words = ["abba","baba","bbaa","cd","cd"]
Output: ["abba","cd"]
Explanation:
One of the ways we can obtain the resultant array is by using the following operations:
- Since words[2] = "bbaa" and words[1] = "baba" are anagrams, we choose index 2 and delete words[2].
  Now words = ["abba","baba","cd","cd"].
- Since words[1] = "baba" and words[0] = "abba" are anagrams, we choose index 1 and delete words[1].
  Now words = ["abba","cd","cd"].
- Since words[2] = "cd" and words[1] = "cd" are anagrams, we choose index 2 and delete words[2].
  Now words = ["abba","cd"].
We can no longer perform any operations, so ["abba","cd"] is the final answer.

Example 2:
Input: words = ["a","b","c","d","e"]
Output: ["a","b","c","d","e"]
Explanation:
No two adjacent strings in words are anagrams of each other, so no operations are performed.*/

/*INTUITION*/
/*Question may seem tricky at first but it is easy.
In the questions which involve checking two "adjacent" elements/strings, doing two pointers is not always
the solution, especially when one element is to be removed and it is to be compared with the next element

In this cases use the following method:
1. Put the first element/string of the given array into the resultant array
2. Now compare this last element of the array with all the further elements in the original array (arr.back())
*/

class Solution {
public:
    bool isAnagram(string word1, string word2){
        sort(word1.begin(), word1.end());
        sort(word2.begin(), word2.end());

        return word1 == word2;
    }

    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        ans.push_back(words[0]); //put the first element in ans array

        for(int i = 1; i < words.size();i++){ // IMPORTANT: now start the index from 1
            string word1 = ans.back(); //compare the string at the index i with the last element in array
            string word2 = words[i];
            if(!isAnagram(word1, word2)){
                ans.push_back(word2);
            }
        }

        return ans;
    }
};