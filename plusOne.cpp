#include <iostream>
#include <vector>
using namespace std;

vector<int> plusOne(vector<int>& digits) {
    int n = digits.size();
    digits[n-1]++;
    
    for (int i = n-1; i >= 0; i--) {
        if (digits[i] == 10) {
            digits[i] = 0;
            if (i == 0) {
                // If we're at the most significant digit and it's 10, we need to insert 1 at the beginning
                digits.insert(digits.begin(), 1);
            } else {
                // Otherwise, increment the next digit to the left
                digits[i-1]++;
            }
        } else {
            break; // No need to continue if there's no carry
        }
    }
    
    return digits;
}

int main() {
    vector<int> digits = {9, 9, 9}; // Example input
    vector<int> result = plusOne(digits);
    
    cout << "Result after plus one: ";
    for (int digit : result) {
        cout << digit << " ";
    }
    cout << endl;
    
    return 0;
}
