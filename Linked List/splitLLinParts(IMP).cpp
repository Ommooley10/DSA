#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*Given the head of a singly linked list and an integer k, 
split the linked list into k consecutive linked list parts.
The length of each part should be as equal as possible: no two parts should have a size differing by more than one. 
This may lead to some parts being null.
The parts should be in the order of occurrence in the input list, 
and parts occurring earlier should always have a size greater than or equal to parts occurring later.

Return an array of the k parts.

Example 1:
Input: head = [1,2,3], k = 5
Output: [[1],[2],[3],[],[]]
Explanation:
The first element output[0] has output[0].val = 1, output[0].next = null.
The last element output[4] is null, but its string representation as a ListNode is [].

Example 2:
Input: head = [1,2,3,4,5,6,7,8,9,10], k = 3
Output: [[1,2,3,4],[5,6,7],[8,9,10]]
Explanation:
The input has been split into consecutive parts with size difference at most 1, 
and earlier parts are a larger size than the later parts.*/

/**INTUITION**/
/*The problem asks us to split a linked list into k consecutive parts that are as equal in size as possible. 
If the number of nodes is not divisible by k, the first few parts should get one extra node each. 
My first thought was to first determine the total number of nodes in the list, 
then decide how many nodes should go into each part, and finally break the list accordingly.

1]Count the total nodes – Traverse the linked list once to find its length n.
2]Compute part sizes – Using n and k, calculate how many nodes each part should have.
3]If n > k, divide nodes evenly (n / k) and distribute the remainder to the first few parts.
4]If n <= k, the first n parts will have one node each, and the remaining parts will be empty (nullptr).

5]Split the list – Traverse the list again, cutting it into parts according to the computed sizes. 
Every time we finish a part, set its next pointer to NULL and store its head in the answer vector.

6]Fill remaining parts with null – If fewer than k parts were created (possible when n < k), 
push nullptr until the result vector has exactly k elements.

This approach ensures we traverse the list only twice and correctly produce all k parts.
*/

class Solution {
public:
    int findSize(ListNode* head) {
        ListNode* temp = head;
        int count = 0;

        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    vector<int> findPartitionSizes(int n, int k) {
        vector<int> partitionSizes;
        if (n > k) {
            int quotient = n / k;
            int remainder = n % k;

            while (partitionSizes.size() != k) {
                partitionSizes.push_back(quotient);
            }

            int i = 0;
            while (remainder != 0) {
                partitionSizes[i] += 1;
                remainder--;
                i++;
            }
        } else {
            int diff = k - n;
            int toFill = k - diff;

            for (int i = 0; i < toFill; i++) {
                partitionSizes.push_back(1);
            }
        }
        return partitionSizes;
    }

    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> partitions;
        if (head == NULL) {
            while (partitions.size() < k){
                partitions.push_back(nullptr);
            }
            return partitions;
        }

        int n = findSize(head);
        vector<int> sizes = findPartitionSizes(n, k);

        int count = 1;
        ListNode* temp = head;
        int i = 0;
        while (temp != NULL) {
            if (count == sizes[i]) {
                if (temp->next != NULL) {
                    ListNode* newHead = temp->next;
                    temp->next = NULL;
                    partitions.push_back(head);
                    head = newHead;
                    temp = newHead;
                    count = 1;
                    i++;
                } else if (temp->next == NULL) {
                    partitions.push_back(head);
                    temp = NULL;
                }
            } else {
                temp = temp->next;
                count++;
            }
        }

        while (partitions.size() < k) {
            partitions.push_back(nullptr);
        }
        return partitions;
    }
};