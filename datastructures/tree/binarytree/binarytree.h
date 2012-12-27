/**
 * @class BinaryTree
 *
 * @file binarytree.h
 *
 * @brief Binary tree.
 *
 * <p>
 * The binary tree class definition
 * </p>
 *
 * <p>
 * Search trees are data structures that support many dynamic-set operations,
 * like <code>SEARCH</code>, <code>MINIMUM</code>, <code>MAXIMUM</code>,
 * <code>PREDECESSOR</code>, <code>SUCCESSOR</code>, <code>INSERT</code> and
 * <code>DELETE</code>. Binary search trees are a fundamental data structure
 * used to construct more abstract ones such as sets, multisets, associative
 * arrays (dictionaries) or priority queues.
 * </p>
 *
 * <p>
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
 * </p>
 *
 * <p>
 * It takes Θ(n) time to recursively walk a n-node BST. This is because after
 * the initial call, the walking procedure is called recursively exactly twice;
 * once for left child and once for right child.
 * </p>
 *
 * <p>
 * The example binary tree used for subsequent documentation will be based on
 * the ASCII drawn structure below:
 * </p>
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
 * @created Dec 21, 2012
 * @author Vassilis S. Moustakas <vsmoustakas@gmail.com>
 */

#ifndef BINARYTREE_H_
#define BINARYTREE_H_

#include "binarytreenode.h"

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
    BinaryTree(BinaryTreeNode* root);

    /**
     * Destructor.
     */
    virtual ~BinaryTree();

    // -- getter methods

    /**
     * Getter for the binary tree's root.
     *
     * @return The binary tree's root.
     */
    inline BinaryTreeNode* root() { return m_root; }

    // -- setter methods

    /**
     * Setter for the binary tree's root.
     *
     * @param[in] root
     *     The node to be set as root for this binary tree.
     */
    inline void set_root(BinaryTreeNode* root) { m_root = root; }

    // -- public methods

    /**
     * @brief Destroy (a part of) the binary tree.
     *
     * Use the binary tree's root node if you want its full destruction.
     *
     * @param[in] root
     *     The root node of the (sub)tree we want to be destroyed.
     */
    void destroy(BinaryTreeNode* root);

    /**
     * @brief Insertion of a node into the binary tree. Takes O(h) time, on a
     *        binary tree of height h.
     *
     * The creation of the node to be inserted should be done before calling
     * this function.
     *
     * @param[in] node
     *     The node to be inserted in the binary tree.
     */
    void insert(BinaryTreeNode* node);

    /**
     * @brief Removal of a node from the binary tree. Takes O(h) time, on a
     *        binary tree of height h.
     *
     * The function takes a pointer to the node to be removed from the tree.
     * If only the key of the node is available, then use one of the search
     * functions to obtain the pointer to the node containing the key in the
     * tree before using this funtion.
     *
     * @param[in] node
     *     The node to be removed from the binary tree.
     */
    void remove(BinaryTreeNode* node);

    /**
     * @brief Recursive lookup operation on the binary tree. Takes O(h) time,
     *        on a binary tree of height h.
     *
     * @param[in] root
     *     The node to be used as root.
     * @param[in] key
     *     The key to search.
     *
     * @return A pointer to the node in the list found to contain the key
     *         given; <code>null</code> if no such node exists.
     */
    BinaryTreeNode* search_recursive(BinaryTreeNode* root, int key);

    /**
     * @brief Iterative lookup operation on the binary tree. Takes O(h) time,
     *        on a binary tree of height h.
     *
     * <p>
     * CLRS: "On most computers, this version is more efficient". Probably this
     * is due to the recursion "unrolling" inside the while loop used. This
     * strips the recursion overhead and compilers can further optimize loops.
     * </p>
     *
     * @param[in] root
     *     The node to be used as root.
     * @param[in] key
     *     The key to search.
     *
     * @return A pointer to the node in the list found to contain the key
     *         given; <code>null</code> if no such node exists.
     */
    BinaryTreeNode* search_iterative(BinaryTreeNode* root, int key);

    /**
     * @brief Location of the minimum value stored in the binary tree. Takes
     *        O(h) time, on a binary tree of height h.
     *
     * <p>
     * The element with the minimum value in a binary tree can always be found
     * by following left child pointers from the root until a <code>null</code>
     * pointer is encountered.
     * </p>
     *
     * @param[in] root
     *     The node to be used as root.
     *
     * @return A pointer to the node with the minimum key in the binary
     *         tree;<code>null</code> for an empty tree.
     */
    BinaryTreeNode* minimum(BinaryTreeNode* root);

    /**
     * @brief Location of the maximum value stored in the binary tree. Takes
     *        O(h) time, on a binary tree of height h.
     *
     * The element with the maximum value in a binary tree can always be
     * found by following right child pointers from the root until a
     * <code>null</code> pointer is encountered.
     *
     * @return A pointer to the node with the maximum key in the binary
     *         tree;<code>null</code> for an empty tree.
     *
     */
    BinaryTreeNode* maximum(BinaryTreeNode* root);

    /**
     * @brief Location of the successor of a node in the sorted order of all
     *        nodes in the tree.
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
     * @return A pointer to the successor of the given node; <code>null</code>
     *         if the given node has the largest key in the tree.
     */
    BinaryTreeNode* successor_inorder(BinaryTreeNode* node);

    /**
     * @brief Location of the predecessor of a node in the sorted order of all
     *        nodes in the tree.
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
     *         tree.
     */
    BinaryTreeNode* predecessor_inorder(BinaryTreeNode* node);

    /**
     * @brief Depth-first traversal of the binary tree in preorder. Takes Θ(n)
     *        time to walk a BST.
     *
     * <p>
     * Preorder traversal of a node performs the operation first on the node
     * itself, then on its left descendants, and finally on its right
     * descendants. In other words, a node is always visited before any of its
     * children.
     * </p>
     *
     * <p>
     * For the example binary tree, preorder traversal yields the following
     * sequence: <i>100, 50, 25, 75, 150, 125, 110, 175</i>
     * </p>
     *
     * @param[in] root
     *     The root node for the traversal.
     */
    void dft_preorder(BinaryTreeNode* root);

    /**
     * @brief Depth-first traversal of the binary tree in inorder. Used to
     *        print out all keys in the tree in sorted order. Takes Θ(n)
     *        time to walk a BST.
     *
     * <p>
     * Inorder traversal performs the operation first on the node’s left
     * descendants, then on the node itself, and finally on its right
     * descendants. In other words, the left subtree is visited first, then
     * the node itself, and then the node’s right subtree.
     * </p>
     *
     * <p>
     * For the example binary tree, inorder traversal yields the following
     * sequence: <i>25, 50, 75, 100, 110, 125, 150, 175</i>
     * </p>
     *
     * @param[in] root
     *     The root node for the traversal.
     */
    void dft_inorder(BinaryTreeNode* root);

    /**
     * @brief Depth-first traversal of the binary tree in postorder. Takes Θ(n)
     *        time to walk a BST.
     *
     * <p>
     * Postorder traversal performs the operation first on the node’s left
     * descendants, then on the node’s right descendants, and finally on the
     * node itself. In other words, all of a node’s children are visited
     * before the node itself.
     * </p>
     *
     * <p>
     * For the example binary tree, postorder traversal yields the following
     * sequence: <i>25, 75, 50, 110, 125, 175, 150, 100</i>
     * </p>
     *
     * @param[in] root
     *     The root node for the traversal.
     */
    void dft_postorder(BinaryTreeNode* root);

    /**
     * @brief Breadth-first traversal of the binary tree.
     *
     * <p>
     * Breadth-first traversal is performed in level-order, where we visit
     * every node on a level before going to a lower level. This implementation
     * is assisted by an STL queue.
     * </p>
     *
     * <p>
     * For the example binary tree, postorder traversal yields the following
     * sequence: <i>100, 50, 150, 25, 75, 125, 175, 110</i>
     * </p>
     *
     * @param[in] root
     *     The root node for the traversal.
     */
    void bft(BinaryTreeNode* root);
protected:
private:
    /**
     * The root node of this binary tree.
     */
    BinaryTreeNode* m_root;
};

#endif /* BINARYTREE_H_ */
