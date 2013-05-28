#ifndef ARRAY_H_
#define ARRAY_H_

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <climits>

/**
 * @class Array<T>
 *
 * @file array.h
 *
 * Standard C array container class definition.
 *
 * An array is the fundamental contiguously-allocated data structure. It
 * consists of fixed-size data records such that each element can be
 * efficiently located by its index. Arrays are used to construct more abstract
 * data structures such as <em>stacks</em>, <em>queues</em>,
 * <em>associative arrays (dictionaries)</em>.
 *
 * Advantages of contiguously-allocated structures are
 * <ul>
 * <li>
 * Constant-time (O(1)) access given the index.<br />
 * Because the index of each element maps directly to a particular memory
 * address, we can access arbitrary data items instantly provided we know the
 * index.
 * </li>
 * <li>
 * Space efficiency.<br />
 * Arrays consist purely of data, so no space is wasted with links or
 * other formatting information. Further, end-of-record information is not
 * needed because arrays are built from fixed-size records.
 * </li>
 * <li>
 * Memory locality.<br />
 * A common programming idiom involves iterating through all the elements
 * of a data structure. Arrays are good for this because they exhibit excellent
 * memory locality. Physical continuity between successive data accesses helps
 * exploit the high-speed cache memory on modern computer architectures.
 * </li>
 * </ul>
 *
 * Main disadvantage is
 * <ul>
 * <li>
 * Size adjustment.<br />
 * We cannot (easily) adjust their size during runtime.
 * </li>
 * </ul>
 *
 * Expanding arrays can be implemented by exploiting dynamic memory allocation.
 * A bigger array can be acquired and then copy the old one to the lower half
 * of the new one. It can be proven<sup>1</sup> that by doubling the size of
 * the array when we need to expand, each of the <i>n</i> elements need to be
 * moved 2 times on average. This means that the amount of management overhead
 * incurred by this mechanism (i.e., O(n)), is the same as it would have been
 * if a single array of sufficient size had been allocated in advance! Where we
 * definitely loose is on insertion complexity, which becomes
 * <em>amortized</em> O(1) because of the corner cases when an insertion causes
 * an expansion as well.
 *
 * <h3>Dictionary operations</h3>
 *
 * The asymptotic worst-case running times for each of the seven fundamental
 * dictionary operations when the data structure is implemented as an array
 * are shown bellow:
 * <table border="1">
 * <tr>
 * <th>Operation</th>
 * <th>Unsorted array</th>
 * <th>Sorted array</th>
 * </tr>
 * <tr>
 * <td><tt>Search</tt></td>
 * <td>O(n)</td>
 * <td>O(logn)</td>
 * </tr>
 * <tr>
 * <td><tt>Insert</tt></td>
 * <td>O(1)</td>
 * <td>O(n)</td>
 * </tr>
 * <tr>
 * <td><tt>Delete</tt></td>
 * <td>O(1)<sup>*</sup></td>
 * <td>O(n)</td>
 * </tr>
 * <tr>
 * <td><tt>Successor</tt></td>
 * <td>O(n)</td>
 * <td>O(1)</td>
 * </tr>
 * <tr>
 * <td><tt>Predecessor</tt></td>
 * <td>O(n)</td>
 * <td>O(1)</td>
 * </tr>
 * <tr>
 * <td><tt>Minimum</tt></td>
 * <td>O(n)</td>
 * <td>O(1)</td>
 * </tr>
 * <tr>
 * <td><tt>Maximum</tt></td>
 * <td>O(n)</td>
 * <td>O(1)</td>
 * </tr>
 * </table>
 * <sup>*</sup> When removing the element on index <tt>i</tt> we can fill
 * the hole that it leaves by just <tt>A[i]=A[n--]</tt>.
 *
 * <h3>Priority queue operations</h3>
 *
 * The asymptotic worst-case running times for each of the three fundamental
 * priority queue operations when the data structure is implemented as an array
 * are shown bellow:
 * <table border="1">
 * <tr>
 * <th>Operation</th>
 * <th>Unsorted array</th>
 * <th>Sorted array</th>
 * </tr>
 * <tr>
 * <td><tt>Insert</tt></td>
 * <td>O(1)</td>
 * <td>O(n)</td>
 * </tr>
 * <tr>
 * <td><tt>Find-Minimum</tt></td>
 * <td>O(1)</td>
 * <td>O(1)</td>
 * </tr>
 * <tr>
 * <td><tt>Delete-Minimum</tt></td>
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
 * <h3>Stack operations</h3>
 *
 * The asymptotic worst-case running times for each of the fundamental stack
 * operations when the data structure is implemented as an array is shown
 * bellow:
 * <table border="1">
 * <tr>
 * <th>Operation</th>
 * <th></th>
 * </tr>
 * <tr>
 * <td><tt>Push</tt></td>
 * <td>O(1)</td>
 * </tr>
 * <tr>
 * <td><tt>Pop</tt></td>
 * <td>O(1)</td>
 * </tr>
 * <tr>
 * <td><tt>Peek</tt></td>
 * <td>O(1)</td>
 * </tr>
 * <tr>
 * <td><tt>isEmpty</tt></td>
 * <td>O(1)</td>
 * </tr>
 * <tr>
 * <td><tt>isFull</tt></td>
 * <td>O(1)</td>
 * </tr>
 * </table>
 *
 * All operations are independent of <tt>n</tt> since only the top element is accessed.
 *
 * <sup>1</sup> Skiena, <i>The Algorithm Design Manual</i>, 2nd edition, page 67
 *
 * @created Jan 8, 2013
 * @author Vassilis S. Moustakas <vsmoustakas@gmail.com>
 */
template<class T>
class Array {
public:
    Array(int size = 10);
    Array(const Array<T> & obj);

    virtual ~Array();

    Array<T> & operator = (const Array<T> & obj);
    T & operator [] (int i);
    operator T *() const;

    // -- getter methods

    inline T * pointer() const { return m_pointer; }
    inline int size() const { return m_size; }

    // -- setter methods
    // -- public methods

    /**
     * Prints the array in one line in standard output.
     */
    void print();

    /**
     * Resizes the guarded array.
     *
     * @param[in] size
     *     The new size.
     */
    void resize(int size);

    // -- static methods

    /**
     * Search for an element in the array (recursive approach).
     *
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
     * @param[in] target
     *     The target to search for.
     *
     * @return The index of the target within the array; -1 if it wasn't found.
     */
    static int binary_search_recursive(T * array, int lower, int upper, T target);

    /**
     * Search for an element in the array (iterative approach).
     *
     * Read the documentation of the recursive implementation of this method
     * for an asymptotic analysis.
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
    static int binary_search_iterative(T * array, int size, T target);

    /**
     * Insertion sort.
     *
     * Worst case time complexity is Θ(n<sup>2</sup>).
     *
     * @param[in] a
     *     A pointer to the array to be sorted.
     * @param[in] n
     *     The size of the array to be sorted.
     */
    static void insertion_sort(T * a, int n);

    /**
     * Selection sort.
     *
     * Worst case time complexity is Θ(n<sup>2</sup>).
     *
     * @param[in] a
     *     A pointer to the array to be sorted.
     * @param[in] n
     *     The size of the array to be sorted.
     */
    static void selection_sort(T * a, int n);

    /**
     * Merge short.
     *
     * Implements a recursive algorithm.
     *
     * Worst case time complexity is Θ(nlog(n)). As opposed to other in-place
     * algorithms, marge sort needs O(n) space to perform the merging step.
     * On the other hand, it is a stable sort and it can be modified to
     * implement external sorting for big data sets that do not fit in memory.
     *
     * @param[in] a
     *     A pointer to the array to be sorted.
     * @param[in] low
     *     .
     * @param[in] high
     *     .
     */
    static void merge_sort(T * a, int low, int high);

private:
    T * m_pointer;
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
    static void merge(T * a, int l, int m, int h);
};

template<class T>
Array<T>::Array(int size)
{
    if (size < 0)
    {
        std::cerr << "Invalid array size!" << std::endl;
        exit(EXIT_FAILURE);
    }

    m_size = size;
    m_pointer = new T[m_size];
    if (!m_pointer)
    {
        std::cerr << "Memory allocation error!" << std::endl;
        exit(EXIT_FAILURE);
    }
}


template<class T>
Array<T>::Array(const Array<T> & obj)
{
    m_size = obj.size();
    m_pointer = new T[m_size];

    if (!m_pointer)
    {
        std::cerr << "Memory allocation error!" << std::endl;
        exit(EXIT_FAILURE);
    }

    T * src = obj.pointer();
    T * dst = m_pointer;
    memcpy(dst, src, m_size * sizeof(T));
}


template<class T>
Array<T>::~Array()
{
    delete[] m_pointer;
}


template<class T>
Array<T> & Array<T>::operator = (const Array<T> & obj)
{
    if (this != &obj)
    {
        delete m_pointer;
        m_pointer = 0;
        m_size = obj.size();
        m_pointer = new T[m_size];

        if (!m_pointer)
        {
            std::cerr << "Memory allocation error!" << std::endl;
            exit(EXIT_FAILURE);
        }

        T * src = obj.pointer();
        T * dst = m_pointer;
        memcpy(dst, src, m_size * sizeof(T));
    }
}


template<class T>
T & Array<T>::operator [] (int i)
{
    if (i < 0 || i >= m_size)
    {
        std::cerr << "Index out of range!" << std::endl;
        exit(EXIT_FAILURE);
    }

    return m_pointer[i];
}


template<class T>
Array<T>::operator T * () const
{
    return m_pointer;
}


template<class T>
void Array<T>::print()
{
    for (int i = 0; i < m_size; i++)
        std::cout << m_pointer[i] << " ";

    std::cout << std::endl;
}


template<class T>
void Array<T>::resize(int size)
{
    if (size <= m_size)
        std::cout << "You can only augment the array." << std::endl;
    else
    {
        if (size < 0)
        {
            std::cerr << "Invalid array size!" << std::endl;
            exit(EXIT_FAILURE);
        }

        T * src = m_pointer;
        T * dst = new T[size];

        if (!dst)
        {
            std::cerr << "Memory allocation error!" << std::endl;
            exit(EXIT_FAILURE);
        }

        memcpy(dst, src, m_size * sizeof(T));

        delete [] m_pointer;

        m_pointer = dst;
        m_size = size;
    }
}

template<class T>
int Array<T>::binary_search_recursive(T * array, int lower, int upper, T target)
{
    int range = upper - lower;

    if (range < 0) {
        // Limits reversed.
        return -1;
    }
    else if( (range == 0) && (array[lower] != target) ) {
        // Not in array.
        return -1;
    }

    if (array[lower] > array[upper]) {
        // Array unordered.
        return -1;
    }

    int center = lower + (range/2);

    if (target == array[center]) {
        // Base case.
        return center;
    }
    else if (target < array[center]) {
        return binary_search_recursive(array, lower, center - 1, target);
    }
    else {
        return binary_search_recursive(array, center + 1, upper, target);
    }
}


template<class T>
int Array<T>::binary_search_iterative(T * array, int size, T target)
{
    int lower = 0;
    int upper = size - 1;
    int center;
    int range;

    while( true ) {

        if( lower > upper ) {
            // Limits reversed.
            return -1;
        }

        range = upper - lower;

        if( range == 0 && array[lower] != target ) {
            // Not in array.
            return -1;
        }

        if( array[lower] > array[upper] ) {
            // Array unordered.
            return -1;
        }

        center = lower + (range/2);

        if( target == array[center] ){
            return center;
        }
        else if( target < array[center] ){
            upper = center - 1;
        }
        else {
            lower = center + 1;
        }
    }

    return -1;
}


template<class T>
void Array<T>::insertion_sort(T * a, int n)
{
    for (int i = 1; i < n; i++) {
        T key = *(a + i);

        int j = i - 1;
        // While we still are in bounds and we haven't found our proper place
        // in sorted order.
        while (i > 0 && j >= 0 && *(a + j) > key) {

            *(a + j + 1) = *(a + j);

            j = j - 1;
        }

        *(a + j + 1) = key;
    }
}


template<class T>
void Array<T>::selection_sort(T * a, int n)
{
    int min;

    for (int i = 0; i < n; i++) {
        min = i;
        for (int j = i; j < n; j++) {
            if(a[j] < a[min])
                min = j;
        }

        T tmp = *(a + i);
        *(a + i) = *(a + min);
        *(a + min) = tmp;
    }
}


template<class T>
void Array<T>::merge_sort(T * a, int low, int high)
{
    int mid;
    if (low < high) {
        mid = (low + high)/2;
        // Divide and conquer.
        merge_sort(a, low, mid);
        merge_sort(a, mid + 1, high);
        // Combine.
        merge(a, low, mid, high);
    }
}


template<class T>
void Array<T>::merge(T * a, int l, int m, int h)
{
    int n_1 = m - l + 1;
    int n_2 = h - m;
    int i, j, k;
    // Two temporary arrays to hold the two arrays to be merged.
    T * f = new T[h + 1];
    T * x = new T[h + 1];

    // Create arrays F[1..n_1 + 1] and X[1..n_2 + 1]
    for (i = 0; i < n_1; i++) {
        *(f + i) = *(a + l + i);
    }

    for (j = 0; j < n_2; j++) {
        *(x + j) = *(a + m + j + 1);
    }

    // Mark the end of each temporary array using <climits> definitions.
    // TODO: I hate this part of the algorithm! Need to re-think alternatives.
    // TODO: This point here DOES NOT WORK for T other than int!!!

    *(f + i) = INT_MAX;
    *(x + j) = INT_MAX;

    i = 0;
    j = 0;
    for (k = l; k <= h; k++) {
        if ( *(f + i) <= *(x + j) ) {
            *(a + k) = *(f + i);
            i++;
        }
        else {
            *(a + k) = *(x + j);
            j++;
        }
    }

    delete[] f;
    delete[] x;
}


#endif /* ARRAY_H_ */
