/**
 * @class BinaryTreeNode
 *
 * @file binarytreenode.cpp
 *
 * @brief Binary tree node.
 *
 * The binary tree node class implementation.
 *
 * @created Dec 21, 2012
 * @author Vassilis S. Moustakas <vsmoustakas@gmail.com>
 */

#include "binarytreenode.h"

BinaryTreeNode::BinaryTreeNode()
{
    m_key = 0;
    m_parent = 0;
    m_left = 0;
    m_right = 0;
}

BinaryTreeNode::BinaryTreeNode(int key)
{
    m_key = key;
    m_parent = 0;
    m_left = 0;
    m_right = 0;
}

BinaryTreeNode::BinaryTreeNode(
        int key,
        BinaryTreeNode* parent,
        BinaryTreeNode* left,
        BinaryTreeNode* right
        )
{
    m_key = key;
    m_parent = parent;
    m_left = left;
    m_right = right;
}

BinaryTreeNode::~BinaryTreeNode()
{
}

