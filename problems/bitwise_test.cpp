/*
 * test_bitwise.cpp
 *
 *  Created on: Jun 4, 2013
 *      Author: billy
 */


#include <iostream>
#include <cstdlib>

#include "bitwise.cpp"


void test_amLittleEndian()
{
    std::cout << "########################################" << std::endl;
    std::cout << __FUNCTION__ << std::endl;
    std::cout << "########################################" << std::endl;

    if (amLittleEndian())
    {
        std::cout << "Am little-endian!" << std::endl;
    }
    else
    {
        std::cout << "Am big-endian!" << std::endl;
    }

    std::cout << std::endl;
}


void test_amLittleEndianWithUnion()
{
    std::cout << "########################################" << std::endl;
    std::cout << __FUNCTION__ << std::endl;
    std::cout << "########################################" << std::endl;

    if (amLittleEndianWithUnion())
    {
        std::cout << "Am little-endian!" << std::endl;
    }
    else
    {
        std::cout << "Am big-endian!" << std::endl;
    }

    std::cout << std::endl;
}


void test_numberOfOnes()
{
    std::cout << "########################################" << std::endl;
    std::cout << __FUNCTION__ << std::endl;
    std::cout << "########################################" << std::endl;

    int a = 10;
    std:: cout << "Number of 1s in " << a << " are " << numberOfOnes(a) << std::endl;

    a = 0;
    std:: cout << "Number of 1s in " << a << " are " << numberOfOnes(a) << std::endl;

    a = -10;
    std:: cout << "Number of 1s in " << a << " are " << numberOfOnes(a) << std::endl;

    std::cout << std::endl;
}


void test_bitsToModify()
{
    std::cout << "########################################" << std::endl;
    std::cout << __FUNCTION__ << std::endl;
    std::cout << "########################################" << std::endl;

    int a = 5;
    int b = 18;
    std:: cout << "Binary representation of numbers " << a << " and " << b << " differentiate in " << bitsToModify(a, b) << " bits."<< std::endl;

    std::cout << std::endl;
}


void test_swapWithoutBuffer()
{
    std::cout << "########################################" << std::endl;
    std::cout << __FUNCTION__ << std::endl;
    std::cout << "########################################" << std::endl;

    int x = 10;
    int y = 20;
    std::cout << "Before swap: x = " << x << " and y = " << y << std::endl;
    swapWithoutBuffer(x, y);
    std::cout << "After swap: x = " << x << " and y = " << y << std::endl;

    std::cout << std::endl;
}


// #################
// #################


int main(int argc, char** argv)
{
    test_amLittleEndian();
    test_amLittleEndianWithUnion();
    test_numberOfOnes();
    test_bitsToModify();
    test_swapWithoutBuffer();

    return EXIT_SUCCESS;
}



