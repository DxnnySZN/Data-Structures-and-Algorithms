#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<vector<char>> graph;

// defines possible movement directions: up, down, left, right
vector<pair<int, int>> directions = { {1, 0}, {-1, 0}, {0, -1}, {0, 1}};

int rows, columns;

// checks if position (i, j) is valid and not blocked
bool valid(const graph&g, int i, int j){
    return i >= 0 && j >= 0 && i < rows && j < columns && g[i][j] != 'X';
}

// performs bfs to find minimum distance from starting pos (i, j) to treaure 't'
int bfs_min_distance(graph& g, int i, int j){
    queue<pair<int, int>> queue; // stores positions for bfs
    vector<vector<int>> distance(rows, vector<int>(columns, -1)); // distance matrix where -1 represents infinity

    queue.push({i, j});
    distance[i][j] = 0; // starting pos distance is 0

    while(!queue.empty()){
        pair<int, int> node = queue.front(); // gets the current pos
        queue.pop(); // dequeues
        int row = node.first;
        int column = node.second;

        // returns distance if treasure is found
        if(g[row][column] == 't'){
            return distance[row][column];
        }
        g[row][column] = 'X'; // mark node as visited

        // explores all posible directions from the current pos
        for(auto& d : directions){
            int newRow = row + d.first;
            int newColumn = column + d.second;

            // checks if new pos is valid and unvisited
            if(valid(g, newRow, newColumn)){
                queue.push({newRow, newColumn}); // adds the new pos to the queue
                distance[newRow][newColumn] = distance[row][column] + 1; // updates the distance for this pos
            }
        }
    }
    return -1; // indicates there's no way a treasure can be reached
}
int main() {
    cin >> rows >> columns;
    graph g(rows, vector<char>(columns)); // defines the map

    // creates the graph (grid) and reads its contents
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < columns; ++j){
            cin >> g[i][j]; // each cell contains either '.', 'X', or 't'
        }
    }

    int r, c;
    cin >> r >> c;

    int distance = bfs_min_distance(g, r - 1, c - 1); // initial pos: (r - 1, c - 1) & must adjust for 0-based indexing

    if(distance == -1){
        cout << "no treasure can be reached";
    }
    else{
        cout << "minimum distance: " << distance;
    }
    cout << endl;
    
    return 0;

    /* Test_Case: 7 6
                  ..t...
                  ..XXX.
                  ......
                  tX..X.
                  .X..Xt
                  .XX...
                  ..t...
                  5 3 

       Output:    minimum distance: 4 */
}