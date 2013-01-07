/*
 * singlylinkedlist_test.cpp
 *
 *  Created on: Dec 11, 2012
 *      Author: billy
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
void test_print();

SinglyLinkedList* list = new SinglyLinkedList();

int main (int argc, char** argv)
{
//    test_clear();
//    test_prepend();
//    test_append();
//    test_find_iterative();
//    test_find_recursive();
//    test_predecessor_iterative();
//    test_predecessor_recursive();
//    test_remove();
//    test_revert();
    test_sort();
//    test_print();

    return 1;
}

void init_list_random()
{
    srand(time(0));
    for (int i = 0; i < 11; i++) {
        list->prepend(new SinglyLinkedListNode(rand()));
    }
}

void init_list_std()
{
    for (int i = 0; i < 11; i++) {
        list->prepend(new SinglyLinkedListNode(i));
    }
}

void test_clear()
{
    init_list_std();

    std::cout << "Original list:" << std::endl;
    list->print();

    std::cout << "Cleared list:" << std::endl;
    list->clear();
    list->print();
}

void test_prepend()
{
    init_list_std();

    std::cout << "Original list:" << std::endl;
    list->print();

    srand(time(0));
    int random = rand();

    std::cout << "Prepend " << random << std::endl;
    list->prepend(new SinglyLinkedListNode(random));
    list->print();

    list->clear();
}

void test_append()
{
    init_list_std();

    std::cout << "Original list:" << std::endl;
    list->print();

    srand(time(0));
    int random = rand();

    std::cout << "Prepend " << random << std::endl;
    list->append(new SinglyLinkedListNode(random));
    list->print();

    list->clear();
}

void test_find_iterative()
{
    init_list_std();

    std::cout << "Original list:" << std::endl;
    list->print();

    int d;
    SinglyLinkedListNode* found;

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

    list->clear();
}

void test_find_recursive()
{
    init_list_std();

    std::cout << "Original list:" << std::endl;
    list->print();

    int d;
    SinglyLinkedListNode* found;

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

    list->clear();
}

void test_predecessor_iterative()
{
    init_list_std();

    std::cout << "Original list:" << std::endl;
    list->print();

    SinglyLinkedListNode* pred;

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

    list->clear();
}

void test_predecessor_recursive()
{
    init_list_std();

    std::cout << "Original list:" << std::endl;
    list->print();

    SinglyLinkedListNode* pred;

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

    list->clear();
}

void test_remove()
{
    bool done = false;
    init_list_std();

    std::cout << "Original list:" << std::endl;
    list->print();

    std::cout << "Removing head node:" << std::endl;
    done = list->remove(10);
    list->print();

    std::cout << "Removing middle node:" << std::endl;
    done = list->remove(5);
    list->print();

    std::cout << "Removing tail node:" << std::endl;
    done = list->remove(0);
    list->print();

    std::cout << "Trying to remove none existent node:" << std::endl;
    done = list->remove(0);
    list->print();
}

void test_revert()
{
    init_list_std();

    std::cout << "Original list:" << std::endl;
    list->print();

    std::cout << "Reverted list:" << std::endl;
    list->revert();
    list->print();
}

void test_sort()
{
    init_list_random();

    std::cout << "Original list:" << std::endl;
    list->print();

    std::cout << "Sorted list:" << std::endl;
    list->sort();
    list->print();
}

void test_print()
{
    init_list_std();

    std::cout << "Printing list:" << std::endl;
    list->print();

    list->clear();
}
