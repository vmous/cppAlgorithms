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

#define MAX_DIGITS 10

int my_atoi(char* a)
{
   int i = 0;
   int j = 0;
   bool negative = false;
   unsigned int a_len = strlen(a);

   if(a[j] == '-') {
       negative = true;
       j++;
   }

   while(j < a_len) {
       i *= 10;
       i += (a[j++] - '0');
   }

   if (negative)
       i *= -1;

   return i;
}

char* my_itoa(int i)
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

int main(int argc, char** argv)
{
    char a1[2] = {'-', '1'};
    char a2[1] = {'0'};
    char a3[1] = {'1'};
    char a4[4] = {'-', '3', '6', '7'};

    printf("The string %s is the integer %d\n", a1, my_atoi(a1));
    printf("The string %s is the integer %d\n", a2, my_atoi(a2));
    printf("The string %s is the integer %d\n", a3, my_atoi(a3));
    printf("The string %s is the integer %d\n", a4, my_atoi(a4));


    int i1 = -1;
    int i2 = 0;
    int i3 = 1;
    int i4 = -367;

    printf("The integer %d is the string %s\n", i1, my_itoa(i1));
    printf("The integer %d is the string %s\n", i2, my_itoa(i2));
    printf("The integer %d is the string %s\n", i3, my_itoa(i3));
    printf("The integer %d is the string %s\n", i4, my_itoa(i4));

    return 0;
}

