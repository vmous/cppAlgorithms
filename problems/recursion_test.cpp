/*
 * recursion_test.cpp
 *
 *  Created on: Jun 8, 2013
 *      Author: billy
 */

#include <iostream>
#include <cstdlib>
#include <queue>

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


// #################
// #################


int main(int argc, char** argv)
{
    test_factorialRecursive();
    test_factorialIterative();
    test_factorialRecursiveIntermediate();

    return EXIT_SUCCESS;
}
