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

    /* Test_Case: 1 0
                  2 1  1 0
                  2 0
                  4 3  0 1  1 2  0 2
                  8 6  0 4  5 3  3 1  3 7  2 4  6 0 
                  8 6  0 1  2 1  3 4  4 5  5 3  7 6
                  10 9  0 1  0 2  1 3  1 4  2 5  2 6  3 7  3 8  3 9

       Output:    1
                  1
                  2
                  no
                  2
                  no
                  1 
                  
       Explanation: 1 0:
                    One node with zero edges. This is a single isolated tree.
                    Output: 1
 
                    2 1 1 0:
                    Two nodes connected by a single edge. This forms a simple tree.
                    Output: 1
     
                    2 0:
                    Two isolated nodes with no edges, representing two separate tree components.
                    Output: 2
 
                    4 3 0 1 1 2 0 2:
                    Four nodes with edges between nodes 0-1, 1-2, and 0-2, forming a cycle between nodes 0, 1, and 2.
                    Output: no (since there's a cycle, this graph is not a forest)
 
                    8 6 0 4 5 3 3 1 3 7 2 4 6 0:
                    Eight nodes with edges forming two separate cycle-free components.
                    Output: 2
 
                    8 6 0 1 2 1 3 4 4 5 5 3 7 6:
                    Eight nodes with edges forming a cycle in one of the components.
                    Output: no (since there's a cycle, this graph is not a forest)
 
                    10 9 0 1 0 2 1 3 1 4 2 5 2 6 3 7 3 8 3 9:
                    Ten nodes with edges forming a single connected component with no cycles, thus forming one large tree.
                    Output: 1 */
}