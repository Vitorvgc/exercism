#include "acronym.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *abbreviate(const char *phrase) {

    if(phrase == NULL) return NULL;

    int phraseLength = strlen(phrase);
    char *acronym = malloc(phraseLength * sizeof(char));

    int acronymLength = 0;
    for(int i = 0; i < phraseLength; ++i) {
        acronym[acronymLength++] = toupper(phrase[i]);
        while(phrase[i] != ' ' && phrase[i] != '-') ++i;
    }
    acronym[acronymLength] = '\0';

    return acronymLength > 0 ? acronym : NULL;
}
