/**
 * @file array_test.cpp
 *
 * @brief Test unit for the standard C array container class.
 *
 * @see Array.h Array.cpp
 *
 * @created Jan 8, 2013
 * @author Vassilis S. Moustakas <vsmoustakas@gmail.com>
 */

#include <iostream>

#include "array.h"

void test_binary_search_recursive();
void test_binary_search_iterative();
void test_insertion_sort();
void test_selection_sort();
void test_merge_sort();

int main(int argc, char** argv)
{
    test_binary_search_recursive();
    test_binary_search_iterative();
    test_insertion_sort();
    test_selection_sort();
    test_merge_sort();

    return 0;
}

void test_binary_search_recursive()
{
    std::cout << "Testing recursive binary search." << std::endl;

    Array* tester = new Array();

    // Binary search requires sorted array.
    Array::merge_sort(tester->pointer(), 0, tester->size() - 1);

    int ret;
    int num;

    num = 10;
    ret = Array::binary_search_recursive(tester->pointer(), 0, tester->size() - 1, num);
    std::cout << "Searching " << num << " (recursive): " << ret << std::endl;

    num = 0;
    ret = Array::binary_search_recursive(tester->pointer(), 0, tester->size() - 1, num);
    std::cout << "Searching " << num << " (recursive): " << ret << std::endl;

    num = 1000000001;
    ret = Array::binary_search_recursive(tester->pointer(), 0, tester->size() - 1, num);
    std::cout << "Searching " << num << " (recursive): " << ret << std::endl;

    num = 1;
    ret = Array::binary_search_recursive(tester->pointer(), 0, tester->size() - 1, num);
    std::cout << "Searching " << num << " (recursive): " << ret << std::endl;

    std::cout << std::endl;
}

void test_binary_search_iterative()
{
    std::cout << "Testing iterative binary search." << std::endl;

    Array* tester = new Array();

    // Binary search requires sorted array.
    Array::merge_sort(tester->pointer(), 0, tester->size() - 1);

    int ret;
    int num;

    num = 10;
    ret = Array::binary_search_iterative(tester->pointer(), tester->size(), num);
    std::cout << "Searching " << num << " (iterative): " << ret << std::endl;

    num = 0;
    ret = Array::binary_search_iterative(tester->pointer(), tester->size(), num);
    std::cout << "Searching " << num << " (iterative): " << ret << std::endl;

    num = 1000000001;
    ret = Array::binary_search_iterative(tester->pointer(), tester->size(), num);
    std::cout << "Searching " << num << " (iterative): " << ret << std::endl;

    num = 1;
    ret = Array::binary_search_iterative(tester->pointer(), tester->size(), num);
    std::cout << "Searching " << num << " (iterative): " << ret << std::endl;

    std::cout << std::endl;
}

void test_insertion_sort()
{
    std::cout << "Testing insertion sort." << std::endl;

    Array* tester = new Array();
    tester->print();
    Array::insertion_sort(tester->pointer(), tester->size());
    tester->print();

    std::cout << std::endl;
}

void test_selection_sort()
{
    std::cout << "Testing selection sort." << std::endl;

    Array* tester = new Array();
    tester->print();
    Array::selection_sort(tester->pointer(), tester->size());
    tester->print();

    std::cout << std::endl;
}

void test_merge_sort()
{
    std::cout << "Testing merge sort." << std::endl;

    Array* tester = new Array();
    tester->print();
    Array::merge_sort(tester->pointer(), 0, tester->size() - 1);
    tester->print();

    std::cout << std::endl;
}
