#include <bits/stdc++.h>
using namespace std;

/*The median is the middle value in an ordered integer list. 
If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.
 
Example 1:
Input
["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]
Output
[null, null, null, 1.5, null, 2.0]

Explanation
MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1);    // arr = [1]
medianFinder.addNum(2);    // arr = [1, 2]
medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
medianFinder.addNum(3);    // arr[1, 2, 3]
medianFinder.findMedian(); // return 2.0

Constraints:
-105 <= num <= 105
There will be at least one element in the data structure before calling findMedian.
At most 5 * 104 calls will be made to addNum and findMedian.*/

class MedianFinder {
public:
    priority_queue<int> left_maxHeap;
    priority_queue<int, vector<int>, greater<int>> right_minHeap;
    MedianFinder() {}

    void addNum(int num) {
        if(left_maxHeap.empty() || num < left_maxHeap.top()){
            left_maxHeap.push(num);
        }else{
            right_minHeap.push(num);
        }


        //always maintain left_maxHeap.size() one greater than right_minHeap.size()
        //or maintain equal size for both heaps

        if(abs((int)left_maxHeap.size() - (int)right_minHeap.size()) > 1){ //left_maxHeap cannot contain more than 1 greater element than right_minHeap
            right_minHeap.push(left_maxHeap.top());
            left_maxHeap.pop();
        }else if(right_minHeap.size() > left_maxHeap.size()){ //if the size of right_minHeap is more, transfer the element to the left_maxHeap
            left_maxHeap.push(right_minHeap.top());
            right_minHeap.pop();
        }
    }

    double findMedian() {

        //agar dono heap ka size equal hai mtlb even number of elements are present
        if(left_maxHeap.size() == right_minHeap.size()){
            double mean = (left_maxHeap.top() + right_minHeap.top()) / 2.0;
            return mean;
        }else{ //if sizes of the heaps are not equal mtlb odd number of elements are present
            return left_maxHeap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */