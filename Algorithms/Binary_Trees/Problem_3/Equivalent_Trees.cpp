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

bool equal(Node* tree1, Node* tree2) {
    // base case: both trees are empty
    if (tree1 == nullptr && tree2 == nullptr) {
        return true;
    }

    // returns false if only one tree is empty
    if (tree1 == nullptr || tree2 == nullptr) {
        return false;
    }

    // checks if data values are equal and recursively compares subtrees
    return (tree1 -> data == tree2 -> data) && 
    equal(tree1 -> left, tree2 -> left) && 
    equal(tree1 -> right, tree2 -> right);
}

int main() {
    // Binary Tree 1 for Example1 & Example2
    Node* root = new Node(1);

    root -> left = new Node(7);
    root -> left -> left = new Node(2);
    root -> left -> right = new Node(6);
    root -> left -> right -> left = new Node(5);
    root -> left -> right -> right = new Node(11);

    root -> right = new Node(9);
    root -> right -> right = new Node(9);
    root -> right -> right -> left = new Node(5);

    // Binary Tree 2 for Example1
    Node* root2 = new Node(1);

    root2 -> left = new Node(7);
    root2 -> left -> left = new Node(2);
    root2 -> left -> right = new Node(6);
    root2 -> left -> right -> left = new Node(5);
    root2 -> left -> right -> right = new Node(11);

    root2 -> right = new Node(9);
    root2 -> right -> right = new Node(9);
    root2 -> right -> right -> left = new Node(5);

    /* Binary Tree 2 for Example2
    Node* root = new Node(1);

    root -> left = new Node(7);
    root -> left -> left = new Node(2);
    root -> left -> right = new Node(6);
    root -> left -> right -> left = new Node(5);
    root -> left -> right -> right = new Node(11);
    root -> left -> right -> right = new Node(88);

    root -> right = new Node(9);
    root -> right -> right = new Node(9);
    root -> right -> right -> left = new Node(5); */

    if (equal(root, root2)) {
        cout << "they are equal";
    }
    else {
        cout << "they are not equal";
    }
    cout << endl;

    return 0;

    /* Example1:      1                    1
                     / \                  / \
                    7   9                7   9
                   / \   \              / \   \
                  2   6   9            2   6   9
                 / \   \              / \   \
                5  11   5            5  11   5
                     
       Output: they are equal
       
       Example2:      1                    1
                     / \                  / \
                    7   9                7   9
                   / \   \              / \   \
                  2   6   9            2   6   9
                 / \   \                  / \   
                5  11   5                5  88 
                                             \
                                              5  
       
       Output: they are not equal */
}