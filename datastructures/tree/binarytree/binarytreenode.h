#ifndef BINARYTREENODE_H_
#define BINARYTREENODE_H_

/**
 * @class BinaryTreeNode
 *
 * @file binarytreenode.h
 *
 * @brief Binary (search) tree node class definition.
 *
 * @created Dec 21, 2012
 * @author Vassilis S. Moustakas <vsmoustakas@gmail.com>
 */
template<class T>
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
    BinaryTreeNode(T key);

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
            T key,
            BinaryTreeNode<T> * parent,
            BinaryTreeNode<T> * left,
            BinaryTreeNode<T> * right
            );

    /**
     * Destructor.
     */
    virtual ~BinaryTreeNode();

    // -- getter methods

    /**
     * Getter for binary tree node's key.
     *
     * @return
     *     The key of this binary tree node.
     */
    T key() const;

    /**
     * Getter for the binary tree node's parent.
     *
     * @return
     *     A pointer to the parent of this binary tree node.
     */
    BinaryTreeNode<T> * parent() const;

    /**
     * Getter for the binary tree node's left child.
     *
     * @return
     *     A pointer to the left child of this binary tree node.
     */
    BinaryTreeNode<T> * left() const;

    /**
     * Getter for the binary tree node's left child.
     *
     * @return
     *     A reference to the pointer to the left child of this binary tree
     *     node.
     */
    BinaryTreeNode<T> *& left_ref();

    /**
     * Getter for the binary tree node's right child.
     *
     * @return
     *     A pointer to the right child of this binary tree node.
     */
    BinaryTreeNode<T> * right() const;

    /**
     * Getter for the binary tree node's right child.
     *
     * @return
     *     A reference to the pointer to the right child of this binary tree node.
     */
    BinaryTreeNode<T> *& right_ref();

    // -- setter methods

    /**
     * Setter for the binary tree node's key.
     *
     * @param[in] key
     *     The key to be set for this binary tree node.
     */
    void set_key(const T & key);

    /**
     * Setter for the binary tree node's parent.
     *
     * @param[in] parent
     *     A pointer to the node to be set as this binary tree node's parent.
     */
    void set_parent(BinaryTreeNode<T> * parent);

    /**
     * Setter for the binary tree node's left child.
     *
     * @param[in] left
     *     A pointer to the node to be set as this binary tree node's left
     *     child.
     */
    void set_left(BinaryTreeNode<T> * left);

    /**
     * Setter for the binary tree node's right child.
     *
     * @param[in] right
     *     A pointer to the node to be set as this binary tree node's right
     *     child.
     */
    void set_right(BinaryTreeNode<T> * right);
protected:
private:
    /**
     * The key conveyed by this binary tree node.
     */
    T m_key;

    /**
     * A pointer to the parent of this binary tree node.
     */
    BinaryTreeNode<T> * m_parent;

    /**
     * A pointer to the left child of this binary tree node.
     */
    BinaryTreeNode<T> * m_left;

    /**
     * A pointer to the right child of this binary tree node.
     */
    BinaryTreeNode<T> * m_right;
};


template<class T>
BinaryTreeNode<T>::BinaryTreeNode()
{
    m_key = 0;
    m_parent = 0;
    m_left = 0;
    m_right = 0;
}


template<class T>
BinaryTreeNode<T>::BinaryTreeNode(T key)
{
    m_key = key;
    m_parent = 0;
    m_left = 0;
    m_right = 0;
}


template<class T>
BinaryTreeNode<T>::BinaryTreeNode(
        T key,
        BinaryTreeNode<T> * parent,
        BinaryTreeNode<T> * left,
        BinaryTreeNode<T> * right
        )
{
    m_key = key;
    m_parent = parent;
    m_left = left;
    m_right = right;
}


template<class T>
BinaryTreeNode<T>::~BinaryTreeNode()
{
}


template<class T>
T BinaryTreeNode<T>::key() const
{
    return m_key;
}


template<class T>
BinaryTreeNode<T> * BinaryTreeNode<T>::parent() const
{
    return m_parent;
}


template<class T>
BinaryTreeNode<T> * BinaryTreeNode<T>::left() const
{
    return m_left;
}


template<class T>
BinaryTreeNode<T> *& BinaryTreeNode<T>::left_ref()
{
    return m_left;
}


template<class T>
BinaryTreeNode<T> * BinaryTreeNode<T>::right() const
{
    return m_right;
}


template<class T>
BinaryTreeNode<T> *& BinaryTreeNode<T>::right_ref()
{
    return m_right;
}


template<class T>
void BinaryTreeNode<T>::set_key(const T & key)
{
    m_key = key;
}


template<class T>
void BinaryTreeNode<T>::set_parent(BinaryTreeNode<T> * parent)
{
    m_parent = parent;
}


template<class T>
void BinaryTreeNode<T>::set_left(BinaryTreeNode<T> * left)
{
    m_left = left;
}


template<class T>
void BinaryTreeNode<T>::set_right(BinaryTreeNode<T> * right)
{
    m_right = right;
}

#endif /* BINARYTREENODE_H_ */
