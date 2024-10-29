/* Depth-First Search (DFS):
        Approach: DFS explores as far down a branch as possible before backtracking to explore other branches.
        Data Structure: Uses a stack (LIFO) or recursion for its traversal.
        Traversal Order: Goes as deep as possible along one branch, then backtracks and continues from the next unexplored branch.
   
   Applications:
        Finding connected components in a graph.
        Solving puzzles like mazes.
        Topological sorting and detecting cycles in directed graphs.

   Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges.
   Space Complexity: O(V) for the recursion stack (in the worst case, all vertices are visited). */

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

/* this will return dfs for all the nodes no matter if some nodes aren't connected to anything. 
   this is different than the function above because the function above focuses on a single starting node and explores only its reachable nodes. */
list<int> dfs_recursive(const graph& G){
    int gSize = G.size();
    list<int> output;
    vector<bool> visited(gSize, false);
    for(int i = 0; i < gSize; ++i){
        dfs_recursive(G, i, visited, output);
    }
    return output;
}

int main() {
    ifstream infile("Test_Case.txt");
    if(!infile){
        cerr << "unable to open Test_Case.txt";
        return 1;
    }

    int nodeAmt = 4;
    int edgeAmt = 2;
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
    // dfs_recursive(G, 0, visited, output); | original algorithm

    output = dfs_recursive(G); // new algorithm

    // prints the output sequence
    cout << "DFS output: ";
    for(auto& i : output){
        cout << i << " ";
    }
    cout << endl;

    return 0;

    /* Graph:     0---------------2
                                 
                                
                  1---------------3
                  
       Test_Case: 0 2
                  1 3

       Output:    DFS output: 0 2 1 3 */ 
}