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
    
    int findLevel(Node* node, int key, int level = 1) {
        if (node == nullptr) {
            return -1;
        }
        if (node->data == key) {
            return level;
        }
        
        int leftLevel = findLevel(node->left, key, level + 1);
        if (leftLevel != -1) {
            return leftLevel;
        }
        
        return findLevel(node->right, key, level + 1);
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

    cout << "Binary Tree Level of a Node\n\n";
    cout << "Inorder traversal: ";
    tree.inorder(tree.root);
    cout << "\n\n";
        
    int nodeKey = 2;
    int level = tree.findLevel(tree.root, nodeKey);
    if (level != -1) {
        cout << "Level of node " << nodeKey << ": " << level << '\n';
    } else {
        cout << "Node " << nodeKey << " not found in the tree\n";
    }
    
    nodeKey = 4;
    level = tree.findLevel(tree.root, nodeKey);
    if (level != -1) {
        cout << "Level of node " << nodeKey << ": " << level << '\n';
    } else {
        cout << "Node " << nodeKey << " not found in the tree\n";
    }
    return 0;
}