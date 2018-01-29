#ifndef SPACE_AGE_H
#define SPACE_AGE_H

enum planets {
    EARTH  , MERCURY,
    VENUS  , MARS   ,
    JUPITER, SATURN ,
    URANUS , NEPTUNE
};

double convert_planet_age(enum planets planet, long long int seconds);

#endif /* SPACE_AGE_H */
