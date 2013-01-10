#ifndef SINGLYLINKEDLIST_H_
#define SINGLYLINKEDLIST_H_

#include "singlylinkedlistnode.h"

/**
 * @class SinglyLinkedList
 *
 * @file singlylinkedlist.h
 *
 * @brief Singly linked list class definition.
 *
 * <p>
 * Singly linked lists are the fundamental of linked data structures. Pointers
 * are the connections that hold the noncontiguous-allocated data nodes of the
 * linked structures together. Linked lists are used to construct more abstract
 * data structures such as <emph>stacks<emph>, <emph>queues</emph> or
 * <emph>associative arrays (dictionaries)</emph>.
 * </p>
 *
 * <ul>
 * Advantages of linked lists over static arrays are
 *
 * <li>Overflow on linked structures can never occur unless the memory is
 * actually full.</li>
 *
 * <li>Insertions and deletions are simpler than for contiguous (array)
 * lists.</li>
 *
 * <li>With large records, moving pointers is easier and faster than moving
 * the items themselves.</li>
 * </ul>
 *
 * <ul>
 * while  the relative disadvantages of linked lists over arrays include
 *
 * <li>Linked structures require extra space for storing pointer fields.</li>
 *
 * <li>Linked lists do not allow efficient random access to items.</li>
 *
 * <li>Arrays allow better memory locality and cache performance than random
 * pointer jumping.</li>
 * </ul>
 *
 * <p>
 * The asymptotic worst-case running times for each of the seven fundamental
 * dictionary operations when the data structure is implemented as a singly
 * linked list are shown bellow:
 * <table border="0">
 * <tr>
 * <th>Dictionary operation</th>
 * <th>Unsorted singly</th>
 * <th>Sorted singly</th>
 * </tr>
 * <tr>
 * <td>Search</td>
 * <td>O(n)</td>
 * <td>O(n)</td>
 * </tr>
 * <tr>
 * <td>Insert</td>
 * <td>O(1)</td>
 * <td>O(n)</td>
 * </tr>
 * <tr>
 * <td>Delete</td>
 * <td>O(n)*</td>
 * <td>O(n)*</td>
 * </tr>
 * <tr>
 * <td>Successor</td>
 * <td>O(n)</td>
 * <td>O(1)</td>
 * </tr>
 * <tr>
 * <td>Predecessor</td>
 * <td>O(n)</td>
 * <td>O(n)*</td>
 * </tr>
 * <tr>
 * <td>Minimum</td>
 * <td>O(n)</td>
 * <td>O(1)</td>
 * </tr>
 * <tr>
 * <td>Maximum</td>
 * <td>O(n)</td>
 * <td>O(1)*</td>
 * </tr>
 * </table>
 * <p>
 *
 * @created Dec 11, 2012
 * @author Vassilis S. Moustakas <vsmoustakas@gmail.com>
 */
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
    inline SinglyLinkedListNode* head() { return m_head; }

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
    void prepend(SinglyLinkedListNode* node);

    /**
     * Appends the node given to the list's tail.
     *
     * @param[in] node
     *     The list node to be appended.
     */
    void append(SinglyLinkedListNode* node);

    /**
     * @brief Finds the first node in the list that matches the data given.
     *
     * This method implements an iterative algorithm.
     *
     * @param[in] data
     *     The data to search.
     *
     * @return A pointer to the node in the list first found to contain the
     *         data given; <code>null</code> if no such node exists.
     */
    SinglyLinkedListNode* find_iterative(int data);

    /**
     * @brief Finds the first node in the list that matches the data given.
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
    SinglyLinkedListNode* find_recursive(SinglyLinkedListNode* head, int data);

    /**
     * @brief Finds the predecessor of the first element with the given data.
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
    SinglyLinkedListNode* predecessor_iterative(int data);

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
    SinglyLinkedListNode* predecessor_recursive(SinglyLinkedListNode* head, int data);

    /**
     * Removes the first element found with the given data.
     *
     * @param[in] data
     *     The data to search for.
     *
     * @return <code>true</code> if the deletion was successful;
     *         <code>false</code> otherwise.
     */
    bool remove(int data);

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
