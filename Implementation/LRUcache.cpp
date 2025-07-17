#include <bits/stdc++.h>
using namespace std;

/*Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. 
Otherwise, add the key-value pair to the cache. 
If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.

Example 1:
Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4*/

/*INTUITION:
At first glance it may seem like using a vector as the data structure for implementing this, although that can be 
used as the solution but it has two main issues:
i. We need to traverse the whole array each time when the "get" method is called.
ii. we are using the "erase" method which takes a lot of complecity especially in the cases with large number of
method calls.

So here the most feasible data structure to be used is "Doubly Linked List" (DLL) along with "map", and why? that's because DLL
STL in c++ provides with methods like dll.begin(), dll,push_front(), dll.back() which run in constant time.

The reason to use a DLL with MAP:
1. dll to store the keys and update the positioning of the keys to maintain a LRU cache
2. MAP to use store the key and its address(as we need the position of the key whenever the get method is called so 
we would want the address of the key to be stored to avoid a linear search for that element which would ultimately
increase the complexity) and the value of the key.

**BRIEF:**
dll -> to store the keys
map -> to store the keys and their address and value.

**APPROACH:**
1)We will keep the most recently used element at the front of the linked list.
2) We need to update the linked list whenever a method is called, meaning that even if "get" method is called we still
need to update the linked list and sent the element (for which the get method was called) to the front of the list 
as it is recently used now.

**UPDATING list: the updation of list requires 3 things: (if it exists)**
i. erasing/removing/deleting it from the current position.
ii. putting the element to the front of the list.
iii. updating the address of that key in the map (as the key is now transferred to the front of the list)

3) Whenever new element is added, it should be added to the front of the dll and also will be added to map 

*/

class LRUCache {
public:
    list<int> dll;

    // the "list<int>::iterator" stores the address of the key whenever dll.begin() is called
    unordered_map<int, pair<list<int>::iterator,int>> mpp;
    int n;

    LRUCache(int capacity) {
        n = capacity;
    }
    
    int get(int key) {
        if(mpp.find(key) == mpp.end()) return -1;

        //most important operation of the code: UPDATING THE LIST if the key is already there(stated above) 
        dll.erase(mpp[key].first);
        dll.push_front(key);
        mpp[key].first = dll.begin();  //updating the address for the key


        return mpp[key].second;
    }
    
    void put(int key, int value) {
        if(mpp.find(key) != mpp.end()){

            //Same operation: UPDATING THE LIST IF KEY IS ALREADY THERE
            dll.erase(mpp[key].first);
            dll.push_front(key);
            mpp[key].first = dll.begin();

            mpp[key].second = value;
        }else{
            dll.push_front(key);
            mpp[key] = {dll.begin(), value};
            n--;
        }

        if(n < 0){ //need to keep the track of the capacity of the list as well, as we add the n will decrease so if it becomes negative, remove the key from the list and the map
            int keytoBeDeleted = dll.back();
            mpp.erase(keytoBeDeleted);
            dll.pop_back();
            n++;
        }

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */