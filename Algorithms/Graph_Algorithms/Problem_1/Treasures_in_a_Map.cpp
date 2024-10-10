#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<char>> graph;
vector<pair<int, int>> directions = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} }; /* top ->    {-1, 0}
                                                                             bottom -> {1, 0}
                                                                             left ->   {0, -1}
                                                                             right ->  {0, 1} */

// returns true if position (initialRow, initialColumn) is inside of graph g
bool isValid(graph& g, int initialRow, int initialColumn){
    return initialRow >= 0 && initialRow < g.size() && initialColumn >= 0 && initialColumn < g[0].size();
}

bool dfs_treasure(graph& g, int initialRow, int initialColumn){
    if(g[initialRow][initialColumn] == 'X'){
        return false;
    }
    if(g[initialRow][initialColumn] == 't'){
        return true;
    }
    g[initialRow][initialColumn] = 'X' // marks this position as visited
    for(auto& d : directions){
        int newRow = initialRow + d.first;
        int newColumn = initialColumn + d.second;
        if(isValid(g, newRow, newColumn) && dfs_treasure(g, newRow, newColumn)){
            return true;
        }
    }
    return false;
}

int main() {
    int rows, columns;
    cin >> rows >> columns; // reads the rows and columns of the map

    graph g(rows, vector<char>(columns));

    // reads elements in the map
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < columns; ++j){
            cin >> g[i][j];
        }
    }
    int initialRow, initialColumn;
    cin >> initialRow >> initialColumn; // initial row and column starting from 1

    bool treasure = dfs_treasure(g, initialRow - 1, initialColumn - 1);
    if(treasure){
        cout << "yes";
    }
    else{
        cout << "no";
    }
    cout << endl;
    return 0;

    /* Test_Case1: 7 6
                   ..t...
                   ......
                   tX..X.
                   .X..Xt
                   .XX...
                   ..t...
                   5 3

       Output1:    yes

       Test_Case2: 4 10
                   ..t...X...
                   .....X..t.
                   XXXXX.X...
                   .......X.t
                   4 1

       Output2:    no */ 
}