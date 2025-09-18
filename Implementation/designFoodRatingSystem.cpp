#include <bits/stdc++.h>
using namespace std;

/*Design a food rating system that can do the following:

Modify the rating of a food item listed in the system.
Return the highest-rated food item for a type of cuisine in the system.
Implement the FoodRatings class:

*FoodRatings(String[] foods, String[] cuisines, int[] ratings) Initializes the system.

*The food items are described by foods, cuisines and ratings, all of which have a length of n.
foods[i] is the name of the ith food, cuisines[i] is the type of cuisine of the ith food, and
ratings[i] is the initial rating of the ith food.

*void changeRating(String food, int newRating) Changes the rating of the food item with the name food.

*String highestRated(String cuisine) Returns the name of the food item that has the highest rating for the given type of cuisine. 

*If there is a tie, return the item with the lexicographically smaller name.

Note that a string x is lexicographically smaller than string y if x comes before y in dictionary order, 
that is, either x is a prefix of y, or if i is the first position such that x[i] != y[i], then x[i] comes before y[i] in alphabetic order.

 
Example 1:

Input
["FoodRatings", "highestRated", "highestRated", "changeRating", "highestRated", "changeRating", "highestRated"]
[[["kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"], ["korean", "japanese", "japanese", "greek", "japanese", "korean"], [9, 12, 8, 15, 14, 7]], ["korean"], ["japanese"], ["sushi", 16], ["japanese"], ["ramen", 16], ["japanese"]]
Output
[null, "kimchi", "ramen", null, "sushi", null, "ramen"]

Explanation
FoodRatings foodRatings = new FoodRatings(["kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"], ["korean", "japanese", "japanese", "greek", "japanese", "korean"], [9, 12, 8, 15, 14, 7]);
foodRatings.highestRated("korean"); // return "kimchi"
                                    // "kimchi" is the highest rated korean food with a rating of 9.
foodRatings.highestRated("japanese"); // return "ramen"
                                      // "ramen" is the highest rated japanese food with a rating of 14.
foodRatings.changeRating("sushi", 16); // "sushi" now has a rating of 16.
foodRatings.highestRated("japanese"); // return "sushi"
                                      // "sushi" is the highest rated japanese food with a rating of 16.
foodRatings.changeRating("ramen", 16); // "ramen" now has a rating of 16.
foodRatings.highestRated("japanese"); // return "ramen"
                                      // Both "sushi" and "ramen" have a rating of 16.
                                      // However, "ramen" is lexicographically smaller than "sushi".*/


//1] SOLUTION 1: BRUTE FORCE (using only one map):
class FoodRatings {
public:
    unordered_map<string, pair<int, string>> mpp; //food -> {rating, cuisine}
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();

        for(int i = 0; i < n; i++){
            mpp[foods[i]] = {ratings[i], cuisines[i]};
        }
    }
    
    void changeRating(string food, int newRating) {
        for(auto &it: mpp){
            if(it.first == food){
                it.second.first = newRating;
                break;
            }
        }
    }
    
    string highestRated(string cuisine) {
        priority_queue<string, vector<string>, greater<string>> highRatedDishes;

        //find the highest rated dish first
        int maxRating = INT_MIN;
        for(auto &it: mpp){
            if(it.second.second == cuisine){
                maxRating = max(maxRating, it.second.first);
            }
        }

        //finding the dishes with highest rating
        for(auto &it: mpp){
            if(it.second.first == maxRating && it.second.second == cuisine){
                highRatedDishes.push(it.first);
            }
        }
        return highRatedDishes.top();
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */


//2] OPTIMAL SOLUTION (using 3 maps):
class FoodRatings {
public:
    unordered_map<string, set<pair<int, string>>> cuisine_ratings_food; //cuisine -> set<pair<rating, food>>
    unordered_map<string, string> food_cuisine; //food -> cuisine
    unordered_map<string, int> food_rating; //food -> rating
    
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        
        for(int i = 0; i<n; i++) {
            string food    = foods[i];
            string cuisine = cuisines[i];
            int rating     = ratings[i];
            
            cuisine_ratings_food[cuisine].insert({-rating, food});  //storing -ve rating because we want smallest lexicographical order
            food_cuisine[food] = cuisine;
            food_rating[food]  = rating;
            
            
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = food_cuisine[food];
        int oldRating  = food_rating[food];
        
        cuisine_ratings_food[cuisine].erase({-oldRating, food});
        cuisine_ratings_food[cuisine].insert({-newRating, food});
        food_rating[food] = newRating;
        
    }
    
    string highestRated(string cuisine) {
        return begin(cuisine_ratings_food[cuisine])->second; 
        
        //first item will have highest absolute rating "we put all ratings in negative" (ordered_set)
        //Why did we not put them in ascending order and just return the last element of ordered_set ?
        //Ans : Because We can have a case like below
        //{(15, abc), (16, ramen), (16, sushi)} -> Order in ordered_set. last element is not lexicographically smaller
        //{(-16, ramen), (-16, sushi), (-15, abc)} -> First element is now lexicographically smaller
    }
};