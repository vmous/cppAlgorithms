/*
 * singlylinkedlist.h
 *
 *  Created on: Dec 11, 2012
 *      Author: billy
 */

#ifndef SINGLYLINKEDLIST_H_
#define SINGLYLINKEDLIST_H_

#include "singlylinkedlistnode.h"

class SinglyLinkedList {
public:
    SinglyLinkedList();
    virtual ~SinglyLinkedList();

    // -- getter methods
    inline SinglyLinkedListNode* head() { return m_head; }

    // -- public methods
    void prepend(SinglyLinkedListNode* node);
    void append(SinglyLinkedListNode* node);
    SinglyLinkedListNode* find(int data);
    void revert();
    void sort();

    void print();
protected:
private:
    SinglyLinkedListNode* m_head;
};

#endif /* SINGLYLINKEDLIST_H_ */
