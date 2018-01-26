#include <ctype.h>
#include "pangram.h"

#define ALPHABET_SIZE 26

bool is_pangram(const char *sentence) {

    if(!sentence) return false;
    
    bool contains_char[ALPHABET_SIZE] = {0};
    int unique_chars = 0;

    for(const char *p = sentence; *p; ++p) {

        if(!isalpha(*p)) continue;

        int index = tolower(*p) - 'a';

        if(!contains_char[index]) {
            contains_char[index] = true;
            ++unique_chars;
        }
    }

    return unique_chars == ALPHABET_SIZE;
}
