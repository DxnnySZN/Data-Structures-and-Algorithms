#include <iostream>
#include <vector>
#include <list>

using namespace std;

typedef vector<vector<int>> graph;

/* if a node has not been visited, it becomes marked as visited and pushed to the output stack for backtracking purposes.
   if the nodes connected to the marked node have not been visited, do the same process to those nodes in numerical order. */ 
void dfs_recursive(const graph& G, int startingNode, vector<bool>& visited, list<int>& output){
    if(!visited[startingNode]){
        visited[startingNode] = true;
        output.push_back(startingNode);

        // checks adjacent nodes
        for(int i = 0; i < G[startingNode].size(); ++i){
            dfs_recursive(G, G[startingNode][i], visited, output);
        }
    }
}

int main() {
    int nodeAmt, edgeAmt = 5;
    graph G(nodeAmt);

    // reads all edges
    for(int i = 0; i < edgeAmt; ++i){
        int x, y; // (x, y) is an edge of graph G
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    vector<bool> visited(nodeAmt);
    list<int> output;
    dfs_recursive(G, 0, visited, output);

    // print the output sequence
    cout << "DFS output: ";
    for(auto& i : output){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}