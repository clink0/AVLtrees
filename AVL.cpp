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

AVL::AVL() : root(nullptr) {}

AVL::~AVL() {
    while (root) deleteKey(root->key);
}

int AVL::height(Node* n) {
    return n ? n->height : 0;
}

int AVL::balanceFactor(Node* n) {
    return n ? height(n->left) - height(n->right) : 0;
}

void AVL::updateHeight(Node* n) {
    if (n) {
        n->height = 1 + std::max(height(n->left), height(n->right));
    }
}

Node* AVL::rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

Node* AVL::rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}

Node* AVL::balance(Node* n) {
    if (!n) return n;

    updateHeight(n);

    int balance = balanceFactor(n);

    if (balance > 1) {
        if (balanceFactor(n->left) < 0) {
            n->left = rotateLeft(n->left);
        }
        return rotateRight(n);
    }

    if (balance < -1) {
        if (balanceFactor(n->right) > 0) {
            n->right = rotateRight(n->right);
        }
        return rotateLeft(n);
    }

    return n;
}


Node* AVL::insert(Node* n, int key) {
    if (!n) return new Node(key);

    if (key < n->key) {
        n->left = insert(n->left, key);
    } else if (key > n->key) {
        n->right = insert(n->right, key);
    } else {
        return n; // Duplicate keys are not allowed.
    }

    return balance(n);
}

void AVL::insert(int key) {
    root = insert(root, key);
}

Node* AVL::deleteNode(Node* root, int key) {
    if (!root) return root;

    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        if (!root->left || !root->right) {
            Node* temp = root->left ? root->left : root->right;
            if (!temp) {
                temp = root;
                root = nullptr;
            } else {
                *root = *temp;
            }
            delete temp;
        } else {
            Node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (!root) return root;

    return balance(root);
}

void AVL::deleteKey(int key) {
    root = deleteNode(root, key);
}

// Find the minimum value node in a subtree.
Node* AVL::minValueNode(Node* n) {
    Node* current = n;
    while (current->left) current = current->left;
    return current;
}

// Search for a key and return the node.
Node* AVL::search(Node* n, int key) {
    if (!n || n->key == key) return n;

    if (key < n->key) return search(n->left, key);

    return search(n->right, key);
}

Node* AVL::search(int key) {
    return search(root, key);
}

int AVL::getRootKey() const {
    return root ? root->key : -1;
}

void AVL::inorder(Node* n) {
    if (n) {
        inorder(n->left);
        std::cout << n->key << " ";
        inorder(n->right);
    }
}

void AVL::printInorder() {
    inorder(root);
    std::cout << std::endl;
}
