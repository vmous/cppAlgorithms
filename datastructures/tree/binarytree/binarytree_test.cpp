/*
 * binarytree_test.cpp
 *
 *  Created on: Dec 21, 2012
 *      Author: billy
 */

#include "binarytree.h"
#include "binarytreenode.h"

#include <iostream>

BinaryTree* bst;

void init()
{
    BinaryTreeNode* _100 = new BinaryTreeNode(100);
    BinaryTreeNode* _50 = new BinaryTreeNode(50);
    BinaryTreeNode* _150 = new BinaryTreeNode(150);
    BinaryTreeNode* _25 = new BinaryTreeNode(25);
    BinaryTreeNode* _75 = new BinaryTreeNode(75);
    BinaryTreeNode* _125 = new BinaryTreeNode(125);
    BinaryTreeNode* _175 = new BinaryTreeNode(175);
    BinaryTreeNode* _110 = new BinaryTreeNode(110);

    bst = new BinaryTree(_100);
    bst->insert(_50);
    bst->insert(_150);
    bst->insert(_25);
    bst->insert(_75);
    bst->insert(_125);
    bst->insert(_175);
    bst->insert(_110);
}

void test_dft_preorder()
{
    std::cout << "Depth-first traversal, preorder:" << std::endl;
    bst->dft_preorder(bst->root());
    std::cout << std::endl;
}

void test_dft_inorder()
{
    std::cout << "Depth-first traversal, inorder:" << std::endl;
    bst->dft_inorder(bst->root());
    std::cout << std::endl;
}

void test_dft_postorder()
{
    std::cout << "Depth-first traversal, postorder:" << std::endl;
    bst->dft_postorder(bst->root());
    std::cout << std::endl;
}

void test_bft()
{
    std::cout << "Breadth-first traversal:" << std::endl;
    bst->bft(bst->root());
    std::cout << std::endl;
}

void test_insert(int key)
{

}

void test_remove(int key)
{
    std::cout << "Removing node " << key << std::endl;
    bst->remove(bst->search_recursive(bst->root(), key));
}

int main (int argc, char** argv)
{

    init();

    test_bft();

    test_remove(100);

    test_bft();

    return 0;
}
