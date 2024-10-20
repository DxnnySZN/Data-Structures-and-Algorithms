#include <iostream>
#include <vector>

using namespace std;

int rows, columns;
typedef vector<vector<char>> graph; // defines a type for the graph as a 2D vector of characters
vector<pair<int, int>> directions = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} }; /* top (directions[0]) ->    {-1, 0} 
                                                                             bottom (directions[1]) -> {1, 0}
                                                                             left (directions[2]) ->   {0, -1}
                                                                             right (directions[3]) ->  {0, 1} */

// returns true if position (i, j) is within the grid boundaries
bool valid(const graph& G, int i, int j){
	return i >= 0 && i < int(G.size()) && j >= 0 && j < int(G[0].size());
}

void dfs_count(graph& G, int i, int j, int& count){
	if(G[i][j] == 'X'){ 
        return; // will return 0 because it's a wall
    }
	if(G[i][j] == 't'){
        ++count; // counts the reward
    }
	G[i][j] = 'X'; // marks the position (i, j) as visited to avoid re-visiting

	// explores all possible directions
    for(auto& d : directions){
		int adjustedRow = i + d.first;
		int adjustedColumn = j + d.second;

		// new position = (adjustedRow, adjustedColumn)
		if(valid(G, adjustedRow, adjustedColumn)){
            dfs_count(G, adjustedRow, adjustedColumn, count);
        } 
	}
}

int main() {
	cin >> rows >> columns;
	graph G(rows, vector<char>(columns));

	for(int i = 0; i < rows; ++i){
        for(int j = 0; j < columns; ++j){
            cin >> G[i][j];
        }
	}

	int initialRow, initialColumn;
	cin >> initialRow >> initialColumn;	// counting from 1
    int numRewards = 0;
	dfs_count(G, initialRow - 1, initialColumn - 1, numRewards);
	
	cout << numRewards << endl; // outputs the total number of rewards found
    return 0;

    /* Test_Case1:   7 6
                     ..t...
                     ..XXX.
                     ......
                     tX..X.
                     .X..Xt
                     .XX...
                     ..t...
                     5 3

       Output1:      4

       Explanation1: the initial position (5, 3) allows dfs to explore open spaces and collect rewards.
                     four rewards are reachable, so the output is 4.
        
       Test_Case2:   4 10
                     ..t...X...
                     .....X..t.
                     XXXXX.X...
                     .......X.t
                     4 1
    
       Output2:      0
       
       Explanation2: starting from (4, 1), the dfs is blocked by walls, preventing exploration.
                     no rewards are reachable, resulting in an output of 0.

       Test_Case3:   5 7
                     .......
                     .XXXXXt
                     .X...Xt
                     .X.X.XX
                     ...X.Xt
                     5 5
        
        Output3:     2 
        
        Explanation3: from position (5, 5), the dfs explores accessible areas and finds two rewards. 
                      only two rewards are reachable, so the output is 2. */
}