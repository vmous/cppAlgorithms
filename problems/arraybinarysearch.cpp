/*
 * arraybinarysearch.cpp
 *
 *  Created on: Dec 28, 2012
 *      Author: billy
 */

#include <iostream>

int array[12] = {6, 23, 59, 69, 1001, 1015, 3495, 4321, 13456, 56632, 466732, 1000000000};

int binary_search_recursive(int* a, int lower, int upper, int target)
{
    int range = upper - lower;

    if (range < 0) {
        // Limits reversed.
        return -1;
    }
    else if( (range == 0) && (a[lower] != target) ) {
        // Not in array.
        return -1;
    }

    if (a[lower] > a[upper]) {
        // Array unordered.
        return -1;
    }

    int center = lower + (range/2);

    if (target == array[center]) {
        // Base case.
        return center;
    }
    else if (target < array[center]) {
        return binary_search_recursive(a, lower, center - 1, target);
    }
    else {
        return binary_search_recursive(a, center + 1, upper, target);
    }
}

int binary_search_iterative(int* a, int lower, int upper, int target)
{
    int center;
    int range;

    if( lower > upper ) {
        // Limits reversed.
        return -1;
    }

    while( true ) {
        range = upper - lower;

        if( range == 0 && a[lower] != target ) {
            // Not in array.
            return -1;
        }

        if( a[lower] > a[upper] ) {
            // Array unordered.
            return -1;
        }

        center = lower + (range/2);

        if( target == a[center] ){
            return center;
        }
        else if( target < a[center] ){
            upper = center - 1;
        }
        else {
            lower = center + 1;
        }
    }
}

int main(int argc, char** argv)
{
    int ret = -1;

//    ret = binary_search_recursive(array, 0, 11, 466732);
    ret = binary_search_iterative(array, 0, 11, 466732);
    std::cout << "Searching number 466732: " << ret << std::endl;

//    ret = binary_search_recursive(array, 0, 11, 0);
    ret = binary_search_iterative(array, 0, 11, 0);
    std::cout << "Searching number 0: " << ret << std::endl;

//    ret = binary_search_recursive(array, 0, 11, 1000000001);
    ret = binary_search_iterative(array, 0, 11, 1000000001);
    std::cout << "Searching number 1000000001: " << ret << std::endl;

//    ret = binary_search_recursive(array, 0, 11, 666);
    ret = binary_search_iterative(array, 0, 11, 666);
    std::cout << "Searching number 666: " << ret << std::endl;

    return 0;
}
