/*
 * recursion.cpp
 *
 *  Created on: Jun 8, 2013
 *      Author: billy
 */

#include <queue>
#include <algorithm>



/**
 * Compute the factorial of a given number.
 *
 * Recursive algorithm.
 *
 * @param[in] number
 *     The given number to compute its factorial.
 *
 * @return
 *     The factorial.
 */
int factorialRecursive(int number)
{
    if (number > 1) {
        // Recursive case.
        return number * factorialRecursive(number - 1);
    }
    else {
        // Base case.
        return 1;
    }
}


// #################
// #################


/**
 * Compute the factorial of a given number.
 *
 * Iterative algorithm.
 *
 * Iterative implementations are in most cases well more efficient than their
 * recursive counterparts in modern computer architectures.
 *
 * @param[in] number
 *     The given number to compute its factorial.
 *
 * @return
 *     The factorial.
 */
int factorialIterative(int number)
{
    int val = 1;
    for (int i = number; i > 1; i--)
        val *= i;

    return val;
}


// #################
// #################


/**
 * Compute the factorial of a given number and return all intermediate results.
 *
 * @param[in] number
 *     The given number to compute its factorial.
 * @param[in,out] results
 *     A reference to a queue to contain the intermediate results.
 *
 * @return
 *     The factorial at a certain recursion depth.
 *
 */
int factorialRecursiveIntermediate(int number, std::queue<int> & results)
{
    if (number > 1) {
        // Recursive case.
        results.push(number * factorialRecursiveIntermediate(number - 1, results));
        return results.back();
    }
    else {
        // Base case.
        results.push(1);
        return 1;
    }
}


// #################
// #################


/**
 * Function to compute the nth Fibonacci number.
 *
 * @param[in] n
 *     The n-th number.
 *
 * @return
 *     The n-th number of the Fibonacci sequence.
 */
long fib(int n)
{
    return (n <= 1 ? n : fib(n - 1) + fib(n - 2));
}


// #################
// #################


/**
 * String permutation.
 *
 * Recursive algorithm.
 *
 * @param[in,out] s
 *     The string to be permuted.
 * @param[in] i
 *     The index of the string for a given recursion step.
 * @param[in] n
 *     The index of the last element in the string.
 */
void permuteRecursive(char *s, int i, int n)
{
    if (i == n)
    {
        // This part is executed when I have recursively come up to the last
        // element, then we print the state of the array now.

        // if string contains duplicates then at this point it might be a good
        // idea to have a hash table and:
        // 1. If s is inside the hash table do not print it
        // 2. If s is not inside the hash table print it and add it to the hash
        //    table.
        std::cout << s << std::endl;
    }
    else
    {
        for (int j = i; j <= n; j++)
        {
            // What the first swap is doing is by swapping i with j it fixes the
            // respective spot.
            std::swap( s[i], s[j] );
            permuteRecursive(s, i + 1, n);
            // backtrack
            std::swap( s[i], s[j] );
        }
    }
}


/**
 * String permutation.
 *
 * Iterative algorithm.
 *
 * @param[in,out] s
 *     The string to be permuted.
 */
void permuteIterative(char* s)
{
    unsigned int * p = new unsigned int[strlen(s)];
    register unsigned int i, j, tmp; // Upper Index i; Lower Index j

    for(i = 0; i < strlen(s); i++)
    {
        // p[i] == i controls iteration and index boundaries for i
        p[i] = 0;
    }

    std::cout << s << std::endl;

    // setup first swap points to be 1 and 0 respectively (i & j)
    i = 1;
    while(i < strlen(s))
    {
        if (p[i] < i)
        {
            // IF i is odd then j = p[i] otherwise j = 0
            j = i % 2 * p[i];
            std::swap( s[i], s[j] );

            std::cout << s << std::endl;

            // increase index "weight" for i by one
            p[i]++;
            // reset index i to 1 (assumed)
            i = 1;
        }
        else
        {
            // otherwise p[i] == i
            // reset p[i] to zero
            p[i] = 0;
            // set new index value for i (increase by one)
            i++;
        }
    }
    delete p;
}


// #################
// #################


/**
 * A function that prints all possible combinations of the characters in a
 * string.
 *
 * A recursive algorithm.
 *
 * These combinations range in length from one to the length of the string.
 * Two combinations that differ only in ordering of their characters are the
 * same combination. In other words, “12” and “31” are different combinations
 * from the input string “123”, but “21” is the same as “12”.
 *
 * @param [in] instr
 *     The input string.
 * @param [out] outstr
 *     The output string.
 * @param [in] index
 *     The index in the string a each recursion step.
 */
void combineRecursive(std::string instr, std::string outstr, int index)
{
    for (int i = index; i < instr.length(); i++) {
        outstr += instr.at(i);
        std::cout << outstr << std::endl;
        combineRecursive(instr, outstr, i + 1);
        outstr = outstr.substr(0, outstr.length() - 1);
    }
}


// #################
// #################


/**
 * People often give others their telephone number as a word representing the
 * seven digit number. For example, if my telephone number were 866-2665, I
 * could tell people my number is “TOOCOOL,” instead of the hard-to-remember
 * seven-digit number.
 *
 *  _____     _____     _____
 * |     |   | ABC |   | DEF |
 * |  1  |   |  2  |   |  3  |
 * |_____|   |_____|   |_____|
 *
 *  _____     _____     _____
 * | GHI |   | JKL |   | MNO |
 * |  4  |   |  5  |   |  6  |
 * |_____|   |_____|   |_____|
 *
 *  _____     _____     _____
 * | PRS |*  | TUV |   | WXY |*
 * |  7  |   |  8  |   |  9  |
 * |_____|   |_____|   |_____|
 *
 * <sup>*</sup> For simplification we make all digits represent 3 letters so
 * we stripped off Q from digit 7 and Z from 9.
 *
 * Note that many other possibilities (most of which are nonsensical) can
 * represent 866-2665.
 *
 * This function takes an <tt>n</tt>-digit telephone number and prints out all
 * of the possible “words” or combinations of letters that can represent the
 * given number. Because the 0 and 1 keys have no letters on them, only the
 * digits 2–9 are to letters. You’ll be passed an array of seven integers, with
 * each element being one digit in the number. You may assume that only valid
 * phone numbers will be passed to your routine.
 *
 * First of all, the different combinations of such a scheme are 3<sup>n</sup>
 * for a <tt>n</tt> digit number. Ignoring the operations involved in printing
 * the string, the focus of the function is changing letters. Changing a single
 * letter is a constant time operation. The first letter changes 3 times, the
 * second letter changes 3 times each time the first letter changes for a total
 * of 9 times, and so on for the other digits. For a telephone number of length
 * <tt>n</tt>, the total number of operations is
 * <tt>3 + 32 + 33 + ... + 3<sup>n–1</sup> + 3<sup>n</sup></tt>. Retaining only
 * the highest order term, the running time is <tt>O(3<sup>n</sup>)</tt>.
 *
 * Recursive implementation.
 *
 * @param[in] telephone
 *     The array containing the phone number.
 * @param[in] num_digits
 *     The number of digits of the given phone number.
 * @param[in] cur_digit
 *     The index of the digit to be processed in this recursive step.
 * @param[in,out] result
 *     The intermediate results passed between the recursive steps.
 */
void telephoneWordsRecursive(int * telephone, int num_digits, int cur_digit, std::string & result)
{
    const char charKeys[][3] = {
            {'0', '0', '0'}, // Digit 0
            {'1', '1', '1'}, // Digit 1
            {'A', 'B', 'C'}, // Digit 2
            {'D', 'E', 'F'}, // Digit 3
            {'G', 'H', 'I'}, // Digit 4
            {'J', 'K', 'L'}, // Digit 5
            {'M', 'N', 'O'}, // Digit 6
            {'P', 'R', 'S'}, // Digit 7 (no Q)
            {'T', 'U', 'V'}, // Digit 8
            {'W', 'X', 'Y'}  // Digit 9 (no Z)
    };

    // If the current digit has passed the last digit...
    if (cur_digit == num_digits)
    {
        // ...print the word because you're at the end.
        std::cout << result << std::endl;
        return;
    }
    else
    {
        // For each of the three digits that can represent the current digit
        for (int i = 0; i < 3; i++) {
            // Have the i-th letter that can represent the current digit.
            result += charKeys[telephone[cur_digit]][i];
            // Move to the next digit and recurse.
            telephoneWordsRecursive(telephone, num_digits, cur_digit + 1, result);
            // At this point, since we have returned from a recursive step,
            // then we have just printed all the possible different combinations
            // of the letter representations of digits on the right of the
            // current digit. With the next command, we strip this current digit
            // in order to pick up its next letter representation in the
            // following iteration of the for-loop and recurse once more in
            // order to print all the possible combinations of the letter
            // representations of digits on its right.
            result = result.substr(0, result.length() - 1);
            // If the current digit is 0 or 1 return because no letters are
            // assigned to these digit keys.
            if ((telephone[cur_digit] == 0) || (telephone[cur_digit] == 1))
                return;
        }
    }
}


/**
 * The same as above but with an iterative approach.
 *
 * @param[in] telephone
 *     The array containing the phone number.
 * @param[in] num_digits
 *     The number of digits of the given phone number.
 */
void telephoneWordsIterative(int * telephone, int num_digits)
{
    const char charKeys[][3] = {
            {'0', '0', '0'}, // Digit 0
            {'1', '1', '1'}, // Digit 1
            {'A', 'B', 'C'}, // Digit 2
            {'D', 'E', 'F'}, // Digit 3
            {'G', 'H', 'I'}, // Digit 4
            {'J', 'K', 'L'}, // Digit 5
            {'M', 'N', 'O'}, // Digit 6
            {'P', 'R', 'S'}, // Digit 7 (no Q)
            {'T', 'U', 'V'}, // Digit 8
            {'W', 'X', 'Y'}  // Digit 9 (no Z)
    };

    std::string result = "";

    // Initialize the result with the first telephone word.
    for (int i = 0; i < num_digits; i++)
        result += charKeys[telephone[i]][0];

    // Loop infinitely.
    while (true)
    {
        // Print the result of the previous loop
        std::cout << result << std::endl;

        // Start looping from end to start and until -1 that denotes end of
        // processing.
        for (int i = num_digits - 1; i >= -1; i--)
        {
            // If attempted to carry past leftmost digit, we are done.
            if (i == -1) return;

            // Assuming that 2 = HIGH, 1 = MEDIUM and 0 = low value from the
            // available letters for each key. Again, you’re trying to figure
            // out how to determine the next word in alphabetical order. Because
            // you’re working from right to left, you should look for something
            // that always happens on the right side of a word as it changes to
            // the next word in alphabetical order. Looking back at the original
            // observations, you noticed that the last letter always changes.
            // This seems to indicate that a good way to start is to increment
            // the last letter.
            // If the last letter is at its HIGH value and you increment it, you
            // reset the last letter to its LOW value and increment the
            // second-to-last letter. Suppose, however, that the second-to-last
            // number is already at its high value. Try looking at the list to
            // figure out what you need to do. From the list, it appears that
            // you reset the second-to-last number to its low value and
            // increment the third-to-last number. You continue carrying your
            // increment like this until you don’t have to reset a letter to its
            // low value. This sounds like the algorithm you want, but you still
            // have to work out how to start it and how to know when you’re
            //finished. You can start by manually creating the first string as
            // you did when writing out the list. Now you need to determine how
            // to end. Look at the last string and figure out what happens if
            // you try to increment it. Every letter resets to its low value.
            // You could check whether every letter is at its low value, but
            // this seems inefficient. The first letter resets only once, when
            // you’ve  printed out all the words. You can use this to signal
            // that you’re done printing out all the words. Again, you have to
            // consider the cases where there is a 0 or a 1. Because 0 and 1
            // effectively can’t be incremented (they always stay as 0 and 1),
            // you should always treat a 0 or a 1 as if it were at its highest
            // letter value and increment its left neighbor. In outline form,
            // the steps are as follows:

            if (charKeys[telephone[i]][2] == result.at(i) ||
                    telephone[i] == 0 || telephone[i] == 1)
            {
                result.at(i) = charKeys[telephone[i]][0];
                // No break so that the loop continues to the next digit.
            }
            else if (charKeys[telephone[i]][0] == result.at(i))
            {
                result.at(i) = charKeys[telephone[i]][1];
                break;
            }
            else if (charKeys[telephone[i]][1] == result.at(i))
            {
                result.at(i) = charKeys[telephone[i]][2];
                break;
            }
        }
    }
}
