#include <iostream>
#include <queue>
#include <vector>

using namespace std;

string hotPotatoGame(const vector<string>& children, int passes){
    queue<string> q;

    // enqueue all children
    for(const string& child : children){
        q.push(child);
    }
    while(q.size() > 1){
        for(int i = 0; i < passes - 1; ++i){ // (passes - 1) ensures the child holding the potato is eliminated
            // dequeue and enqueue
            string frontChild = q.front();
            q.pop();
            q.push(frontChild);
        }
        q.pop(); // remove child with the potato
    }
    return q.front(); // winner
}

int main() {
    vector<string> children = {"Jayden", "Kayden", "Hayden", "Ayden", "Steve"};
    int passes = 4;

    string winner = hotPotatoGame(children, passes);
    cout << "The winner is " << winner << " with " << passes << " passes" << endl;
    return 0;

    /* 
    Round 1:
    * The potato is passed 3 times (passes - 1 = 4 - 1 = 3), and then the fourth child in the current sequence is eliminated: *
    Pass 1: Jayden passes to Kayden → Queue: Kayden, Hayden, Ayden, Steve, Jayden
    Pass 2: Kayden passes to Hayden → Queue: Hayden, Ayden, Steve, Jayden, Kayden
    Pass 3: Hayden passes to Ayden → Queue: Ayden, Steve, Jayden, Kayden, Hayden
    Elimination: Ayden is removed → Queue: Steve, Jayden, Kayden, Hayden

    Round 2:
    Pass 1: Steve passes to Jayden → Queue: Jayden, Kayden, Hayden, Steve
    Pass 2: Jayden passes to Kayden → Queue: Kayden, Hayden, Steve, Jayden
    Pass 3: Kayden passes to Hayden → Queue: Hayden, Steve, Jayden, Kayden
    Elimination: Hayden is removed → Queue: Steve, Jayden, Kayden

    Round 3:
    Pass 1: Steve passes to Jayden → Queue: Jayden, Kayden, Steve
    Pass 2: Jayden passes to Kayden → Queue: Kayden, Steve, Jayden
    Pass 3: Kayden passes to Steve → Queue: Steve, Jayden, Kayden
    Elimination: Steve is removed → Queue: Jayden, Kayden

    Round 4:
    Pass 1: Jayden passes to Kayden → Queue: Kayden, Jayden
    Pass 2: Kayden passes to Jayden → Queue: Jayden, Kayden
    Pass 3: Jayden passes to Kayden → Queue: Kayden, Jayden
    Elimination: Kayden is removed → Queue: Jayden
    
    Output: The winner is Jayden with 4 passes */
}