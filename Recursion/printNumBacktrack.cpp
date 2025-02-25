#include <iostream>
using namespace std;
//PRINTING 1 TO N USING BACKTRACKING (Recursion)
void increasing(int i, int n){
    if(i<1){
        return;
    }else{
        increasing(i-1,n);   //Note that here the function call executes but the print statement below it doesnt
        cout << i << endl;   //write the print statement after the function call
    }
}

int main() {
    int n=10;
    increasing(n,n);
    return 0;
}