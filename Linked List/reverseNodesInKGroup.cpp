#include <bits/stdc++.h>
using namespace std;

/*Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. 
If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]

Example 2:
Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//1] BRUTE FORCE SOLUTION (O(n) time & space complexity)
class Solution {
public: 
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<int> nodes;
        int n = 0;

        ListNode* temp = head;
        while(temp != NULL){
            nodes.push_back(temp->val);
            n++;
            temp = temp->next;
        }

        int i = 0; 
        int j = k - 1; 
        while(j < n){
            reverse(nodes.begin() + i, nodes.begin() + j + 1);
            i = i + k; 
            j = j + k; 
        }

        ListNode* newHead = new ListNode(nodes[0]);
        ListNode* mover = newHead;

        for(i = 1; i < nodes.size(); i++){
            ListNode* temp = new ListNode(nodes[i]);
            mover->next = temp;
            mover = temp;
        }

        return newHead;
    }
};
