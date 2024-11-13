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
// isomorphic trees have the same structure and nodes can be flipped to match each other
bool isomorphic(Node* tree1, Node* tree2) {
    // base case: both trees are empty -> isomorphic
    if (tree1 == nullptr && tree2 == nullptr) {
        return true;
    }

    if(tree1 == nullptr || tree2 == nullptr) {
        return false;
    }

    // recursive case: checks for isomorphism without flipping or with flipping subtrees
    return (isomorphic(tree1 -> left, tree2 -> left) && isomorphic(tree1 -> right, tree2 -> right)) 
    || (isomorphic(tree1 -> left, tree2 -> right) && isomorphic(tree1 -> right, tree2 -> left));
}

int main() {
    // define tree1
    Node* root = new Node(1);
    root -> left = new Node(2);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);
    root -> left -> right -> left = new Node(7);
    root -> left -> right -> right = new Node(8);
    root -> right = new Node(3);
    root -> right -> left = new Node(6);

    // define tree2
    Node* root2 = new Node(1);
    root2 -> left = new Node(3);
    root2 -> left -> right = new Node(6);
    root2 -> right = new Node(2);
    root2 -> right -> left = new Node(4);
    root2 -> right -> right = new Node(5);
    root2 -> right -> right -> left = new Node(8);
    root2 -> right -> right -> right = new Node(7);

    if (isomorphic(root, root2)){
        cout << "they are isomorphic";
    }
    else {
        cout << "they are not isomorphic";
    }
    cout << endl;

    return 0;
}