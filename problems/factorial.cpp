/*
 * factorial.cpp
 *
 *  Created on: Dec 28, 2012
 *      Author: billy
 */

#include <iostream>

int factorial (int number)
{
    if (number > 1) {
        // Recursive case.
        return number * factorial(number - 1);
    }
    else {
        // Base case.
        return 1;
    }
}

int main(int argc, char** argv)
{
    int num = 4;

    std::cout << num << "! = " << factorial(num) << std::endl;

    return 0;
}


