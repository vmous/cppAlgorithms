/*
 * stringmatch.cpp
 *
 *  Created on: Jan 4, 2013
 *      Author: billy
 */

#include <iostream>
#include <cstring>

char text[8] = {'a', 'a', 'b', 'a', 'b', 'b', 'a', '\0'};
char pattern[5] = {'a', 'b', 'b', 'a', '\0'};
//char pattern[5] = {'a', 'b', 'b', 'x', '\0'};

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
 */
int findmatch(char* p, char* t)
{
    int m = strlen(p);
    int n = strlen(t);

    // Check out the loop is ending at n - m not n.
    for (int i = 0; i <= (n - m); i++) {
        int j = 0;
        while ( (j < m) && (p[j] == t[i + j]) )
            j++;

        if (j == m)
            return i;
    }

    return -1;
}

int main(int argc, char** argv)
{
    int pos = findmatch(pattern, text);
    std::cout << "The string was ";
    if (pos != -1)
        std::cout << "found at position " << pos << "!" << std::endl;
    else
        std::cout <<"not found!" << std::endl;
    return 0;
}
