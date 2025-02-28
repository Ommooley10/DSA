//basic important question

//This question can also be solved by storing the data in some data structure (preferably a stack) and then replacing the values.
#include <bits/stdc++.h>

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
    public:
        ListNode* reverseList(ListNode* head) {
            ListNode* curr = head;
            ListNode* prev = NULL;
    
    
            while(curr != NULL){
                ListNode* front = curr->next;
                curr->next = prev;
                prev = curr;
                curr = front;
            }
            return prev;
        }
    };