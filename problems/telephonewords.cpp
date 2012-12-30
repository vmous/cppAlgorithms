/*
 * telephonewords.cpp
 *
 * People often give others their telephone number as a word representing the
 * seven digit number. For example, if my telephone number were 866-2665, I
 * could tell people my number is “TOOCOOL,” instead of the hard-to-remember
 * seven-digit number. Note that many other possibilities (most of which are
 * nonsensical) can represent 866-2665. Write a routine that takes a
 * seven-digit telephone number and prints out all of the possible “words” or
 * combinations of letters that can represent the given number. Because the 0
 * and 1 keys have no letters on them, you should change only the digits 2–9
 * to letters. You’ll be passed an array of seven integers, with each element
 * being one digit in the number. You may assume that only valid phone numbers
 * will be passed to your routine. You can use the helper routine
 *
 *     char getCharKey( int telephoneKey, int place )
 *
 * which takes a telephone key (0–9) and a place of either 1, 2, 3 and returns
 * the character corresponding to the letter in that position on the specified
 * key. For example, getCharKey(3, 2) will return ‘E’ because the telephone
 * key 3 has the letters “DEF” on it and ‘E’ is the second letter.
 *
 *  Created on: Dec 31, 2012
 *      Author: billy
 */
#include <iostream>

#define TELEPHONE_NUM_LENGTH 10

int t[TELEPHONE_NUM_LENGTH] = {4, 4, 2, 1, 0, 1, 4, 8, 3, 5};
char r[TELEPHONE_NUM_LENGTH] = "";

char getCharKey(int telephoneKey, int place)
{
    char c;

    return c;
}

/**
 * It can be no less than O(3^n) because there are 3^n solutions, so any correct
 * solution must be at least O(3^n). Getting each new word requires only constant
 * time operations so the running time is indeed O(3^n).
 */
void telephone_words_recursive(int* telephone, int cur_digit, char* result)
{
    int i = 0;

    if (cur_digit == TELEPHONE_NUM_LENGTH) {
        std::cout << result << std::endl;
    }
    else {
        for (int i = 1; i <= 3; i++) {
            result[cur_digit] = getCharKey(telephone[cur_digit], i);
            telephone_words_recursive(telephone, cur_digit + 1, result);
            if ((telephone[cur_digit] == 0) || (telephone[cur_digit] == 1))
                return;
        }
    }
}

/**
 * For the iterative implementation also, there must be at least 3^n solutions,
 * thus the algorithm can be no better than O(3^n) if it is correct. There is
 * slight constant overhead in finding each word, but we can ignore it.
 * Therefore, this is also an O(3^n) solution.
 */
void telephone_words_iterative()
{
    int i;
    /* Initialize the result (in our example,
     * put GWP1WAR in result).
     */
    for (i = 0; i < TELEPHONE_NUM_LENGTH; i++)
        r[i] = getCharKey(t[i], 1);
    /* Main loop begins */
    while (true) {
        for (i = 0; i < TELEPHONE_NUM_LENGTH; ++i) {
            std::cout << r + i;
        }
        std::cout << std::endl;
        /* Start at the end and try to increment from right
         * to left.
         */
        for (i = TELEPHONE_NUM_LENGTH - 1; i >= -1; i--) {
            /* You’re done because you
             * tried to carry the leftmost digit.
             */
            if (i == -1)
                return;
            /* Otherwise, we’re not done and must continue. */
            /* You want to start with this condition so that you can
             * deal with the special cases, 0 and 1 right away.
             */
            if (getCharKey(t[i], 3) == r[i] || t[i] == 0
                    || t[i] == 1) {
                r[i] = getCharKey(t[i], 1);
                /* No break, so loop continues to next digit */
            } else if (getCharKey(t[i], 1) == r[i]) {
                r[i] = getCharKey(t[i], 2);
                break;
            } else if (getCharKey(t[i], 2) == r[i]) {
                r[i] = getCharKey(t[i], 3);
                break;
            }
        }
    }
}

int main(int argc, char** argv)
{
    telephone_words_recursive(t, 0, r);
}
