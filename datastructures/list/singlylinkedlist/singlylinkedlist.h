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
    /**
     * Constructor.
     */
    SinglyLinkedList();

    /**
     * Destructor.
     */
    virtual ~SinglyLinkedList();

    // -- getter methods

    /**
     * Getter for the list's head.
     *
     * @return The list's head.
     */
    inline SinglyLinkedListNode* head() { return m_head; }

    // -- public methods

    /**
     * Prepends the node given to the list's head.
     *
     * @param node The list node to be prepended.
     */
    void prepend(SinglyLinkedListNode* node);

    /**
     * Appends the node given to the list's tail.
     *
     * @param node The list node to be appended.
     */
    void append(SinglyLinkedListNode* node);

    /**
     * Finds the first node in the list that matches the data given.
     *
     * @param data The data to base the find process.
     *
     * @return A pointer to the node in the list first found to contain the
     *         data given; <code>null</code> if no such node exists.
     */
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

    /**
     * Reverts the list.
     */
    void revert();

    /**
     * Sorts the list.
     */
    void sort();

    /**
     * Prints the list.
     */
    void print();
protected:
private:
    /**
     * Pointer to the list's head.
     */
    SinglyLinkedListNode* m_head;
};

#endif /* SINGLYLINKEDLIST_H_ */
