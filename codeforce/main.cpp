// Recursive CPP program for level
// order traversal of Binary Tree
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data,
pointer to left child
and a pointer to right child */
class node {
public:
    int data;
    node *left, *right;
};

/* Function prototypes */
void printCurrentLevel(node* root, int level, vector<int>*x);
int height(node* node);
node* newNode(int data);

/* Function to print level
order traversal a tree*/
void printLevelOrder(node* root, vector<int>*x)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        printCurrentLevel(root, i, x);
}

/* Print nodes at a current level */
void printCurrentLevel(node* root, int level, vector<int>*x)
{
    if (root == NULL)
        return;
    if (level == 1) {
        x->push_back(root->data);
        cout << root->data << " ";
    }
    else if (level > 1) {
        printCurrentLevel(root->left, level - 1, x);
        printCurrentLevel(root->right, level - 1, x);
    }
}

/* Compute the "height" of a tree -- the number of
	nodes along the longest path from the root node
	down to the farthest leaf node.*/
int height(node* node)
{
    if (node == NULL)
        return 0;
    else {
        /* compute the height of each subtree */
        int lheight = height(node->left);
        int rheight = height(node->right);

        /* use the larger one */
        if (lheight > rheight) {
            return (lheight + 1);
        }
        else {
            return (rheight + 1);
        }
    }
}

/* Helper function that allocates
a new node with the given data and
NULL left and right pointers. */
node* newNode(int data)
{
    node* Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;

    return (Node);
}

/* Driver code*/
int main()
{
    vector<int>x;
    node* root = newNode(5);
    root->left = newNode(2);
    root->right = newNode(6);
    root->left->left = newNode(4);
    root->left->right = newNode(8);
    root->right->left = newNode(4);
    root->right->right = newNode(5);
    root->left->left->left = newNode(4);
    root->right->left->left = newNode(4);
    root->left->left->right = newNode(5);
    root->right->left->right = newNode(5);


    cout << "Level Order traversal of binary tree is \n";
    printLevelOrder(root,&x);
    int h = 0, num = 1;
    int size = x.size();
    cout<<"size "<< size << endl;
    for (h; num <size; h++) {
        cout<<"yes ";
        num*=2;
    }
    h = height(root);
    cout<<"h "<<h<<endl;
    int index;
    index = pow(2, h-1) - 1;
    cout<<index<<endl;
    int sum=0;
    for (int i = index; i < size; i++) {
        sum+=x[i];
    }
    cout<<sum;
    return 0;
}

// This code is contributed by rathbhupendra
