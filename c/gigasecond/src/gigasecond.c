#include "gigasecond.h"

time_t gigasecond_after(time_t current_time) {
    
    struct tm date = *localtime(&current_time);
    date.tm_sec += 1000000000;
    return mktime(&date);
}
