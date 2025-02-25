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
        ListNode* swapPairs(ListNode* head) {
            if (head == NULL || head->next == NULL) return head;
    
            ListNode* dummy = new ListNode(-1); // Dummy node to handle edge cases
            dummy->next = head;
            ListNode* prev = dummy;
            ListNode* curr = head;
    
            while (curr != NULL && curr->next != NULL) {
                ListNode* front = curr->next;
                
                // Swapping
                curr->next = front->next;
                front->next = curr;
                prev->next = front;
    
                // Move `prev` and `curr` two steps forward
                prev = curr;
                curr = curr->next;
            }
    
            return dummy->next;
        }
    };
    