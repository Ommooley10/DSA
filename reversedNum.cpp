// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int main() {
    int n=123;
    int revNum=0;
    int lastdigit;
    if(n<0){     //if n is a negative number
        int pos= n-2*n;
        while(pos>0){
            lastdigit=pos%10;
            pos=pos/10;
            revNum=(revNum*10)+lastdigit;
        }
        int ans=revNum-2*revNum;
        cout << ans << endl;
    }else if(n>0){   //if n is a positive number
        while(n>0){
        lastdigit=n%10;
        n=n/10;
        revNum=(revNum*10)+lastdigit;
    }
    cout << revNum << endl;
    }       
    return 0;
}