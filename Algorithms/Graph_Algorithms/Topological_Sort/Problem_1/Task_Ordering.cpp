#include <iostream>
#include <vector>
#include <map> 
#include <queue>

using namespace std;

// defines a map to store words and their corresponding node indices
typedef map<string, int> Words; // map <key, value> -> <word, node index>
typedef map<int, string> Nodes; // map <key, value> -> <node index, word>

// defines adjacency list types
typedef vector<int> adj;
typedef vector<adj> graph;

vector<string> topological_sort(const graph& g, Words& words, Nodes& nodes){
    // stores the number of predecessors for each node
    vector<int> predecessor(g.size(), 0);

    // counts the number of predecessors for each node
    for(int i = 0; i < g.size(); ++i){
        for(int j : g[i]){
            ++predecessor[j];
        }
    }

    // maintains lexicographical order for nodes with 0 predecessors
    priority_queue<string, vector<string>, greater<string>> queue;
    
    Words::const_iterator i;

    // initializes the queue with nodes that have no predecessors
    for(i = words.begin(); i != words.end(); i++){
        if(predecessor[i -> second] == 0){
            queue.push(i -> first);
        }
    }

    // stores the result of the topological sort
    vector<string> topological_ordering;
    
    // processes nodes in topological order
    while(!queue.empty()){
        string i = queue.top();
        queue.pop();
        topological_ordering.push_back(i);

        // reduces the count of predecessors for adjacent nodes
        for(int j : g[words[i]]){
            if(--predecessor[j] == 0){
                queue.push(nodes[j]);
            }
        }
    }
    return topological_ordering;
}

int main() {
    int n;
    while(cin >> n){
        Words words; // map to store words and their node indices
        Nodes nodes; // map to store node indices and their corresponding words

        // inputs words and maps them to node indices
        for(int i = 0; i < n; ++i){
            string word;
            cin >> word;
            words[word] = i; 
            nodes[i] = word;
        }
    
        graph g(n);

        int m;
        cin >> m;

        // inputs all dependencies (edges)
        for(int i = 0; i < m; ++i){
            string x, y;
            cin >> x >> y;
            g[words[x]].push_back(words[y]); // adds the dependence
        }

        vector<string> topological = topological_sort(g, words, nodes);
        
        // outputs the topological order if it includes all nodes
        if(topological.size() == n){
            for(auto word: topological){
                cout << word;
            }
        }
        else{
            // outputs a message if no valid ordering exists
            cout << "no valid ordering";
        }
        cout << endl; 
    }
    return 0;
}