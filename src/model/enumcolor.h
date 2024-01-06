
#ifndef ENUMCOLOR_H
#define ENUMCOLOR_H

enum eColor
{
    Healthy,
    Infected,
    Isolated,
    Contagious,
    Immune
};

const char *colorToString(eColor color);

#endif // ENUMCOLOR_H
