//
// Created by kaloyyyyy on 26/04/2022.
//
using namespace std;
#include <iostream>
#include <cstring>
#include "avlTree.h"


// Calculate height
int height(avlNode *N) {
    if (N == NULL) {
        return 0;
    }
    return N->height;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

// New node creation
avlNode *newNode(int key) {
    avlNode *node = new avlNode();
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return (node);
}

// Rotate right
avlNode *rightRotate(avlNode *y) {
    avlNode *x = y->left;
    avlNode *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left),
                    height(y->right)) +
                1;
    x->height = max(height(x->left),
                    height(x->right)) +
                1;
    cout << "right rotate\n";
    cout << "root:\n";
    if (x != nullptr) {
        cout << x->key << endl;
        printTree(x->left, "  ", false);
        printTree(x->right, "  ", true);
    }
    return x;
}

// Rotate left
avlNode *leftRotate(avlNode *x) {
    avlNode *y = x->right;
    avlNode *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left),
                    height(x->right)) +
                1;
    y->height = max(height(y->left),
                    height(y->right)) +
                1;
    cout << "left rotate\n";
    cout << "root:\n";
    if (y != nullptr) {
        cout << y->key << endl;
        printTree(y->left, "  ", false);
        printTree(y->right, "  ", true);
    }
    return y;
}

// Get the balance factor of each node
int getBalanceFactor(avlNode *N) {
    if (N == NULL) {
        return 0;
    }
    return height(N->left) -
           height(N->right);
}

// Insert a node
avlNode *insertNode(avlNode *node, int key) {
    // Find the correct postion and insert the node
    if (node == NULL) {
        return (newNode(key));
    }
    if (key < node->key) {
        node->left = insertNode(node->left, key);
    } else if (key > node->key) {
        node->right = insertNode(node->right, key);
    } else {
        return node;
    }

    // Update the balance factor of each node and
    // balance the tree
    node->height = 1 + max(height(node->left),
                           height(node->right));
    int balanceFactor = getBalanceFactor(node);
    if (balanceFactor > 1) {
        if (key < node->left->key) {
            return rightRotate(node);
        } else if (key > node->left->key) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
    }
    if (balanceFactor < -1) {
        if (key > node->right->key) {
            return leftRotate(node);
        } else if (key < node->right->key) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
    }
    return node;
}

// Node with minimum value
avlNode *nodeWithMimumValue(avlNode *node) {
    avlNode *current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Delete a node
avlNode *deleteNode(avlNode *root, int key) {
    // Find the node and delete it
    cout << root->key << " and " << key << endl;
    if (root == NULL) {
        return root;
    }
    if (key < root->key) {
        cout << "traverse left\n";
        cout << root->key << endl;
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        cout << "traverse right\n";
        cout << root->key << endl;
        root->right = deleteNode(root->right, key);
    } else {
        if ((root->left == NULL) || (root->right == NULL)) {
            cout << "if ((root->left == NULL) || (root->right == NULL))\n";
            avlNode *temp = root->left ? root->left : root->right;
            cout << "avlNode *temp = root->left ? root->left : root->right;\n";
            if (temp == NULL) {
                cout << "temp is null\n";
                temp = root;
                root = NULL;
            } else {
                cout << "root not empty..." << root->key;
                *root = *temp;
                cout << "\nroot = temp..." << root->key << endl;
            }
            free(temp);
        } else {
            avlNode *temp = nodeWithMimumValue(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right,
                                     temp->key);
        }
    }

    if (root == NULL) {
        return root;
    }

    // Update the balance factor of each node and
    // balance the tree
    root->height = 1 + max(height(root->left),
                           height(root->right));
    int balanceFactor = getBalanceFactor(root);
    if (balanceFactor > 1) {
        if (getBalanceFactor(root->left) >= 0) {
            cout << "going right rotate\n";
            return rightRotate(root);
        } else {
            root->left = leftRotate(root->left);
            cout << "left rotate then going right rotate\n";
            return rightRotate(root);
        }
    }
    if (balanceFactor < -1) {
        if (getBalanceFactor(root->right) <= 0) {
            cout << "going left rotate\n";
            return leftRotate(root);
        } else {
            root->right = rightRotate(root->right);
            cout << "going left rotate then right\n";
            return leftRotate(root);
        }
    }
    return root;
}

// Print the tree
void printTree(avlNode *root, string indent, bool last) {
    if (root != nullptr) {
        cout << indent;
        if (last) {
            cout << "R----";
            indent += "   ";
        } else {
            cout << "L----";
            indent += "|  ";
        }
        cout << root->key << endl;
        printTree(root->left, indent, false);
        printTree(root->right, indent, true);
    }
}

void avlMenu() {
    char menuChoice = 'y';
    avlNode *root = NULL;
    do {
        cout << "a. add node   b. print tree   c. delete node    x. exit\n";
        cin >> menuChoice;
        switch (menuChoice) {
            case 'a':
                int add;
                cin >> add;
                root = insertNode(root, add);
                cout << "node added\n";
                break;
            case 'b':
                cout << "root:\n";
                if (root != nullptr) {
                    cout << root->key << endl;
                    printTree(root->left, "  ", false);
                    printTree(root->right, "  ", true);
                }
                break;
            case 'c':
                cout << "root:\n";
                if (root != nullptr) {
                    cout << root->key << endl;
                    printTree(root->left, "  ", false);
                    printTree(root->right, "  ", true);
                }
                cout << "choose a node to delete\n";
                int del;
                cin >> del;
                root = deleteNode(root, del);
                cout << "After deleting " << endl;
                cout << "root:\n";
                if (root != nullptr) {
                    cout << root->key << endl;
                    printTree(root->left, "  ", false);
                    printTree(root->right, "  ", true);
                }
        }
    } while (menuChoice != 'x');
}