#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
    
    string sentence = "My name is Haley";
    vector<string> vec1;
    
    stringstream ss(sentence); //using stringstream
    string word;
    while(ss >> word){
        vec1.push_back(word);
    }
    
    for(int i=0;i<vec1.size();i++){
        cout << vec1[i] << " ";
    }

    return 0;
}
