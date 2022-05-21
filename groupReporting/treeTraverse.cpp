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
    auto *root = new Node(49);
    root->left = new Node(28);
    root->right = new Node(83);
    root->left->left = new Node(18);
    root->left->left->left = new Node(11);
    root->left->left->right = new Node(19);

    root->left->right = new Node(40);
    root->left->right->left = new Node(32);
    root->left->right->right = new Node(44);

    root->right->left = new Node(75);
    root->right->left->left = new Node(69);

    root->right->right = new Node(97);
    root->right->right->left = new Node(92);
    root->right->right->right = new Node(99);
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