#include "space_age.h"

// number of seconds of an Earth year
const int EARTH_YEAR_DURATION = 31557600;

// returns @planet orbital period multplier in relation to Earth
double orbital_period_mult(enum planets planet) {
    
    switch(planet) {
        case EARTH  : return 1.0;
        case MERCURY: return 0.2408467;
        case VENUS  : return 0.61519726;
        case MARS   : return 1.8808158;
        case JUPITER: return 11.862615;
        case SATURN : return 29.447498;
        case URANUS : return 84.016846;
        case NEPTUNE: return 164.79132;
    }
    return -1;
}

double convert_planet_age(enum planets planet, long long int seconds) {

    double year_duration = orbital_period_mult(planet) * EARTH_YEAR_DURATION;
    return seconds / year_duration;
}
