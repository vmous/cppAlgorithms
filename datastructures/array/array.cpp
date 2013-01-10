/**
 * @class Array
 *
 * @file array.cpp
 *
 * @brief Standard C array container class definition.
 *
 * @created Jan 8, 2013
 * @author Vassilis S. Moustakas <vsmoustakas@gmail.com>
 */

#include <iostream>
#include <climits>

#include "array.h"

Array::Array()
{
    m_pointer = 0;
    m_size = 0;

    m_size = 10;
    m_pointer = new int[10];
    m_pointer[0] = 10;
    m_pointer[1] = 28;
    m_pointer[2] = 103;
    m_pointer[3] = 21;
    m_pointer[4] = 7;
    m_pointer[5] = 9;
    m_pointer[6] = 1000;
    m_pointer[7] = 99;
    m_pointer[8] = 459;
    m_pointer[9] = 1;
}

Array::Array(int size)
{
    m_pointer = new int[size];
    if(m_pointer)
        m_size = size;
    else
        m_size = 0;
}

Array::~Array()
{
    delete[] m_pointer;
    m_size = 0;
}

// -- getter methods
// -- setter methods
// -- public methods

int Array::binary_search_recursive(int* array, int lower, int upper, int target)
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

int Array::binary_search_iterative(int* array, int size, int target)
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

void Array::print()
{
    for (int i = 0; i < m_size; i++)
        std::cout << m_pointer[i] << " ";

    std::cout << std::endl;
}

void Array::insertion_sort(int* a, int n)
{
        for (int i = 1; i < n; i++) {
                int key = *(a + i);

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

void Array::selection_sort(int* a, int n)
{
    int min;

    for (int i = 0; i < n; i++) {
        min = i;
        for (int j = i; j < n; j++) {
            if(a[j] < a[min])
                min = j;
        }

        int tmp = *(a + i);
        *(a + i) = *(a + min);
        *(a + min) = tmp;
    }
}

void Array::merge_sort(int* a, int low, int high)
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

// -- private methods

void Array::merge(int* a, int l, int m, int h)
{
    int n_1 = m - l + 1;
    int n_2 = h - m;
    int i, j, k;
    // Two temporary arrays to hold the two arrays to be merged.
    int* f = new int[h + 1];
    int* x = new int[h + 1];

    // Create arrays F[1..n_1 + 1] and X[1..n_2 + 1]
    for (i = 0; i < n_1; i++) {
        *(f + i) = *(a + l + i);
    }

    for (j = 0; j < n_2; j++) {
        *(x + j) = *(a + m + j + 1);
    }

    // Mark the end of each temporary array using <climits> definitions.
    // TODO: I hate this part of the algorithm! Need to re-think alternatives.
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
