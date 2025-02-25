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

class Solution {
    public:
      Node* constructLL(vector<int>& arr) {
          Node* head = new Node(arr[0]);
          Node* mover = head;
          
          for(int i=1;i<arr.size();i++){
              Node* temp = new Node(arr[i]);
              mover->next = temp;
              mover = temp;
          }
          return head;
      }
  };

void printLL(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    Solution sol;
    Node* head = sol.constructLL(arr);
    printLL(head);
    return 0;
}