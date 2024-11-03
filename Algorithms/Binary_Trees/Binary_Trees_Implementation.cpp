/* Binary Tree - Data structure where each node has at most two child nodes, commonly referred to as the left and right children. 

   Each node in a binary tree contains:

        1. Data or a value (the content of the node).
        2. Left child: a reference to another binary tree node, or null if there’s no left child.
        3. Right child: a reference to another binary tree node, or null if there’s no right child.

   Key Properties of a Binary Tree:
        - Root: The topmost node in the tree.
        - Leaf nodes: Nodes without children (i.e., both left and right children are null).
        - Height: The length of the longest path from the root to a leaf node.
        - Depth: The distance from the root node to a specific node.

   Binary trees can vary in structure, and specific types, like binary search trees or complete binary trees, have additional rules that govern the arrangement of nodes. */ 

#include <iostream>

using namespace std;

/* class - blueprint for creating objects.
   this is designated to represent nodes within a binary tree. */
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

int main() {
    Node* root = new Node(5); // root is an instance (an object) of the Node class

    // "->" accesses members of objects and pointers to objects
    root -> left = new Node(3); 
    root -> right = new Node(8);
    root -> left -> right = new Node(6); // adds a right child to the root's left child (value 3) with value 6

    cout << "value of root node: " << root -> data << endl;
    cout << "value of root left node: " << root -> left -> data << endl;
    cout << "value of root right node: " << root -> right -> data << endl;

    return 0;

    /* Graph:       5
                   / \
                  3   8
                   \
                    6

       Output: value of root node: 5
               value of root left node: 3
               value of root right node: 8 */
}