#include <iostream>
#include <vector>

using namespace std;
// User function Template for C++

class Node {
public:
    int data;
    Node* next;

    // Default constructor
    Node()
    {
        data = 0;
        next = NULL;
    }

    // Parameterised Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};


Node* removeTail(Node* head){
    if(head == NULL || head->next == NULL) return NULL;

    Node* temp = head;

    while(temp->next->next != NULL){
        temp = temp->next;
    }
    delete temp->next;
    return head;
}

Node* removeHead(Node* head){
    if(head == NULL || head->next == NULL) return NULL;

    head = head->next;
    return head;
}

//OR

Node* removeHead(Node* head){
    if(head == NULL || head->next == NULL) return NULL;

    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}


Node* removeKthElement(Node* head, int k){
    if(head == NULL || head->next == NULL) return NULL;
    else if(k == 1){
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }else{
         int count = 0;
         Node* temp = head;
         Node* prev = NULL;

         while(temp != NULL){
            count++;
            if(count == k){
                prev->next = prev->next->next;
                free(temp);
                break;
            }
            prev = temp;
            temp = temp->next;
         }
         return head;
    }
}

Node* removeGivenNode(Node* node){
    if(node->next == NULL) return NULL;

    node->data = node->next->data;
    node->next = node->next->next;
}

