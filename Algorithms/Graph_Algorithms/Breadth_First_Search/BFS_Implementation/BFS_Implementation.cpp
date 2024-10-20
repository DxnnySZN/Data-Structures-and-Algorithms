#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

typedef vector<vector<int>> graph;

list<int> bfs(const graph& g){
    int nodes = g.size(); // gets # of nodes in graph
    list<int> output; // stores the bfs traversal result
    queue<int> queue; // processes nodes in first-in-first-out order
    vector<bool> encounteredNodes(nodes, false); // tracks visited nodes

    // loops over each node in the graph to handle disconnected components
    for(int i = 0; i < nodes; ++i){ 
        if(!encounteredNodes[i]){ // starts if node has not been visited
            // adds node to the queue and marks it as visited
            queue.push(i);
            encounteredNodes[i] = true;

            while(!queue.empty()){
                int currentNode = queue.front(); // gets the next node in the queue
                queue.pop(); // removes node from queue
                output.push_back(currentNode); // adds the node to the bfs result

                // explores the adjacent nodes of the current node
                for(int j : g[currentNode]){
                    // if adjacent hasn't been visited, add it to the queue and mark it as visited
                    if(!encounteredNodes[j]){ 
                        queue.push(j); 
                        encounteredNodes[j] = true; 
                    }
                }
            }
        }
    }
    return output;
}

int main() {
    int nodes = 5;
    int edges = 5;
    graph g(nodes);

    // reads the edges from user input and populates adjacency list
    for(int i = 0; i < edges; ++i){
        int x, y;
        cin >> x >> y; 
        g[x].push_back(y);
        g[y].push_back(x);
    }

    // performs bfs on the graph
    list<int> output;
    output = bfs(g);
    cout << "bfs output: " << endl;

    // prints bfs result
    for(auto& j : output){
        cout << j << " ";
    }

    return 0;
}