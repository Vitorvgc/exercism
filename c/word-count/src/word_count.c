#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "word_count.h"

// set all characters of word to lowercase
void to_lower(char *word) {
    
    for(char *p = word; *p; ++p)
        *p = tolower(*p);
}

// remove apostrophes of word if it is between '' or ""
void remove_quotation(char **word) {

    char *w = *word;
    int length = strlen(w);
    if(w[0] == w[length-1] && (w[0] == '\'' || w[0] == '\"')) {
        w[length-1] = '\0';
        ++(*word);
    }
}

// reset the data stored in words
void clean_word_count(word_count_word_t *words) {
    
    for(int i = 0; i < MAX_WORDS; ++i) {
        memset(words[i].text, 0, MAX_WORD_LENGTH);
        words[i].count = 0;
    }
}

// try to insert word in the words structure
// return 0 if inserted successfully, otherwise return
// EXCESSIVE_LENGHT_WORD or EXCESSIVE_NUMBER_OF_WORDS
int insert_word_at_word_count(const char* word, word_count_word_t *words, int *size) {
    
    if(strlen(word) > MAX_WORD_LENGTH)
        return EXCESSIVE_LENGTH_WORD;

    for(int i = 0; i < *size; ++i) {
        if(!strncmp(word, words[i].text, MAX_WORD_LENGTH)) {
            ++words[i].count;
            return 0;
        }
    }

    if(*size >= MAX_WORDS)
        return EXCESSIVE_NUMBER_OF_WORDS;

    strncpy(words[*size].text, word, sizeof(words[*size].text));
    ++words[*size].count;
    ++(*size);
    return 0;
}

int word_count(const char *input_text, word_count_word_t *words) {

    clean_word_count(words);

    int input_len = strlen(input_text) + 1;
    char input_text_copy[input_len];
    strncpy(input_text_copy, input_text, input_len);

    char *delimiters = " \n,.:!&@$%^&";
    char *word = strtok(input_text_copy, delimiters);
    int size = 0;
    while(word) {
        to_lower(word);
        remove_quotation(&word);

        int error = insert_word_at_word_count(word, words, &size);
        if(error) return error;

        word = strtok(NULL, delimiters);
    }

    return size;
}
