/*
 * factorial.cpp
 *
 *  Created on: Dec 28, 2012
 *      Author: billy
 */

#include <iostream>

int factorial_recursive (int number)
{
    if (number > 1) {
        // Recursive case.
        return number * factorial_recursive(number - 1);
    }
    else {
        // Base case.
        return 1;
    }
}

/**
 * Iterative implementations are in most cases well more efficient than their
 * recursive counterparts.
 */
int factorial_iterative (int number)
{
    int val = 1;
    for (int i = number; i > 1; i--)
        val *= i;

    return val;
}

/**
 * For example, if you need a factorial routine that returns all of its
 * intermediate results (factorials less than n), as well as the final result
 * (n!), you most naturally return these results as an integer array, which
 * means the routine needs to allocate an array. You also need to know where
 * in the array each result should be written. These tasks are most easily
 * accomplished using a wrapper routine, as follows:
 */
int factorial_recursive_all(int number, int* results, int level)
{
    if (number > 1) {
        // Recursive case.
        results[level] = number * factorial_recursive_all(number - 1, results, level + 1);
        return results[level];
    }
    else {
        // Base case.
        results[level] = 1;
        return 1;
    }
}

int main(int argc, char** argv)
{
    int num = 5;

//    std::cout << num << "! = " << factorial_recursive(num) << std::endl;

    std::cout << num << "! = " << factorial_iterative(num) << std::endl;

    return 0;
}


