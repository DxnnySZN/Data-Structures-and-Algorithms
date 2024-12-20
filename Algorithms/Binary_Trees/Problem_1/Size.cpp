#include <iostream>

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

// calculates the size (# of nodes) in a binary tree
int size(Node* node) {
    if(node == nullptr) { // empty binary tree (base case)
        return 0;
    }
    else {
        return 1 + size(node -> left) + size(node -> right); // recursive case: 1 (for the current node) + size of left subtree + size of right subtree
    }
}

int main() {
    Node* root = new Node(1);

    root -> left = new Node(7);
    root -> left -> left = new Node(2);
    root -> left -> right = new Node(6);
    root -> left -> right -> left = new Node(5);
    root -> left -> right -> right = new Node(11);

    root -> right = new Node(9);
    root -> right -> right = new Node(9);
    root -> right -> right -> left = new Node(5);

    cout << size(root) << endl;

    return 0;

    /* Graph:         1
                     / \
                    7   9
                   / \   \
                  2   6   9
                 / \   \
                5  11   5

    
       Output:  9 */
}