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

// calculates the height of the binary tree
int height(Node* node) {
    if(node == nullptr) {
        return -1; // base case: height of an empty tree is -1
    }
    
    // recursively finds the height of the left and right subtrees
    int leftHeight = height(node -> left);
    int rightHeight = height(node -> right);

    // returns 1 (for the current node) + the larger height
    return 1 + max(leftHeight, rightHeight);
}

int main() {
    Node* root = new Node(1);

    root -> left = new Node(7);
    root -> left -> left = new Node(2);
    root -> left -> right = new Node(6);
    root -> left -> right -> left = new Node(5);
    root -> left -> right -> right = new Node(88);
    root -> left -> right -> right -> right = new Node(5);

    root -> right = new Node(9);
    root -> right -> right = new Node(9);

    cout << height(root) << endl;

    return 0;

    /* Graph:                 1
                             / \
                            7   9
                           / \   \
                          2   6   9
                             / \
                            5  88
                                \
                                 5

       Output:            4 */
}