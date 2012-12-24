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
     * @param[in] key
     *     The key of the node constructed.
     */
    BinaryTreeNode(int key);

    /**
     * Constructor.
     *
     * @param[in] key
     *     The key of the node constructed.
     * @param[in] parent
     *     The parent of the node constructed.
     * @param[in] left
     *     The left child of the node constructed.
     * @param[in] right
     *     The right child of the node constructed.
     */
    BinaryTreeNode(
            int key,
            BinaryTreeNode* parent,
            BinaryTreeNode* left,
            BinaryTreeNode* right
            );

    /**
     * Destructor.
     */
    virtual ~BinaryTreeNode();

    // -- getter methods

    /**
     * Getter for binary tree node's key.
     *
     * @return The key of this binary tree node.
     */
    inline int key() { return m_key; }

    /**
     * Getter for the binary tree node's parent.
     *
     * @return A pointer to the parent of this binary tree node.
     */
    inline BinaryTreeNode* parent() { return m_parent; }

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
     * Setter for the binary tree node's key.
     *
     * @param[in] key
     *     The key to be set for this binary tree node.
     */
    inline void set_key(int key) { m_key = key; }

    /**
     * Setter for the binary tree node's parent.
     *
     * @param[in] parent
     *     A pointer to the node to be set as this binary tree node's parent.
     */
    inline void set_parent(BinaryTreeNode* parent) { m_parent = parent; }

    /**
     * Setter for the binary tree node's left child.
     *
     * @param[in] left
     *     A pointer to the node to be set as this binary tree node's left
     *     child.
     */
    inline void set_left(BinaryTreeNode* left) { m_left = left; }

    /**
     * Setter for the binary tree node's right child.
     *
     * @param[in] right
     *     A pointer to the node to be set as this binary tree node's right
     *     child.
     */
    inline void set_right(BinaryTreeNode* right) { m_right = right; }
protected:
private:
    /**
     * The key conveyed by this binary tree node.
     */
    int m_key;

    /**
     * A pointer to the parent of this binary tree node.
     */
    BinaryTreeNode* m_parent;

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
