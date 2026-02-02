#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.*/

/*INTUITION:
The intuition here is to first reverse the linked list from the middle node (as we do in palindrome LL prob)
and then doing the operations/ making connections as desired.
*/
class Solution {
public:
    ////General code for reversing the Linked list
    ListNode* reverseLL(ListNode* head){ 
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

    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){ //finding the middle node using slow-fast pointer technique
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* curr = head;
        ListNode* prev = reverseLL(slow); //reversing the list from the middle node

        //IMP: The connection logic (refer from codestorywithmik video for better understanding)
        while(prev->next != NULL){
            ListNode* tempPrev = prev->next;
            ListNode* temp = curr->next;

            curr->next = prev;
            prev->next = temp;
            curr = temp;
            prev = tempPrev;
        }
    }
};