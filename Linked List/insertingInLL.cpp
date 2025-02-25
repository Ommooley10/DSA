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


/*Node* insertHead(Node* head, int val){
    Node* temp = new Node(val, head);
    return temp;
}*/

Node* insertTail(Node* head, int val){
    Node* temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new Node(val);
}

