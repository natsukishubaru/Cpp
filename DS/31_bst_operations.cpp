#include <iostream>
#include <string>
using namespace std;

class Automobile {
public:
    string type;
    string company;
    int year;
    
    Automobile() {
        type = "";
        company = "";
        year = 0;
    }
    
    Automobile(string t, string c, int y) {
        type = t;
        company = c;
        year = y;
    }
    
    void display() {
        cout << "Type: " << type << ", Company: " << company << ", Year: " << year;
    }
};

class Node {
public:
    Automobile data;
    Node* left;
    Node* right;
    
    Node(Automobile auto_data) {
        data = auto_data;
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
    
    Node* insert(Node* node, Automobile auto_data) {
        if (node == nullptr) {
            return new Node(auto_data);
        }
        if (auto_data.year < node->data.year) {
            node->left = insert(node->left, auto_data);
        } else {
            node->right = insert(node->right, auto_data);
        }
        return node;
    }
    
    Node* findMin(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }
    
    Node* deleteNode(Node* node, int year) {
        if (node == nullptr) {
            return nullptr;
        }
        
        if (year < node->data.year) {
            node->left = deleteNode(node->left, year);
        } else if (year > node->data.year) {
            node->right = deleteNode(node->right, year);
        } else {
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                return nullptr;
            } else if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            } else {
                Node* temp = findMin(node->right);
                node->data = temp->data;
                node->right = deleteNode(node->right, temp->data.year);
            }
        }
        return node;
    }
    
    void inorder(Node* node) {
        if (node != nullptr) {
            inorder(node->left);
            node->data.display();
            cout << endl;
            inorder(node->right);
        }
    }
    
    void preorder(Node* node) {
        if (node != nullptr) {
            node->data.display();
            cout << endl;
            preorder(node->left);
            preorder(node->right);
        }
    }
    
    void postorder(Node* node) {
        if (node != nullptr) {
            postorder(node->left);
            postorder(node->right);
            node->data.display();
            cout << endl;
        }
    }
};

int main() {
    BST tree;
    
    tree.root = tree.insert(tree.root, Automobile("Sedan", "Toyota", 2018));
    tree.root = tree.insert(tree.root, Automobile("SUV", "Honda", 2015));
    tree.root = tree.insert(tree.root, Automobile("Hatchback", "Ford", 2020));
    tree.root = tree.insert(tree.root, Automobile("Coupe", "BMW", 2012));
    tree.root = tree.insert(tree.root, Automobile("Truck", "Chevrolet", 2019));
    tree.root = tree.insert(tree.root, Automobile("Convertible", "Mercedes", 2021));
    
    cout << "Binary Search Tree :\n\n";
    cout << "Inorder Traversal :\n";
    tree.inorder(tree.root);
    cout << endl;
    
    cout << "Preorder Traversal :\n";
    tree.preorder(tree.root);
    cout << endl;
    
    cout << "Postorder Traversal :\n";
    tree.postorder(tree.root);
    cout << endl;
    
    cout << "Deleting automobile with year 2015 :\n";
    tree.root = tree.deleteNode(tree.root, 2015);
    
    cout << "\nInorder Traversal after deletion :\n";
    tree.inorder(tree.root);
    
    return 0;
}