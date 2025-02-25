//BINARY EXPONENTIATION: DIVIDING THE PROBLEM INTO SMALLER PROBLEMS AND THEN SOLVING THEM.

class Solution {
public:
    double myPow(double x, int n) {
        double ans=1;
        if(n>0){ 
            while(n>0){
                if(n%2 == 1){ //WHEN N IS ODD
                    n=n-1;
                    ans=ans*x;
                }else{   //WHEN N IS EVEN
                    x=x*x;
                    n=n/2;
                }
            }
            return ans;
        }else{
            int n1 = abs(n);
            while(n1>0){
                if(n1%2 == 1){ //WHEN N IS ODD
                    n1=n1-1;
                    ans=ans*x;
                }else{
                    x=x*x;
                    n1=n1/2;
                }
            }
            return (1.0/ans);
        }
        return 1;
    }
};

#include <iostream>

int main() {
    Solution sol;
    double x;
    int n;

    std::cout << "Enter the base (x): ";
    std::cin >> x;
    std::cout << "Enter the exponent (n): ";
    std::cin >> n;

    double result = sol.myPow(x, n);
    std::cout << x << " raised to the power " << n << " is " << result << std::endl;

    return 0;
}