//PROBABLY THE BEST QUESTION IN LINKED LIST

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
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            //initialize the variables
            ListNode* t1 = l1;
            ListNode* t2 = l2;
    
            //use dummyNode for creating the answer Linked list
            ListNode* dummyNode = new ListNode(-1);
            ListNode* curr = dummyNode;
            
            int ans;
            int carry = 0;
            while(t1 != NULL || t2 != NULL){
               int val1 = (t1 != NULL) ? t1->val : 0; // Get t1 value if not NULL
                int val2 = (t2 != NULL) ? t2->val : 0; // Get t2 value if not NULL
                ans = val1 + val2 + carry;
    
                if(ans > 9){
                    carry = ans/10;
                    ans = ans%10;
                    ListNode* temp = new ListNode(ans);
                    curr->next = temp;
                    curr = temp;
                }else{
                    ListNode* temp = new ListNode(ans);
                    curr->next = temp;
                    curr = temp;
                    carry = 0;
                }
                if(t1 != NULL)t1=t1->next;
                if(t2 != NULL)t2=t2->next;
            }
            if(carry != 0){
                ListNode* temp = new ListNode(carry);
                curr->next = temp;
            }
            return dummyNode->next;
        }
    };