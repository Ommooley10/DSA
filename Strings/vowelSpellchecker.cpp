#include <bits/stdc++.h>
using namespace std;

/*Given a wordlist, we want to implement a spellchecker that converts a query word into a correct word.
For a given query word, the spell checker handles two categories of spelling mistakes:

Capitalization: If the query matches a word in the wordlist (case-insensitive), 
then the query word is returned with the same case as the case in the wordlist.
Example: wordlist = ["yellow"], query = "YellOw": correct = "yellow"
Example: wordlist = ["Yellow"], query = "yellow": correct = "Yellow"
Example: wordlist = ["yellow"], query = "yellow": correct = "yellow"
Vowel Errors: If after replacing the vowels ('a', 'e', 'i', 'o', 'u') of the query word with any vowel individually, 
it matches a word in the wordlist (case-insensitive), then the query word is returned with the same case as the match in the wordlist.

Example: wordlist = ["YellOw"], query = "yollow": correct = "YellOw"
Example: wordlist = ["YellOw"], query = "yeellow": correct = "" (no match)
Example: wordlist = ["YellOw"], query = "yllw": correct = "" (no match)
In addition, the spell checker operates under the following precedence rules:

When the query exactly matches a word in the wordlist (case-sensitive), you should return the same word back.
When the query matches a word up to capitlization, you should return the first such match in the wordlist.
When the query matches a word up to vowel errors, you should return the first such match in the wordlist.
If the query has no matches in the wordlist, you should return the empty string.
Given some queries, return a list of words answer, where answer[i] is the correct word for query = queries[i].

Example 1:
Input: wordlist = ["KiTe","kite","hare","Hare"], queries = ["kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"]
Output: ["kite","KiTe","KiTe","Hare","hare","","","KiTe","","KiTe"]

Example 2:
Input: wordlist = ["yellow"], queries = ["YellOw"]
Output: ["yellow"]*/

/*INTUITION
Do as directed in the question:
1. Take a set for searching the exact of the query in the wordlist (in O(1)).

2. Take Hashmap to searching the capitalization, and map each word in the wordlist with its smallcase version.

3. Take hashmap again for vowels misplace/incorrect checking, and in this case use WILDCARD as '*' 
(or any other char) for converting the word in the wordlist into a general format and store its mapping
 with original word in a map, do the same with each query while checking it.  
*/


//SOLUTION 1:(BRUTE FORCE): The part of vowel checking is brute force 
class Solution {
public:
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

    //1. Function for converting word into smallcase
    string convertSmallcase(string word) {
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        return word;
    }

    //2. Check the position of vowels in two given words, and append the positions in 2 different vectors
    bool isVowelCheck(string query, string word) {
        if (query.size() != word.size())
            return false;

        vector<int> queryCount;
        vector<int> wordCount;
        string query1 = convertSmallcase(query);
        string word1 = convertSmallcase(word);

        for (int i = 0; i < query1.size(); i++) {
            if (vowels.find(query1[i]) != vowels.end()) {
                queryCount.push_back(i);
            }
        }

        for (int i = 0; i < word1.size(); i++) {
            if (vowels.find(word1[i]) != vowels.end()) {
                wordCount.push_back(i);
            }
        }
        return queryCount == wordCount;
    }

    //3. Do the same with consonants, just one thing extra, this time also chck if the consonants are same or not
    bool isConsonantCheck(string query, string word) {
        if (query.size() != word.size())
            return false;

        vector<int> queryCount;
        vector<int> wordCount;
        string queryConsonant;
        string wordConsonant;
        string query1 = convertSmallcase(query);
        string word1 = convertSmallcase(word);

        for (int i = 0; i < query1.size(); i++) {
            if (vowels.find(query1[i]) == vowels.end()) {
                queryCount.push_back(i);
                queryConsonant.push_back(query1[i]);
            }
        }

        for (int i = 0; i < word1.size(); i++) {
            if (vowels.find(word1[i]) == vowels.end()) {
                wordCount.push_back(i);
                wordConsonant.push_back(word1[i]);
            }
        }
        return ((queryCount == wordCount) && (queryConsonant == wordConsonant));
    }

    //3. Main function
    vector<string> spellchecker(vector<string>& wordlist,vector<string>& queries) {
        vector<string> ans;
        unordered_set<string> words(wordlist.begin(), wordlist.end());
        unordered_map<string, string> smallcase;

        /*Map each word in the word list with its smallcase version
                smallcase -> original
            eg. kite -> KiTe
                hare -> Hare
        */
        for (auto word : wordlist) {
            string smallcaseWord = convertSmallcase(word);
            if(smallcase.find(smallcaseWord) == smallcase.end()) //store only the first occurence
            smallcase[smallcaseWord] = word; 
        }

        // iterate over queries vector and check 3 conditions
        for (auto query : queries) {
            bool matched = false; //take a flag variable

            //CONDITION 1: Check if the query is already present in the wordlist as it is (set is used)
            if (words.find(query) != words.end()) {
                ans.push_back(query);
                matched = true;
            } 
            else {
            //CONDITION 2: Check if the smallcase of the query string is present in the map of smallcase words we made earlier
                string smallCaseQuery = convertSmallcase(query);
                if (smallcase.find(smallCaseQuery) != smallcase.end()) { 
                    ans.push_back(smallcase[smallCaseQuery]);
                    matched = true;
                }
            }
            
            if (!matched) { //if still not matched
            //CONDITION 3: Check if the vowels are misplaced or incorrectly used
                for (auto word : wordlist) {  //WE NEED TO OPTIMISE THIS CODE,DONE IN OPTIMISED VERSION
                    if (isVowelCheck(query, word) &&
                        isConsonantCheck(query, word)) {
                        ans.push_back(word);
                        matched = true;
                        break;
                    }
                }
            }
            // IF STILL NOT MATCHED, append an empty string onto the ans vector
            if (!matched) {
                ans.push_back("");
            }
        }
        return ans;
    }
};


//SOLUTION 2: OPTIMISED VERSION (almost the same as above just the additional looping for checking vowel has been solved using map)
class Solution {
public:
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

    string getSmallcase(string word) {
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        return word;
    }

    string getWildcard(string word){ // add '*' as wildcard in place of vowels so that the rest of the structure remains the same
        //eg KiTe becomes k*t*
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        string wildcard;
        for(int i = 0; i < word.size(); i++){
            if(vowels.count(word[i]) > 0){
                wildcard.push_back('*');
            }else{
                wildcard.push_back(word[i]);
            }
        }
        return wildcard;
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        vector<string> ans;
        unordered_set<string> words(wordlist.begin(), wordlist.end());
        unordered_map<string, string> smallcase;
        unordered_map<string, string> wildcardMap;

        for (auto word : wordlist) {
            string smallcaseWord = getSmallcase(word);

            if(smallcase.find(smallcaseWord) == smallcase.end())
            smallcase[smallcaseWord] = word; 
        }

        //OPTIMIZATION: precompute the wildcard of each word in wordlist
        //eg k*t* -> KiTe (mapping done in this way)
        for(auto word: wordlist){
            string wildcard = getWildcard(word);

            if(wildcardMap.find(wildcard) == wildcardMap.end()) //only take the first occurence
            wildcardMap[wildcard] = word;
        }

        for (auto query : queries) {
            bool matched = false;
            if (words.find(query) != words.end()) {
                ans.push_back(query);
                matched = true;
            } 
            else {
                string smallCaseQuery = getSmallcase(query);

                if (smallcase.find(smallCaseQuery) != smallcase.end()) { 
                    ans.push_back(smallcase[smallCaseQuery]);
                    matched = true;
                }
            }
            
            if (!matched) { //OPTIMISED HERE
                string queryWildcard = getWildcard(query);

                //
                if(wildcardMap.find(queryWildcard) != wildcardMap.end()){
                    ans.push_back(wildcardMap[queryWildcard]);
                    matched = true;
                }
            }

            if (!matched) {
                ans.push_back("");
            }
        }
        return ans;
    }
};

