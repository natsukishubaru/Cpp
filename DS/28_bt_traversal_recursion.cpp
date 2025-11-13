#include <iostream>
using namespace std;

class Node{
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
    
    void preorder(Node* node) {
        if (node != nullptr) {
            cout << node->data << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }
    
    void inorder(Node* node) {
        if (node != nullptr) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }
    
    void postorder(Node* node) {
        if (node != nullptr) {
            postorder(node->left);
            postorder(node->right);
            cout << node->data << " ";
        }
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
    
    cout << "Binary Tree Traversals\n\n";
    cout << "Preorder traversal: ";
    tree.preorder(tree.root);
    cout << endl;
    
    cout << "Inorder traversal: ";
    tree.inorder(tree.root);
    cout << endl;
    
    cout << "Postorder traversal: ";
    tree.postorder(tree.root);
    cout << endl;
    
    return 0;
}