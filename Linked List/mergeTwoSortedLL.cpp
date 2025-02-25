//CONCEPT OF DUMMY NODE IN LINKED LIST

#include <iostream>

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
    public:
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            ListNode* t1 = list1;
            ListNode* t2 = list2;
    
            ListNode* dummyNode = new ListNode(-1);
            ListNode* temp = dummyNode;
    
            // edge cases
            if (t1 == NULL)
                return list2;
            if (t2 == NULL)
                return list1;
    
            while (t1 != NULL && t2 != NULL) {
                if (t1->val < t2->val) {
                    temp->next = t1;
                    temp = t1;
                    t1 = t1->next;
                } else {
                    temp->next = t2;
                    temp = t2;
                    t2 = t2->next;
                }
            }
    
            //handling the last digit if left
            if(t1!=NULL) temp->next = t1;
            else temp->next = t2;
    
            return dummyNode->next;
        }
    };
