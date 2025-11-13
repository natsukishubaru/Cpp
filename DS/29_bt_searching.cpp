#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree {
public:
    Node* root;
    
    BinaryTree() {
        root = nullptr;
    }

    void inorder(Node* node) {
        if (node != nullptr) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }
        
    bool search(Node* node, int key) {
        if (node == nullptr) {
            return false;
        }
        if (node->data == key) {
            return true;
        }
        return search(node->left, key) || search(node->right, key);
    }
};

int main() {
    BinaryTree tree;
    tree.root = new Node(1);
    tree.root->left = new Node(2);
    tree.root->right = new Node(3);
    tree.root->left->left = new Node(4);
    tree.root->left->right = new Node(5);
    tree.root->right->left = new Node(6);
    tree.root->right->right = new Node(7);

    cout << "Binary Tree Searching\n\n";
    cout << "Inorder traversal: ";
    tree.inorder(tree.root);
    cout << '\n';
        
    int searchKey = 4;
    if (tree.search(tree.root, searchKey)) {
        cout << "\nElement " << searchKey << " found in the tree\n";
    } else {
        cout << "\nElement " << searchKey << " not found in the tree\n";
    }
    
    searchKey = 10;
    if (tree.search(tree.root, searchKey)) {
        cout << "\nElement " << searchKey << " found in the tree\n";
    } else {
        cout << "\nElement " << searchKey << " not found in the tree\n";
    }
    
    return 0;
}