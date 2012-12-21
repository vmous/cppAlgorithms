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
    m_data = 0;
    m_left = 0;
    m_right = 0;
}

BinaryTreeNode::BinaryTreeNode(int data)
{
    m_data = data;
    m_left = 0;
    m_right = 0;
}

BinaryTreeNode::BinaryTreeNode(int data, BinaryTreeNode* left, BinaryTreeNode* right)
{
    m_data = data;
    m_left = left;
    m_right = right;
}

BinaryTreeNode::~BinaryTreeNode()
{
}

