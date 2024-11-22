#include <iostream>
#include <vector>

using namespace std;

// ex. v = 1 2 3 will print out (1,2,3)
void print(const vector<int>& v) {
    if (v.size() != 0) {
        cout << "(" << v[0];
        for (int i = 1; i < v.size(); ++i) {
            cout << "," << v[i];
        }
        cout << ")" << endl;
    }
}

/* generates all permutations of integers from 1 to n

   parameters:
        pos: the current position in the vector being filled
        v: a vector to store the current permutation
        used: a boolean vector to track which numbers are already used in the permutation */
void permutations(int pos, vector<int>& v, vector<bool>& used) {
    int n = v.size();

    // if all positions are filled, print the permutation
    if (pos == n) {
        print(v);
    }
    else {
        // try placing each unused number in the current position
        for (int j = 0; j < n; ++j) {
            if (!used[j]) { // check if the number (j + 1) is not used yet
                used[j] = true; // mark the number as used
                v[pos] = j + 1; // place the number in the current position
                permutations(pos + 1, v, used);  // recursively fill the next position
                used[j] = false; // backtrack: unmark the number for future permutations
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    vector<bool> used(n, false);

    permutations(0, v, used);
    
    return 0;

    /* Test_Case: 3
    
       Output:   (1,2,3)
                 (1,3,2)
                 (2,1,3)
                 (2,3,1)
                 (3,1,2)
                 (3,2,1)

       Explanation: for n = 3, all permutations of {1, 2, 3} are generated.
                    the function systematically tries all possible orders by backtracking. */
}