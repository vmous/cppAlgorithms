/*
 * singlylinkedlistnode.cpp
 *
 *  Created on: Dec 11, 2012
 *      Author: billy
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

