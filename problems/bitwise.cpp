/*
 * multiply_noop.cpp
 *
 *  Created on: Jun 3, 2013
 *      Author: billy
 */

#include <iostream>
#include <cstdlib>
#include <math.h>

/**
 * Check the endianness of your machine.
 *
 * How can you examine the individual bytes of an integer? A C character is a
 * single-byte data type. It could be useful to view an integer as four
 * consecutive characters. To do this, you create a pointer to the integer.
 * Then, you can cast the integer pointer to a character pointer. This enables
 * you to access the integer like an array of 1-byte data types. Using the
 * character pointer, you can examine the bytes and determine the format.
 * Specifically, to determine the computer’s endianness, get a pointer to an
 * integer with the value of 1. Then, cast the pointer to a <tt>char *</tt>.
 * This changes the size of the data to which the pointer points. When you
 * dereference this pointer, you access a 1-byte character instead of a 4-byte
 * integer. Then you can test the first byte to see if it is 1. If the byte’s
 * value is 1, then the machine is little-endian because the LSB is at the
 * lowest memory address. If the byte’s value is 0, then the machine is
 * big-endian because the MSB is at the lowest memory address.
 *
 */
bool amLittleEndian()
{
    int testNum;
    char * ptr;
    testNum = 1;
    ptr = (char *) &testNum;

    // return the byte at the lowest address.
    return (*ptr);
}


// #################
// #################


/**
 * Check the endianness of your machine.
 *
 * Use of union.
 */
bool amLittleEndianWithUnion()
{
    union {
        int daInt;
        char daByte;
    } endianTest;
    endianTest.daInt = 1;
    return endianTest.daByte;
}


// #################
// #################


/**
 * Write a function to get the number of 1s in the binary representation of the
 * given interger.
 *
 * Right shifting the given number and bitwise ANDing with 1 until the number
 * becomes zero, results in endless loop for negative numbers.
 *
 * TODO: Doesn't seem to work correctly though everywhere it is the same! Have
 * to check again the result for negative numbers...
 */
int numberOfOnes(int x)
{
    int count = 0;

    // Until the number becomes zero...
    while (x)
    {
        ++count;
        x = x & (x - 1);
    }

    return count;
}


// #################
// #################


/**
 * Given two integers calculate the number of bits that need to be modified to
 * change the one to the other.
 */
int bitsToModify(int x, int y)
{
    // We XOR the two numbers to set 1 to the bits that they differ.
    int temp = x ^ y;

    // Then we count the number of ones
    return numberOfOnes(temp);
}


// #################
// #################


/**
 * A function to swap two integers without the use of temporary buffer variable.
 *
 * @param[in,out] x
 *     A reference to the first number to be swapped.
 * @param[in,out] y
 *     A reference to the second number to be swapped.
 */
void swapWithoutBuffer(int & x, int & y)
{
    x = x ^ y;
    y = x ^ y;
    x = x ^ y;
}
