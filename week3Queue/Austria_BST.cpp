#include <iostream>
using namespace std;

struct node {
    int key;
    struct node *left, *right;
};

// Create a node
node *newNode(int item) {
    node *temp = new node();
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

void inorder(node *root);
void searchNode(node *root, int find);
struct node *insert(node *node, int key);
struct node *minValueNode(node *node);
struct node *deleteNode(node *root, int key);

// Driver code
int main() {
    struct node *root = NULL;
    int key;
    char choice = 'i';
    cout << "Binary Search Tree\n\n";
    do {
        cout << "a.insert\nb.delete\nc.search\nd.exit\n";
        cin >> choice;
        switch (choice) {
            case 'a':
                cout << "enter key to insert: \n";
                cin >> key;
                root = insert(root, key);
                cout << "BST inorder:\n";
                inorder(root);
                cout << endl;
                break;
            case 'b':
                cout << "enter key to delete: \n";
                cin >> key;
                root = deleteNode(root, key);
                cout << "BST inorder:\n";
                inorder(root);
                cout << endl;
                break;
            case 'c':
                cout << "enter key to search\n";
                cin >> key;
                searchNode(root, key);
                break;
            default:
                cout << "enter a valid choice\n";
                break;
        }
    } while (choice != 'd');
}

// Inorder Traversal
void inorder(node *root) {
    if (root != NULL) {
        // Traverse left
        inorder(root->left);
        // Traverse root
        cout << root->key << " -> ";
        // Traverse right
        inorder(root->right);
    }
}

// Inorder search
void searchNode(node *root, int find) {
    if (root != NULL) {
        // Traverse left
        searchNode(root->left, find);
        // Traverse root
        if (root->key == find) {
            cout << "Searched: " << root->key << endl;
            return;
        }// Traverse right
        searchNode(root->right, find);
    }
}

// Insert a node
struct node *insert(node *node, int key) {
    // Return a new node if the tree is empty
    if (node == NULL) { return newNode(key); }
    // Traverse to the right place and insert the node
    if (key < node->key) {
        node->left = insert(node->left, key);
    } else {
        node->right = insert(node->right, key);
    }

    return node;
}

// Find the inorder successor
struct node *minValueNode(node *node) {
    struct node *current = node;
    // Find the leftmost leaf
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Deleting a node
struct node *deleteNode(node *root, int key) {
    // Return if the tree is empty
    if (root == NULL) { return root; }
    // Find the node to be deleted
    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {// If the node is with only one child or no child
        if (root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        // If the node has two children
        struct node *temp = minValueNode(root->right);
        // Place the inorder successor in position of the node to be deleted
        root->key = temp->key;
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

