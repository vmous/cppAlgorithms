/*
 * stringpermutator.cpp
 *
 *  Created on: Dec 14, 2012
 *      Author: billy
 */
#include <iostream>

#define MAX_STRING_LENGTH 3

char s[MAX_STRING_LENGTH] = {'a','b','c'};

char tmp;

int main(int argc, char** argv)
{
  for (int i = 0; i < MAX_STRING_LENGTH; i++) {
    for (int j = 0; j < MAX_STRING_LENGTH; j++) {
       if (i != j) {
         tmp = s[i];
         s[i] = s[j];
         s[j] = tmp;
       }
       std::cout << s << " ";
    }
  }
  std::cout << std::endl;
}


