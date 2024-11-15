#include <iostream>
#include <vector>

using namespace std;

class Node {
public: // all attributes & functions are accessible outside the class

    int data;  // stores the value of the node
    Node* left; // pointer to the left child node
    Node* right; // pointer to the right child node

    // this constructor initializes the node's data
    Node(int value){
        data = value;

        // both children are initially empty so they are defined as null pointers
        left = nullptr;
        right = nullptr;
    }
    
};

vector<int> postorder(Node* node) {
    vector<int> result;

    // order of the postorder traversal: visit left subtree, visit right subtree, visit root
    if (node != nullptr) {
        // visits left subtree
        vector<int> leftSubtree = postorder(node -> left);
        result.insert(result.end(), leftSubtree.begin(), leftSubtree.end()); // concatenates all elements in left subtree vector to the end of result vector

        // visits right subtree
        vector<int> rightSubtree = postorder(node -> right);
        result.insert(result.end(), rightSubtree.begin(), rightSubtree.end()); // concatenates all elements in right subtree vector to the end of result vector

        // visits root
        result.push_back(node -> data);
    }

    return result;
}

int main() {
    Node* root = new Node(10);
    root -> left = new Node(5);
    root -> left -> left = new Node(3);
    root -> left -> right = new Node(7);
    root -> right = new Node(15);
    root -> right -> left = new Node(12);
    root -> right -> right = new Node(20);

    vector<int> postorderTraversal = postorder(root);
    cout << "postorder traversal: ";
    for (int value : postorderTraversal) {
        cout << value << " ";
    }
    cout << endl;

    return 0;

    /* Graph:        10
                    /  \
                   5    15
                  / \   / \
                 3   7 12  20

       Output : postorder traversal: 3 7 5 12 20 15 10 */
}