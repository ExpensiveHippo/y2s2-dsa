#pragma once

#include "BinaryNode.hpp"

class BST {
private:
    BinaryNode* root;

public:
    // constructor
    BST();

    // search an item in the binary search tree
    BinaryNode* search(ItemType target);
    BinaryNode* search(BinaryNode* root, ItemType target);

    // insert an item to the binary search tree
    void insert(ItemType item);
    void insert(BinaryNode*& root, ItemType item);

    // delete an item from the binary search tree
    void remove(ItemType target);
    void remove(BinaryNode*& root, ItemType target);

    // traverse the binary search tree in inorder
    void inOrder();
    void inOrder(BinaryNode* t);

    // traverse the binary search tree in preorder
    void preOrder();
    void preOrder(BinaryNode* t);

    // traverse the binary search tree in postorder
    void postOrder();
    void postOrder(BinaryNode* t);

    // check if the binary search tree is empty
    bool isEmpty();

    // ----------------- to be implemented ------------------
    // count the number of nodes in the binary search tree
    int countNodes();
    int countNodes(BinaryNode* t);

    // compute the height of the binary search tree
    int getHeight();
    int getHeight(BinaryNode* t);

    // check if the binary search tree is balanced
    bool isBalanced();
    bool isBalanced(BinaryNode* t);
};
