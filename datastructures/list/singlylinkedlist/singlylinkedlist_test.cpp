/**
 * @file singlylinkedlist_test.cpp
 *
 * Test unit for the singly linked list class.
 *
 * @see singlylinkedlist.h singlylinkedlist.cpp singlylinkedlistnode.h
 * singlylinkedlistnode.cpp
 *
 * @created Dec 11, 2012
 * @author Vassilis S. Moustakas <vsmoustakas@gmail.com>
 */

#include "singlylinkedlist.h"

#include <cstdlib>
#include <iostream>
#include <ctime>

void init_list_random();
void init_list_std();

void test_clear();
void test_prepend();
void test_append();
void test_find_iterative();
void test_find_recursive();
void test_predecessor_iterative();
void test_predecessor_recursive();
void test_remove();
void test_revert();
void test_sort();
//void test_isCircular();
//void test_circulize();
void test_nth_to_last();
void test_print();

SinglyLinkedList<int> * list = new SinglyLinkedList<int>();

int main (int argc, char** argv)
{
    test_clear();
    test_prepend();
    test_append();
    test_find_iterative();
    test_find_recursive();
    test_predecessor_iterative();
    test_predecessor_recursive();
    test_remove();
    test_revert();
    test_sort();
//    test_isCircular();
//    test_circulize();
    test_nth_to_last();
    test_print();

    return EXIT_SUCCESS;
}


// auxiliary functions


void init_list_random()
{
    if(list->head())
        list->clear();

    srand(time(0));
    for (int i = 0; i < 11; i++) {
        list->prepend(new SinglyLinkedListNode<int>(rand() % 100));
    }
}


void init_list_random_circular()
{
    if(list->head())
        list->clear();

    srand(time(0));
    for (int i = 0; i < 1; i++) {
        list->prepend(new SinglyLinkedListNode<int>(rand() % 100));
    }

    list->circulize();
}


void init_list_std()
{
    if(list->head())
        list->clear();

    for (int i = 0; i < 11; i++) {
        list->prepend(new SinglyLinkedListNode<int>(i));
    }
}


void finalize_list()
{
    if(list->head())
        list->clear();
}


// test functions


void test_clear()
{
    std::cout << "########################################" << std::endl;
    std::cout << __FUNCTION__ << std::endl;
    std::cout << "########################################" << std::endl;

    init_list_std();

    std::cout << "Original list:" << std::endl;
    list->print();
    std::cout << "Cleared list:" << std::endl;
    list->clear();
    list->print();

    finalize_list();
    std::cout << std::endl;
}


void test_prepend()
{
    std::cout << "########################################" << std::endl;
    std::cout << __FUNCTION__ << std::endl;
    std::cout << "########################################" << std::endl;

    init_list_std();

    std::cout << "Original list:" << std::endl;
    list->print();

    srand(time(0));
    int random = rand();

    std::cout << "Prepend " << random << std::endl;
    list->prepend(new SinglyLinkedListNode<int>(random));
    list->print();

    finalize_list();
    std::cout << std::endl;
}


void test_append()
{
    std::cout << "########################################" << std::endl;
    std::cout << __FUNCTION__ << std::endl;
    std::cout << "########################################" << std::endl;

    init_list_std();

    std::cout << "Original list:" << std::endl;
    list->print();

    srand(time(0));
    int random = rand();

    std::cout << "Prepend " << random << std::endl;
    list->append(new SinglyLinkedListNode<int>(random));
    list->print();

    finalize_list();
    std::cout << std::endl;
}


void test_find_iterative()
{
    std::cout << "########################################" << std::endl;
    std::cout << __FUNCTION__ << std::endl;
    std::cout << "########################################" << std::endl;

    init_list_std();

    std::cout << "Original list:" << std::endl;
    list->print();

    int d;
    SinglyLinkedListNode<int> * found;

    // -- Finding head
    d = 10;
    found = list->find_iterative(d);
    std::cout << "Finding data " << d << " (iterative): ";
    if (found != 0) {
        std::cout <<  "found!" << std::endl;
    }
    else {
        std::cout <<  "NOT found!" << std::endl;
    }

    // -- Finding other
    d = 0;
    found = list->find_iterative(d);
    std::cout << "Finding data " << d << " (iterative): ";
    if (found != 0) {
        std::cout <<  "found!" << std::endl;
    }
    else {
        std::cout <<  "NOT found!" << std::endl;
    }

    // -- Finding non-existent
    d = 100;
    found = list->find_iterative(d);
    std::cout << "Finding data " << d << " (iterative): ";
    if (found != 0) {
        std::cout <<  "found!" << std::endl;
    }
    else {
        std::cout <<  "NOT found!" << std::endl;
    }

    finalize_list();
    std::cout << std::endl;
}


void test_find_recursive()
{
    std::cout << "########################################" << std::endl;
    std::cout << __FUNCTION__ << std::endl;
    std::cout << "########################################" << std::endl;

    init_list_std();

    std::cout << "Original list:" << std::endl;
    list->print();

    int d;
    SinglyLinkedListNode<int> * found;

    // -- Finding head
    d = 10;
    found = list->find_recursive(list->head(), d);
    std::cout << "Finding data " << d << " (recursive): ";
    if (found != 0) {
        std::cout <<  "found!" << std::endl;
    }
    else {
        std::cout <<  "NOT found!" << std::endl;
    }

    // -- Finding other
    d = 0;
    found = list->find_recursive(list->head(), d);
    std::cout << "Finding data " << d << " (recursive): ";
    if (found != 0) {
        std::cout <<  "found!" << std::endl;
    }
    else {
        std::cout <<  "NOT found!" << std::endl;
    }

    // -- Finding non-existent
    d = 100;
    found = list->find_recursive(list->head(), d);
    std::cout << "Finding data " << d << " (recursive): ";
    if (found != 0) {
        std::cout <<  "found!" << std::endl;
    }
    else {
        std::cout <<  "NOT found!" << std::endl;
    }

    finalize_list();
    std::cout << std::endl;
}


void test_predecessor_iterative()
{
    std::cout << "########################################" << std::endl;
    std::cout << __FUNCTION__ << std::endl;
    std::cout << "########################################" << std::endl;

    init_list_std();

    std::cout << "Original list:" << std::endl;
    list->print();

    SinglyLinkedListNode<int> * pred;

    // -- Checking head predecessor.

    pred = list->predecessor_iterative(10);
    std::cout << "Predecessor head (iterative): ";
    if (pred != 0) {
        std::cout << pred->data() << std::endl;
    }
    else {
        std::cout << "No predecessor found!" << std::endl;
    }

    // -- Checking other predecessor.

    pred = list->predecessor_iterative(0);
    std::cout << "Predecessor of 0 / tail (iterative): ";
    if (pred != 0) {
        std::cout << pred->data() << std::endl;
    }
    else {
        std::cout << "No predecessor found!" << std::endl;
    }

    // -- Checking predecessor of non existent node

    pred = list->predecessor_iterative(100);
    std::cout << "Predecessor of 100 / non-existent (iterative): ";
    if (pred != 0) {
        std::cout << pred->data() << std::endl;
    }
    else {
        std::cout << "No predecessor found!" << std::endl;
    }

    finalize_list();
    std::cout << std::endl;
}


void test_predecessor_recursive()
{
    std::cout << "########################################" << std::endl;
    std::cout << __FUNCTION__ << std::endl;
    std::cout << "########################################" << std::endl;

    init_list_std();

    std::cout << "Original list:" << std::endl;
    list->print();

    SinglyLinkedListNode<int> * pred;

    // -- Checking head predecessor.

    pred = list->predecessor_recursive(list->head(), 10);
    std::cout << "Predecessor head (recursive): ";
    if (pred != 0) {
        std::cout << pred->data() << std::endl;
    }
    else {
        std::cout << "No predecessor found!" << std::endl;
    }

    // -- Checking other predecessor.

    pred = list->predecessor_recursive(list->head(), 0);
    std::cout << "Predecessor of 0 / tail (recursive): ";
    if (pred != 0) {
        std::cout << pred->data() << std::endl;
    }
    else {
        std::cout << "No predecessor found!" << std::endl;
    }

    // -- Checking predecessor of non existent node

    pred = list->predecessor_recursive(list->head(), 100);
    std::cout << "Predecessor of 100 / non-existent (recursive): ";
    if (pred != 0) {
        std::cout << pred->data() << std::endl;
    }
    else {
        std::cout << "No predecessor found!" << std::endl;
    }

    finalize_list();
    std::cout << std::endl;
}


void test_remove()
{
    std::cout << "########################################" << std::endl;
    std::cout << __FUNCTION__ << std::endl;
    std::cout << "########################################" << std::endl;

    bool done = false;
    init_list_std();

    std::cout << "Original list:" << std::endl;
    list->print();

    int toremove = 10;
    std::cout << "Removing head node: " << toremove << std::endl;
    done = list->remove(toremove);
    list->print();

    toremove = 5;
    std::cout << "Removing middle node: " << toremove << std::endl;
    done = list->remove(toremove);
    list->print();

    toremove = 0;
    std::cout << "Removing tail node: " << toremove << std::endl;
    done = list->remove(toremove);
    list->print();

    std::cout << "Trying to remove none existent node: " << toremove << std::endl;
    done = list->remove(toremove);
    list->print();

    finalize_list();
    std::cout << std::endl;
}


void test_revert()
{
    std::cout << "########################################" << std::endl;
    std::cout << __FUNCTION__ << std::endl;
    std::cout << "########################################" << std::endl;

    init_list_std();

    std::cout << "Original list:" << std::endl;
    list->print();

    std::cout << "Reverted list:" << std::endl;
    list->revert();
    list->print();

    finalize_list();
    std::cout << std::endl;
}


void test_sort()
{
    std::cout << "########################################" << std::endl;
    std::cout << __FUNCTION__ << std::endl;
    std::cout << "########################################" << std::endl;

    init_list_random();

    std::cout << "Original list:" << std::endl;
    list->print();

    std::cout << "Sorted list:" << std::endl;
    list->sort();
    list->print();

    finalize_list();
    std::cout << std::endl;
}


// ATTENTION: Broken finalization. KEEP DISABLED!
//void test_isCircular()
//{
//    std::cout << "########################################" << std::endl;
//    std::cout << __FUNCTION__ << std::endl;
//    std::cout << "########################################" << std::endl;
//
//    init_list_std();
//    std::cout << "isCirular = " << (list->isCircular() ? "yes" : "no") << std::endl;
//    finalize_list();
//
//    init_list_random_circular();
//    std::cout << "isCirular = " << (list->isCircular() ? "yes" : "no") << std::endl;
//
//    finalize_list();
//    std::cout << std::endl;
//}


// ATTENTION: Broken finalization. KEEP DISABLED!
//void test_circulize()
//{
//    std::cout << "########################################" << std::endl;
//    std::cout << __FUNCTION__ << std::endl;
//    std::cout << "########################################" << std::endl;
//
//    init_list_std();
//
//    list->circulize();
//    list->print();
//
//    finalize_list();
//    std::cout << std::endl;
//}


void test_nth_to_last()
{
    std::cout << "########################################" << std::endl;
    std::cout << __FUNCTION__ << std::endl;
    std::cout << "########################################" << std::endl;

    init_list_std();

    list->print();

    int n = 0;
    SinglyLinkedListNode<int> * sln = list->nth_to_last(n);
    if (sln)
        std::cout << "The " << n << "-th to last is " << list->nth_to_last(n)->data() << "." << std::endl;
    else
        std::cout << "The " << n << "-th to last is \"undefined\"." << std::endl;

    n = 5;
    sln = list->nth_to_last(n);
    if (sln)
        std::cout << "The " << n << "-th to last is " << list->nth_to_last(n)->data() << "." << std::endl;
    else
        std::cout << "The " << n << "-th to last is \"undefined\"." << std::endl;

    n = 10;
    sln = list->nth_to_last(n);
    if (sln)
        std::cout << "The " << n << "-th to last is " << list->nth_to_last(n)->data() << "." << std::endl;
    else
        std::cout << "The " << n << "-th to last is \"undefined\"." << std::endl;

    n = 11;
    sln = list->nth_to_last(n);
    if (sln)
        std::cout << "The " << n << "-th to last is " << list->nth_to_last(n)->data() << "." << std::endl;
    else
        std::cout << "The " << n << "-th to last is \"undefined\"." << std::endl;

    n = -1;
    sln = list->nth_to_last(n);
    if (sln)
        std::cout << "The " << n << "-th to last is " << list->nth_to_last(n)->data() << "." << std::endl;
    else
        std::cout << "The " << n << "-th to last is \"undefined\"." << std::endl;

    finalize_list();
    std::cout << std::endl;
}


void test_print()
{
    std::cout << "########################################" << std::endl;
    std::cout << __FUNCTION__ << std::endl;
    std::cout << "########################################" << std::endl;

    init_list_std();

    std::cout << "Printing list:" << std::endl;
    list->print();

    finalize_list();
    std::cout << std::endl;
}
