#ifndef BINARYTREE_H_
#define BINARYTREE_H_

#include "binarytreenode.h"

#include <iostream>
#include <queue>
#include <stack>

/**
 * @class BinaryTree
 *
 * @file binarytree.h
 *
 * @brief Binary (search) tree class definition.
 *
 * <p>
 * Binary search trees are a fundamental data structure used to construct more
 * abstract ones such as <em>sets</em>, <em>multisets</em>,
 * <em>associative arrays (dictionaries)</em> or <em>priority
 * queues</em>.
 *
 * Basic operations on binary search trees (BST) can be considered fast, since,
 * in every iteration, half of the nodes are eliminated by choosing to follow
 * the left or the right subtree. For example, we can know that a lookup
 * process was successful by the time there is only one node left to search.
 * Therefore, the running time of the lookup is equal to the number of times
 * that you can halve n nodes before you get to 1. This number, x, is the same
 * as the number of times you can double 1 before reaching n, and it can be
 * expressed as 2x = n. You can find this x by using a logarithm. Thus, in the
 * worst case, such operations run on Θ(log(n)) time for a complete and
 * balanced BST. A degenerated case would be one that each node has only one
 * child resulting in a linked list scheme with the lookup becoming an Θ(n)
 * operation.
 *
 * The data structure has no control over the order of insertion. If the user
 * inserts the keys in sorted order we end up with a linear structure where
 * only right pointers are used. Thus binary trees can have heights ranging
 * from lgn to n. Average case analysis suggests that if we consider each of
 * the n! possible insertion orderings equally likely and average over those,
 * then with high probability the resulting tree will have O(log n) height!!!
 * (power of randomization). This kind of tree is called balanced.
 *
 * It takes Θ(n) time to recursively walk a n-node BST. This is because after
 * the initial call, the walking procedure is called recursively exactly twice;
 * once for left child and once for right child.
 *
 * The asymptotic average- and worst-case complexity for space and the three
 * fundamental dictionary operations if this abstract data structured is built
 * upon a binary search tree are shown bellow:
 * <table border="0">
 * <tr>
 * <th></th>
 * <th>Average-case</th>
 * <th>Worst-case</th>
 * </tr>
 * <tr>
 * <td>Space</td>
 * <td>O(n)</td>
 * <td>O(n)</td>
 * </tr>
 * <tr>
 * <td>Search</td>
 * <td>O(log n)</td>
 * <td>O(n)</td>
 * </tr>
 * <tr>
 * <td>Insert</td>
 * <td>O(log n)</td>
 * <td>O(n)</td>
 * </tr>
 * <tr>
 * <td>Delete</td>
 * <td>O(log n)</td>
 * <td>O(n)</td>
 * </tr>
 * </table>
 *
 * The asymptotic worst-case running times for each of the three fundamental
 * priority queue operations when the data structure is implemented as a
 * binary search tree are shown bellow:
 * <table border="1">
 * <tr>
 * <th>Priority queue operation</th>
 * <th>Balanced BST</th>
 * </tr>
 * <tr>
 * <td>Insert</td>
 * <td>O(logn)</td>
 * </tr>
 * <tr>
 * <td>Find-Minimum</td>
 * <td>O(1)</td>
 * </tr>
 * <tr>
 * <td>Delete-Minimum</td>
 * <td>O(logn)</td>
 * </tr>
 * </table>
 *
 * Find-minimum can achieve constant time (the same way as with arrays) by
 * maintaining an extra pointer to the minimum entry. The pointer should be
 * updated each time a new entry is inserted with value less than the current
 * minimum. On delete minimum, we delete and then perform a honest find-minimum
 * which takes logarithmic time on a tree, and hence can be folded into the
 * cost of each deletion.
 *
 * The example binary tree used for subsequent documentation will be based on
 * the ASCII drawn structure below:
 *
 * <pre>
 *                     ___
 *                    |100|
 *                    |___|
 *                   /     \
 *              ____/       \____
 *             /                 \
 *         ___/                   \___
 *        |50 |                   |150|
 *        |___|                   |___|
 *       /     \                 /     \
 *      /       \               /       \
 *  ___/         \___       ___/         \___
 * |25 |         |75 |     |125|         |175|
 * |___|         |___|     |___|         |___|
 *                        /
 *                       /
 *                   ___/
 *                  |110|
 *                  |___|
 *
 * </pre>
 *
 * @created Dec 21, 2012
 * @author Vassilis S. Moustakas <vsmoustakas@gmail.com>
 */
template<class T>
class BinaryTree {
public:
    /**
     * Default constructor.
     */
    BinaryTree();

    /**
     * Constructor.
     *
     * @param[in] root
     *     The root node for the binary tree constructed.
     */
    BinaryTree(BinaryTreeNode<T> * root);

    /**
     * Destructor.
     */
    virtual ~BinaryTree();

    // -- getter methods

    /**
     * Getter for the binary tree's root.
     *
     * @return
     *     The binary tree's root.
     */
    BinaryTreeNode<T> * root() const;

    /**
     * Getter for the binary tree's root.
     *
     * @return
     *     A reference to the binary tree's root.
     */
    BinaryTreeNode<T> *& root_ref();

    // -- setter methods

    /**
     * Setter for the binary tree's root.
     *
     * @param[in] root
     *     The node to be set as root for this binary tree.
     */
    void set_root(BinaryTreeNode<T> * root);

    // -- public methods

    /**
     * Destroy (a part of) the binary tree.
     *
     * Use the binary tree's root node if you want its full destruction. The
     * algorithm is recursive thus needs a reference to pointer to the root
     * node to be manipulated since the base case dictates the destruction of
     * the root node.
     *
     * @param[in] root
     *     A reference to the root node of the (sub)tree we want to be destroyed.
     */
    void destroy(BinaryTreeNode<T> *& root);

    /**
     * Creates a copy of the binary tree.
     *
     * @return
     *     A pointer to the root of the binary tree copy.
     */
    BinaryTreeNode<T> * copy(BinaryTreeNode<T> * root);

    /**
     * Insertion of a node into the binary tree. Takes O(h) time, on a binary
     * tree of height h.
     *
     * The creation of the node to be inserted should be done before calling
     * this function.
     *
     * This method implements a recursive algorithm, thus it needs a reference
     * to the pointer to the root node since the base case of the recursion
     * dictates alternation of the root pointer.
     *
     * @param[in] root
     *     A reference to the root node.
     * @param[in] node
     *     The node to be inserted in the binary tree.
     */
    void insert_recursive(BinaryTreeNode<T> *& root, BinaryTreeNode<T>* node);

    /**
     * Insertion of a node into the binary tree. Takes O(h) time, on a binary
     * tree of height h.
     *
     * The creation of the node to be inserted should be done before calling
     * this function.
     *
     * This method implements an iterative algorithm.
     *
     * @param[in] node
     *     The node to be inserted in the binary tree.
     */
    void insert_iterative(BinaryTreeNode<T> * node);

    /**
     * Removal of a node from the binary tree. Takes O(h) time, on a binary
     * tree of height h.
     *
     * The function takes a pointer to the node to be removed from the tree.
     * If only the key of the node is available, then use one of the search
     * functions to obtain the pointer to the node containing the key in the
     * tree before using this function.
     *
     * @param[in] node
     *     The node to be removed from the binary tree.
     */
    void remove(BinaryTreeNode<T> * node);

    /**
     * Recursive lookup operation on the binary tree. Takes O(h) time, on a
     * binary tree of height h.
     *
     * @param[in] root
     *     The node to be used as root.
     * @param[in] key
     *     The key to search.
     *
     * @return
     *     A pointer to the node in the list found to contain the key given;
     *     <code>null</code> if no such node exists.
     */
    BinaryTreeNode<T> * search_recursive(BinaryTreeNode<T> * root, T key);

    /**
     * Iterative lookup operation on the binary tree. Takes O(h) time, on a
     * binary tree of height h.
     *
     * CLRS: "On most computers, this version is more efficient". Probably this
     * is due to the recursion "unrolling" inside the while loop used. This
     * strips the recursion overhead and compilers can further optimize loops.
     *
     * @param[in] root
     *     The node to be used as root.
     * @param[in] key
     *     The key to search.
     *
     * @return
     *     A pointer to the node in the list found to contain the key given;
     *     <code>null</code> if no such node exists.
     */
    BinaryTreeNode<T> * search_iterative(BinaryTreeNode<T> * root, T key);

    /**
     * Location of the minimum value stored in the binary tree. Takes O(h)
     * time, on a binary tree of height h.
     *
     * The element with the minimum value in a binary tree can always be found
     * by following left child pointers from the root until a <code>null</code>
     * pointer is encountered.
     *
     * @param[in] root
     *     The node to be used as root.
     *
     * @return
     *     A pointer to the node with the minimum key in the binary tree;
     *     <code>null</code> for an empty tree.
     */
    BinaryTreeNode<T> * minimum(BinaryTreeNode<T> * root);

    /**
     * Location of the maximum value stored in the binary tree. Takes O(h)
     * time, on a binary tree of height h.
     *
     * The element with the maximum value in a binary tree can always be
     * found by following right child pointers from the root until a
     * <code>null</code> pointer is encountered.
     *
     * @return
     *     A pointer to the node with the maximum key in the binary tree;
     *     <code>null</code> for an empty tree.
     *
     */
    BinaryTreeNode<T> * maximum(BinaryTreeNode<T> * root);

    /**
     * Location of the successor of a node in the sorted order of all nodes in
     * the tree.
     *
     * The sorted order is determined by an inorder tree walk. If all keys
     * are distinct, the successor of a node is the one with the smallest key
     * greater than the key of the node in hand. The structure of the binary
     * tree allows to determine the successor of a node without ever comparing
     * keys.
     *
     * If the right subtree of the node is non-empty, the successor of the node,
     * is the leftmost node in the right subtree. If the right subtree of the
     * given node is empty, and the node has a successor, then the successor
     * node is the lowest ancestor of the given node whose left child is also an
     * ancestor of the given node.
     *
     * @param[in] node
     *     The node whose successor is to be found.
     *
     * @return
     *     A pointer to the successor of the given node; <code>null</code> if
     *     the given node has the largest key in the tree or a <code>null</code>
     *     pointer was provided as argument.
     */
    BinaryTreeNode<T> * successor_inorder(BinaryTreeNode<T> * node);

    /**
     * Location of the predecessor of a node in the sorted order of all nodes in
     * the tree.
     *
     * The sorted order is determined by an inorder tree walk. If all keys
     * are distinct, the predecessor of a node is the one with the greatest key
     * that is smaller than the key of the node in hand. The structure of the
     * binary tree allows to determine the successor of a node without ever
     * comparing keys.
     *
     * If the left subtree of the node is non-empty, the predecessor of the
     * node, is the rightmost node in the left subtree. If the left subtree of
     * the given node is empty, and the node has a predecessor, then the
     * predecessor is the closest ancestor such that the given node is
     * descended from the right child of that predecessor.
     *
     * @param[in] node
     *     The node whose predecessor is to be found.
     *
     * @return A pointer to the predecessor of the given node;
     *         <code>null</code> if the given node has the largest key in the
     *         tree or a <code>null</code> pointer was provided as argument.
     */
    BinaryTreeNode<T> * predecessor_inorder(BinaryTreeNode<T> * node);

    /**
     * Depth-first traversal of the binary tree in preorder. Takes Θ(n) time to
     * walk a BST.
     *
     * Preorder traversal of a node performs the operation first on the node
     * itself, then on its left descendants, and finally on its right
     * descendants. In other words, a node is always visited before any of its
     * children.
     *
     * Uses of preorder traversal:
     * <ul>
     * <li>
     * prefix expression on an expression tree,
     * </li>
     * <li>
     * tree copy creation.
     * </li>
     * </ul>
     *
     * For the example binary tree, preorder traversal yields the following
     * sequence: <i>100, 50, 25, 75, 150, 125, 110, 175</i>
     *
     * @param[in] root
     *     The root node for the traversal.
     */
    void dft_preorder(BinaryTreeNode<T> * root);

    /**
     * An iterative implementation of the depth-first preorder traversal.
     */
    void dft_preorder_iterative();

    /**
     * Depth-first traversal of the binary tree in inorder. Used to print out
     * all keys in the tree in sorted order. Takes Θ(n) time to walk a BST.
     *
     * Inorder traversal performs the operation first on the node’s left
     * descendants, then on the node itself, and finally on its right
     * descendants. In other words, the left subtree is visited first, then
     * the node itself, and then the node’s right subtree.
     *
     * Uses of inorder traversal:
     * <ul>
     * <li>
     * infix expression on an expression tree,
     * </li>
     * <li>
     * in the case of a binary search tree gives the nodes in an increasing
     * order (if the decreasing order is needed, then we create a reversed
     * version of the standard inorder - first visit right subtree, then the
     * left),
     * </li>
     * </ul>
     *
     * For the example binary tree, inorder traversal yields the following
     * sequence: <i>25, 50, 75, 100, 110, 125, 150, 175</i>
     *
     * @param[in] root
     *     The root node for the traversal.
     */
    void dft_inorder(BinaryTreeNode<T> * root);

    /**
     * An iterative implementation of the depth-first inorder traversal.
     */
    void dft_inorder_iterative();

    /**
     * Depth-first traversal of the binary tree in postorder. Takes Θ(n) time
     * to walk a BST.
     *
     * Postorder traversal performs the operation first on the node’s left
     * descendants, then on the node’s right descendants, and finally on the
     * node itself. In other words, all of a node’s children are visited
     * before the node itself.
     *
     * Uses of postorder traversal:
     * <ul>
     * <li>
     * postfix expression on an expression tree,
     * </li>
     * <li>
     * tree deletion,
     * </li>
     * </ul>
     *
     * For the example binary tree, postorder traversal yields the following
     * sequence: <i>25, 75, 50, 110, 125, 175, 150, 100</i>
     *
     * @param[in] root
     *     The root node for the traversal.
     */
    void dft_postorder(BinaryTreeNode<T> * root);

    /**
     * An iterative implementation of the depth-first postorder traversal.
     */
    void dft_postorder_iterative();

    void dft_pre_in_post_order(BinaryTreeNode<T> * root,
            std::queue<T> & preQ, std::queue<T> & inQ, std::queue<T> & postQ);

    /**
     * Breadth-first traversal of the binary tree.
     *
     * Breadth-first traversal is performed in level-order, where we visit
     * every node on a level before going to a lower level. This implementation
     * is assisted by an STL queue.
     *
     * For the example binary tree, postorder traversal yields the following
     * sequence: <i>100, 50, 150, 25, 75, 125, 175, 110</i>
     */
    void bft();
protected:
private:
    /**
     * The root node of this binary tree.
     */
    BinaryTreeNode<T> * m_root;
};


template<class T>
BinaryTree<T>::BinaryTree()
{
    m_root = 0;
}

template<class T>
BinaryTree<T>::BinaryTree(BinaryTreeNode<T> * root)
{
    m_root = root;
}

template<class T>
BinaryTree<T>::~BinaryTree()
{
    destroy(m_root);
}


template<class T>
BinaryTreeNode<T> * BinaryTree<T>::root() const
{
    return m_root;
}


template<class T>
BinaryTreeNode<T> *& BinaryTree<T>::root_ref()
{
    return m_root;
}


template<class T>
void BinaryTree<T>::set_root(BinaryTreeNode<T> * root)
{
    m_root = root;
}


template<class T>
void BinaryTree<T>::destroy(BinaryTreeNode<T> *& root)
{
    if (root != 0)
    {
        destroy(root->left_ref());
        destroy(root->right_ref());
        BinaryTreeNode<T> * tmp = root;
        root = 0;
        delete tmp;
    }
}


template<class T>
BinaryTreeNode<T> * BinaryTree<T>::copy(BinaryTreeNode<T> * root)
{
    BinaryTreeNode<T> * t;
    BinaryTreeNode<T> * l;
    BinaryTreeNode<T> * r;

    if (!root)
        t = 0;
    else
    {
        l = copy(root->left_ref());
        r = copy(root->right_ref());
        t = new BinaryTreeNode<T>(root->key(), 0, l, r);
    }

    return t;
}


template<class T>
void BinaryTree<T>::insert_recursive(BinaryTreeNode<T> *& root, BinaryTreeNode<T> * node)
{
    if (root == NULL)
    {
        root = node;
    }
    else
    {
        if (node->key() < root->key())
        {
            insert_recursive(root->left_ref(), node);
        }
        else
        {
            insert_recursive(root->right_ref(), node);
        }
    }
}


template<class T>
void BinaryTree<T>::insert_iterative(BinaryTreeNode<T> * node)
{
    BinaryTreeNode<T> * parent = 0;
    BinaryTreeNode<T> * curr = m_root;

    while (curr != 0)
    {
        parent = curr;
        if (node->key() < curr->key())
            curr = curr->left();
        else
            curr = curr->right();
    }

    node->set_parent(parent);

    if (parent == 0)
    {
        // Tree was empty.
        m_root = node;
    }
    else
    {
        if (node->key() < parent->key())
            parent->set_left(node);
        else
            parent->set_right(node);
    }
}


template<class T>
void BinaryTree<T>::remove(BinaryTreeNode<T> * node)
{
    BinaryTreeNode<T> * splice = 0;
    BinaryTreeNode<T> * curr = 0;

    // Determine the spliced out node.
    if (node->left() == 0 || node->right() == 0)
    {
        // The node to be removed has at most 1 child...
        splice = node;
    }
    else
    {
        // ...else, node to be removed has 2 children.
        splice = successor_inorder(node);
    }

    // Determine curr node. Set to the non-NIL child of splice.
    // Set to NIL if splice has no children.
    if (splice->left() != 0)
        curr = splice->left();
    else
        curr = splice->right();

    if (curr != 0)
        curr->set_parent(splice->parent());

    if (splice->parent() == 0)
        m_root = curr;
    else
    {
        if (splice == (splice->parent())->left())
            (splice->parent())->set_left(curr);
        else
            (splice->parent())->set_right(curr);
    }

    // If the successor of the node was the one spliced out, copy its key
    // and any satellite data to node.
    if (splice != node)
        node->set_key(splice->key());

    // Check that the splice node is actually deleted and not the node given
    // as an argument to the function since some times splice != node.
    delete splice;
}


template<class T>
BinaryTreeNode<T> * BinaryTree<T>::search_recursive(BinaryTreeNode<T> * root, T key)
{
    if (root == 0 || root->key() == key)
        return root;

    if (root->key() > key)
        return search_recursive(root->left(), key);
    else
        return search_recursive(root->right(), key);

}


template<class T>
BinaryTreeNode<T> * BinaryTree<T>::search_iterative(BinaryTreeNode<T> * root, T key)
{
    BinaryTreeNode<int> * node = root;

    while (node != 0 && node->key() != key) {
        if (node->key() > key)
            node = node->left();
        else
            node = node->right();
    }

    return node;
}


template<class T>
BinaryTreeNode<T> * BinaryTree<T>::minimum(BinaryTreeNode<T> * root)
{
    if (root == 0)
        return 0;

    BinaryTreeNode<T> * node = root;

    while (node->left() != 0)
        node = node->left();

    return node;
}


template<class T>
BinaryTreeNode<T> * BinaryTree<T>::maximum(BinaryTreeNode<T> * root)
{
    if (root == 0)
        return 0;

    BinaryTreeNode<T> * node = root;

    while (node->right() != 0)
        node = node->right();

    return node;
}


template<class T>
BinaryTreeNode<T> * BinaryTree<T>::successor_inorder(BinaryTreeNode<T> * node)
{
    BinaryTreeNode<T> * successor = 0;

    if (node != 0) {
        // If the right subtree of the node is non-empty...
        if (node->right() != 0) {
            // ...the successor of the node, is the leftmost node
            // in the right subtree.
            successor = minimum(node->right());
        }
        else {
            BinaryTreeNode<T> * curr = node;

            // To find the successor if the right subtree of the node is empty, we
            // simply go up the tree from the given node until we encounter a node
            // that is the left child of its parent.
            successor = curr->parent();
            while (successor != 0 && curr == successor->right()) {
                curr = successor;
                successor = successor->parent();
            }
        }
    }

    return successor;
}


template<class T>
BinaryTreeNode<T> * BinaryTree<T>::predecessor_inorder(BinaryTreeNode<T> * node)
{
    BinaryTreeNode<T> * predecessor = 0;

    if (node != 0) {
        // If the left subtree of the node is non-empty...
        if (node->left() != 0) {
            // ...the predecessor of the node, is the rightmost node
            // in left subtree.
            predecessor = maximum(node->left());
        }
        else {
            BinaryTreeNode<T> * curr = node;

            // To find the predecessor if the left subtree of the node is empty, we
            // simply go up the tree for the given node until we encounter the
            // closest ancestor such that the given node is descended from the
            // right child of that predecessor.
            predecessor = curr->parent();
            while (predecessor != 0 && curr == predecessor->left()) {
                curr = predecessor;
                predecessor = predecessor->parent();
            }
        }
    }

    return predecessor;
}


template<class T>
void BinaryTree<T>::dft_preorder(BinaryTreeNode<T> * root)
{
    if (root != 0) {
        std::cout << root->key() << std::endl;
        dft_preorder(root->left());
        dft_preorder(root->right());
    }
}


template<class T>
void BinaryTree<T>::dft_preorder_iterative()
{
    if (!m_root)
        return;

    std::stack<BinaryTreeNode<T> *> st;
    BinaryTreeNode<T> * btn = 0;
    st.push(m_root);

    while (!st.empty())
    {
        btn = st.top();
        std::cout << btn->key() << std::endl;
        st.pop();

        // I push first right and then left into the stack because I want to
        // process the left node first!
        if (btn->right()) st.push(btn->right());
        if (btn->left()) st.push(btn->left());
    }
}


template<class T>
void BinaryTree<T>::dft_inorder(BinaryTreeNode<T> * root)
{
    if (root != 0) {
        dft_inorder(root->left());
        std::cout << root->key() << std::endl;
        dft_inorder(root->right());
    }
 }


template<class T>
void BinaryTree<T>::dft_inorder_iterative()
{
    std::stack<BinaryTreeNode<T> *> st;
    BinaryTreeNode<T> * btn = m_root;
    bool finished = false;

    while (!finished)
    {
        if (btn)
        {
            st.push(btn);
            btn = btn->left();
        }
        else
        {
            if (st.empty())
                finished = true;
            else
            {
                btn = st.top();
                st.pop();
                std::cout << btn->key() << std::endl;
                btn = btn->right();
            }
        }
    }
}


template<class T>
void BinaryTree<T>::dft_postorder(BinaryTreeNode<T> * root)
{
    if (root != 0) {
        dft_postorder(root->left());
        dft_postorder(root->right());
        std::cout << root->key() << std::endl;
    }
}


template<class T>
void BinaryTree<T>::dft_postorder_iterative()
{
    if (!m_root)
        return;

    // Primary stack
    std::stack<BinaryTreeNode<T> *> ps;
    // Final stack
    std::stack<BinaryTreeNode<T> *> fs;

    ps.push(m_root);

    while (!ps.empty())
    {
        BinaryTreeNode<T> * btn = ps.top();
        fs.push(btn);
        ps.pop();

        if (btn->left())
            ps.push(btn->left());

        if (btn->right())
            ps.push(btn->right());
    }

    while (!fs.empty())
    {
        std::cout << (fs.top())->key() << std::endl;
        fs.pop();
    }
}


template<class T>
void BinaryTree<T>::dft_pre_in_post_order(BinaryTreeNode<T> * root,
        std::queue<T> & preQ, std::queue<T> & inQ, std::queue<T> & postQ)
{
    if (root)
    {
        preQ.push(root->key());
        dft_pre_in_post_order(root->left(), preQ, inQ, postQ);
        inQ.push(root->key());
        dft_pre_in_post_order(root->right(), preQ, inQ, postQ);
        postQ.push(root->key());
    }
}


template<class T>
void BinaryTree<T>::bft()
{
    if (!m_root)
        return;

    // Create a queue.
    std::queue<BinaryTreeNode<T> *> q;
    BinaryTreeNode<T> * node = 0;

    if (m_root)
        q.push(m_root);

    while (!q.empty()) {
        // Dequeue a node from the front.
        node = q.front();
        std::cout << node->key() << std::endl;

        // Enqueue the left child.
        if (node->left() != 0)
            q.push(node->left());

        // Enqueue the right child.
        if (node->right() != 0)
            q.push(node->right());

        // Pop the visited node.
        q.pop();
    }
}

#endif /* BINARYTREE_H_ */
