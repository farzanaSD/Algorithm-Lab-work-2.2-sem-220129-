#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Function to insert nodes in a binary tree
Node* insertNode() {
    int val;
    cout << "Enter node value (-1 for NULL): ";
    cin >> val;

    if (val == -1) return nullptr; //

    Node* newNode = new Node(val);
    cout << "Enter left child of " << val << ": ";
    newNode->left = insertNode();  // Left child input
    cout << "Enter right child of " << val << ": ";
    newNode->right = insertNode(); // Right child input

    return newNode;
}

// Inorder Traversal (Left -> Root -> Right)
void inorderTraversal(Node* root) {
    if (root == nullptr) return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

// Preorder Traversal (Root -> Left -> Right)
void preorderTraversal(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Postorder Traversal (Left -> Right -> Root)
void postorderTraversal(Node* root) {
    if (root == nullptr) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

int main() {
    cout << "Create your binary tree: \n";
    Node* root = insertNode(); // Taking user input for the tree

    cout << "\nInorder Traversal: ";
    inorderTraversal(root);
    cout << endl;

    cout << "Preorder Traversal: ";
    preorderTraversal(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    postorderTraversal(root);
    cout << endl;

    return 0;
}

