#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> graph;

// populates the adjacency list with edges between nodes
void read_graph(graph& g, int edges){
    int x, y;
    for(int j = 0; j < edges; ++j){
        // reads each edge and adds both directions
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
}

void search_cycles(const graph& g, vector<bool>& visited, int i, int previousNode, bool& found){
    if(!visited[i]){
        visited[i] = true;

        // traverse all neighbors of the current node
        for(int j = 0; j < g[i].size(); ++j){
            if(g[i][j] != previousNode){ // avoid going back to the node we came from
                search_cycles(g, visited, g[i][j], i, found);
                if(found){ // return immediately once a cycle is found
                    return;
                }
            }
        }
    }
    else{
        found = true; // indicates a cycle if node has been revisited
    }
}

/* prints # of trees of g, if g is a forest.
   prints "no" otherwise. */
void dfs(const graph& g){ // pass parameter as const because the graph will only be analyzed, not modified
    vector<bool> visited(g.size(), false); // tracks visited nodes
    int numTrees = 0;

    // iterates through all nodes in the graph
    for(int i = 0; i < (int)g.size(); ++i){
        if(!visited[i]){
            bool found = false;
            search_cycles(g, visited, i, i, found);
            if(found){ // cycle has been found -> g is not a forest
                cout << "no" << endl;
                return;
            }
            else{
                ++numTrees;
            }
        }
    }
    cout << numTrees << endl;
}

int main() {
    int nodes, edges;
    while(cin >> nodes >> edges){ // while we keep reading graphs
        graph g(nodes); // initiaizes empty graph with specified number of nodes
        read_graph(g, edges); // reads and constructs the graph
        dfs(g); // determines if it's a forest
    }
    return 0;
}