/*
 * general.cpp
 *
 *  Created on: Jun 4, 2013
 *      Author: billy
 */

#include <cmath>


/**
 * Multiply two integers without using the multiplication oparator.
 *
 * If we wanted to multiply an integer by 2 (or any other power of 2 - a.k.a.
 * an even number) then we would just need to shift the given integer left by
 * one (or the power of 2) place(s).
 */
int multiplyWithoutOperator(int x, int y)
{
    bool negative = false;
    if (x < 0)
    {
        if (y > 0) negative = true;
    }
    else
    {
        if (y < 0) negative = true;
    }

    x = (int) std::abs((long int) x);
    y = (int) std::abs((long int) y);

    int result = 0;

    for(int i = 1; i <= y; i++)
        result += x;

    return (negative ? (-1 * result) : result);
}


// #################
// #################


/**
 * Multiply two integers without using the multiplication oparator.
 *
 * Nice recursive implementation.
 */
int multiplyWithoutOperatorRecursively(int x, int y)
{
    /* 0  multiplied with anything gives 0 */
    if(y == 0)
        return 0;

    /* Add x one by one */
    if(y > 0 )
        return (x + multiplyWithoutOperatorRecursively(x, y-1));

    /* the case where y is negative */
    if(y < 0 )
        return -multiplyWithoutOperatorRecursively(x, -y);
}


// #################
// #################


/**
 * Multiply two integers without using the multiplication oparator.
 *
 * Cooler than cool mathematical implementation.
 */
int multiplyWithoutOperatorExpLn(int x, int y)
{
    bool negative = false;
    if (x < 0)
    {
        if (y > 0) negative = true;
    }
    else
    {
        if (y < 0) negative = true;
    }

    x = (int) std::abs((long int) x);
    y = (int) std::abs((long int) y);

    int result = exp(log(x) + log(y));

    return (negative ? (-1 * result) : result);
}


// #################
// #################


/**
 * A function to determine whether the two given numbers are equal without using
 * the equality operator.
 */
bool equalityWithoutOperator(int x, int y)
{
    return !(x ^ y);
}
