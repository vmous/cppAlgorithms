/*
 * stringcombinator.cpp
 *
 * Implement a function that prints all possible combinations of the characters
 * in a string. These combinations range in length from one to the length of
 * the string. Two combinations that differ only in ordering of their
 * characters are the same combination. In other words, “12” and “31” are
 * different combinations from the input string “123”, but “21” is the same as
 * “12”.
 *
 * Attention to the fact that this is a different problem from that of printing
 * all possible permutations of a string
 *
 *  Created on: Dec 30, 2012
 *      Author: billy
 */

#include <iostream>
#include <string>

#define MAX_STRING_LENGTH 4

std::string str ("1234");
std::string buff ("");

void combine_recursive(std::string instr, std::string outstr, int index)
{
    for (int i = index; i < instr.length(); i++) {
        outstr += instr.at(i);
        std::cout << outstr << std::endl;
        combine_recursive(instr, outstr, i + 1);
        outstr = outstr.substr(0, outstr.length() - 1);
    }
}

int main(int argc, char** argv)
{
    combine_recursive(str, buff, 0);

    return 0;
}


