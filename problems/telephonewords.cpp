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

int main(int argc, char** argv)
{
    telephone_words_recursive(t, 0, r);
}
