#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<int> nums;

    nums.push(10);
    nums.push(20);
    nums.push(30);

    /* nums = [10]
              [20]
              [30] */

    int front = nums.front();
    cout << "Front: " << front << endl; // Front: 10

    nums.pop();
    cout << "New Front: " << nums.front() << endl; // New Front: 20

    if(nums.empty()){
        cout << "Queue is empty";
    }
    else{
        cout << "Queue is not empty"; // ✓
    }
    cout << endl;

    nums.push(15);
    nums.push(65);
    nums.push(100);
    cout << "Queue Size: " << nums.size() << endl; // Queue Size: 5

    queue<int> numsCopy = nums;
    // iterate through copy of the queue and print all elements | 20 30 15 65 100
    while(!numsCopy.empty()){ 
        int frontElement = numsCopy.front();
        cout << frontElement << " ";
        numsCopy.pop();
    }
    cout << endl;
    return 0;
}