//
// Created by kaloyyyyy on 26/04/2022.
//

#ifndef GROUPREPORTING_TREETRAVERSE_H
#define GROUPREPORTING_TREETRAVERSE_H

struct Node {
    int data;
    struct Node *left, *right;

    explicit Node(int data) {
        this->data = data;
        left = right = nullptr;
    }
};

void preOrder(Node *treeNode);
void inOrder(Node *treeNode);
void postOrder(Node *treeNode);
void treeTraversal();

#endif //GROUPREPORTING_TREETRAVERSE_H
