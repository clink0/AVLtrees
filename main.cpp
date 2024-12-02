/******************************************************
*                                                     *
*                CE-223 Final Project:                *
*               AVL Tree Implementation               *
*                                                     *
*        Jett Fuller, Gavin Wakefield, Luke Bray      *
*                                                     *
******************************************************/

#include "AVL.h"
#include <iostream>
using namespace std;


int main() {
    AVL tree;

    int elements[] = {15, 10, 20, 8, 12, 17, 25, 6, 11, 14, 16, 18, 22, 27, 5, 9, 13, 19, 21, 23, 26, 28, 7, 24, 29};
    cout << "Inserting elements: ";
    for (int elem : elements) {
        cout << elem << " ";
        tree.insert(elem);
    }
    cout << endl;


    cout << "Inorder traversal after inserts: ";
    tree.printInorder();

    int searchElements[] = {14, 7, 19, 27, 22, 10, 5, 24, 29, 13};
    for (int elem : searchElements) {
        tree.search(elem);
        cout << "Inorder traversal after searching " << elem << ": ";
        tree.printInorder();
    }

    cout << "Deleting elements: ";
    for (int elem : elements) {
        cout << elem << " ";
        tree.deleteKey(elem);
        cout << "Inorder traversal after deleting " << elem << ": ";
        tree.printInorder();
    }
    cout << endl;

    return 0;
}
