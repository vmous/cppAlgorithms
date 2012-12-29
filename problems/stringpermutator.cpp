/*
 * stringpermutator.cpp
 *
 * Implement a routine that prints all possible orderings of the characters in
 * a string. In other words, print all permutations that use all the characters
 * from the original string. For example, given the string “hat”, your function
 * should print the strings “tha”, “aht”, “tah”, “ath”, “hta”, and “hat”. Treat
 * each character in the input string as a distinct character, even if it is
 * repeated. Given the string “aaa”, your routine should print “aaa” six times.
 * You may print the permutations in any order you choose.
 *
 * Created on: Dec 14, 2012
 *      Author: billy
 */
#include <iostream>

#define MAX_STRING_LENGTH 4

char string[MAX_STRING_LENGTH] = {'a','b','c','d'};

void swap(char* x, char* y)
{
    char tmp = *x;
    *x = *y;
    *y = tmp;
}

void permute_recursive(char *s, int i, int n)
{
    if (i == n) {
        std::cout << s << std::endl;
    }
    else {
        for (int j = i; j <=n; j++) {
            swap( (s + i), (s + j) );
            permute_recursive(s, i + 1, n);
            // backtrack
            swap( (s + i), (s + j) );
        }
    }
}

int main(int argc, char** argv)
{
//    permute_iterative();
    permute_recursive(string, 0, MAX_STRING_LENGTH - 1);
}


