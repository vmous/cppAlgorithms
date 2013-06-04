/*
 * test_general.cpp
 *
 *  Created on: Jun 4, 2013
 *      Author: billy
 */


#include <iostream>
#include <cstdlib>

#include "general.cpp"


void test_multiplyWithouOperator()
{
    std::cout << "########################################" << std::endl;
    std::cout << __FUNCTION__ << std::endl;
    std::cout << "########################################" << std::endl;

    int a = 11;
    int b = 8;
    std:: cout << a << " * " << b << " = " << multiplyWithouOperator(a, b) << std::endl;

    a = 0;
    b = 4;
    std:: cout << a << " * " << b << " = " <<  multiplyWithouOperator(a, b) << std::endl;

    a = 4;
    b = 0;
    std:: cout << a << " * " << b << " = " <<  multiplyWithouOperator(a, b) << std::endl;

    a = -11;
    b = 8;
    std:: cout << a << " * " << b << " = " <<  multiplyWithouOperator(a, b) << std::endl;

    a = 11;
    b = -8;
    std:: cout << a << " * " << b << " = " <<  multiplyWithouOperator(a, b) << std::endl;


    a = -11;
    b = -8;
    std:: cout << a << " * " << b << " = " << multiplyWithouOperator(a, b) << std::endl;

    std::cout << std::endl;
}


void test_multiplyWithouOperatorRecursively()
{
    std::cout << "########################################" << std::endl;
    std::cout << __FUNCTION__ << std::endl;
    std::cout << "########################################" << std::endl;

    int a = 11;
    int b = 8;
    std:: cout << a << " * " << b << " = " << multiplyWithouOperatorRecursively(a, b) << std::endl;

    a = 0;
    b = 4;
    std:: cout << a << " * " << b << " = " <<  multiplyWithouOperatorRecursively(a, b) << std::endl;

    a = 4;
    b = 0;
    std:: cout << a << " * " << b << " = " <<  multiplyWithouOperatorRecursively(a, b) << std::endl;

    a = -11;
    b = 8;
    std:: cout << a << " * " << b << " = " <<  multiplyWithouOperatorRecursively(a, b) << std::endl;

    a = 11;
    b = -8;
    std:: cout << a << " * " << b << " = " <<  multiplyWithouOperatorRecursively(a, b) << std::endl;


    a = -11;
    b = -8;
    std:: cout << a << " * " << b << " = " << multiplyWithouOperatorRecursively(a, b) << std::endl;

    std::cout << std::endl;
}


// #################
// #################


int main(int argc, char** argv)
{
    test_multiplyWithouOperator();
    test_multiplyWithouOperatorRecursively();

    return EXIT_SUCCESS;
}
