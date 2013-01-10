/**
 * @class SinglyLinkedListNode
 *
 * @file singlylinkedlistnode.cpp
 *
 * @brief Singly linked list node class implementation.
 *
 * @created Dec 11, 2012
 * @author Vassilis S. Moustakas <vsmoustakas@gmail.com>
 */

#include "singlylinkedlistnode.h"

SinglyLinkedListNode::SinglyLinkedListNode() {
    m_data = 0;
    m_next = 0;
}

SinglyLinkedListNode::SinglyLinkedListNode(int data) {
    m_data = data;
    m_next = 0;
}

SinglyLinkedListNode::SinglyLinkedListNode(int data, SinglyLinkedListNode* next)
{
    m_data = data;
    m_next = next;
}

SinglyLinkedListNode::~SinglyLinkedListNode() {
}

// -- getter methods
// -- setter methods
// -- public methods
