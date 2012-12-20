/*
 * singlylinkedlist.cpp
 *
 *  Created on: Dec 11, 2012
 *      Author: billy
 */

#include <iostream>

#include "singlylinkedlist.h"

SinglyLinkedList::SinglyLinkedList()
{
    m_head = 0;
}

SinglyLinkedList::~SinglyLinkedList()
{
}

// -- public methods

void SinglyLinkedList::prepend(SinglyLinkedListNode* node)
{
    node->set_next(m_head);
    m_head = node;
}

void SinglyLinkedList::append(SinglyLinkedListNode* node)
{
    if (m_head == 0) {
        node->set_next(0);
        m_head = node;
        return;
    }

    SinglyLinkedListNode* lln = m_head;

    while (lln != 0) {
        if (lln->next() == 0) {
            break;
        }
        lln = lln->next();
    }

    node->set_next(0);
    lln->set_next(node);
}

SinglyLinkedListNode* SinglyLinkedList::find(int data)
{
    SinglyLinkedListNode* lln = m_head;

    while (lln != 0) {
        if (lln->data() == data)
            break;

        lln = lln->next();
    }

    return lln;
}

bool SinglyLinkedList::remove(int data)
{
    SinglyLinkedListNode* prev = 0;
    SinglyLinkedListNode* curr = m_head;

    while (curr != 0) {
        if (curr->data() == data) {
            if (prev != 0) {
                // Bypass the node to be deleted.
                prev->set_next(curr->next());
            }
            else {
                // The node you delete is the head, so reset the head pointer
                // to the next element...
                m_head = curr->next();
            }
            // Delete the pointer to the node to be deleted.
            delete curr;
            return true;
        }
        prev = curr;
        curr = curr->next();
    }

    return false;
}

void SinglyLinkedList::clear()
{
    SinglyLinkedListNode* curr = m_head;
    SinglyLinkedListNode* next = 0;

    while (curr != 0) {
        next = curr->next();
        delete curr;
        curr = next;
    }

    m_head = 0;
}

void SinglyLinkedList::revert()
{
    SinglyLinkedListNode* prev = 0;
    SinglyLinkedListNode* curr = m_head;
    SinglyLinkedListNode* next = 0;

    if (curr == 0 || curr->next() == 0)
        return;

    while (curr != 0) {
        next = curr->next();
        curr->set_next(prev);
        prev = curr;
        curr = next;
    }

    m_head = prev;
}

void SinglyLinkedList::sort()
{
    if (m_head == 0 || m_head->next() == 0)
        return;

    SinglyLinkedListNode* prev = 0;
    SinglyLinkedListNode* curr = m_head;
    SinglyLinkedListNode* next = curr->next();

    SinglyLinkedListNode* first = 0;
    SinglyLinkedListNode* second = 0;
    SinglyLinkedListNode* third = 0;

    while (curr != 0) {
        first = prev;
        second = curr;
        third = next;

        if (curr->data() > next->data()) {
            curr->set_next(next->next());
            third = curr;
            next->set_next(curr);
            second = next;
            if (prev != 0)
                prev->set_next(next);
        }

        if (third->next() == 0)
            break;


        prev = second;
        curr = third;
        next = third->next();
    }
}

void SinglyLinkedList::print()
{
    SinglyLinkedListNode* lln = m_head;
    std::cout << "HEAD -> ";

    while (lln != 0) {
        std::cout << "| " << lln->data() << " | -> ";
        lln = lln->next();
    }

    std::cout << "NULL" << std::endl;
}
