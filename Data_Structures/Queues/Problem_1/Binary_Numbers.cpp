#include <iostream>
#include <queue>

using namespace std;

void generateBinaryNums(int num){
    queue<string> queue;
    queue.push("1");

    for(int i = 0; i < num; ++i){
        string front = queue.front();
        queue.pop(); // dequeue front element

        cout << front << endl; // display front element

        // ascending order
        queue.push(front + "0");
        queue.push(front + "1");
    }
}

int main() {
    int num;
    while(cin >> num){
        if(num <= 0){
        cout << "Please enter a positive integer" << endl;
        }
        else{
            generateBinaryNums(num);
        }
    }
    return 0;

    /* Test_Case: 5
                  7
                  
       Output:    1 -> prints 1 and enqueues 10 and 11
                  10 -> prints 10 and enqueues 100 and 101
                  11 -> prints 11 and enqueues 110 and 111
                  100 -> prints 100 and enqueues 1000 and 1001
                  101 -> prints 101 and enqueues 1010 and 1011

                  1 -> prints 1 and enqueues 10 and 11
                  10 -> prints 10 and enqueues 100 and 101
                  11 -> prints 11 and enqueues 110 and 111
                  100 -> prints 100 and enqueues 1000 and 1001
                  101 -> prints 101 and enqueues 1010 and 1011
                  110 -> prints 110 and enqueues 1100 and 1101
                  111 -> prints 111 and enqueues 1110 and 1111 */
}