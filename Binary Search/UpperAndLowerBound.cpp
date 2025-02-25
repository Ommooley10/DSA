#include <iostream>
#include <vector>
#include <algorithm> // for lower_bound and upper_bound

using namespace std;

int main() {
    // Create a sorted vector
    vector<int> vec = {1, 2, 4, 4, 5, 6, 8, 9};

    // Value to find bounds for
    int value = 4;

    // Find lower bound: an index ind such that mid[ind] >= value
    auto lower = lower_bound(vec.begin(), vec.end(), value);
    if (lower != vec.end()) {
        cout << "Lower bound of " << value << " is at index: " << (lower - vec.begin()) << " with value: " << *lower << endl;
    } else {
        cout << "Lower bound of " << value << " not found." << endl;
    }

    // Find upper bound: and index ind such that mid[ind] > value
    auto upper = upper_bound(vec.begin(), vec.end(), value);
    if (upper != vec.end()) {
        cout << "Upper bound of " << value << " is at index: " << (upper - vec.begin()) << " with value: " << *upper << endl;
    } else {
        cout << "Upper bound of " << value << " not found." << endl;
    }

    return 0;
}