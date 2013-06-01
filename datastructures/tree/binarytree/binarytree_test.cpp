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
#include <stdlib.h>

BinaryTree<int> * init_tree_std();
void finalize_tree(BinaryTree<int> * tree);

void test_destroy();
void test_copy();
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
void test_dft_preorder_iterative();
void test_dft_inorder();
void test_dft_inorder_iterative();
void test_dft_postorder();
void test_dft_postorder_iterative();
void test_bft();

int main (int argc, char** argv)
{

    test_destroy();
    test_copy();
    test_insert_recursive();
    test_insert_iterative();
    test_remove();
    test_search_recursive();
    test_search_iterative();
    test_minimum();
    test_maximum();
    test_successor_inorder();
    test_predecessor_inorder();
    test_dft_preorder();
    test_dft_preorder_iterative();
    test_dft_inorder();
    test_dft_inorder_iterative();
    test_dft_postorder();
    test_dft_postorder_iterative();
    test_bft();

    return EXIT_SUCCESS;
}

BinaryTree<int> * init_tree_std()
{
    BinaryTreeNode<int> * _100 = new BinaryTreeNode<int>(100);
    BinaryTreeNode<int> * _50 = new BinaryTreeNode<int>(50);
    BinaryTreeNode<int> * _150 = new BinaryTreeNode<int>(150);
    BinaryTreeNode<int> * _25 = new BinaryTreeNode<int>(25);
    BinaryTreeNode<int> * _75 = new BinaryTreeNode<int>(75);
    BinaryTreeNode<int> * _125 = new BinaryTreeNode<int>(125);
    BinaryTreeNode<int> * _175 = new BinaryTreeNode<int>(175);
    BinaryTreeNode<int> * _110 = new BinaryTreeNode<int>(110);

//    bst = new BinaryTree<int>();
//    bst->insert_recursive(bst->root_ref(), _100);
//    bst->insert_recursive(bst->root_ref(), _50);
//    bst->insert_recursive(bst->root_ref(), _150);
//    bst->insert_recursive(bst->root_ref(), _25);
//    bst->insert_recursive(bst->root_ref(), _75);
//    bst->insert_recursive(bst->root_ref(), _125);
//    bst->insert_recursive(bst->root_ref(), _175);
//    bst->insert_recursive(bst->root_ref(), _110);

    BinaryTree<int> * bst = new BinaryTree<int>(_100);
    bst->insert_iterative(_50);
    bst->insert_iterative(_150);
    bst->insert_iterative(_25);
    bst->insert_iterative(_75);
    bst->insert_iterative(_125);
    bst->insert_iterative(_175);
    bst->insert_iterative(_110);

    return bst;
}

void finalize_tree(BinaryTree<int> * bst)
{
    bst->destroy(bst->root_ref());
    if(bst->root() == 0) {
        BinaryTree<int> * tmp = bst;
        bst = 0;
        delete tmp;
    }
}

void test_destroy()
{
    std::cout << "########################################" << std::endl;
    std::cout << __FUNCTION__ << std::endl;
    std::cout << "########################################" << std::endl;

    BinaryTree<int> * bst = init_tree_std();
    bst->bft();

    std::cout << "Testing destroy existing binary tree..." << std::endl;
    bst->destroy(bst->root_ref());
    bst->bft();

    if(bst->root() == 0)
    {
        std::cout << "Testing destroy empty binary tree..." << std::endl;
        bst->destroy(bst->root_ref());
    }

    finalize_tree(bst);
    std::cout << std::endl;
}


void test_copy()
{
    std::cout << "########################################" << std::endl;
    std::cout << __FUNCTION__ << std::endl;
    std::cout << "########################################" << std::endl;


    std::cout << "Master copied:" << std::endl;
    BinaryTree<int> * bst = init_tree_std();
    bst->bft();

    std::cout << "Standard copy before copy:" << std::endl;
    BinaryTree<int> * copy = new BinaryTree<int>();
    copy->bft();

    std::cout << "Standard copy after copy:" << std::endl;
    BinaryTreeNode<int> * foo = bst->copy(bst->root_ref());
    copy->set_root(foo);
    copy->bft();

    finalize_tree(bst);
    finalize_tree(copy);
    std::cout << std::endl;

}

void test_insert_recursive()
{
    std::cout << "########################################" << std::endl;
    std::cout << __FUNCTION__ << std::endl;
    std::cout << "########################################" << std::endl;

    BinaryTree<int> * bst;

    std::cout << "Testing recursive insertion." << std::endl;

    BinaryTreeNode<int> * _100 = new BinaryTreeNode<int>(100);
    BinaryTreeNode<int> * _50 = new BinaryTreeNode<int>(50);
    BinaryTreeNode<int> * _150 = new BinaryTreeNode<int>(150);
    BinaryTreeNode<int> * _25 = new BinaryTreeNode<int>(25);
    BinaryTreeNode<int> * _75 = new BinaryTreeNode<int>(75);
    BinaryTreeNode<int> * _125 = new BinaryTreeNode<int>(125);
    BinaryTreeNode<int> * _175 = new BinaryTreeNode<int>(175);
    BinaryTreeNode<int> * _110 = new BinaryTreeNode<int>(110);

    bst = new BinaryTree<int>();
    bst->insert_recursive(bst->root_ref(), _100);
    bst->insert_recursive(bst->root_ref(), _50);
    bst->insert_recursive(bst->root_ref(), _150);
    bst->insert_recursive(bst->root_ref(), _25);
    bst->insert_recursive(bst->root_ref(), _75);
    bst->insert_recursive(bst->root_ref(), _125);
    bst->insert_recursive(bst->root_ref(), _175);
    bst->insert_recursive(bst->root_ref(), _110);

    bst->bft();

    finalize_tree(bst);
    std::cout << std::endl;
}

void test_insert_iterative()
{
    std::cout << "########################################" << std::endl;
    std::cout << __FUNCTION__ << std::endl;
    std::cout << "########################################" << std::endl;

    BinaryTree<int> * bst;

    std::cout << "Testing iterative insertion." << std::endl;

    BinaryTreeNode<int> * _100 = new BinaryTreeNode<int>(100);
    BinaryTreeNode<int> * _50 = new BinaryTreeNode<int>(50);
    BinaryTreeNode<int> * _150 = new BinaryTreeNode<int>(150);
    BinaryTreeNode<int> * _25 = new BinaryTreeNode<int>(25);
    BinaryTreeNode<int> * _75 = new BinaryTreeNode<int>(75);
    BinaryTreeNode<int> * _125 = new BinaryTreeNode<int>(125);
    BinaryTreeNode<int> * _175 = new BinaryTreeNode<int>(175);
    BinaryTreeNode<int> * _110 = new BinaryTreeNode<int>(110);

    bst = new BinaryTree<int>(_100);
    bst->insert_iterative(_50);
    bst->insert_iterative(_150);
    bst->insert_iterative(_25);
    bst->insert_iterative(_75);
    bst->insert_iterative(_125);
    bst->insert_iterative(_175);
    bst->insert_iterative(_110);

    bst->bft();

    finalize_tree(bst);
    std::cout << std::endl;
}

void test_remove()
{
    std::cout << "########################################" << std::endl;
    std::cout << __FUNCTION__ << std::endl;
    std::cout << "########################################" << std::endl;

    BinaryTree<int> * bst = init_tree_std();
    int key;

    key = 175;
    bst->bft();
    std::cout << "Testing remove of key with no children: " << key << std::endl;
    bst->remove(bst->search_recursive(bst->root(), key));
    bst->bft();
    std::cout << std::endl;
    finalize_tree(bst);

    bst = init_tree_std();
    key = 125;
    bst->bft();
    std::cout << "Testing remove of key with exactly one child: " << key << std::endl;
    bst->remove(bst->search_recursive(bst->root(), key));
    bst->bft();
    std::cout << std::endl;
    finalize_tree(bst);

    bst = init_tree_std();
    key = 100;
    bst->bft();
    std::cout << "Testing remove of key with no children: " << key << std::endl;
    bst->remove(bst->search_recursive(bst->root(), key));
    bst->bft();

    finalize_tree(bst);
    std::cout << std::endl;
}

void test_search_recursive()
{
    std::cout << "########################################" << std::endl;
    std::cout << __FUNCTION__ << std::endl;
    std::cout << "########################################" << std::endl;

    BinaryTree<int> * bst = init_tree_std();
    int key;

    key = 100;
    std::cout << "Testing search recursive for key: " << key << ": ";
    if (bst->search_recursive(bst->root(), key) != 0)
    {
        std::cout << "Found :)" << std::endl;
    }
    else
    {
        std::cout << "Not found :(" << std::endl;
    }
    std::cout << std::endl;

    key = 25;
    std::cout << "Testing search recursive for key: " << key << ": ";
    if (bst->search_recursive(bst->root(), key) != 0)
    {
        std::cout << "Found :)" << std::endl;
    }
    else
    {
        std::cout << "Not found :(" << std::endl;
    }
    std::cout << std::endl;

    key = 175;
    std::cout << "Testing search recursive for key: " << key << ": ";
    if (bst->search_recursive(bst->root(), key) != 0)
    {
        std::cout << "Found :)" << std::endl;
    }
    else
    {
        std::cout << "Not found :(" << std::endl;
    }
    std::cout << std::endl;

    key = 69;
    std::cout << "Testing search recursive for key: " << key << ": ";
    if (bst->search_recursive(bst->root(), key) != 0)
    {
        std::cout << "Found :)" << std::endl;
    }
    else
    {
        std::cout << "Not found :(" << std::endl;
    }

    finalize_tree(bst);
    std::cout << std::endl;
}

void test_search_iterative()
{
    std::cout << "########################################" << std::endl;
    std::cout << __FUNCTION__ << std::endl;
    std::cout << "########################################" << std::endl;

    BinaryTree<int> * bst = init_tree_std();
    int key;

    key = 100;
    std::cout << "Testing search iterative for key: " << key << ": ";
    if (bst->search_iterative(bst->root(), key) != 0)
    {
        std::cout << "Found :)" << std::endl;
    }
    else
    {
        std::cout << "Not found :(" << std::endl;
    }
    std::cout << std::endl;

    key = 25;
    std::cout << "Testing search iterative for key: " << key << ": ";
    if (bst->search_iterative(bst->root(), key) != 0)
    {
        std::cout << "Found :)" << std::endl;
    }
    else
    {
        std::cout << "Not found :(" << std::endl;
    }
    std::cout << std::endl;

    key = 175;
    std::cout << "Testing search iterative for key: " << key << ": ";
    if (bst->search_iterative(bst->root(), key) != 0)
    {
        std::cout << "Found :)" << std::endl;
    }
    else
    {
        std::cout << "Not found :(" << std::endl;
    }
    std::cout << std::endl;

    key = 69;
    std::cout << "Testing search iterative for key: " << key << ": ";
    if (bst->search_iterative(bst->root(), key) != 0)
    {
        std::cout << "Found :)" << std::endl;
    }
    else
    {
        std::cout << "Not found :(" << std::endl;
    }

    finalize_tree(bst);
    std::cout << std::endl;
}

void test_minimum()
{
    std::cout << "########################################" << std::endl;
    std::cout << __FUNCTION__ << std::endl;
    std::cout << "########################################" << std::endl;

    BinaryTree<int> * bst = init_tree_std();

    std::cout << "Testing minimum: ";
    std::cout << bst->minimum(bst->root())->key() << std::endl;

    finalize_tree(bst);
    std::cout << std::endl;
}

void test_maximum()
{
    std::cout << "########################################" << std::endl;
    std::cout << __FUNCTION__ << std::endl;
    std::cout << "########################################" << std::endl;

    BinaryTree<int> * bst = init_tree_std();

    std::cout << "Testing maximum: ";
    std::cout << bst->maximum(bst->root())->key() << std::endl;

    finalize_tree(bst);
    std::cout << std::endl;
}

void test_successor_inorder()
{
    std::cout << "########################################" << std::endl;
    std::cout << __FUNCTION__ << std::endl;
    std::cout << "########################################" << std::endl;

    BinaryTree<int> * bst = init_tree_std();
    int key;
    BinaryTreeNode<int> * successor;

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

    finalize_tree(bst);
    std::cout << std::endl;
}

void test_predecessor_inorder()
{
    std::cout << "########################################" << std::endl;
    std::cout << __FUNCTION__ << std::endl;
    std::cout << "########################################" << std::endl;

    BinaryTree<int> * bst = init_tree_std();
    int key;
    BinaryTreeNode<int> * predecessor;

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

    finalize_tree(bst);
    std::cout << std::endl;
}

void test_dft_preorder()
{
    std::cout << "########################################" << std::endl;
    std::cout << __FUNCTION__ << std::endl;
    std::cout << "########################################" << std::endl;

    BinaryTree<int> * bst = init_tree_std();

    std::cout << "Testing preorder depth-first traversal." << std::endl;
    bst->dft_preorder(bst->root());

    finalize_tree(bst);
    std::cout << std::endl;
}

void test_dft_preorder_iterative()
{
    std::cout << "########################################" << std::endl;
    std::cout << __FUNCTION__ << std::endl;
    std::cout << "########################################" << std::endl;

    BinaryTree<int> * bst = init_tree_std();

    std::cout << "Testing preorder depth-first traversal." << std::endl;
    bst->dft_preorder_iterative();

    finalize_tree(bst);
    std::cout << std::endl;
}

void test_dft_inorder()
{
    std::cout << "########################################" << std::endl;
    std::cout << __FUNCTION__ << std::endl;
    std::cout << "########################################" << std::endl;

    BinaryTree<int> * bst = init_tree_std();

    std::cout << "Testing inorder depth-first traversal." << std::endl;
    bst->dft_inorder(bst->root());

    finalize_tree(bst);
    std::cout << std::endl;
}

void test_dft_inorder_iterative()
{
    std::cout << "########################################" << std::endl;
    std::cout << __FUNCTION__ << std::endl;
    std::cout << "########################################" << std::endl;

    BinaryTree<int> * bst = init_tree_std();

    std::cout << "Testing inorder depth-first traversal." << std::endl;
    bst->dft_inorder_iterative();

    finalize_tree(bst);
    std::cout << std::endl;
}

void test_dft_postorder()
{
    std::cout << "########################################" << std::endl;
    std::cout << __FUNCTION__ << std::endl;
    std::cout << "########################################" << std::endl;

    BinaryTree<int> * bst = init_tree_std();

    std::cout << "Testing postorder depth-first traversal." << std::endl;
    bst->dft_postorder(bst->root());

    finalize_tree(bst);
    std::cout << std::endl;
}

void test_dft_postorder_iterative()
{
    std::cout << "########################################" << std::endl;
    std::cout << __FUNCTION__ << std::endl;
    std::cout << "########################################" << std::endl;

    BinaryTree<int> * bst = init_tree_std();

    std::cout << "Testing postorder depth-first traversal." << std::endl;
    bst->dft_postorder_iterative();

    finalize_tree(bst);
    std::cout << std::endl;
}

void test_bft()
{
    std::cout << "########################################" << std::endl;
    std::cout << __FUNCTION__ << std::endl;
    std::cout << "########################################" << std::endl;

    BinaryTree<int> * bst = init_tree_std();

    std::cout << "Testing breadth-first traversal." << std::endl;
    bst->bft();

    finalize_tree(bst);
    std::cout << std::endl;
}
