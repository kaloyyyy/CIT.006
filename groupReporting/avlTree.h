//
// Created by kaloyyyyy on 26/04/2022.
//

#ifndef GROUPREPORTING_AVLTREE_H
#define GROUPREPORTING_AVLTREE_H
#include <cstring>
using namespace std;
class avlNode {
public:
    int key;
    avlNode *left;
    avlNode *right;
    int height;
};
int max(int a, int b);
int height(avlNode*N);
avlNode *rightRotate(avlNode *y);
avlNode *leftRotate(avlNode *x);
int getBalanceFactor(avlNode *N);
avlNode *insertNode(avlNode *node, int key);
avlNode *nodeWithMimumValue(avlNode *node);
avlNode *deleteNode(avlNode *root, int key);
void printTree(avlNode *root, string indent, bool last);
void avlMenu();

#endif //GROUPREPORTING_AVLTREE_H
