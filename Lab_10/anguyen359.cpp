//Programmed by Albert Nguyen

#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <sstream>

using namespace std;

struct Node {
    int val;
    Node *left, *right;
};

class BinaryTree {
    public:
        BinaryTree() {}
        void insertKey(Node *root, int key);
        void deleteKey(Node *root, int key);
        void printPreorder(Node *root);
        void printPostorder(Node *root);
        void printInorder(Node *root);
        Node *root;
};

int main() {
    int key;
    string input, numbers;
    BinaryTree tree;

    //translate user input of 'd(key)', 'i(key)', 'opre', 'opost', 'oin', and 'e' exits 
    do {
        cin >> input;
        numbers = input.substr(1);
        stringstream value(numbers);
        value >> key;
        switch(input[0]) {
            case 'd': 
                tree.deleteKey(tree.root, key);
                break;
            case 'i': 
                tree.insertKey(tree.root, key);
                break;
            case 'o': 
                if(numbers == "pre") {
                    tree.printPreorder(tree.root);
                }
                else if(numbers == "post"){
                    tree.printPostorder(tree.root);
                }
                else {
                    tree.printInorder(tree.root);
                }
                break;
            default:
                break;
        }
    } while(input[0] != 'e');

    return 0;
}

void BinaryTree::insertKey(Node *root, int key) {
    if(root == NULL) {
        root->val = key;
    }
    else if(key > root->val) {
        insertKey(root->right, key);
    }
    else {
        insertKey(root->left, key);
    }
}

void BinaryTree::deleteKey(Node *root, int key) {
    if(root->val == key) {
        //is leaf
        if(root->left == NULL && root->right == NULL) {
            root = NULL;
        }
        //has 2 childs or 1 right child
        else if(root->right != NULL) {
            root->val = root->right->val;
            root->right = NULL;
        }
        //only 1 left child
        else {
            root->val = root->left->val;
            root->left = NULL;
        }
    }
    else if(key > root->val) {
        deleteKey(root->right, key);
    }
    else {
        deleteKey(root->left, key);
    }
}


void BinaryTree::printPreorder(Node *root) {
    if(root == NULL) {
        return; 
    }
    cout << root->val << endl; 
    printPostorder(root->left); 
    printPostorder(root->right); 
}

void BinaryTree::printPostorder(Node *root) {
    if(root == NULL) {
        return; 
    }
    printPostorder(root->left); 
    printPostorder(root->right); 
    cout << root->val << endl; 
}

void BinaryTree::printInorder(Node *root) {
    if(root == NULL) {
        return; 
    }
    printPostorder(root->left);  
    cout << root->val << endl;
    printPostorder(root->right);
}