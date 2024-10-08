#include <iostream>
#include <vector>
#include <list>
#include <fstream>

using namespace std;

typedef vector<vector<int>> graph;

/* if a node has not been visited, it becomes marked as visited and pushed to the output stack for backtracking purposes.
   if the nodes connected to the marked node have not been visited, do the same process to those nodes in numerical order. */ 
void dfs_recursive(const graph& G, int startingNode, vector<bool>& visited, list<int>& output){
    // base case: if the current node has not been visited yet, we proceed with the DFS
    if(!visited[startingNode]){
        // mark the current node as visited to avoid revisiting it in future DFS calls
        visited[startingNode] = true;

         // add the current node to the output list. this records the order of nodes visited in the DFS
        output.push_back(startingNode);

        /* this for loop will explore all adjacent nodes of the current node.
           graph G is an adjacency list, so G[startingNode] gives us a list of nodes connected to the current node. */
        for(int i = 0; i < G[startingNode].size(); ++i){
            // for each adjacent node of the current node, call the dfs_recursive function
            dfs_recursive(G, G[startingNode][i], visited, output);
        }
    }
}

int main() {
    ifstream infile("Test_Case.txt");
    if(!infile){
        cerr << "unable to open Test_Case.txt";
        return 1;
    }

    int nodeAmt = 5;
    int edgeAmt = 5;
    graph G(nodeAmt); // initializes graph with the number of nodes

    // reads all edges from the file
    for(int i = 0; i < edgeAmt; ++i){
        int x, y; // (x, y) is an edge of graph G
        infile >> x >> y;
        // checks if x and y are valid nodes
        if(x < 0 || x >= nodeAmt || y < 0 || y >= nodeAmt){
            cerr << "invalid node value: (" << x << ", " << y << ")" << endl;
            continue; // skip this edge if it's invalid
        }
        G[x].push_back(y);
        G[y].push_back(x);
    }

    infile.close(); // closes the file after reading

    vector<bool> visited(nodeAmt, false); // initializes visited vector
    list<int> output;
    dfs_recursive(G, 0, visited, output); // starts DFS from node 0

    // prints the output sequence
    cout << "DFS output: ";
    for(auto& i : output){
        cout << i << " ";
    }
    cout << endl;

    return 0;

    /* Test_Case: 0 1
                  0 4
                  1 4
                  0 2
                  2 3

       Output:    DFS output: 0 1 4 2 3 */ 
}