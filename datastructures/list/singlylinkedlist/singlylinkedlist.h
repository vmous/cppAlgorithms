#ifndef SINGLYLINKEDLIST_H_
#define SINGLYLINKEDLIST_H_

#include "singlylinkedlistnode.h"

#include <iostream>

/**
 * @class SinglyLinkedList
 *
 * @file singlylinkedlist.h
 *
 * Singly linked list class definition.
 *
 * Singly linked lists are the fundamental of linked data structures. Pointers
 * are the connections that hold the non-contiguous-allocated data nodes of the
 * linked structures together. Linked lists are used to construct more abstract
 * data structures such as <em>stacks</em>, <em>queues</em> or
 * <em>associative arrays (dictionaries)</em>.
 *
 * Advantages of linked lists over static arrays are
 * <ul>
 * <li>
 * overflow on linked structures can never occur unless the memory is
 * actually full,
 * </li>
 * <li>
 * insertions and deletions are simpler than for contiguous (array) lists,
 * </li>
 * <li>
 * with large records, moving pointers is easier and faster than moving the
 * items themselves.
 * </li>
 * </ul>
 *
 * The relative disadvantages of linked lists over arrays include
 * <ul>
 * <li>
 * linked structures require extra space for storing pointer fields,
 * </li>
 * <li>
 * linked lists do not allow efficient random access to items,
 * </li>
 * <li>
 * arrays allow better memory locality and cache performance than random
 * pointer jumping.
 * </li>
 * </ul>
 *
 * <h3>Dictionary operations</h3>
 *
 * The asymptotic worst-case running times for each of the seven fundamental
 * dictionary operations when the data structure is implemented as a singly
 * linked list are shown bellow:
 * <table border="1">
 * <tr>
 * <th>Dictionary operation</th>
 * <th>Unsorted singly</th>
 * <th>Sorted singly</th>
 * </tr>
 * <tr>
 * <td><tt>Search</tt></td>
 * <td>O(n)</td>
 * <td>O(n)</td>
 * </tr>
 * <tr>
 * <td><tt>Insert</tt></td>
 * <td>O(1)</td>
 * <td>O(n)</td>
 * </tr>
 * <tr>
 * <td><tt>Delete</tt></td>
 * <td>O(n)<sup>*</sup></td>
 * <td>O(n)<sup>*</sup></td>
 * </tr>
 * <tr>
 * <td><tt>Successor</tt></td>
 * <td>O(n)</td>
 * <td>O(1)</td>
 * </tr>
 * <tr>
 * <td><tt>Predecessor</tt></td>
 * <td>O(n)</td>
 * <td>O(n)</td>
 * </tr>
 * <tr>
 * <td><tt>Minimum</tt></td>
 * <td>O(n)</td>
 * <td>O(1)</td>
 * </tr>
 * <tr>
 * <td><tt>Maximum</tt></td>
 * <td>O(n)</td>
 * <td>O(1)<sup>**</sup></td>
 * </tr>
 * </table>
 *
 * <sup>*</sup> We spend linear time searching the predecessor.<br />
 * <sup>**</sup> The trick is to charge the cost to each deletion, which
 * already takes linear time. Adding an extra linear sweep to update the
 * pointer does not harm the asymptotic complexity of <tt>Delete</tt>, while
 * gaining us <tt>Maximum</tt> in constant time!
 *
 * Sorting of linked lists provide quick termination of unsuccessful searches
 * but not the benefits of binary search, like in arrays, since we cannot
 * access the median element without traversing all the elements before it.
 *
 * @created Dec 11, 2012
 * @author Vassilis S. Moustakas <vsmoustakas@gmail.com>
 */
template<class T>
class SinglyLinkedList {
public:
    /**
     * Default constructor.
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
    inline SinglyLinkedListNode<T> * head() { return m_head; }

    // -- setter methods
    // -- public methods

    /**
     * Clear list.
     */
    void clear();

    /**
     * Prepends the node given to the list's head.
     *
     * @param[in] node
     *     The list node to be prepended.
     */
    void prepend(SinglyLinkedListNode<T> * node);

    /**
     * Appends the node given to the list's tail.
     *
     * @param[in] node
     *     The list node to be appended.
     */
    void append(SinglyLinkedListNode<T> * node);

    /**
     * Finds the first node in the list that matches the data given.
     *
     * This method implements an iterative algorithm.
     *
     * @param[in] data
     *     The data to search.
     *
     * @return A pointer to the node in the list first found to contain the
     *         data given; <code>null</code> if no such node exists.
     */
    SinglyLinkedListNode<T> * find_iterative(T data);

    /**
     * Finds the first node in the list that matches the data given.
     *
     * This method implements a recursive algorithm.
     *
     * @param[in] head
     *     The head of the list to be searched.
     * @param[in] data
     *     The data to search.
     *
     * @return A pointer to the node in the list first found to contain the
     *         data given; <code>null</code> if no such node exists.
     */
    SinglyLinkedListNode<T> * find_recursive(SinglyLinkedListNode<T> * head, T data);

    SinglyLinkedListNode<T> * successor_iterative(T data);
    SinglyLinkedListNode<T> * successor_recursive(T data);

    /**
     * Finds the predecessor of the first element with the given data.
     *
     * Implemented with an iterative algorithm.
     *
     * @param[in] data
     *     The data to search for.
     *
     * @return A pointer to the predecessor of the first occurrence of a node
     *         with the given data. If no such node exists, the
     *         <code>null</code> pointer is returned.
     */
    SinglyLinkedListNode<T> * predecessor_iterative(T data);

    /**
     * Finds the predecessor of the given node in the list.
     *
     * Implemented with a recursive algorithm.
     *
     * @param[in] head
     *     The head of the list to be searched.
     * @param[in] data
     *     The data to search
     *
     * @return A pointer to the predecessor of the first occurrence of a node
     *         with the given data. If no such node exists, the
     *         <code>null</code> pointer is returned.
     */
    SinglyLinkedListNode<T> * predecessor_recursive(SinglyLinkedListNode<T> * head, T data);

    /**
     * Removes the first element found with the given data.
     *
     * @param[in] data
     *     The data to search for.
     *
     * @return <code>true</code> if the deletion was successful;
     *         <code>false</code> otherwise.
     */
    bool remove(T data);

    /**
     * Reverts the list.
     */
    void revert();

    /**
     * Sorts the list.
     */
    void sort();

    /**
     * Checks if the list is circular.
     *
     * @return <code>true</code> if the list is circular;<code>false</code>
     *         otherwise.
     */
    bool isCircular();

    /**
     * Connects the last node with the head.
     *
     * ATTENTION: Do not use it. Breaks a lot of functionalities based on list
     * traversal (print, delete etc)
     */
    void circulize();

    /**
     * Find the <it>N</it>-th to last element in the list.
     */
    SinglyLinkedListNode<T> * nth_to_last(int n);

    /**
     * Prints the list.
     */
    void print();
protected:
private:
    /**
     * Pointer to the list's head.
     */
    SinglyLinkedListNode<T> * m_head;
};


template<class T>
SinglyLinkedList<T>::SinglyLinkedList()
{
    m_head = 0;
}


template<class T>
SinglyLinkedList<T>::~SinglyLinkedList()
{
}


template<class T>
void SinglyLinkedList<T>::clear()
{
    while (m_head != 0) {
        SinglyLinkedListNode<T> * del = m_head;
        m_head = del->next();
        delete del;
    }
}


template<class T>
void SinglyLinkedList<T>::prepend(SinglyLinkedListNode<T> * node)
{
    node->set_next(m_head);
    m_head = node;
}


template<class T>
void SinglyLinkedList<T>::append(SinglyLinkedListNode<T> * node)
{
    if (m_head == 0) {
        node->set_next(0);
        m_head = node;
        return;
    }

    SinglyLinkedListNode<T> * lln = m_head;

    while (lln != 0) {
        if (lln->next() == 0) {
            break;
        }
        lln = lln->next();
    }

    node->set_next(0);
    lln->set_next(node);
}


template<class T>
SinglyLinkedListNode<T> * SinglyLinkedList<T>::find_iterative(T data)
{
    SinglyLinkedListNode<T> * lln = m_head;

    while (lln != 0) {
        if (lln->data() == data)
            break;

        lln = lln->next();
    }

    return lln;
}


template<class T>
SinglyLinkedListNode<T> * SinglyLinkedList<T>::find_recursive(SinglyLinkedListNode<T> * head, T data)
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


template<class T>
SinglyLinkedListNode<T> * SinglyLinkedList<T>::successor_iterative(T data)
{

}


template<class T>
SinglyLinkedListNode<T> * SinglyLinkedList<T>::successor_recursive(T data)
{

}


template<class T>
SinglyLinkedListNode<T> * SinglyLinkedList<T>::predecessor_iterative(T data)
{
    SinglyLinkedListNode<T> * lln = m_head;
    SinglyLinkedListNode<T> * prev = 0;

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


template<class T>
SinglyLinkedListNode<T> * SinglyLinkedList<T>::predecessor_recursive(SinglyLinkedListNode<T> * head, T data)
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


template<class T>
bool SinglyLinkedList<T>::remove(T data)
{
    SinglyLinkedListNode<T> * prev = 0;
    SinglyLinkedListNode<T> * curr = m_head;

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


template<class T>
void SinglyLinkedList<T>::revert()
{
    if (!m_head || !m_head->next())
        return;

    SinglyLinkedListNode<T> * prev = 0;
    SinglyLinkedListNode<T> * curr = m_head;
    SinglyLinkedListNode<T> * step = 0;

    while (curr) {
        step = curr->next();

        curr->set_next(prev);
        prev = curr;
        curr = step;
    }

    m_head = prev;
}


template<class T>
void SinglyLinkedList<T>::sort()
{
    if (m_head == 0 || m_head->next() == 0)
        return;

    bool swap = false;
    do {
        SinglyLinkedListNode<T> * prev = 0;
        SinglyLinkedListNode<T> * curr = m_head;
        SinglyLinkedListNode<T> * next = m_head->next();
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

                SinglyLinkedListNode<T> * tmp = curr;
                curr = next;
                next = tmp;
            }

            prev = curr;
            curr = next;
            next = next->next();

        }
    } while (swap);
}


template<class T>
bool SinglyLinkedList<T>::isCircular()
{
    if (!m_head)
        return false;

    SinglyLinkedListNode<T> * slow = m_head;
    SinglyLinkedListNode<T> * fast = m_head->next();

    while (true)
    {
        // If the fast pointer encounters a NULL element.
        if (!fast || !fast->next())
            return false;
        // If fast pointer ever equals slow or fast's next pointer is ever
        // equal to slow then it's a circular list.
        else if (fast == slow || fast->next() == slow)
            return true;
        else
        {
            // Advance the pointers.
            slow = slow->next();
            fast = fast->next()->next();
        }
    }
}


template<class T>
void SinglyLinkedList<T>::circulize()
{
    if (m_head)
    {
        SinglyLinkedListNode<T> * lln = m_head;

        while(lln->next())
        {
            lln = lln->next();
        }

        lln->set_next(m_head);
    }
}


template<class T>
SinglyLinkedListNode<T> * SinglyLinkedList<T>::nth_to_last(int n)
{
    if (!m_head || n < 0)
        return 0;

    SinglyLinkedListNode<T> * driver = m_head;
    SinglyLinkedListNode<T> * sentinel = 0;

    while (n != 0 && driver->next())
    {
        driver = driver->next();
        n--;
    }

    if (n == 0)
    {
        sentinel = m_head;
        while (driver->next())
        {
            driver = driver->next();
            sentinel = sentinel->next();
        }
        return sentinel;
    }
    else
    {
        return 0;
    }
}


template<class T>
void SinglyLinkedList<T>::print()
{
    SinglyLinkedListNode<T> * lln = m_head;
    std::cout << "HEAD -> ";

    while (lln != 0) {
        std::cout << "| " << lln->data() << " | -> ";
        lln = lln->next();
    }

    std::cout << "NULL" << std::endl;
}


#endif /* SINGLYLINKEDLIST_H_ */
