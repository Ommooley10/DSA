#include <bits/stdc++.h>
using namespace std;

/*You are given a palindromic string s.
Return the lexicographically smallest palindromic permutation of s.

Example 1:
Input: s = "z"
Output: "z"
Explanation:
A string of only one character is already the lexicographically smallest palindrome.

Example 2:
Input: s = "babab
Output: "abbba"
Explanation:
Rearranging "babab" → "abbba" gives the smallest lexicographic palindrome.

Example 3:
Input: s = "daccad"
Output: "acddca"
Explanation:
Rearranging "daccad" → "acddca" gives the smallest lexicographic palindrome.*/


// TIP: the trick here is to sort the first half of the string and reverse (or sort in decreasing order) the other half.
// eg s = babab, first half sort = ab, next half sort (reversed/decreasing) = ba, left the middle 'b' as it is for odd s.size(). Final s = abbba
//eg s = daccad, first half sort = acd, next half sort (reversed/decreasing) = dca, resulting string = acddca


class Solution {
public:

    /*NOTE: when using sort function i.e sort(s.begin(), s.begin() + i + 1) here +1 is added to include the index i in sorting range
    although this is not needed while starting the sort from index i i.e sort(s.begin() + i, s.end()) here no need to add +1 (if starting the sort from i index)*/
    string smallestPalindrome(string s) {
        int n = s.size();
        string copy = s;
        if (n == 1 || n == 2)
            return s;

        int mid = n / 2;

        if (n % 2 != 0) {
            sort(s.begin(), s.begin() + mid); //here s.begin() + mid won't include the mid index
            sort(s.begin() + mid + 1, s.end(), greater<char>());
        } else {
            sort(s.begin(), s.begin() + mid);
            sort(s.begin() + mid, s.end(), greater<char>());
        }

        return s;
    }
};