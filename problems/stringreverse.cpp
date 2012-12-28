/*
 * stringreverse.cpp
 *
 * Step 1: Implement a character-based revert function for a string.
 * Step 2: Implement a word-based revert function for a string. Assume that all
 * words are space delimited and treat punctuation the same as letters.
 *
 *  Created on: Dec 14, 2012
 *      Author: billy
 */

#include <iostream>
#include <cstring>

char s[6] = {'a','b','c','d','e','\0'};

char w[20] = {'M', 'y', ' ', 'n', 'a', 'm', 'e', ' ', 'i', 's', ' ', 'V', 'a', 's', 's', 'i', 'l', 'i', 's', '\0'};

void char_reverse(char* s, unsigned int s_length)
{
    for (int i = 0; i < s_length/2; i++) {
        char c = s[i];
        s[i] = s[s_length - 1 - i];
        s[s_length - 1 - i] = c;
    }
}

void word_reverse()
{
    char_reverse(w, strlen(w));
    int i = 0;
    int start = 0;
    for (int i = 0; i <= strlen(w); i++) {
        if (w[i] == ' ' || w[i] == '\0') {
            char_reverse((w + start), (i - start));
            start = i + 1;
        }
    }
}

int main(int argc, char** argv)
{
//    char_reverse(s, strlen(s));
    word_reverse();

    std::cout << w << std::endl;
}
