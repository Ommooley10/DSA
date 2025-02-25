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
        ListNode* oddEvenList(ListNode* head) {
            //edge case
            if(head == nullptr || head->next == nullptr) return head;
    
            //define the pointers
            ListNode* odd = head;
            ListNode* even = head->next;
            ListNode* evenHead = head->next;
    
            //main algo
            while(even != NULL && even->next != NULL){
                odd->next = odd->next->next;
                even->next = even->next->next;
    
                odd = odd->next;
                even = even->next;
            }
    
            //join the odd list with even list
            odd->next = evenHead;
            return head;
        }
    };
