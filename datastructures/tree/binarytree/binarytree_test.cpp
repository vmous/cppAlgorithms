/**
 * @file binarytree_test.cpp
 *
 * @brief Test unit for the binary tree class.
 *
 * @see binarytree.h binarytree.cpp binarytreenode.h
 * binarytreenode.cpp
 *
 * @created Dec 21, 2012
 * @author Vassilis S. Moustakas <vsmoustakas@gmail.com>
 */

#include "binarytree.h"
#include "binarytreenode.h"

#include <iostream>

BinaryTree* initialize();
void finalize(BinaryTree* tree);

void test_destroy();
void test_insert_recursive();
void test_insert_iterative();
void test_remove();
void test_search_recursive();
void test_search_iterative();
void test_minimum();
void test_maximum();
void test_successor_inorder();
void test_predecessor_inorder();
void test_dft_preorder();
void test_dft_inorder();
void test_dft_postorder();
void test_bft();

int main (int argc, char** argv)
{

//    test_destroy();
//    test_insert_recursive();
//    test_insert_iterative();
//    test_remove();
//    test_search_recursive();
//    test_search_iterative();
//    test_minimum();
//    test_maximum();
    test_successor_inorder();
//    test_predecessor_inorder();
//    test_dft_preorder();
//    test_dft_inorder();
//    test_dft_postorder();
//    test_bft();


    return 0;
}

BinaryTree* initialize()
{
    BinaryTreeNode* _100 = new BinaryTreeNode(100);
    BinaryTreeNode* _50 = new BinaryTreeNode(50);
    BinaryTreeNode* _150 = new BinaryTreeNode(150);
    BinaryTreeNode* _25 = new BinaryTreeNode(25);
    BinaryTreeNode* _75 = new BinaryTreeNode(75);
    BinaryTreeNode* _125 = new BinaryTreeNode(125);
    BinaryTreeNode* _175 = new BinaryTreeNode(175);
    BinaryTreeNode* _110 = new BinaryTreeNode(110);

//    bst = new BinaryTree();
//    bst->insert_recursive(bst->root_ref(), _100);
//    bst->insert_recursive(bst->root_ref(), _50);
//    bst->insert_recursive(bst->root_ref(), _150);
//    bst->insert_recursive(bst->root_ref(), _25);
//    bst->insert_recursive(bst->root_ref(), _75);
//    bst->insert_recursive(bst->root_ref(), _125);
//    bst->insert_recursive(bst->root_ref(), _175);
//    bst->insert_recursive(bst->root_ref(), _110);

    BinaryTree* bst = new BinaryTree(_100);
    bst->insert_iterative(_50);
    bst->insert_iterative(_150);
    bst->insert_iterative(_25);
    bst->insert_iterative(_75);
    bst->insert_iterative(_125);
    bst->insert_iterative(_175);
    bst->insert_iterative(_110);

    return bst;
}

void finalize(BinaryTree* bst)
{
    bst->destroy(bst->root_ref());
    if(bst->root() == 0) {
        BinaryTree* tmp = bst;
        bst = 0;
        delete tmp;
    }
}

void test_destroy()
{
    BinaryTree* bst;

    std::cout << "Testing destroy existing binary tree." << std::endl;
    bst = initialize();
    bst->destroy(bst->root_ref());

    if(bst->root() == 0) {
        std::cout << "Testing destroy empty binary tree." << std::endl;
        bst->destroy(bst->root_ref());
    }

    finalize(bst);
}

void test_insert_recursive()
{
    BinaryTree* bst;

    std::cout << "Testing recursive insertion." << std::endl;

    BinaryTreeNode* _100 = new BinaryTreeNode(100);
    BinaryTreeNode* _50 = new BinaryTreeNode(50);
    BinaryTreeNode* _150 = new BinaryTreeNode(150);
    BinaryTreeNode* _25 = new BinaryTreeNode(25);
    BinaryTreeNode* _75 = new BinaryTreeNode(75);
    BinaryTreeNode* _125 = new BinaryTreeNode(125);
    BinaryTreeNode* _175 = new BinaryTreeNode(175);
    BinaryTreeNode* _110 = new BinaryTreeNode(110);

    bst = new BinaryTree();
    bst->insert_recursive(bst->root_ref(), _100);
    bst->insert_recursive(bst->root_ref(), _50);
    bst->insert_recursive(bst->root_ref(), _150);
    bst->insert_recursive(bst->root_ref(), _25);
    bst->insert_recursive(bst->root_ref(), _75);
    bst->insert_recursive(bst->root_ref(), _125);
    bst->insert_recursive(bst->root_ref(), _175);
    bst->insert_recursive(bst->root_ref(), _110);

    bst->bft(bst->root());
    std::cout << std::endl;

    finalize(bst);
}

void test_insert_iterative()
{
    BinaryTree* bst;

    std::cout << "Testing iterative insertion." << std::endl;

    BinaryTreeNode* _100 = new BinaryTreeNode(100);
    BinaryTreeNode* _50 = new BinaryTreeNode(50);
    BinaryTreeNode* _150 = new BinaryTreeNode(150);
    BinaryTreeNode* _25 = new BinaryTreeNode(25);
    BinaryTreeNode* _75 = new BinaryTreeNode(75);
    BinaryTreeNode* _125 = new BinaryTreeNode(125);
    BinaryTreeNode* _175 = new BinaryTreeNode(175);
    BinaryTreeNode* _110 = new BinaryTreeNode(110);

    bst = new BinaryTree(_100);
    bst->insert_iterative(_50);
    bst->insert_iterative(_150);
    bst->insert_iterative(_25);
    bst->insert_iterative(_75);
    bst->insert_iterative(_125);
    bst->insert_iterative(_175);
    bst->insert_iterative(_110);

    bst->bft(bst->root());
    std::cout << std::endl;

    finalize(bst);
}

void test_remove()
{
    BinaryTree* bst;

    int key;

    bst = initialize();
    key = 175;
    bst->bft(bst->root());
    std::cout << "Testing remove of key with no children." << std::endl;
    bst->remove(bst->search_recursive(bst->root(), key));
    bst->bft(bst->root());
    std::cout << std::endl;
    finalize(bst);

    bst = initialize();
    key = 125;
    bst->bft(bst->root());
    std::cout << "Testing remove of key with exactly one child." << std::endl;
    bst->remove(bst->search_recursive(bst->root(), key));
    bst->bft(bst->root());
    std::cout << std::endl;
    finalize(bst);

    bst = initialize();
    key = 100;
    bst->bft(bst->root());
    std::cout << "Testing remove of key with no children." << std::endl;
    bst->remove(bst->search_recursive(bst->root(), key));
    bst->bft(bst->root());
    std::cout << std::endl;
    finalize(bst);
}

void test_search_recursive()
{
    BinaryTree* bst = initialize();

    int key;

    key = 100;
    std::cout << "Testing search recursive for key: " << key << ": ";
    if (bst->search_recursive(bst->root(), key) != 0) {
        std::cout << "Found :)" << std::endl;
    }
    else {
        std::cout << "Not found :(" << std::endl;
    }
    std::cout << std::endl;

    key = 25;
    std::cout << "Testing search recursive for key: " << key << ": ";
    if (bst->search_recursive(bst->root(), key) != 0) {
        std::cout << "Found :)" << std::endl;
    }
    else {
        std::cout << "Not found :(" << std::endl;
    }
    std::cout << std::endl;

    key = 175;
    std::cout << "Testing search recursive for key: " << key << ": ";
    if (bst->search_recursive(bst->root(), key) != 0) {
        std::cout << "Found :)" << std::endl;
    }
    else {
        std::cout << "Not found :(" << std::endl;
    }
    std::cout << std::endl;

    key = 69;
    std::cout << "Testing search recursive for key: " << key << ": ";
    if (bst->search_recursive(bst->root(), key) != 0) {
        std::cout << "Found :)" << std::endl;
    }
    else {
        std::cout << "Not found :(" << std::endl;
    }
    std::cout << std::endl;

    finalize(bst);
}

void test_search_iterative()
{
    BinaryTree* bst = initialize();

    int key;

    key = 100;
    std::cout << "Testing search iterative for key: " << key << ": ";
    if (bst->search_iterative(bst->root(), key) != 0) {
        std::cout << "Found :)" << std::endl;
    }
    else {
        std::cout << "Not found :(" << std::endl;
    }
    std::cout << std::endl;

    key = 25;
    std::cout << "Testing search iterative for key: " << key << ": ";
    if (bst->search_iterative(bst->root(), key) != 0) {
        std::cout << "Found :)" << std::endl;
    }
    else {
        std::cout << "Not found :(" << std::endl;
    }
    std::cout << std::endl;

    key = 175;
    std::cout << "Testing search iterative for key: " << key << ": ";
    if (bst->search_iterative(bst->root(), key) != 0) {
        std::cout << "Found :)" << std::endl;
    }
    else {
        std::cout << "Not found :(" << std::endl;
    }
    std::cout << std::endl;

    key = 69;
    std::cout << "Testing search iterative for key: " << key << ": ";
    if (bst->search_iterative(bst->root(), key) != 0) {
        std::cout << "Found :)" << std::endl;
    }
    else {
        std::cout << "Not found :(" << std::endl;
    }
    std::cout << std::endl;

    finalize(bst);
}

void test_minimum()
{
    BinaryTree* bst;

    bst = initialize();
    std::cout << "Testing minimum: ";
    std::cout << bst->minimum(bst->root())->key() << std::endl;
    std::cout << std::endl;
    finalize(bst);
}

void test_maximum()
{
    BinaryTree* bst;

    bst = initialize();
    std::cout << "Testing maximum: ";
    std::cout << bst->maximum(bst->root())->key() << std::endl;
    std::cout << std::endl;
    finalize(bst);
}

void test_successor_inorder()
{
    BinaryTree* bst;

    int key;
    BinaryTreeNode* successor;

    bst = initialize();

    key = 150;
    successor = bst->successor_inorder(bst->search_recursive(bst->root(), key));
    std::cout << "Successor (node with a right sub-tree) " << key << ": ";
    if (successor != 0)
        std::cout << successor->key() << std::endl;
    else
        std::cout << "no successor" << std::endl;
    std::cout << std::endl;

    key = 75;
    successor = bst->successor_inorder(bst->search_recursive(bst->root(), key));
    std::cout << "Successor (node with empty right sub-tree) " << key << ": ";
    if (successor != 0)
        std::cout << successor->key() << std::endl;
    else
        std::cout << "no successor" << std::endl;
    std::cout << std::endl;

    key = 175;
    successor = bst->successor_inorder(bst->search_recursive(bst->root(), key));
    std::cout << "Successor (node with empty right sub-tree with no successor) " << key << ": ";
    if (successor != 0)
        std::cout << successor->key() << std::endl;
    else
        std::cout << "no successor" << std::endl;
    std::cout << std::endl;

    finalize(bst);
}

void test_predecessor_inorder()
{
    BinaryTree* bst;

    int key;
    BinaryTreeNode* predecessor;

    bst = initialize();

    key = 125;
    predecessor = bst->predecessor_inorder(bst->search_recursive(bst->root(), key));
    std::cout << "Predecessor (node with a left sub-tree) " << key << ": ";
    if (predecessor != 0)
        std::cout << predecessor->key() << std::endl;
    else
        std::cout << "no predecessor" << std::endl;
    std::cout << std::endl;

    key = 110;
    predecessor = bst->predecessor_inorder(bst->search_recursive(bst->root(), key));
    std::cout << "Predecessor (node with empty left sub-tree) " << key << ": ";
    if (predecessor != 0)
        std::cout << predecessor->key() << std::endl;
    else
        std::cout << "no predecessor" << std::endl;
    std::cout << std::endl;

    key = 25;
    predecessor = bst->predecessor_inorder(bst->search_recursive(bst->root(), key));
    std::cout << "Predecessor (node with empty left sub-tree with no predecessor) " << key << ": ";
    if (predecessor != 0)
        std::cout << predecessor->key() << std::endl;
    else
        std::cout << "no predecessor" << std::endl;
    std::cout << std::endl;

    finalize(bst);
}

void test_dft_preorder()
{
    BinaryTree* bst;

    bst = initialize();
    std::cout << "Testing preorder depth-first traversal." << std::endl;
    bst->dft_preorder(bst->root());
    std::cout << std::endl;
    finalize(bst);
}

void test_dft_inorder()
{
    BinaryTree* bst;

    bst = initialize();
    std::cout << "Testing inorder depth-first traversal." << std::endl;
    bst->dft_inorder(bst->root());
    std::cout << std::endl;
    finalize(bst);
}

void test_dft_postorder()
{
    BinaryTree* bst;

    bst = initialize();
    std::cout << "Testing postorder depth-first traversal." << std::endl;
    bst->dft_postorder(bst->root());
    std::cout << std::endl;
    finalize(bst);
}

void test_bft()
{
    BinaryTree* bst;

    bst = initialize();
    std::cout << "Testing breadth-first traversal." << std::endl;
    bst->bft(bst->root());
    std::cout << std::endl;
    finalize(bst);
}
