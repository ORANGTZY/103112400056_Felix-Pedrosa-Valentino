#include <iostream>
#include "bstree.h"
using namespace std;

int main() {
    cout << "Hello World!" << endl;
    address root = Nil;

    // Insert data
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 7);
    insertNode(root, 2);
    insertNode(root, 5);
    insertNode(root, 1);
    insertNode(root, 3);

    cout << "PreOrder    : ";
    printPreorder(root);
    cout << endl;

    cout << "PostOrder   : ";
    printPostorder(root);
    cout << endl;

    return 0;
}