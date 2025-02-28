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
         int count = 1;
         Node* temp = head;
         Node* prev = NULL;

         while(temp != NULL){
            if(count == k){
                prev->next = prev->next->next;
                free(temp);
                break;
            }
            count++;
            prev = temp;
            temp = temp->next;
         }
         return head;
    }
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Creating a linked list with 5 elements
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Original list: ";
    printList(head);

    // Removing the 3rd element
    head = removeKthElement(head, 3);

    cout << "List after removing 3rd element: ";
    printList(head);

    return 0;
}