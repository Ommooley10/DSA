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
    
        // code for deleting the kth node of the linked list (here the kth node would be the middle node which is calculated below)
        ListNode* removeMidLL(ListNode* head, int k){
            if(head == NULL) return NULL;
            else if(k==1){
                head = head->next;
                return head;
            }else{
                ListNode* temp = head;
                ListNode* prev = NULL;
                int count = 0;
    
                while(temp != NULL){
                    count++;
                    if(count == k){
                        prev->next = prev->next->next;
                        delete(temp);
                        break;
                    }
                    prev = temp;
                    temp = temp->next;
                }
                return head;
            }
        }
    
        ListNode* deleteMiddle(ListNode* head) {
            if (!head || !head->next) return NULL;
            
            //using fast and slow pointer technique to find the middle node
            ListNode* fast = head;
            ListNode* slow = head;
    
            while(fast != NULL && fast->next != NULL){
                fast = fast->next->next;
                slow = slow->next;
            }
    
            ListNode* temp = head;
            int count = 0;
    
            //calculating the index number of the middle node obtained
            while(temp != slow){
                count++;
                temp = temp->next;
            }
            //V.V.IMPORTANT
            count++; //because the loop will terminate exactly when the slow node is reached, so as there is 1 based indexing, we need to add one more to get the index of the middle node
    
            return removeMidLL(head,count);
        }
    };