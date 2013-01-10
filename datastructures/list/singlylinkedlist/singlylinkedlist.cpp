/**
 * @class SinglyLinkedList
 *
 * @file singlylinkedlist.cpp
 *
 * @brief Singly linked list class implementation.
 *
 * @created Dec 11, 2012
 * @author Vassilis S. Moustakas <vsmoustakas@gmail.com>
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

void SinglyLinkedList::clear()
{
    while (m_head != 0) {
        SinglyLinkedListNode* del = m_head;
        m_head = del->next();
        delete del;
    }
}

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

SinglyLinkedListNode* SinglyLinkedList::find_iterative(int data)
{
    SinglyLinkedListNode* lln = m_head;

    while (lln != 0) {
        if (lln->data() == data)
            break;

        lln = lln->next();
    }

    return lln;
}

SinglyLinkedListNode* SinglyLinkedList::find_recursive(SinglyLinkedListNode* head, int data)
{
    if (head == 0) {
        return 0;
    }
    else if (head->data() == data) {
        return head;
    }
    else {
        return find_recursive(head->next(), data);
    }
}

SinglyLinkedListNode* SinglyLinkedList::predecessor_iterative(int data)
{
    SinglyLinkedListNode* lln = m_head;
    SinglyLinkedListNode* prev = 0;

    bool found = false;
    while (lln != 0) {
        if (lln->data() == data) {
            found = true;
            break;
        }
        prev = lln;
        lln = lln->next();
    }

    if (found) {
        return prev;
    }
    else{
        return 0;
    }
}

SinglyLinkedListNode* SinglyLinkedList::predecessor_recursive(SinglyLinkedListNode* head, int data)
{
    if ( (head == 0) || (head->next() == 0) ) {
        return 0;
    }

    if ((head->next())->data() == data ) {
        return head;
    }
    else {
        return (predecessor_recursive(head->next(), data));
    }
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

    bool swap = false;
    do {
        SinglyLinkedListNode* prev = 0;
        SinglyLinkedListNode* curr = m_head;
        SinglyLinkedListNode* next = m_head->next();
        swap = false;
        while (next != 0) {
            if (curr->data() > next->data()) {
                swap = true;
                curr->set_next(next->next());
                next->set_next(curr);
                if (prev != 0) {
                    prev->set_next(next);
                }
                else {
                    m_head = next;
                }

                SinglyLinkedListNode* tmp = curr;
                curr = next;
                next = tmp;
            }

            prev = curr;
            curr = next;
            next = next->next();

        }
    } while (swap);
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
