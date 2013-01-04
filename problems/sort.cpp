/*
 * sort.cpp
 *
 *  Created on: Dec 16, 2012
 *      Author: billy
 */
#include <iostream>

#define ARRAY_LENGTH 10
int array[ARRAY_LENGTH] = {10, 1, 28, 103, 21, 7, 9, 1000, 99, 459};

void print_int_array(int* arr, int n)
{
    for (int i = 0; i < n; i++) {
        std::cout << *(arr + i) << " ";
    }
    std::cout << std::endl;
}

/**
 * This function implements the insertion sort algorithm.
 * Worst case: Θ (n^2)
 */
void insertion_sort(int* arr, int n)
{
    for (int i = 1; i < n; i++) {
        int key = *(arr + i);
        int j = i - 1;
        while (i > 0 && *(arr + j) > key) {
            *(arr + j + 1) = *(arr + j);
            j = j - 1;
        }

        *(arr + j + 1) = key;
    }
}

int main(int argc, char** argv)
{
    print_int_array(array, ARRAY_LENGTH);
    insertion_sort(array, ARRAY_LENGTH);
    print_int_array(array, ARRAY_LENGTH);

    return 0;
}
