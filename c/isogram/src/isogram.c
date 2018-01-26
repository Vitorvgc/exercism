#include <ctype.h>
#include "isogram.h"

bool is_isogram(const char phrase[]) {
    
    bool containsChar[26] = {0};

    for(int i = 0; phrase[i]; ++i) {
        
        if(!isalpha(phrase[i])) continue;

        int index = tolower(phrase[i]) - 'a';

        if(containsChar[index]) return false;
        else containsChar[index] = true;
    }

    return true;
}
