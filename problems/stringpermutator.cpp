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
char string_duplicates[MAX_STRING_LENGTH] = {'t','o','o','l'};

/**
 * Just swaps the elements pointed to by the respective pointers without
 * changing the pointers themselves.
 */
void swap(char* x, char* y)
{
    char tmp = *x;
    *x = *y;
    *y = tmp;
}

void permute_recursive(char *s, int i, int n)
{
    if (i == n) {
        // if string contains duplicates then at this point it might be a good
        // idea to have a hash table and:
        // 1. If s is inside the hash table do not print it
        // 2. If s is not inside the hash table print it and add it to the hash
        //    table.
        std::cout << s << std::endl;
    }
    else {
        for (int j = i; j <= n; j++) {
            swap( (s + i), (s + j) );
            permute_recursive(s, i + 1, n);
            // backtrack
            swap( (s + i), (s + j) );
        }
    }
}

void permute_iterative(char* s)
{
    unsigned int p[MAX_STRING_LENGTH];
    register unsigned int i, j, tmp; // Upper Index i; Lower Index j

    for(i = 0; i < MAX_STRING_LENGTH; i++) {
        // p[i] == i controls iteration and index boundaries for i
        p[i] = 0;
    }

    std::cout << s << std::endl;

    // setup first swap points to be 1 and 0 respectively (i & j)
    i = 1;
    while(i < MAX_STRING_LENGTH) {
        if (p[i] < i) {
            // IF i is odd then j = p[i] otherwise j = 0
            j = i % 2 * p[i];
            swap( (s + i), (s + j) );

            std::cout << s << std::endl;

            // increase index "weight" for i by one
            p[i]++;
            // reset index i to 1 (assumed)
            i = 1;
        } else {
            // otherwise p[i] == i
            // reset p[i] to zero
            p[i] = 0;
            // set new index value for i (increase by one)
            i++;
        }
    }
}

int main(int argc, char** argv)
{
    std::cout << "Recursive:" << std::endl;
    permute_recursive(string, 0, MAX_STRING_LENGTH - 1);
    std::cout << std::endl << "Iterative:" << std::endl;
    permute_iterative(string);
}


