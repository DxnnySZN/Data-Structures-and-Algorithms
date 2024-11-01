#include <iostream>
#include <vector>
#include <list>
#include <stack>

using namespace std;

typedef vector<vector<int>> graph;

list<int> topological_sort(graph& g){
    int nodes = g.size(); // total # of nodes in graph g
    vector<int> dag(nodes, 0); // dag: directed acyclic graph | stores in-degrees for each node

    // calculates in-degrees for each node
    for(int i = 0; i < nodes; ++i){
        for(int j : g[i]){
            ++dag[j]; // increment in-degree for each adjacent node
        }
    }
    stack<int> s; // stack to store nodes with zero in-degrees

    // pushes all nodes with zero in-degrees into the stack
    for(int i = 0; i < nodes; ++i){
        if(dag[i] == 0){
            s.push(i); 
        }
    }

    list<int> output; // topological ordering

    // processes nodes until stack is empty
    while(!s.empty()){
        int i = s.top();
        s.pop();
        output.push_back(i); // adds node to output

        // reduces in-degrees of all adjacent nodes
        for(int j : g[i]){
            if(--dag[j] == 0){ // if in-degree of node becomes 0, push it to stack
                s.push(j);
            }
        }
    }

    return output;
}

int main() {
    int nodes, edges;
    cin >> nodes >> edges;
    graph g(nodes);

    // reads each edge and populates the adjacency list
    for(int i = 0; i < edges; ++i){
        int source, destiny;
        cin >> source >> destiny;

        // source has a direct connection (arrow) pointing to destiny
        g[source].push_back(destiny); // g[destiny].push_back(source); will not work because we have directed graph
    }

    list<int> output = topological_sort(g);

    // prints output sequence
    for(auto& element : output){
        cout << element << " ";
    }
    cout << endl;

    return 0;
    
    /* Test_Case:  6
                   6
                   2 3
                   3 1
                   4 0
                   4 1
                   5 0
                   5 2

      Output:      5 2 3 4 1 0

      Explanation: Nodes: 6
                   Edges: 6
                   Edges List: 2 -> 3
                               3 -> 1
                               4 -> 0
                               4 -> 1
                               5 -> 0
                               5 -> 2

                   In-degree array: [2, 2, 1, 1, 0, 0]
                   This means Node 0 has 2 incoming edges (from nodes 4 and 5).
                              Node 1 has 2 incoming edges (from nodes 3 and 4).
                              Node 2 has 1 incoming edge (from node 5).
                              Node 3 has 1 incoming edge (from node 2).
                              Nodes 4 and 5 have no incoming edges.

                   After adding nodes with an in-degree of 0 to a stack to start the ordering process, the code will eventually result in the output listed above the explanation.
                   
                   Initial nodes with zero in-degrees are identified and processed, starting with nodes 5 and 4 (no incoming edges).
                   Processing continues until all nodes are added to the output list in a way that maintains their dependencies.

                   This algorithm works correctly because it processes all dependencies of each node before adding it to the ordering, 
                   guaranteeing a valid topological sort for the graph. */
}