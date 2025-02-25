#include<bits/stdc++.h>
using namespace std;

struct Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
};

int main(){
    vector<int> arr =  {2,5,8,7};
    Node* y = new Node(arr[0],nullptr);
    cout << y->data;
} //EXPECTED OUTPUT: 2