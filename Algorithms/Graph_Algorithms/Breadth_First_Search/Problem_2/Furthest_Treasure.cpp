#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<vector<char>> graph;

int rows, columns;

// possible movement directons: right, left, up, down
vector<pair<int, int>> directions = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} }; 

// checks if a cell is within grid bounds and not blocked by 'X'
bool valid(const graph& g, int row, int column){
    return row >= 0 && column >= 0 && row < int(g.size()) && column < int(g[0].size()) && g[row][column] != 'X';
}

// finds the maximum distance to any reachable treasure 't' from a start cell
void bfs(graph& g, int row, int column, int& distance){
    distance = -1;
    queue<pair<int, int>> queue; // queue to store cells to explore
    queue.push({row, column}); // starts from initial cell
    vector<vector<int>> distances(rows, vector<int>(columns, -1)); // tracks distances from the start cell
    vector<vector<bool>> visited(rows, vector<bool>(columns, false)); // tracks visited cells
    distances[row][column] = 0; // distance to the start cell is 0

    // processes cells in the queue
    while(!queue.empty()){
        pair<int, int> node = queue.front();
        queue.pop();
        int x = node.first;
        int y = node.second;
        visited[x][y] = true;

        if(g[x][y] == 't'){
            distance = distances[x][y]; // updates distance to the furthest reachable treasure
        }
        g[x][y] = 'X';

        for(auto& possibleDirections : directions){
            int newRow = x + possibleDirections.first;
            int newColumn = y + possibleDirections.second;

            // if new cell is valid and unvisited, add it to the queue
            if(valid(g, newRow, newColumn) && distances[newRow][newColumn] == -1){
                queue.push( {newRow, newColumn} );
                distances[newRow][newColumn] = distances[x][y] + 1; // increments distance from start
            }
        }
    }
}

int main() {
    cin >> rows >> columns;
    graph g(rows, vector<char>(columns));

    // reading of the graph
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < columns; ++j){
            cin >> g[i][j];
        }
    }

    int initialRow, initialColumn;
    cin >> initialRow >> initialColumn; // ex. (3, 4) -> (2, 3)

    int distance; // distance of the furthest treasure

    bfs(g, initialRow - 1, initialColumn - 1, distance);

    if(distance == -1){
        cout << "no treasure can be reached";
    }
    else{
        cout << "maximum distance: " << distance;
    }
    cout << endl;

    return 0;

    /* Test_Case1: 7 6
                   ..t...
                   ..XXX.
                   ......
                   tX..X.
                   .X..Xt
                   .XX...
                   ..t...
                   5 3

       Output:     maximum distance: 6
    
       Test_Case2: 4 10
                   ..t...X...
                   .....X..t.
                   XXXXX.X...
                   .......X.t
                   4 1

       Output:     no treasure can be reached */
}