#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

typedef vector<vector<char>> graph; // defines a type for the graph as a 2D vector of characters
vector<pair<int, int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} }; /* top (directions[0]) ->    {-1, 0} 
                                                                             bottom (directions[1]) -> {1, 0}
                                                                             left (directions[2]) ->   {0, -1}
                                                                             right (directions[3]) ->  {0, 1} */

// returns true if position (i, j) is inside the graph
bool valid(graph& G, int i, int j){
    return i >= 0 && i < G.size() && j >= 0 && j < G[0].size();
}

bool dfs_treasure(graph& G, int i, int j){
    if(G[i][j] == 'X'){
        return false; // will return false because it's a wall
    }
    if(G[i][j] == 't'){
        return true; // found treasure
    }
    G[i][j] = 'X'; // marks the position (i, j) as visited to avoid re-visiting

    // explores all possible directions
    for(auto& d : directions){
        int adjustedRow = i + d.first;
        int adjustedColumn = j + d.second;

        // new position = (adjustedRow, adjustedColumn)
        if(valid(G, adjustedRow, adjustedColumn) && dfs_treasure(G, adjustedRow, adjustedColumn)){
            return true;
        }
    }
    return false; // no treasure found in this path
}

int main() {
    ifstream infile("Test_Case.txt");

    if(!infile){
        cerr << "unable to open file";
        return 1;
    }

    int rows, columns;
    infile >> rows >> columns; 

    graph G(rows, vector<char>(columns));

    // reads elements in the map
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < columns; ++j){
            infile >> G[i][j];
        }
    }
    int initialRow, initialColumn;
    infile >> initialRow >> initialColumn;	

    infile.close(); // closes the file after reading

    // calls the dfs function to check if a treasure is found
    bool treasure = dfs_treasure(G, initialRow - 1, initialColumn - 1); // user input is 1-based, so subtract 1 to convert to 0-based indexing for the grid

    if(treasure){
        cout << "yes" << endl;
    }
    else{
        cout << "no" << endl;
    }

    return 0;

    /* Test_Case:   3 3
                    ..t
                    .X.
                    ...
                    2 2 
            
       Output:      no
       
       Explanation: grid is a 3x3 matrix & starting position is (2, 2), which translates to (1, 1).
                    dfs starts at (1, 1), which is an 'X'.
                    since the starting position is blocked, the function immediately returns false (no). */
}