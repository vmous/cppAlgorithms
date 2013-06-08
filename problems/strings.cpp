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
 *
 * @param[in] str
 *     The string to be searched for.
 *
 * @return
 *     The first non-repeated character in the given string or the <tt>NUL</tt>
 *     (<tt>'\0'</tt>) if all characters are reapeated.
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


// #################
// #################


/**
 * A function that finds the first non-repeated character in a string.
 *
 * For instance, the first non-repeated character in “total” is 'o' and the
 * first nonrepeated character in “teeter” is 'r'.
 *
 * This algorithm has O(n) time complexity since we get optimal search in
 * constant time by putting the characters in a hash map.
 *
 * @param[in] str
 *     The string to be searched for.
 *
 * @return
 *     The first non-repeated character in the given string or the <tt>NUL</tt>
 *     (<tt>'\0'</tt>) if all characters are reapeated.
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


// #################
// #################


/**
 * A function that deletes characters from an ASCII string.
 *
 * Any character existing in "remove" must be deleted from "str". For example,
 * given an "str" of "Battle of the Vowels: Hawaii vs. Grozny" and a "remove" of
 * "aeiou", the function should transform "str" to “Bttl f th Vwls: Hw vs. Grzny”.
 *
 * Given <tt>m</tt> the size of <tt>remove</tt> and <tt>n</tt> the size of
 * <tt>str</tt> the time complexity of the algorithm is O(m + 2n) which is
 * linear.
 *
 * @param[in] remove
 *     The string with the characters to remove.
 * @param[in] str
 *     The character string to transform.
 *
 * @return
 *     A new character array containing the transformed string.
 */
char * removeChars(const char * remove, const char * str)
{
    // Hash map for O(1) search for removed chars
    __gnu_cxx::hash_map<char, char> hm;
    for (int i = 0; i < strlen(remove); i++)
        hm[remove[i]] = remove[i];

    // Count the characters of the new string
    int new_str_len = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        if (hm.find(str[i]) == hm.end())
            new_str_len++;
    }

    char * new_str = new char[new_str_len + 1];

    // Create the new string.
    int j = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        if (hm.find(str[i]) == hm.end())
            new_str[j++] = str[i];
    }
    new_str[j] = '\0';

    return new_str;
}


// #################
// #################


/**
 * What is the worst-case running time of these two nested loops? The inner
 * 'while' loop goes around at most m times, and potentially far less when the
 * pattern match fails. This, plus two other statements, lies within the outer
 * for loop. The outer loop goes around at most n−m times, since no complete
 * alignment is possible once we get too far to the right of the text. The
 * time complexity of nested loops multiplies, so this gives a worst-case
 * running time of O((n − m)(m + 2)). We did not count the time it takes to
 * compute the length of the strings using the function strlen. Since the
 * implementation of strlen is not given, we must guess how long it should
 * take. If we explicitly count the number of characters until we hit the end
 * of the string; this would take time linear in the length of the string. This
 * suggests that the running time should be O(n + m + (n − m)(m + 2)). Let’s
 * use our knowledge of the Big Oh to simplify things. Since m+2 = Θ(m), the
 * '+2' isn’t interesting, so we are left with O(n + m + (n − m)m). Multiplying
 * this out yields O(n + m + nm − m^2), which still seems kind of ugly. However,
 * in any interesting problem we know that n ≥ m, since it is impossible to
 * have p as a substring of t for any pattern longer than the text itself. One
 * consequence of this is that n +m ≤ 2n = Θ(n). Thus our worst-case running
 * time simplifies further to O(n + nm − m^2). Two more observations and we are
 * done. First, note that n ≤ nm, since m ≥ 1 in any interesting pattern.
 * Thus n + nm = Θ(nm), and we can drop the additive n, simplifying our
 * analysis to O(nm − m^2). Finally, observe that the −m^2 term is negative,
 * and thus only serves to lower the value within. Since the Big Oh gives an
 * upper bound, we can drop any negative term without invalidating the upper
 * bound. That n ≥ m implies that mn ≥ m^2, so the negative term is not big
 * enough to cancel any other term which is left. Thus we can simply express
 * the worst-case running time of this algorithm as O(nm).
 *
 * @param[in] pattern
 *     The character string pattern to search.
 * @param[in] text
 *     The character string to be searched for the given pattern.
 *
 * @return
 *     The index of the start of the pattern inside the given text or
 *     <tt>-1</tt> if the pattern does not appear in the text.
 */
int patternMatch(const char * pattern, const char * text)
{
    int m = strlen(pattern);
    int n = strlen(text);

    // Check out the loop is ending at n - m not n.
    for (int i = 0; i <= (n - m); i++) {
        int j = 0;
        while ( (j < m) && (pattern[j] == text[i + j]) )
            j++;

        if (j == m)
            return i;
    }

    return -1;
}


// #################
// #################


/**
 * Reverses the characters in a given string.
 *
 * In place reverse algorithm extended to be able to reverse part of a string.
 *
 * @param[in,out] w
 *     The string we want to reverse.
 * @param[in] start
 *     The start index in the give string. This is needed if you need to reverse
 *     part of the given string (i.e. when you want to reverse the characters
 *     for each word in a sentence). If you want to reverse the whole given
 *     string set it to <code>0</code>.
 * @param[in] end
 *     The end index in the given string. As with <code>start</code> parameter,
 *     this is needed when you need to reverse part of the given string. If you
 *     want to reverse the whole given string set it to <code>strlen(w)</code>.
 */
void reverseChars(char * w, int start, int end)
{
    unsigned int s_length = end - start;

    for (int i = 0; i < s_length/2; i++) {
        char c = w[start + i];
        w[start + i] = w[s_length - 1 - i + start];
        w[s_length - 1 - i + start] = c;
    }
}


// #################
// #################


/**
 * Reverses the characters for each word in a sentence without changing the
 * order of the words.
 *
 * Identifies the start and end of each word in the sentence and applies the
 * reversion of characters for each word.
 *
 * @param[in,out] s
 *     The sentence string.
 *
 * @see <code>reverseChars(char *, int, int)</code>
 */
void reverseCharsInWords(char * s)
{
    int start = 0;
    int end = 0;

    for (int i = 0; i <= strlen(s); i++)
    {
        if (s[i] == ' ' || s[i] == '\0')
        {
            reverseChars(s, start, end);
            start = ++end;
        }
        else
        {
            end++;
        }
    }
}


// #################
// #################


/**
 * Reverses the order of words in a sentence.
 *
 * Generic algorithm that uses with O(n) space complexity.
 *
 * @param[in,out] s
 *     The sentence whose words we want reversed.
 */
void reverseWordsInSentenceGeneric(char * s)
{
    char * s_copy = new char[strlen(s) + 1];

    strcpy(s_copy, s);

    int start = 0;
    int end = 0;
    int str_len = strlen(s_copy);

    for (int i = 0; i <= str_len; i++)
    {
        if (s_copy[i] == ' ' || s_copy[i] == '\0')
        {
            int sub_str_len = end - start;
            int x;
            int y;
            for (int j = 0; j <= sub_str_len; j++)
            {
                x = start + j;
                y = str_len - sub_str_len - start + j;
                if (j == sub_str_len) {
                    if (s[y] != '\0')
                        s[y] = ' ';
                }
                else
                {
                    s[y] = s_copy[x];
                }
            }

            start = ++end;
        }
        else
        {
            end++;
        }
    }
}


// #################
// #################


/**
 * Reverses the order of words in a sentence.
 *
 * Elegant algorithm that first reverses all characters in a sentence
 * in order to revert the order of words and then reverses the characters in
 * each word to get them in their original form.
 *
 * The algorithm performs in-place reversion thus not needing additional
 * buffers.
 *
 * @param[in,out] s
 *     The sentence whose words we want reversed.
 *
 * @see <code>reverseChars(char *, int, int)</code>
 * @see <code>reverseCharsInWords(char *)</code>
 */
void reverseWordsInSentenceElegant(char * s)
{
    reverseChars(s, 0, strlen(s));
    reverseCharsInWords(s);
}


// #################
// #################


/**
 * A routine that converts a string to a signed integer.
 *
 * @param[in] a
 *     The string to be converted.
 *
 * @return
 *     The integer.
 */
int stringToInteger(const char * a)
{
    bool negative = false;
    int number = 0;

    if (!a || strlen(a) == 0)
    {
        std::cout << "Trying to convert null or empty string!" << std::endl;
        exit(EXIT_FAILURE);
    }

    int i = 1;
    int a_len = strlen(a);
    for (int j = a_len - 1; j >= 0 ; j--)
    {
        if (a[j] < '0' || a[j] > '9')
        {
            if (j == 0 && a[j] == '-')
                negative = true;
            else if (j == 0 && a[j] == '+')
                negative = false;
            else
            {
                std::cout << "Invalid number representation." << std::endl;
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            number += (a[j] - '0') * i;
            i *= 10;
        }
    }

    if (negative) number *= -1;

    return number;
}


// #################
// #################


/**
 * A routine to convert a signed integer stored as an int back to a string.
 *
 * An iterative implementation.
 *
 * ATTENTION: Does no work correctly with negative numbers.
 *
 * @param[in] i
 *     The unsigned integer to be converted.
 */
void integerToStringIterative(unsigned int i)
{
    std::stack<int> s;

    while (i >= 10)
    {
        s.push(i);
        i /= 10;
    }
    std::cout << (char) (i + '0');

    while (!s.empty())
    {
        i = s.top();
        s.pop();
        std::cout << (char) (i % 10 + '0');
    }
}


// #################
// #################


/**
 * A routine to convert a signed integer stored as an int back to a string.
 *
 * An iterative implementation.
 *
 * @param[in] i
 *     The integer to be converted.
 *
 * @return
 *     The string representation of the given integer.
 */
char * integerToStringIterative_v2(int i)
{
    int j = 0;
    bool negative = false;

    char * a = new char[10];

    if (i < 0) {
        i *= -1;
        negative = true;
    }

    // Fill the buffer with digit characters in reverse order
    do {
        a[j++] = (char)((i % 10) + '0');
        i /= 10;
    } while (i != 0);

    if (negative)
        a[j++] = '-';

    a[j] = '\0';

    unsigned int a_len = strlen(a);
    for (int g = 0; g < a_len/2; g++) {
        char c = a[g];
        a[g] = a[a_len - 1 - g];
        a[a_len - 1 - g] = c;
    }

    return a;

}


// #################
// #################


/**
 * A routine to convert an unsigned integer stored as an int back to a string.
 *
 * A recursive implementation.
 *
 * ATTENTION: Does no work correctly with negative numbers.
 *
 * @param[in] i
 *     The unsigned integer to be converted.
 */
void integerToStringRecursive(unsigned int i)
{
    if(i < 10)
    {
        std::cout << (char)(i + '0');
    }
    else
    {
        integerToStringRecursive(i/10);
        std::cout << (char)(i % 10 + '0');
    }
}
