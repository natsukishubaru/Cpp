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

class BST {
public:
    Node* root;
    
    BST() {
        root = nullptr;
    }
    
    Node* insert(Node* node, int data) {
        if (node == nullptr) {
            return new Node(data);
        }
        if (data < node->data) {
            node->left = insert(node->left, data);
        } else {
            node->right = insert(node->right, data);
        }
        return node;
    }

    Node* findMinRecursive(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }
        if (node->left == nullptr) {
            return node;
        }
        return findMinRecursive(node->left);
    }
    
    void inorder(Node* node) {
        if (node != nullptr) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }
};

int main() {
    cout << "Binary Search Tree Minimum Value\n\n";
    
    BST tree;
    
    tree.root = tree.insert(tree.root, 50);
    tree.root = tree.insert(tree.root, 30);
    tree.root = tree.insert(tree.root, 70);
    tree.root = tree.insert(tree.root, 20);
    tree.root = tree.insert(tree.root, 40);
    tree.root = tree.insert(tree.root, 60);
    tree.root = tree.insert(tree.root, 80);
    
    cout << "Inorder Traversal: ";
    tree.inorder(tree.root);
    cout << "\n";
    
    Node* minNodeRec = tree.findMinRecursive(tree.root);
    if (minNodeRec != nullptr) {
        cout << "Minimum value in BST (Recursive): " << minNodeRec->data << "\n";
    } else {
        cout << "Tree is empty\n";
    }
    
    return 0;
}