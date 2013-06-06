/*
 * strings.cpp
 *
 *  Created on: Jun 6, 2013
 *      Author: billy
 */


#include <cstring>
#include <ext/hash_map>


/**
 * A function that finds the first non-repeated character in a string.
 *
 * For instance, the first non-repeated character in “total” is 'o' and the
 * first nonrepeated character in “teeter” is 'r'.
 *
 * This algorithm has O(n<sup>2</sup>) time complexity.
 */
char firstNonRepeatingChar(const char * str)
{
    char c;

    for (int i = 0; i < strlen(str); i++)
    {
        bool isRepeated = false;
        for (int j = 0; j < strlen(str); j++)
        {
            if (i == j) continue;

            if (str[i] == str[j])
            {
                isRepeated = true;
                break;
            }
        }

        if (!isRepeated)
            return str[i];

    }

    return '\0';
}


/**
 * A function that finds the first non-repeated character in a string.
 *
 * For instance, the first non-repeated character in “total” is 'o' and the
 * first nonrepeated character in “teeter” is 'r'.
 *
 * This algorithm has O(n) time complexity since we get optimal search in
 * constant time by putting the characters in a hash map.
 */
char firstNonRepeatingCharWithHashMap(const char * str)
{
    __gnu_cxx::hash_map<char, int> hm;
    for (int i = 0; i < strlen(str); i++)
    {
        if (hm.find(str[i]) == hm.end())
            hm[str[i]] = 1;
        else
            hm[str[i]] = hm[str[i]] + 1;
    }

//    for(__gnu_cxx::hash_map<char, int>::iterator it = hm.begin(); it != hm.end(); it ++)
//        std::cout << (*it).first << " => " << (*it).second << std::endl;

    for (int i = 0; i < strlen(str); i++)
        if (hm[str[i]] == 1) return str[i];

    return '\0';
}
