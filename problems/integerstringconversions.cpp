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
#include <cstring>

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

void my_itoa()
{

}

int main(int argc, char** argv)
{
    char s_1[4] = {'-', '1'};
    char s_2[4] = {'0'};
    char s_3[4] = {'1'};
    char s_4[4] = {'-', '3', '6', '7'};

    printf("The string %s is the integer %d\n", s_1, my_atoi(s_1));
    printf("The string %s is the integer %d\n", s_2, my_atoi(s_2));
    printf("The string %s is the integer %d\n", s_3, my_atoi(s_3));
    printf("The string %s is the integer %d\n", s_4, my_atoi(s_4));

    return 0;
}

