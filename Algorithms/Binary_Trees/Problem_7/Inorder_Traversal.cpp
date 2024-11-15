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

vector<int> inorder(Node* node) {
    vector<int> result;

    // order of the inorder traversal: visit left subtree, visit root, visit right subtree,
    if (node != nullptr) {
        // visits left subtree
        vector<int> leftSubtree = inorder(node -> left);
        result.insert(result.end(), leftSubtree.begin(), leftSubtree.end()); // concatenates all elements in left subtree vector to the end of result vector

        // visits root
        result.push_back(node -> data);

        // visits right subtree
        vector<int> rightSubtree = inorder(node -> right);
        result.insert(result.end(), rightSubtree.begin(), rightSubtree.end()); // concatenates all elements in right subtree vector to the end of result vector
    }

    return result;
}

int main() {
    Node* root = new Node(1);
    root -> left = new Node(2);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);
    root -> right = new Node(3);
    root -> right -> left = new Node(6);
    root -> right -> right = new Node(7);

    vector<int> inorderTraversal = inorder(root);
    cout << "inorder traversal: ";
    for (int value : inorderTraversal) {
        cout << value << " ";
    }
    cout << endl;

    return 0;
}