// WATCH STRIVER VIDEO FOR THIS NAHI TAR STRIKE NAHI HONAR

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
        ListNode* rotateRight(ListNode* head, int k) {
            if (!head || !head->next || k == 0) return head; // Edge case handling
    
            ListNode* tmp = head;
            ListNode* prv = NULL;
            
            // Finding the length of the LL
            int len = 0;  
            while (tmp != NULL) {
                len++;
                prv = tmp;
                tmp = tmp->next;
            }
    
            // If k is a multiple of len, no rotation needed
            k = k % len;
            if (k == 0) return head;
    
            // Joining the tail of the LL with the head
            prv->next = head;
    
            // Finding the new tail (which is at position len - k)
            int pos = len - k;
            int count = 1;
            ListNode* temp = head;
    
            while (count < pos) {
                temp = temp->next;
                count++;
            }
    
            // `temp` is now at the new tail
            head = temp->next; // New head
            temp->next = NULL; // Break the cycle
    
            return head;
        }
    };
    