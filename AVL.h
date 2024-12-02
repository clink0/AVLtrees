/******************************************************
*                                                     *
*                CE-223 Final Project:                *
*               AVL Tree Implementation               *
*                                                     *
*        Jett Fuller, Gavin Wakefield, Luke Bray      *
*                                                     *
******************************************************/

#ifndef AVL_H
#define AVL_H

struct Node {
    int key;
    Node* left;
    Node* right;
    int height;

    Node(int k) : key(k), left(nullptr), right(nullptr), height(1) {}
};

class AVL {
private:
    Node* root;

    int height(Node* n);
    int balanceFactor(Node* n);
    void updateHeight(Node* n);

    Node* rotateRight(Node* y);
    Node* rotateLeft(Node* x);

    Node* balance(Node* n);

    Node* insert(Node* n, int key);
    Node* deleteNode(Node* n, int key);
    Node* minValueNode(Node* n);

    Node* search(Node* n, int key);
    void inorder(Node* n);

public:
    AVL();
    ~AVL();

    void insert(int key);
    void deleteKey(int key);
    Node* search(int key);
    void printInorder();

    int getRootKey() const;
};




#endif //AVL_H



