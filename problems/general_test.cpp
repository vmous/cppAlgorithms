/*
 * test_general.cpp
 *
 *  Created on: Jun 4, 2013
 *      Author: billy
 */


#include <iostream>
#include <cstdlib>

#include "general.cpp"


void test_multiplyWithoutOperator()
{
    std::cout << "########################################" << std::endl;
    std::cout << __FUNCTION__ << std::endl;
    std::cout << "########################################" << std::endl;

    int a = 11;
    int b = 8;
    std::cout << a << " * " << b << " = " << multiplyWithoutOperator(a, b) << std::endl;

    a = 0;
    b = 4;
    std::cout << a << " * " << b << " = " <<  multiplyWithoutOperator(a, b) << std::endl;

    a = 4;
    b = 0;
    std::cout << a << " * " << b << " = " <<  multiplyWithoutOperator(a, b) << std::endl;

    a = -11;
    b = 8;
    std::cout << a << " * " << b << " = " <<  multiplyWithoutOperator(a, b) << std::endl;

    a = 11;
    b = -8;
    std::cout << a << " * " << b << " = " <<  multiplyWithoutOperator(a, b) << std::endl;

    a = -11;
    b = -8;
    std::cout << a << " * " << b << " = " << multiplyWithoutOperator(a, b) << std::endl;

    std::cout << std::endl;
}


void test_multiplyWithoutOperatorRecursively()
{
    std::cout << "########################################" << std::endl;
    std::cout << __FUNCTION__ << std::endl;
    std::cout << "########################################" << std::endl;

    int a = 11;
    int b = 8;
    std::cout << a << " * " << b << " = " << multiplyWithoutOperatorRecursively(a, b) << std::endl;

    a = 0;
    b = 4;
    std::cout << a << " * " << b << " = " <<  multiplyWithoutOperatorRecursively(a, b) << std::endl;

    a = 4;
    b = 0;
    std::cout << a << " * " << b << " = " <<  multiplyWithoutOperatorRecursively(a, b) << std::endl;

    a = -11;
    b = 8;
    std::cout << a << " * " << b << " = " <<  multiplyWithoutOperatorRecursively(a, b) << std::endl;

    a = 11;
    b = -8;
    std::cout << a << " * " << b << " = " <<  multiplyWithoutOperatorRecursively(a, b) << std::endl;

    a = -11;
    b = -8;
    std::cout << a << " * " << b << " = " << multiplyWithoutOperatorRecursively(a, b) << std::endl;

    std::cout << std::endl;
}


void test_multiplyWithoutOperatorExpLn()
{
    std::cout << "########################################" << std::endl;
    std::cout << __FUNCTION__ << std::endl;
    std::cout << "########################################" << std::endl;

    int a = 11;
    int b = 8;
    std::cout << a << " * " << b << " = " << multiplyWithoutOperatorExpLn(a, b) << std::endl;

    a = 0;
    b = 4;
    std::cout << a << " * " << b << " = " <<  multiplyWithoutOperatorExpLn(a, b) << std::endl;

    a = 4;
    b = 0;
    std::cout << a << " * " << b << " = " <<  multiplyWithoutOperatorExpLn(a, b) << std::endl;

    a = -11;
    b = 8;
    std::cout << a << " * " << b << " = " <<  multiplyWithoutOperatorExpLn(a, b) << std::endl;

    a = 11;
    b = -8;
    std::cout << a << " * " << b << " = " <<  multiplyWithoutOperatorExpLn(a, b) << std::endl;

    a = -11;
    b = -8;
    std::cout << a << " * " << b << " = " << multiplyWithoutOperatorExpLn(a, b) << std::endl;

    std::cout << std::endl;
}


void test_equalityWithoutOperator()
{
    std::cout << "########################################" << std::endl;
    std::cout << __FUNCTION__ << std::endl;
    std::cout << "########################################" << std::endl;

    int a = 11;
    int b = 11;
    std::cout << a << " and " << b << (equalityWithoutOperator(a, b) ? " are " : " are not ") << "equal." << std::endl;

    a = 0;
    b = 4;
    std::cout << a << " and " << b << (equalityWithoutOperator(a, b) ? " are " : " are not ") << "equal." << std::endl;

    a = 11;
    b = -11;
    std::cout << a << " and " << b << (equalityWithoutOperator(a, b) ? " are " : " are not ") << "equal." << std::endl;

    a = 0;
    b = 0;
    std::cout << a << " and " << b << (equalityWithoutOperator(a, b) ? " are " : " are not ") << "equal." << std::endl;

    std::cout << std::endl;
}


void test_rand7FromRand5()
{
    std::cout << "########################################" << std::endl;
    std::cout << __FUNCTION__ << std::endl;
    std::cout << "########################################" << std::endl;

    std::srand(time(NULL));
    int n = 5;
    int m = 7;
    std::cout << "For n = " << n << " and m = " << m << ":" << std::endl;

    for (int i = 0; i < 50; i++)
    {
        std::cout << rand7FromRand5() << " ";
    }
   std::cout << std::endl;

   std::cout << std::endl;
}


// #################
// #################


int main(int argc, char** argv)
{
    test_multiplyWithoutOperator();
    test_multiplyWithoutOperatorRecursively();
    test_multiplyWithoutOperatorExpLn();
    test_equalityWithoutOperator();
    test_rand7FromRand5();

    return EXIT_SUCCESS;
}
