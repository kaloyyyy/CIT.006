//
// Created by kaloyyyyy on 26/04/2022.
//
using namespace std;
#include <iostream>
#include "treeTraverse.h"

// Preorder traversal
void preOrder(struct Node *treeNode) {
    if (treeNode == NULL) {
        return;
    }
    cout << treeNode->data << "->";
    preOrder(treeNode->left);
    preOrder(treeNode->right);
}

// Postorder traversal
void postOrder(struct Node *treeNode) {
    if (treeNode == NULL) {
        return;
    }

    postOrder(treeNode->left);
    postOrder(treeNode->right);
    cout << treeNode->data << "->";
}

// Inorder traversal
void inOrder(struct Node *treeNode) {
    if (treeNode == NULL) {
        return;
    }

    inOrder(treeNode->left);
    cout << treeNode->data << "->";
    inOrder(treeNode->right);
}
void treeTraversal() {
    char order;
    auto *root = new Node(1);
    root->left = new Node(12);
    root->right = new Node(9);
    root->left->left = new Node(5);
    root->left->right = new Node(6);
    root->right->left = new Node(10);
    root->right->right = new Node(2);
    cout << "            root: " << root->data << endl;
    cout << "    L: " << root->left->data << "            R: " << root->right->data << endl;
    cout << "L: " << root->left->left->data << "    R: " << root->left->right->data;
    cout << "    L: " << root->right->left->data << "    R: " << root->right->right->data << endl;
    cout << "a. preorder\nb. inorder\nc. postorder\nd. try all\n";
    cin >> order;
    switch (order) {
        case 'a':
            cout << "Preorder traversal\n";
            preOrder(root);
            break;
        case 'b':
            cout << "Inorder traversal\n";
            inOrder(root);
            break;
        case 'c':
            cout << "Postorder traversal\n";
            postOrder(root);
            break;
        case 'd':
            cout << "Preorder traversal\n";
            preOrder(root);
            cout << "\nInorder traversal\n";
            inOrder(root);
            cout << "\nPostorder traversal\n";
            postOrder(root);
            break;
        default:
            cout << "invalid choice\n";
            break;
    }
    cout << endl << endl;
}