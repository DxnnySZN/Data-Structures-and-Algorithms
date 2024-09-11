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
    cin >> num;

    if(num <= 0){
        cout << "Please enter a positive integer" << endl;
    }
    else{
        generateBinaryNums(num);
    }
    return 0;
}