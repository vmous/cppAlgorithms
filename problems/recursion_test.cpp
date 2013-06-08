/*
 * recursion_test.cpp
 *
 *  Created on: Jun 8, 2013
 *      Author: billy
 */

#include <iostream>
#include <cstdlib>
#include <queue>
#include <cstring>

#include "recursion.cpp"


void test_factorialRecursive()
{
    std::cout << "########################################" << std::endl;
    std::cout << __FUNCTION__ << std::endl;
    std::cout << "########################################" << std::endl;

    int num = 5;

    std::cout << num << "! = " << factorialRecursive(num) << std::endl;

    std::cout << std::endl;
}


void test_factorialIterative()
{
    std::cout << "########################################" << std::endl;
    std::cout << __FUNCTION__ << std::endl;
    std::cout << "########################################" << std::endl;

    int num = 5;

    std::cout << num << "! = " << factorialIterative(num) << std::endl;

    std::cout << std::endl;
}


void test_factorialRecursiveIntermediate()
{
    std::cout << "########################################" << std::endl;
    std::cout << __FUNCTION__ << std::endl;
    std::cout << "########################################" << std::endl;

    std::queue<int> results;

    int number = 5;
    factorialRecursiveIntermediate(8, results);

    while (!results.empty())
    {
        std::cout << results.front() << " ";
        results.pop();
    }
    std::cout << std::endl;

    std::cout << std::endl;
}


void test_fib()
{
    std::cout << "########################################" << std::endl;
    std::cout << __FUNCTION__ << std::endl;
    std::cout << "########################################" << std::endl;

    int n = 10;

    for (int i = 0; i <= n; i++)
        std::cout << fib(i) << " ";
    std::cout << std::endl;

    std::cout << std::endl;
}


void test_permuteRecursive()
{
    std::cout << "########################################" << std::endl;
    std::cout << __FUNCTION__ << std::endl;
    std::cout << "########################################" << std::endl;

    char string[5] = {'a', 'b', 'c', '\0'};
    std::cout << "Recursive:" << std::endl;
    permuteRecursive(string, 0, strlen(string) - 1);

//    std::cout << std::endl;
//
//    char string_duplicates[5] = {'t', 'o', 'o', 'l', '\0'};
//    std::cout << "Recursive:" << std::endl;
//    permuteRecursive(string_duplicates, 0, strlen(string_duplicates) - 1);

    std::cout << std::endl;
}


void test_permuteIterative()
{
    std::cout << "########################################" << std::endl;
    std::cout << __FUNCTION__ << std::endl;
    std::cout << "########################################" << std::endl;

    char string[5] = {'a', 'b', 'c', '\0'};
    std::cout << "Iterative:" << std::endl;
    permuteIterative(string);

//    std::cout << std::endl;
//
//    char string_duplicates[5] = {'t', 'o', 'o', 'l', '\0'};
//    std::cout << "Iterative:" << std::endl;
//    permuteIterative(string_duplicates);

    std::cout << std::endl;
}


// #################
// #################


int main(int argc, char** argv)
{
    test_factorialRecursive();
    test_factorialIterative();
    test_factorialRecursiveIntermediate();
    test_fib();
    test_permuteRecursive();
    test_permuteIterative();

    return EXIT_SUCCESS;
}
