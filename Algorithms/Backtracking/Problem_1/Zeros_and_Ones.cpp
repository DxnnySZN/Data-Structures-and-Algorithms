/* backtracking is a problem-solving technique that involves exploring all possible solutions by building them 
   incrementally and abandoning a solution as soon as it is determined to be invalid or suboptimal.

   in backtracking:
        the algorithm recursively explores decision trees or paths, "backtracking" whenever a partial solution 
        fails to satisfy the problem's constraints.
        
        this approach carefully eliminates paths that cannot lead to the correct solution, reducing the 
        search space.

   example applications:
        solving puzzles (like sudoku), finding all permutations of a set, and pathfinding in mazes.

   backtracking ensures that all possible solutions are explored but can be computationally expensive 
   for large problem spaces. */

#include <iostream>
#include <vector>

using namespace std;

// prints the contents of a vector separated by spaces
void print(const vector<int>& vector) {
    int vectorSize = vector.size();
    for (int i = 0; i < vectorSize; ++i) {
        cout << vector[i]; // prints the current element

        // if not the last element, print a space
        if (i != vectorSize - 1) { 
            cout << " ";
        }
    }
    cout << endl;
}

// recursive function to generate all binary strings of a given length
void backtrack(vector<int>& vector, int index) {
    int vectorSize = vector.size();

    // prints the current binary string
    if (index == vectorSize) {
        print(vector); // base case
    }
    else {
        /* explores both possibilities (0 and 1) at the current index

        sets the current index to 0 and recursively processes the next index */
        vector[index] = 0; 
        backtrack(vector, index + 1);

        // sets the current index to 1 and recursively processes the next index
        vector[index] = 1; 
        backtrack(vector, index + 1);
    }
}

int main() {
    int naturalNumber; // stores the length of binary strings
    cin >> naturalNumber;
    vector<int> vector(naturalNumber); // creates vector of the given size to hold the binary string
    backtrack(vector, 0); // starts the backtracking process from index 0

    return 0;

    /* Test_Case: 3
       
       Output: 0 0 0
               0 0 1
               0 1 0
               0 1 1
               1 0 0
               1 0 1
               1 1 0
               1 1 1 

      Tree Visualization:          []
                                 /    \
                              [0]      [1]
                             /  \      /  \
                          [0,0] [0,1] [1,0] [1,1]
                           / \   / \   / \   / \
                          000 001 010 011 100 101 110 111
                          
       Explanation: Level 0: Initial State
                        Start with an empty vector: [].
                        At this point, the function hasn't made any decisions yet.
                    
                    Level 1: Decision for Index 0
                        From [], you decide the value for vector[0].
                        Left branch: vector[0] = 0 → Partial string [0].
                        Right branch: vector[0] = 1 → Partial string [1].
                    
                    Level 2: Decision for Index 1
                        For each partial string ([0] and [1]), decide the value for vector[1].
                            For [0]:
                                Left branch: vector[1] = 0 → Partial string [0, 0].
                                Right branch: vector[1] = 1 → Partial string [0, 1].
                                
                            For [1]:
                                Left branch: vector[1] = 0 → Partial string [1, 0].
                                Right branch: vector[1] = 1 → Partial string [1, 1].
                    
                    Level 3: Decision for Index 2
                        For each partial string ([0, 0], [0, 1], [1, 0], [1, 1]), decide the value for vector[2].
                            For [0, 0]:
                                Left branch: vector[2] = 0 → Complete string 000.
                                Right branch: vector[2] = 1 → Complete string 001.
                        Repeat similarly for [0, 1], [1, 0], and [1, 1]. */
}