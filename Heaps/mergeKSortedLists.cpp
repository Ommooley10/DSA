#include <bits/stdc++.h>
using namespace std;

/*You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
Merge all the linked-lists into one sorted linked-list and return it.

Example 1:
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted linked list:
1->1->2->3->4->4->5->6

Example 2:
Input: lists = []
Output: []

Example 3:
Input: lists = [[]]
Output: []*/


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> minHeap;  //use minHeap to maintain a sorted order

        //Put the elements of the vector<ListNode*> lists into a minHeap;
        for(auto a :lists){
            while(a!=nullptr){
                minHeap.push(a->val);
                a = a->next;
            }
        }
        if(minHeap.empty()) return nullptr; //if the minHeap is empty return nullptr/NULL
        

        //Create a new list using the elements of the minHeap, and this list will be sorted as minHeap keeps sorted order.
        int topEle = minHeap.top();
        minHeap.pop();

        ListNode* head = new ListNode(topEle);
        ListNode* mover = head;

        while(!minHeap.empty()){
            int currEle = minHeap.top();
            minHeap.pop();

            ListNode* temp = new ListNode(currEle);
            mover->next = temp;
            mover = temp;
        }
        return head;
    }
};