#include <iostream>
#include<vector>
#include<map>
using namespace std;
int main() {
    
    vector<int> arr={1,3,1,2,5,2,6,6,1};
    map<int, int> mpp;
    for(int i=0;i<arr.size();i++){
        mpp[arr[i]]=mpp[arr[i]]+1;
    }
    
    for(auto it:mpp){
        cout << it.first << "->" << it.second << endl;   //displaying the key(number in the array)- value(its frequency or count) is displayed
    }

    cout << mpp[1] << endl;  //displaying the count of 1 in the given array (arr)
    return 0;
}

/*NOTE: Always use UNORDERED MAP for the best time complexity, if the TLE error is encountered then only 
switch to normal MAP 
Time complexity of unordered map - O(1) , o(n) in worst case
time complexity of ordered map - O(n)*/
 