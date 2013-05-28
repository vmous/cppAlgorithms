/**
 * @file array_test.cpp
 *
 * @brief Test unit for the standard C array container class.
 *
 * @see array.h array.cpp
 *
 * @created Jan 8, 2013
 * @author Vassilis S. Moustakas <vsmoustakas@gmail.com>
 */

#include <iostream>
#include <stdlib.h>

#include "array.h"

#define MAX_RANDOM_NUMBER 1000


void prepare_array(Array<int> & arr)
{
    arr[0] = 10;
    arr[1] = 28;
    arr[2] = 103;
    arr[3] = 21;
    arr[4] = 7;
    arr[5] = 9;
    arr[6] = 1000;
    arr[7] = 99;
    arr[8] = 459;
    arr[9] = 1;
}


void test_copy_constructor()
{
    std::cout << "Testing copy constructor." << std::endl;

    Array<int> foo(10);
    prepare_array(foo);

    Array<int> first(foo);
    first.print();

    Array<int> second(10);
    second.print();

    Array<int> third(first);
    third.print();

    std::cout << std::endl;
}


void test_resize()
{
    std::cout << "Testing array resize." << std::endl;

    Array<int> foo(10);
    prepare_array(foo);
    foo.print();

    foo.resize(5);
    foo.resize(15);
    foo.print();

    std::cout << std::endl;
}


void test_binary_search_recursive()
{
    std::cout << "Testing recursive binary search." << std::endl;

    Array<int> tester;
    prepare_array(tester);

    // Binary search requires sorted array.
    Array<int>::merge_sort(tester, 0, tester.size() - 1);
    tester.print();

    int ret;
    int num;

    num = 10;
    ret = Array<int>::binary_search_recursive(tester, 0, tester.size() - 1, num);
    std::cout << "Searching " << num << " (recursive): " << ret << std::endl;

    num = 0;
    ret = Array<int>::binary_search_recursive(tester, 0, tester.size() - 1, num);
    std::cout << "Searching " << num << " (recursive): " << ret << std::endl;

    num = 1000000001;
    ret = Array<int>::binary_search_recursive(tester, 0, tester.size() - 1, num);
    std::cout << "Searching " << num << " (recursive): " << ret << std::endl;

    num = 1;
    ret = Array<int>::binary_search_recursive(tester, 0, tester.size() - 1, num);
    std::cout << "Searching " << num << " (recursive): " << ret << std::endl;

    std::cout << std::endl;
}


void test_binary_search_iterative()
{
    std::cout << "Testing iterative binary search." << std::endl;

    Array<int> tester;
    prepare_array(tester);

    // Binary search requires sorted array.
    Array<int>::merge_sort(tester, 0, tester.size() - 1);
    tester.print();

    int ret;
    int num;

    num = 10;
    ret = Array<int>::binary_search_iterative(tester, tester.size(), num);
    std::cout << "Searching " << num << " (iterative): " << ret << std::endl;

    num = 0;
    ret = Array<int>::binary_search_iterative(tester, tester.size(), num);
    std::cout << "Searching " << num << " (iterative): " << ret << std::endl;

    num = 1000000001;
    ret = Array<int>::binary_search_iterative(tester, tester.size(), num);
    std::cout << "Searching " << num << " (iterative): " << ret << std::endl;

    num = 1;
    ret = Array<int>::binary_search_iterative(tester, tester.size(), num);
    std::cout << "Searching " << num << " (iterative): " << ret << std::endl;

    std::cout << std::endl;
}


void test_insertion_sort()
{
    std::cout << "Testing insertion sort." << std::endl;

    Array<int> tester;
    prepare_array(tester);
    tester.print();
    Array<int>::insertion_sort(tester, tester.size());
    tester.print();

    std::cout << std::endl;
}


void test_selection_sort()
{
    std::cout << "Testing selection sort." << std::endl;

    Array<int> tester;
    prepare_array(tester);
    tester.print();
    Array<int>::selection_sort(tester, tester.size());
    tester.print();

    std::cout << std::endl;
}


void test_merge_sort()
{
    std::cout << "Testing merge sort." << std::endl;

    Array<int> tester;
    prepare_array(tester);
    tester.print();
    Array<int>::merge_sort(tester, 0, tester.size() - 1);
    tester.print();

    std::cout << std::endl;
}


int main(int argc, char** argv)
{
    test_copy_constructor();
    test_resize();
    test_binary_search_recursive();
    test_binary_search_iterative();
    test_insertion_sort();
    test_selection_sort();
    test_merge_sort();

    return EXIT_SUCCESS;
}
