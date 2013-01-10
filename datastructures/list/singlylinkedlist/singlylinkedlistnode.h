#ifndef SINGLYLINKEDLISTNODE_H_
#define SINGLYLINKEDLISTNODE_H_

/**
 * @class SinglyLinkedListNode
 *
 * @file singlylinkedlistnode.h
 *
 * @brief Singly linked list node class definition.
 *
 * @created Dec 11, 2012
 * @author Vassilis S. Moustakas <vsmoustakas@gmail.com>
 */
class SinglyLinkedListNode {
public:
    /**
     * Default constructor.
     */
    SinglyLinkedListNode();

    /**
     * @brief Constructor.
     *
     * This constructor initializes the data with the given data and defaults
     * the next pointer to <code>NULL</code>.
     *
     * @param[in] data
     *     The data with which to initialize the new singly linked list node.
     */
    SinglyLinkedListNode(int data);

    /**
     * Constructor.
     *
     * @param[in] data
     *     The data with which to initialize the new singly linked list node.
     * @param[in] next
     *     The pointer with which to initialize the new singly linked list
     *     node's next node.
     */
    SinglyLinkedListNode(int data, SinglyLinkedListNode* next);

    /**
     * Destructor.
     */
    virtual ~SinglyLinkedListNode();

    // -- getter methods

    /**
     * Getter for the node's next pointer.
     *
     * @return A pointer to the next node.
     */
    inline SinglyLinkedListNode* next() { return m_next; }

    /**
     * Getter for the node's data.
     *
     * @return The data of the node.
     */
    inline int data() { return m_data; }

    // -- setter methods

    /**
     * Setter for the node's pointer to the next node.
     *
     * @param[in] next
     *     A pointer to the node which we want set as next.
     */
    inline void set_next(SinglyLinkedListNode* next) { m_next = next; }

    // -- public methods
protected:
private:
    /**
     * The data of the node.
     */
    int m_data;

    /**
     * A pointer to the next node in the list sequence.
     */
    SinglyLinkedListNode* m_next;
};

#endif /* SINGLYLINKEDLISTNODE_H_ */
