#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int key) {
    Node* newNode = new Node();
    newNode->data = key;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node* insert(Node* root, int key) {
    if (root == nullptr) {
        return createNode(key);
    }

    if (key < root->data) {
        root->left = insert(root->left, key);
    } else if (key > root->data) {
        root->right = insert(root->right, key);
    }
    return root;
}

void preOrder(Node* root) {
    if (root == nullptr) {
        return;
    }

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main() {
    Node* root = nullptr;
    string operation;
    int key;

    while (true) {
        cin >> operation;
        if (operation == "#") {
            break;
        }
        else if (operation == "insert") {
            cin >> key;
            root = insert(root, key);
        }  
    }
    preOrder(root);
    return 0;
}