#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*You are given two non-empty linked lists representing two non-negative integers. 
The most significant digit comes first and each of their nodes contains a single digit. 
Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example 1:
Input: l1 = [7,2,4,3], l2 = [5,6,4]
Output: [7,8,0,7]

Example 2:
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [8,0,7]

Example 3:
Input: l1 = [0], l2 = [0]
Output: [0]*/

/*SOLUTION 1: BRUTE FORCE (doing what is said), but this solution may cause problems for larger testcases as
the "stoi" method does not work for larger testcases properly*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        
        //3. putting the values of the linked lists in a string format
        string str1;
        string str2;

        while (t1 != NULL || t2 != NULL) {
            if (t1 != NULL){
                str1.push_back(t1->val + '0');
                t1 = t1->next;
            }
            if (t2 != NULL){
                str2.push_back(t2->val + '0');
                t2 = t2->next;
            }
        }

        //2. Converting the string into numbers for addition
        int num1 = stoi(str1);
        int num2 = stoi(str2);

        int ans = num1 + num2; //adding the numbers
        string result = to_string(ans);

        //3. Inserting the numbers to an array 
        vector<int> numbers;
        for (int i = 0; i < result.size(); i++) {
            numbers.push_back(result[i] - '0');
        }

        //4. Generating a linked list from the numbers in the array
        ListNode* head = new ListNode(numbers[0]);
        ListNode* curr = head;

        for (int i = 1; i < numbers.size(); i++) {
            ListNode* temp = new ListNode(numbers[i]);
            curr->next = temp;
            curr = temp;
        }

        return head;
    }
};


//SOLUTION 2: Using stack as the solution for the problem

/*INTUITION: 
1. Considering that we have to keep the order of the number in the linked list same (not like the
Add2Numbers I problem), a stack will be useful here, as we do the addition from the rightmost digit of the number
therefore we need to have the rightmost digit with us, and inserting the elements in the stack in order
will have the rightmost element on the top.

2. So use two stacks for the two LL, and perform the addition on the top element of the stack in the same
manner as done in the Add2Numbers I leetcode problem.

3. After performing the addition insert the result in a new stack called ans stack, and at last build the LL
by taking element from the stack in order.*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> stk1;
        stack<int> stk2;

        stack<int> ans;

        ListNode* t1 = l1;
        ListNode* t2 = l2;

        //1. Inserting the values of the two list in stack
        while(t1 != NULL || t2 != NULL){
            if(t1 != NULL){
                stk1.push(t1->val);
                t1 = t1->next;
            }

            if(t2 != NULL){
                stk2.push(t2->val);
                t2 = t2->next;
            }
        }

        //2. Main logic of adding numbers keeping the carry in mind
        int carry = 0;
        while(!stk1.empty() || !stk2.empty()){
            int num1, num2;

            if(stk1.empty()) num1 = 0; //if stack is empty consider the number as 0
            else num1 = stk1.top();

            if(stk2.empty()) num2 = 0; ////if stack is empty consider the number as 0
            else num2 = stk2.top();

            int result = num1 + num2 + carry;

            //addition logic
            if(result > 9){ 
                carry = result/10;
                result = result%10;
                ans.push(result);
            }else{
                ans.push(result);
                carry = 0;
            }

            if(!stk1.empty()) stk1.pop();
            if(!stk2.empty()) stk2.pop();
        }
        if(carry != 0) ans.push(carry);

        //3. Build the linkedlist from the ans stack and return it
        ListNode* head = new ListNode(ans.top());
        ListNode* curr = head;
        ans.pop();

        while(!ans.empty()){
            ListNode* temp = new ListNode(ans.top());
            ans.pop();

            curr->next = temp;
            curr = temp;
        }

        return head;
    }
};