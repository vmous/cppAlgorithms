/*
 * integerstringconversions.cpp
 *
 * Write two conversion routines. The first routine converts a string to a
 * signed integer. You may assume that the string only contains digits and the
 * minus character (‘-’), that it is a properly formatted integer number, and
 * that the number is within the range of an int type. The second routine
 * converts a signed integer stored as an int back to a string.
 *
 *  Created on: Dec 28, 2012
 *      Author: billy
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <stack>

#define MAX_DIGITS 10

void itoa_recursive(int i)
{
    if(i < 10)
    {
        std::cout << (char)(i + '0');
    }
    else
    {
        itoa_recursive(i/10);
        std::cout << (char)(i % 10 + '0');
    }
}

void itoa_iterative(int i)
{
    std::stack<int> s;

    while (i >= 10)
    {
        s.push(i);
        i /= 10;
    }
    std::cout << (char) (i + '0');

    while (!s.empty())
    {
        i = s.pop();
        std::cout << (char) (i % 10 + '0');
    }
}

char* itoa_iterative_v2(int i)
{
    int j = 0;
    bool negative = false;

    char* a = (char*)malloc(10*sizeof(char));

    if (i < 0) {
        i *= -1;
        negative = true;
    }

    // Fill the buffer with digit characters in reverse order
    do {
        a[j++] = (char)((i % 10) + '0');
        i /= 10;
    } while (i != 0);

    if (negative)
        a[j++] = '-';

    a[j] = '\0';

    unsigned int a_len = strlen(a);
    for (int g = 0; g < a_len/2; g++) {
        char c = a[g];
        a[g] = a[a_len - 1 - g];
        a[a_len - 1 - g] = c;
    }

    return a;

}

// This is a good I implemented.
// TODO: Does not handle overflows.
int super_atoi(char * a)
{
    bool negative = false;
    int number = 0;

    if (!a || strlen(a) == 0)
    {
        std::cout << "Trying to convert null or empty string!" << std::endl;
        exit(EXIT_FAILURE);
    }

    int i = 1;
    int a_len = strlen(a);
    for (int j = a_len - 1; j >= 0 ; j--)
    {
        if (a[j] < '0' || a[j] > '9')
        {
            if (j == 0 && a[j] == '-')
                negative = true;
            else if (j == 0 && a[j] == '+')
                negative = false;
            else
            {
                std::cout << "Invalid number representation." << std::endl;
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            number += (a[j] - '0') * i;
            i *= 10;
        }
    }

    if (negative) number *= -1;

    return number;
}

int main(int argc, char** argv)
{
    char a1[3] = {'-', '1', '\0'};
    char a2[2] = {'0', '\0'};
    char a3[2] = {'1', '\0'};
    char a4[5] = {'-', '3', '6', '7', '\0'};
    char a5[3] = {'3', '6'};
    char * a6 = 0;
    char a7[1] = {'\0'};
    char a8[5] = {'-', '3', 'A', '7', '\0'};
//
//    printf("The string %s is the integer %d\n", a1, my_atoi(a1));
//    printf("The string %s is the integer %d\n", a2, my_atoi(a2));
//    printf("The string %s is the integer %d\n", a3, my_atoi(a3));
//    printf("The string %s is the integer %d\n", a4, my_atoi(a4));
//
//
//    int i1 = -1;
//    int i2 = 0;
//    int i3 = 1;
//    int i4 = -367;
//    char* a;
//
//    a = my_itoa(i1);
//    printf("The integer %d is the string %s\n", i1, a);
//    delete a;
//    a = my_itoa(i2);
//    printf("The integer %d is the string %s\n", i2, a);
//    delete a;
//    a = my_itoa(i3);
//    printf("The integer %d is the string %s\n", i3, a);
//    delete a;
//    a = my_itoa(i4);
//    printf("The integer %d is the string %s\n", i4, a);
//    delete a;

//    my_atoi_recursive(10);
//    my_atoi_recursive(-10);

    printf("The string %s is the integer %d\n", a1, super_atoi(a1));
    printf("The string %s is the integer %d\n", a2, super_atoi(a2));
    printf("The string %s is the integer %d\n", a3, super_atoi(a3));
    printf("The string %s is the integer %d\n", a4, super_atoi(a4));
    printf("The string %s is the integer %d\n", a5, super_atoi(a5));
    printf("The string %s is the integer %d\n", a6, super_atoi(a6));
    printf("The string %s is the integer %d\n", a7, super_atoi(a7));
    printf("The string %s is the integer %d\n", a8, super_atoi(a8));

    return 0;
}

