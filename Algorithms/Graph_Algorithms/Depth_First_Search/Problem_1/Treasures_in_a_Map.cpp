#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

typedef vector<vector<char>> graph;
vector<pair<int, int>> directions = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} }; /* top (directions[0]) ->    {-1, 0}
                                                                             bottom (directions[1]) -> {1, 0}
                                                                             left (directions[2]) ->   {0, -1}
                                                                             right (directions[3]) ->  {0, 1} */

// returns true if position (initialRow, initialColumn) is inside of graph g
bool isValid(graph& g, int initialRow, int initialColumn){
    return initialRow >= 0 && initialRow < g.size() && initialColumn >= 0 && initialColumn < g[0].size();
}

bool dfs_treasure(graph& g, int initialRow, int initialColumn){
    if(g[initialRow][initialColumn] == 'X'){
        return false; // blocked position
    }
    if(g[initialRow][initialColumn] == 't'){
        return true; // found treasure
    }
    // marks this position as visited
    g[initialRow][initialColumn] = 'X'; 

    // explores in all 4 directions
    for(auto& d : directions){
        int newRow = initialRow + d.first;
        int newColumn = initialColumn + d.second;

        // checks if the new position is valid and recursively calls dfs
        if(isValid(g, newRow, newColumn) && dfs_treasure(g, newRow, newColumn)){
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
    infile >> rows >> columns; // reads the rows and columns of the map

    graph g(rows, vector<char>(columns));

    // reads elements in the map
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < columns; ++j){
            infile >> g[i][j];
        }
    }
    int initialRow, initialColumn;
    infile >> initialRow >> initialColumn; // initial row and column starting from 1

    infile.close(); // don't forget to close the file after reading
    
    bool treasure = dfs_treasure(g, initialRow - 1, initialColumn - 1);
    if(treasure){
        cout << "yes" << endl;
    }
    else{
        cout << "no" << endl;
    }
    return 0;

    /* Test_Case: 3 3
                  ..t
                  .X.
                  ...
                  2 2
                  
       Output:    no (it should be yes) */
}