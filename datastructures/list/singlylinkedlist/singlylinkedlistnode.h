/*
 * singlylinkedlistnode.h
 *
 *  Created on: Dec 11, 2012
 *      Author: billy
 */

#ifndef SINGLYLINKEDLISTNODE_H_
#define SINGLYLINKEDLISTNODE_H_

class SinglyLinkedListNode {
public:
    SinglyLinkedListNode();
    SinglyLinkedListNode(int data);
    SinglyLinkedListNode(int data, SinglyLinkedListNode* next);
    virtual ~SinglyLinkedListNode();

    // -- getter methods
    inline SinglyLinkedListNode* next() { return m_next; }
    inline int data() { return m_data; }

    // -- setter methods
    inline void set_next(SinglyLinkedListNode* next) { m_next = next; }

    // -- public methods
protected:
private:
    int m_data;
    SinglyLinkedListNode* m_next;
};

#endif /* SINGLYLINKEDLISTNODE_H_ */
