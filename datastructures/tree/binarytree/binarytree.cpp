/**
 * @class BinaryTree
 *
 * @file binarytree.cpp
 *
 * @brief Binary tree.
 *
 * The binary tree class implementation.
 *
 * @created Dec 21, 2012
 * @author Vassilis S. Moustakas <vsmoustakas@gmail.com>
 */
#include "binarytree.h"

#include <iostream>
#include <queue>

BinaryTree::BinaryTree()
{
    m_root = 0;
}

BinaryTree::BinaryTree(BinaryTreeNode* root)
{
    m_root = root;
}

BinaryTree::~BinaryTree()
{
    destroy(m_root);
}

// -- getter methods
// -- setter methods
// -- public methods

void BinaryTree::destroy(BinaryTreeNode* root)
{
    if (root != 0) {
        destroy(root->left());
        destroy(root->right());
        delete root;
    }
}

void BinaryTree::insert(BinaryTreeNode* node)
{
    BinaryTreeNode* parent = 0;
    BinaryTreeNode* curr = m_root;

    while (curr != 0) {
        parent = curr;
        if (node->key() < curr->key())
            curr = curr->left();
        else
            curr = curr->right();
    }

    node->set_parent(parent);

    if (parent == 0) {
        // Tree was empty.
        m_root = node;
    }
    else {
        if (node->key() < parent->key())
            parent->set_left(node);
        else
            parent->set_right(node);
    }
}

void BinaryTree::remove(BinaryTreeNode* node)
{
    BinaryTreeNode* splice = 0;
    BinaryTreeNode* curr = 0;

    // Determine the spliced out node.
    if (node->left() == 0 || node->right() == 0) {
        // The node to be removed has at most 1 child...
        splice = node;
    }
    else {
        // ...else, node to be removed has 2 children.
        splice = successor_inorder(node);
    }

    // Determine curr node. Set to the non-NIL child of splice.
    // Set to NIL if splice has no children.
    if (splice->left() != 0)
        curr = splice->left();
    else
        curr = splice->right();

    if (curr != 0)
        curr->set_parent(splice->parent());

    if (splice->parent() == 0)
        m_root = curr;
    else {
        if (splice == (splice->parent())->left())
            (splice->parent())->set_left(curr);
        else
            (splice->parent())->set_right(curr);
    }

    // If the successor of the node was the one spliced out, copy its key
    // and any satellite data to node.
    if (splice != node)
        node->set_key(splice->key());

    // Check that the splice node is actually deleted and not the node given
    // as an argument to the function since some times splice != node.
    delete splice;
}

BinaryTreeNode* BinaryTree::search_recursive(BinaryTreeNode* root, int key)
{
    if (root == 0 || root->key() == key)
        return root;

    if (root->key() > key)
        return search_recursive(root->left(), key);
    else
        return search_recursive(root->right(), key);
}

BinaryTreeNode* BinaryTree::search_iterative(BinaryTreeNode* root, int key)
{
    BinaryTreeNode* node = root;

    while (node != 0 && node->key() != key) {
        if (node->key() > key)
            node = node->left();
        else
            node = node->right();
    }

    return node;
}

BinaryTreeNode* BinaryTree::minimum(BinaryTreeNode* root)
{
    if (root == 0)
        return 0;

    BinaryTreeNode* node = root;

    while (node->left() != 0)
        node = node->left();

    return node;
}

BinaryTreeNode* BinaryTree::maximum(BinaryTreeNode* root)
{
    if (root == 0)
        return 0;

    BinaryTreeNode* node = root;

    while (node->right() != 0)
        node = node->right();

    return node;
}

BinaryTreeNode* BinaryTree::successor_inorder(BinaryTreeNode* node)
{
    BinaryTreeNode* successor = 0;
    BinaryTreeNode* curr = node;

    // If the right subtree of the node is non-empty...
    if (node->right() != 0) {
        // ...the successor of the node, is the leftmost node
        // in the right subtree.
        successor = minimum(node->right());
    }
    else {
        // To find the successor if the right subtree of the node is empty, we
        // simply go up the tree from the given node until we encounter a node
        // that is the left child of its parent.
        successor = curr->parent();
        while (successor != 0 && curr == successor->right()) {
            curr = successor;
            successor = successor->parent();
        }
    }

    return successor;
}

BinaryTreeNode* BinaryTree::predecessor_inorder(BinaryTreeNode* node)
{
    BinaryTreeNode* predecessor = 0;
    BinaryTreeNode* curr = node;

    // If the left subtree of the node is non-empty...
    if (node->left() != 0) {
        // ...the predecessor of the node, is the rightmost node
        // in left subtree.
        predecessor = maximum(node->left());
    }
    else {
        // To find the predecessor if the left subtree of the node is empty, we
        // simply go up the tree for the given node until we encounter the
        // closest ancestor such that the given node is descended from the
        // right child of that predecessor.
        predecessor = curr->parent();
        while (predecessor != 0 && curr == predecessor->left()) {
            curr = predecessor;
            predecessor = predecessor->parent();
        }
    }

    return predecessor;
}

void BinaryTree::dft_preorder(BinaryTreeNode* root)
{
    if (root != 0) {
        std::cout << root->key() << std::endl;
        dft_preorder(root->left());
        dft_preorder(root->right());
    }
}

void BinaryTree::dft_inorder(BinaryTreeNode* root)
{
   if (root != 0) {
       dft_inorder(root->left());
       std::cout << root->key() << std::endl;
       dft_inorder(root->right());
   }
}

void BinaryTree::dft_postorder(BinaryTreeNode* root)
{
    if (root != 0) {
        dft_postorder(root->left());
        dft_postorder(root->right());
        std::cout << root->key() << std::endl;
    }
}

void BinaryTree::bft(BinaryTreeNode* root)
{
    // Create a queue.
    std::queue<BinaryTreeNode*> q;

    if (root != 0)
        q.push(root);

    while (!q.empty()) {
        // Dequeue a node from the front.
        BinaryTreeNode* node = q.front();
        std::cout << node->key() << std::endl;

        // Enqueue the left child.
        if (node->left() != 0)
            q.push(node->left());

        // Enqueue the right child.
        if (node->right() != 0)
            q.push(node->right());

        // Pop the visited node.
        q.pop();
    }
}
