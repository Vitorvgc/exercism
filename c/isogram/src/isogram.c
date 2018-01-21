#include "isogram.h"

bool is_isogram(const char phrase[]) {
    
    bool containsChar[30] = {0};

    for(int i = 0; phrase[i]; ++i) {
        
        int index = -1;
        if(phrase[i] >= 'a' && phrase[i] <= 'z')
            index = phrase[i] - 'a';
        else if(phrase[i] >= 'A' && phrase[i] <= 'Z')
            index = phrase[i] - 'A';

        if(index != -1) {
            if(containsChar[index]) return false;
            else containsChar[index] = true;
        }
    }

    return true;
}
