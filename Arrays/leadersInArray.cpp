#include <iostream>   //KABHI KABHI PICHE SE BHI CHECK KR LIYA KR
#include <vector>
#include <algorithm> // for std::sort
#include <climits>   // for INT_MIN

using namespace std;

vector<int> superiorElements(vector<int>& a) {
    vector<int> res;
    int maxi = INT_MIN;

    // Traverse the array from the end to the beginning
    for(int i = a.size() - 1; i >= 0; i--) {
        // If the current element is greater than the maximum element found so far
        if(a[i] > maxi) {
            maxi = a[i];  // Update the maximum element
            res.push_back(a[i]);  // Add the current element to the result
        }
    }

    // Sort the result vector to get the leaders in the correct order
    sort(res.begin(), res.end());
    return res;
}

int main() {
    // Example array
    vector<int> arr = {16, 17, 4, 3, 5, 2};
    
    // Get the leaders in the array
    vector<int> leaders = superiorElements(arr);
    
    // Print the leaders
    cout << "Leaders in the array: ";
    for(int leader : leaders) {
        cout << leader << " ";
    }
    cout << endl;
    
    return 0;
}
