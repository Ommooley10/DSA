// TORTOISE AND HARE ALGORITHM

#include<bits/stdc++.h>
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };


 class Solution {
    public:
        ListNode *detectCycle(ListNode *head) {
            if (head == NULL) return NULL; // Check if the list is empty
    
            ListNode* slow = head;
            ListNode* fast = head;
    
            // Step 1: Determine if a cycle exists
            while (fast != NULL && fast->next != NULL) {
                slow = slow->next;          // Move slow pointer by 1
                fast = fast->next->next;   // Move fast pointer by 2
    
                if (slow == fast) {         // Cycle detected
                    // Step 2: Find the entry point of the cycle
                    ListNode* entry = head;
                    while (entry != slow) {   //MOST IMPORTANT PART OF THE CODE
                        entry = entry->next; // Move entry pointer by 1
                        slow = slow->next;   // Move slow pointer by 1
                    }
                    return entry; // The start of the cycle
                }
            }
            return NULL; // No cycle
        }
    };