/*
 * recursion.cpp
 *
 *  Created on: Jun 8, 2013
 *      Author: billy
 */

#include <queue>
#include <algorithm>



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


// #################
// #################


/**
 * Function to compute the nth Fibonacci number.
 *
 * @param[in] n
 *     The n-th number.
 *
 * @return
 *     The n-th number of the Fibonacci sequence.
 */
long fib(int n)
{
    return (n <= 1 ? n : fib(n - 1) + fib(n - 2));
}


// #################
// #################


/**
 * String permutation.
 *
 * Recursive algorithm.
 *
 * @param[in,out] s
 *     The string to be permuted.
 * @param[in] i
 *     The index of the string for a given recursion step.
 * @param[in] n
 *     The index of the last element in the string.
 */
void permuteRecursive(char *s, int i, int n)
{
    if (i == n)
    {
        // This part is executed when I have recursively come up to the last
        // element, then we print the state of the array now.

        // if string contains duplicates then at this point it might be a good
        // idea to have a hash table and:
        // 1. If s is inside the hash table do not print it
        // 2. If s is not inside the hash table print it and add it to the hash
        //    table.
        std::cout << s << std::endl;
    }
    else
    {
        for (int j = i; j <= n; j++)
        {
            // What the first swap is doing is by swapping i with j it fixes the
            // respective spot.
            std::swap( s[i], s[j] );
            permuteRecursive(s, i + 1, n);
            // backtrack
            std::swap( s[i], s[j] );
        }
    }
}


// #################
// #################


/**
 * String permutation.
 *
 * Iterative algorithm.
 *
 * @param[in,out] s
 *     The string to be permuted.
 */
void permuteIterative(char* s)
{
    unsigned int * p = new unsigned int[strlen(s)];
    register unsigned int i, j, tmp; // Upper Index i; Lower Index j

    for(i = 0; i < strlen(s); i++)
    {
        // p[i] == i controls iteration and index boundaries for i
        p[i] = 0;
    }

    std::cout << s << std::endl;

    // setup first swap points to be 1 and 0 respectively (i & j)
    i = 1;
    while(i < strlen(s))
    {
        if (p[i] < i)
        {
            // IF i is odd then j = p[i] otherwise j = 0
            j = i % 2 * p[i];
            std::swap( s[i], s[j] );

            std::cout << s << std::endl;

            // increase index "weight" for i by one
            p[i]++;
            // reset index i to 1 (assumed)
            i = 1;
        }
        else
        {
            // otherwise p[i] == i
            // reset p[i] to zero
            p[i] = 0;
            // set new index value for i (increase by one)
            i++;
        }
    }
    delete p;
}

