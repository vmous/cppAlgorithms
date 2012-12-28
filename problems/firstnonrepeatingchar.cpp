/**
 * firstnonrepeatingchar.cpp
 *
 * Write an efficient function to find the first non-repeated character in a
 * string. For instance, the first non-repeated character in “total” is ‘o’
 * and the first nonrepeated character in “teeter” is ‘r’. Discuss the
 * efficiency of your algorithm.
 *
 *  Created on: Dec 27, 2012
 *      Author: billy
 */

#include <iostream>

//char s[7] = {'t','e','e', 't', 'e', 'r', '\0'};
char s[6] = {'t','o','t', 'a', 'l', '\0'};

/**
 * O(n^2)
 */
void solve_1()
{
    char c = '\0';
    for (int i = 0; *(s + i) != '\0'; i++) {
        c = *(s + i);
        bool flag = true;
        for (int j = 0; *(s + j) != '\0'; j++) {
            if ( i != j && *(s + i) == *(s + j) ) {
                flag = false;
                break;
            }
        }
        if (flag)
            break;
    }
    if (c != '\0') {
        std::cout << "Found :D \'" << c << "\'" << std::endl;
    }
    else
        std::cout << "Not found :(" << std::endl;

}

int main(int argc, char** argv)
{

    solve_1();

    return 0;
}

