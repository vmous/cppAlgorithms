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

    /**
     * Remove the first element you find with the given data.
     *
     * @param data The data to search for.
     *
     * @return <code>true</code> if the deletion was successful;
     *         <code>false</code> otherwise.
     */
    bool remove(int data);

    /**
     * Clear the list.
     */
    void clear();

    void revert();
    void sort();

    void print();
protected:
private:
    SinglyLinkedListNode* m_head;
};

#endif /* SINGLYLINKEDLIST_H_ */
