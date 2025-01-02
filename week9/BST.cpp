#include "BST.hpp"
#include "BinaryNode.hpp"

#include <cmath>
#include <iostream>

BST::BST()
    : root(nullptr)
{
}

BinaryNode* BST::search(ItemType item)
{
    return search(root, item);
}

BinaryNode* BST::search(BinaryNode* node, ItemType item)
{
    if (node == nullptr) {
        return nullptr;
    }

    if (node->item == item) {
        return node;
    }

    if (item < node->item) {
        return search(node->left, item);
    } else {
        return search(node->right, item);
    }
}

void BST::insert(ItemType item)
{
    insert(root, item);
}

void BST::insert(BinaryNode*& node, ItemType item)
{
    if (node == nullptr) {
        BinaryNode* n = new BinaryNode();
        n->item = item;
        n->right = nullptr;
        n->left = nullptr;
        node = n;
        return;
    }

    if (node->item == item) {
        return;
    }

    if (node->item > item) {
        insert(node->left, item);
    } else {
        insert(node->right, item);
    }
}

void BST::remove(ItemType target)
{
    remove(root, target);
}

void BST::remove(BinaryNode*& node, ItemType target)
{
    // not found
    if (node == nullptr) {
        return;
    }

    if (node->item > target) {
        remove(node->left, target);
    } else if (node->item < target) {
        remove(node->right, target);
    } else {
        // if no child, just set to nullptr
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            node = nullptr;
            return;
        }

        BinaryNode* temp = node;

        // if 1 child, set to child
        if (node->left == nullptr) {
            node = node->right;
            delete temp;
        } else if (node->right == nullptr) {
            node = node->left;
            delete temp;
        } else {
            // if 2 children, set to inorder successor (left-most leaf in right subtree)
            // remove successor
            temp = temp->right;
            while (temp->left != nullptr) {
                temp = temp->left;
            }
            node->item = temp->item;
            remove(node->right, temp->item);
        }
    }
}

// left root right
void BST::inOrder()
{
    std::cout << "In Order: ";
    inOrder(root);
    std::cout << "END";
}

void BST::inOrder(BinaryNode* node)
{
    if (node == nullptr) {
        return;
    }
    inOrder(node->left);
    std::cout << node->item << ", ";
    inOrder(node->right);
}

// root left right
void BST::preOrder()
{
    std::cout << "Pre Order: ";
    preOrder(root);
    std::cout << "END";
}

void BST::preOrder(BinaryNode* node)
{
    if (node == nullptr) {
        return;
    }
    std::cout << node->item << ", ";
    preOrder(node->left);
    preOrder(node->right);
}

// left right root
void BST::postOrder()
{
    std::cout << "Post Order: ";
    postOrder(root);
    std::cout << "END";
}

void BST::postOrder(BinaryNode* node)
{
    if (node == nullptr) {
        return;
    }
    postOrder(node->left);
    postOrder(node->right);
    std::cout << node->item << ", ";
}

bool BST::isEmpty()
{
    return root == nullptr;
}

int BST::countNodes()
{
    return countNodes(root);
}

int BST::countNodes(BinaryNode* node)
{
    if (node == nullptr) {
        return 0;
    }

    return 1 + countNodes(node->left) + countNodes(node->right);
}

int BST::getHeight()
{
    return getHeight(root);
}

int BST::getHeight(BinaryNode* node)
{
    if (node == nullptr) {
        // level of a tree with only the root node is 0 -> no nodes == -1
        return -1;
    }

    int left = getHeight(node->left);
    int right = getHeight(node->right);

    return 1 + std::max(left, right);
}

bool BST::isBalanced()
{
    return isBalanced(root);
}

bool BST::isBalanced(BinaryNode* node)
{
    if (node == nullptr) {
        return true;
    }

    if (!isBalanced(node->left) || !isBalanced(node->right)) {
        return false;
    }

    int left = getHeight(node->left);
    int right = getHeight(node->right);

    return std::abs(left - right) <= 1;
}
