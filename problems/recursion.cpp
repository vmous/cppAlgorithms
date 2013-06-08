/*
 * recursion.cpp
 *
 *  Created on: Jun 8, 2013
 *      Author: billy
 */

#include <queue>


/**
 * Compute the factorial of a given number.
 *
 * Recursive algorithm.
 *
 * @param[in] number
 *     The given number to compute its factorial.
 *
 * @return
 *     The factorial.
 */
int factorialRecursive(int number)
{
    if (number > 1) {
        // Recursive case.
        return number * factorialRecursive(number - 1);
    }
    else {
        // Base case.
        return 1;
    }
}


// #################
// #################


/**
 * Compute the factorial of a given number.
 *
 * Iterative algorithm.
 *
 * Iterative implementations are in most cases well more efficient than their
 * recursive counterparts in modern computer architectures.
 *
 * @param[in] number
 *     The given number to compute its factorial.
 *
 * @return
 *     The factorial.
 */
int factorialIterative(int number)
{
    int val = 1;
    for (int i = number; i > 1; i--)
        val *= i;

    return val;
}


// #################
// #################


/**
 * Compute the factorial of a given number and return all intermediate results.
 *
 * @param[in] number
 *     The given number to compute its factorial.
 * @param[in,out] results
 *     A reference to a queue to contain the intermediate results.
 *
 * @return
 *     The factorial at a certain recursion depth.
 *
 */
int factorialRecursiveIntermediate(int number, std::queue<int> & results)
{
    if (number > 1) {
        // Recursive case.
        results.push(number * factorialRecursiveIntermediate(number - 1, results));
        return results.back();
    }
    else {
        // Base case.
        results.push(1);
        return 1;
    }
}

