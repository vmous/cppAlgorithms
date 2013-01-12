#ifndef ARRAY_H_
#define ARRAY_H_

/**
 * @class Array
 *
 * @file array.h
 *
 * @brief Standard C array container class definition.
 *
 * <p>
 * An array is the fundamental contiguously-allocated data structure. It
 * consists of fixed-size data records such that each element can be
 * efficiently located by its index. Arrays are used to construct more abstract
 * data structures such as <emph>stacks<emph>, <emph>queues</emph>,
 * <emph>associative arrays (dictionaries)</emph>.
 * </p>
 *
 * <dl>
 * Advantages of contiguously-allocated structures are
 *
 * <dt>Constant-time (O(1)) access given the index</dt>
 * <dd>– Because the index of each element maps directly to a particular memory
 * address, we can access arbitrary data items instantly provided we know the
 * index.</dd>
 *
 * <dt>Space efficiency</dt>
 * <dd>– Arrays consist purely of data, so no space is wasted with links or
 * other formatting information. Further, end-of-record information is not
 * needed because arrays are built from fixed-size records.</dd>
 *
 * <dt>Memory locality</dt>
 * <dd>– A common programming idiom involves iterating through all the elements
 * of a data structure. Arrays are good for this because they exhibit excellent
 * memory locality. Physical continuity between successive data accesses helps
 * exploit the high-speed cache memory on modern computer architectures.</dd>
 *
 * </dl>
 *
 * <p>
 * The most important down-side of using arrays, is that we cannot (easily)
 * adjust their size during runtime. We can bypass this problem by exploiting
 * dynamic memory allocation for acquiring a bigger array in memory and then
 * copy the old one, to the lower half of the new one. Obviously, though, this
 * mechanism incurs additional burden, that breaks the guarantee of constant
 * time (O(1)), worst case, insertion cost. If we double the size of the array
 * each time we run out of space it can be proven (see Skiena's <i>The
 * Algorithm Design Manual</i>, 2nd edition, page 67) that after a total of n
 * insertions each of the n elements move only two times on average, and the
 * total work of managing the dynamic array is the same O(n) as it would have
 * been if a single array of sufficient size had been allocated in advance!
 * </p>
 *
 * <p>
 * The asymptotic worst-case running times for each of the seven fundamental
 * dictionary operations when the data structure is implemented as an array
 * are shown bellow:
 * <table border="0">
 * <tr>
 * <th>Dictionary operation</th>
 * <th>Unsorted array</th>
 * <th>Sorted array</th>
 * </tr>
 * <tr>
 * <td>Search</td>
 * <td>O(n)</td>
 * <td>O(logn)</td>
 * </tr>
 * <tr>
 * <td>Insert</td>
 * <td>O(1)</td>
 * <td>O(n)</td>
 * </tr>
 * <tr>
 * <td>Delete</td>
 * <td>O(1)*</td>
 * <td>O(n)</td>
 * </tr>
 * <tr>
 * <td>Successor</td>
 * <td>O(n)</td>
 * <td>O(1)</td>
 * </tr>
 * <tr>
 * <td>Predecessor</td>
 * <td>O(n)</td>
 * <td>O(1)</td>
 * </tr>
 * <tr>
 * <td>Minimum</td>
 * <td>O(n)</td>
 * <td>O(1)</td>
 * </tr>
 * <tr>
 * <td>Maximum</td>
 * <td>O(n)</td>
 * <td>O(1)</td>
 * </tr>
 * </table>
 * <p>
 *
 * <p>
 * The asymptotic worst-case running times for each of the three fundamental
 * priority queue operations when the data structure is implemented as an array
 * are shown bellow:
 * <table border="0">
 * <tr>
 * <th>Priority queue operation</th>
 * <th>Unsorted array</th>
 * <th>Sorted array</th>
 * </tr>
 * <tr>
 * <td>Insert</td>
 * <td>O(1)</td>
 * <td>O(n)</td>
 * </tr>
 * <tr>
 * <td>Find-Minimum</td>
 * <td>O(1)</td>
 * <td>O(1)</td>
 * </tr>
 * <tr>
 * <td>Delete-Minimum</td>
 * <td>O(n)</td>
 * <td>O(1)</td>
 * </tr>
 * </table>
 *
 * All priority queue deletions involve only the minimum element. By storing
 * the sorted array in reverse order (largest value on top), the minimum
 * element will be the last one in the array. Deleting the tail element
 * requires no movement of any items, just decrementing the number of remaining
 * items n, and so delete-minimum can be implemented in constant time.
 *
 * The table claims we can implement find-minimum in constant time. The trick
 * is using an extra variable to store an index to the minimum entry, so we can
 * simply return this value whenever we are asked to find-minimum. We need to
 * update this variable when an new value is inserted which is less than the
 * current minimum. When deleting the minimum, we then do an honest
 * find-minimum to restore our canned value. The honest find-minimum takes
 * linear time on an unsorted array, and hence can be folded into the cost of
 * each deletion.
 *
 * <p>
 *
 * @created Jan 8, 2013
 * @author Vassilis S. Moustakas <vsmoustakas@gmail.com>
 */
class Array {
public:
    /**
     * Default constructor.
     */
    Array();

    /**
     * Constructor.
     *
     * @param[in] size
     *     The size to be allocated.
     */
    Array(int size);

    /**
     * Destructor.
     */
    virtual ~Array();

    // -- getter methods

    /**
     * Gets the pointer to the wrapped array.
     *
     * @return The pointer to the the wrapped array.
     */
    inline int* pointer() { return m_pointer; }

    /**
     * Gets the size of the wrapped array.
     *
     * @return The size of the wrapped array.
     */
    inline int size() { return m_size; }

    // -- setter methods
    // -- public methods

    /**
     * @brief Search for an element in the array.
     *
     * <p>
     * This method implements a recursive algorithm.
     * </p>
     *
     * <p>
     * A binary search is O(log(n)) because half of the search is eliminated
     * (in a sense, searched) on each iteration. This is more efficient than a
     * simple search through all the elements, which would be O(n). However, in
     * order to perform a binary search the array must be sorted, an operation
     * that is usually O(n log(n)), unless of course the array is always kept
     * in sorted order.
     * </p>
     *
     * @param[in] array
     *     A pointer to the array to be searched.
     * @param[in] lower
     *     The index of the lower bound of the array spanning, in which the
     *     method will operate.
     * @param[in] upper
     *     The index of the upper bound of the array spanning, in which the
     *     method will operate.
     * @param[in] target The target to search for.
     *
     * @return The index of the target within the array; -1 if it wasn't found.
     */
    static int binary_search_recursive(int* array, int lower, int upper, int target);

    /**
     * @brief Search for an element in the array.
     *
     * <p>
     * This method implements an iterative algorithm.
     * </p>
     *
     * <p>
     * Read the documentation of the recursive implementation of this method
     * for an asymptotic analysis.
     * </p>
     *
     * @param[in] array
     *     A pointer to the array to be searched.
     * @param[in] size
     *     The size of the array to be searched.
     * @param[in] target
     *     The target to search for.
     *
     * @return The index of the target within the array; -1 if it wasn't found.
     */
    static int binary_search_iterative(int* array, int size, int target);

    /**
     * @brief Insertion sort.
     *
     * Worst case time complexity is Θ(n^2).
     *
     * @param[in] a
     *     A pointer to the array to be sorted.
     * @param[in] n
     *     The size of the array to be sorted.
     */
    static void insertion_sort(int* a, int n);

    /**
     * @brief Selection sort.
     *
     * Worst case time complexity is Θ(n^2).
     *
     * @param[in] a
     *     A pointer to the array to be sorted.
     * @param[in] n
     *     The size of the array to be sorted.
     */
    static void selection_sort(int* a, int n);

    /**
     * @brief Merge short
     *
     * <p>
     * Implements a recursive algorithm.
     * </p>
     *
     * <p>
     * Worst case time complexity is Θ(nlog(n)). As opposed to other in-place
     * algorithms, marger sort needs O(n) space to perform the merging step.
     * On the other hand, it is a stable sort and it can be modified to
     * implement external sorting for big data sets that do not fit in memory.
     * </p>
     *
     * @param[in] a
     *     A pointer to the array to be sorted.
     * @param[in] low
     *     .
     * @param[in] high
     *     .
     */
    static void merge_sort(int* a, int low, int high);

    /**
     * Prints the array in one line in standard output.
     */
    void print();
protected:
private:
    /**
     * The pointer to the array.
     */
    int* m_pointer;

    /**
     * The size of the array.
     */
    int m_size;

    /**
     * Auxiliary procedure used to implement recursion in the merge sort
     * algorithm.
     *
     * @param a
     *     The array.
     * @param l
     *     Index numbering the elements of the array so that <code>l</code>
     *     is the index of the first element for the left array to be merged.
     * @param m
     *     Index numbering the elements of the array so that <code>m</code>
     *     is the index of the first element for the right array to be merged.
     * @param h
     *     Index numbering the elements of the array so that <code>h</code>
     *     is the index of the last element for the right array to be merged.
     *
     * @see Array::merge_sort(int* a, int low, int high)
     */
    static void merge(int* a, int l, int m, int h);
};

#endif /* ARRAY_H_ */
