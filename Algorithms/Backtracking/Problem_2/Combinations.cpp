#include <iostream>
#include <vector>

using namespace std;

// prints the contents of a vector in a single line
void print(const vector<int>& vector) {
    for (int i = 0; i < vector.size(); ++i) {
        cout << vector[i];
        if ( i != vector.size() - 1) {
            cout << " ";
        }
        cout << endl;
    }
}

/* generates all combinations of zeros and ones

   parameters: 
      elements:
        tracks the current position in the vector where the next value (0 or 1) is being assigned.
        this acts as the depth of the recursion tree.

      vector:
        a dynamic array (vector) that holds the current sequence being constructed.
        it gets modified during recursion to try different combinations.

      onesAccumulated:
        counts the number of ones that have been placed in the vector so far.
        ensures the total number of ones does not exceed the target amtOfOnes.

      amtOfOnes:
        the total number of ones that must appear in each valid combination.
        this is the constraint we are trying to satisfy. */
void backtrack(int elements, vector<int>& vector, int onesAccumulated, int amtOfOnes) {
    // checks if it's possible for the current branch to create a valid combination
    if (onesAccumulated > amtOfOnes || elements - onesAccumulated > vector.size() - amtOfOnes) {
        return;
    } 

    // elements == vector.size() indicates the entire vector has been filled with values of 0s or 1s
    if (elements == vector.size()) {
        print(vector);
    }  

    // explores two possibilities at the current position (elements) 
    else {
        // zero at the current position
        vector[elements] = 0;
        backtrack(elements + 1, vector, onesAccumulated, amtOfOnes);
        
        // one at the current position
        vector[elements] = 1;
        backtrack(elements + 1, vector, onesAccumulated + 1, amtOfOnes);
    }
}

int main() {
    int sizeOfSolution; // total # of positions in the combination
    cin >> sizeOfSolution;

    int amtOfOnes; // # of ones required in each combination
    cin >> amtOfOnes;

    vector<int> vector(sizeOfSolution); // initializes a vector with the specified size to store combinations
    backtrack(0, vector, 0, amtOfOnes); // starts the backtracking process from the first position

    return 0;
}