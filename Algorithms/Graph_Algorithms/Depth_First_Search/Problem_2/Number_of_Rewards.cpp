#include <iostream>
#include <vector>

using namespace std;

int rows, columns;
typedef vector<vector<char>> graph;
vector<pair<int, int>> directions = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} }; /* top (directions[0]) ->    {-1, 0} 
                                                                             bottom (directions[1]) -> {1, 0}
                                                                             left (directions[2]) ->   {0, -1}
                                                                             right (directions[3]) ->  {0, 1} */

// returns true if position (i, j) is valid
bool valid(const graph& G, int i, int j){
	return i >= 0 && i < int(G.size()) && j >= 0 && j < int(G[0].size());
}

void dfs_count(graph& G, int i, int j, int& count){
	if(G[i][j] == 'X'){ 
        return; // will return 0
    }
	if(G[i][j] == 't'){
        ++count;
    }
	G[i][j] = 'X'; // mark the position (i, j) as visited

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
	
	cout << numRewards << endl;
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

       Output1:    4
        
       Test_Case2: 4 10
                   ..t...X...
                   .....X..t.
                   XXXXX.X...
                   .......X.t
                   4 1
    
       Output2:    0
       
       Test_Case3: 5 7
                   .......
                   .XXXXXt
                   .X...Xt
                   .X.X.XX
                   ...X.Xt
                   5 5
        
        Output3:   2 */
}