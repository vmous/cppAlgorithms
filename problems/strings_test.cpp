/*
 * strings_test.cpp
 *
 *  Created on: Jun 6, 2013
 *      Author: billy
 */

#include <iostream>
#include <cstdlib>

#include "strings.cpp"

void test_firstNonRepeatingChar()
{
    std::cout << "########################################" << std::endl;
    std::cout << __FUNCTION__ << std::endl;
    std::cout << "########################################" << std::endl;

    const char * total = "total";
    std::cout << "The first non repeating char in \"" << total << "\" is \'" << firstNonRepeatingChar(total) << "\'." << std::endl;

    const char * teeter = "teeter";
    std::cout << "The first non repeating char in \"" << teeter << "\" is \'" << firstNonRepeatingChar(teeter) << "\'." << std::endl;

    const char * goog = "goog";
    std::cout << "The first non repeating char in \"" << goog << "\" is \'" << firstNonRepeatingChar(goog) << "\'." << std::endl;

    std::cout << std::endl;
}


void test_firstNonRepeatingCharWithHashMap()
{
    std::cout << "########################################" << std::endl;
    std::cout << __FUNCTION__ << std::endl;
    std::cout << "########################################" << std::endl;

    const char * total = "total";
    std::cout << "The first non repeating char in \"" << total << "\" is \'" << firstNonRepeatingCharWithHashMap(total) << "\'." << std::endl;

    const char * teeter = "teeter";
    std::cout << "The first non repeating char in \"" << teeter << "\" is \'" << firstNonRepeatingCharWithHashMap(teeter) << "\'." << std::endl;

    const char * goog = "goog";
    std::cout << "The first non repeating char in \"" << goog << "\" is \'" << firstNonRepeatingCharWithHashMap(goog) << "\'." << std::endl;

    std::cout << std::endl;
}


void test_patternMatch()
{
    std::cout << "########################################" << std::endl;
    std::cout << __FUNCTION__ << std::endl;
    std::cout << "########################################" << std::endl;

    const char * text = "aababba";
    const char * pattern_1 = "abba";
    const char * pattern_2 = "abbx";

    int pos = patternMatch(pattern_1, text);
    if (pos > -1)
        std::cout << "Pattern \"" << pattern_1 << "\" is found at position " << pos << " in text \"" << text << "\"." << std::endl;
    else
        std::cout << "Pattern \"" << pattern_1 << "\" is not found in text \"" << text << "\"." << std::endl;

    pos = patternMatch(pattern_2, text);
    if (pos > -1)
        std::cout << "Pattern \"" << pattern_2 << "\" is found at position " << pos << " in text \"" << text << "\"." << std::endl;
    else
        std::cout << "Pattern \"" << pattern_2 << "\" is not found in text \"" << text << "\"." << std::endl;

    std::cout << std::endl;
}


// #################
// #################


int main(int argc, char** argv)
{
    test_firstNonRepeatingChar();
    test_firstNonRepeatingCharWithHashMap();
    test_patternMatch();

    return EXIT_FAILURE;
}
