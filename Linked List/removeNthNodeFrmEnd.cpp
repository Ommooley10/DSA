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
    
    //NORMAL REMOVING CHA CODE AHE
        ListNode* removeFrmLL(ListNode* head, int k){
            if(head->next == NULL && k==1){
                return NULL;
            }
            else if(k==1){
                head = head->next;
                return head;
            }else{
                int count = 0;
                ListNode* temp = head;
                ListNode* prev = NULL;
    
                while(temp != NULL){
                    count++;
                    if(count == k){
                        prev->next = prev->next->next;
                        delete(temp); //can also use free(temp) here but somehow leetcode is giving an error
                        break;
                    }
                    prev = temp;
                    temp = temp->next;
                }
                return head;
            }
        }
    

        //
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            if(head == NULL) return nullptr;
        
            int count = 0;
            ListNode* tmp = head;
    
            //count the total nodes in LL
            while(tmp != NULL){
                count++;
                tmp = tmp->next;
            }
    
            //count the nth node from end using the total count of nodes
            int reqCount = count-n+1;
            return removeFrmLL(head, reqCount);
        }
    };

