#ifndef BINARYTREENODE_H_
#define BINARYTREENODE_H_

/**
 * @class BinaryTreeNode
 *
 * @file binarytreenode.h
 *
 * @brief Binary tree node.
 *
 * The binary tree node class definition.
 *
 * @created Dec 21, 2012
 * @author Vassilis S. Moustakas <vsmoustakas@gmail.com>
 */
class BinaryTreeNode {
public:
    /**
     * Default constructor.
     */
    BinaryTreeNode();

    /**
     * Constructor.
     *
     * @param[in] data The data of the node constructed.
     */
    BinaryTreeNode(int data);

    /**
     * Constructor.
     *
     * @param[in] data The data of the node constructed.
     * @param[in] left The left child of the node constructed.
     * @param[in] right The right child of the node constructed.
     */
    BinaryTreeNode(int data, BinaryTreeNode* left, BinaryTreeNode* right);

    /**
     * Destructor.
     */
    virtual ~BinaryTreeNode();

    // -- getter methods

    /**
     * Getter for binary tree node's data.
     *
     * @return The data of this binary tree node.
     */
    inline int data() { return m_data; }

    /**
     * Getter for the binary tree node's left child.
     *
     * @return A pointer to the left child of this binary tree node.
     */
    inline BinaryTreeNode* left() { return m_left; }

    /**
     * Getter for the binary tree node's right child.
     *
     * @return A pointer to the right child of this binary tree node.
     */
    inline BinaryTreeNode* right() { return m_right; }

    // -- setter methods

    /**
     * Setter for the binary tree node's left child.
     *
     * @param[in] node A pointer to the node to be set as this binary tree
     *                 node's left child.
     */
    inline void set_left(BinaryTreeNode* node) { m_left = node; }

    /**
     * Setter for the binary tree node's right child.
     *
     * @param[in] node A pointer to the node to be set as this binary tree
     *                 node's right child.
     */
    inline void set_right(BinaryTreeNode* node) { m_right = node; }
protected:
private:
    /**
     * The data conveyed by this binary tree node.
     */
    int m_data;

    /**
     * A pointer to the left child of this binary tree node.
     */
    BinaryTreeNode* m_left;

    /**
     * A pointer to the right child of this binary tree node.
     */
    BinaryTreeNode* m_right;
};

#endif /* BINARYTREENODE_H_ */
