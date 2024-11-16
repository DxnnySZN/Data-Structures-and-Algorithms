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

       Output: postorder traversal: 3 7 5 12 20 15 10
       
       Explanation: Start at the root node 10:
                        Traverse the left subtree rooted at node 5.

                    At node 5:
                        Traverse the left subtree rooted at node 3.

                    At node 3:
                        No left child → No right child → Visit 3 (add 3 to the result).
                        Return to node 5.

                    Back at node 5:
                        Traverse the right subtree rooted at node 7.

                    At node 7:
                        No left child → No right child → Visit 7 (add 7 to the result).
                        Return to node 5.

                    Back at node 5:
                        Both left and right subtrees are visited → Visit 5 (add 5 to the result).
                        Return to the root node 10.

                    Back at the root node 10:
                        Traverse the right subtree rooted at node 15.

                    At node 15:
                        Traverse the left subtree rooted at node 12.

                    At node 12:
                        No left child → No right child → Visit 12 (add 12 to the result).
                        Return to node 15.

                    Back at node 15:
                        Traverse the right subtree rooted at node 20.

                    At node 20:
                        No left child → No right child → Visit 20 (add 20 to the result).
                        Return to node 15.

                    Back at node 15:
                        Both left and right subtrees are visited → Visit 15 (add 15 to the result).
                        Return to the root node 10.

                    Back at the root node 10:
                        Both left and right subtrees are visited → Visit 10 (add 10 to the result). */
}