#include <iostream>
#include "treeTraverse.h"
#include "avlTree.h"
#include "sort.h"
using namespace std;


int main() {
    cout << "what is your topic?" << endl;
    char choice = 'n';
    do {
        cout << "\n\na. tree traversal    b. AVL Tree    c. sorting algorithms    x. exit\n";
        cin >> choice;
        switch (choice) {
            case 'a':
                treeTraversal();
                break;
            case 'b':
                avlMenu();
                break;
            case 'c':
                sort();
                break;
            default:
                cout << "invalid choice\n";
                break;
        }
    } while (choice != 'x');

    return 0;
}



