#include <iostream>
#include <climits>
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
    
    bool isBSTUtil(Node* node, int minVal, int maxVal) {
        if (node == nullptr) {
            return true;
        }
        
        if (node->data <= minVal || node->data >= maxVal) {
            return false;
        }
        
        return isBSTUtil(node->left, minVal, node->data) && 
               isBSTUtil(node->right, node->data, maxVal);
    }
    
    bool isBST() {
        return isBSTUtil(root, INT_MIN, INT_MAX);
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
    BinaryTree tree1;
    tree1.root = new Node(50);
    tree1.root->left = new Node(30);
    tree1.root->right = new Node(70);
    tree1.root->left->left = new Node(20);
    tree1.root->left->right = new Node(40);
    tree1.root->right->left = new Node(60);
    tree1.root->right->right = new Node(80);
    
    cout << "Binary Search Tree Check\n\n";
    cout << "Tree 1 (Inorder): ";
    tree1.inorder(tree1.root);
    cout << endl;
    
    if (tree1.isBST()) {
        cout << "Tree 1 is a BST\n";
    } else {
        cout << "Tree 1 is NOT a BST\n";
    }
    
    cout << '\n';
    
    BinaryTree tree2;
    tree2.root = new Node(50);
    tree2.root->left = new Node(30);
    tree2.root->right = new Node(70);
    tree2.root->left->left = new Node(20);
    tree2.root->left->right = new Node(60);
    tree2.root->right->left = new Node(40);
    tree2.root->right->right = new Node(80);
    
    cout << "Tree 2 (Inorder): ";
    tree2.inorder(tree2.root);
    cout << '\n';
    
    if (tree2.isBST()) {
        cout << "Tree 2 is a BST\n";
    } else {
        cout << "Tree 2 is NOT a BST\n";
    }
    
    return 0;
}