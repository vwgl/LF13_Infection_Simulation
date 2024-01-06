
#include "enumcolor.h"

const char *colorToString(eColor color)
{
    switch (color)
    {
    case Healthy:
        return "Healthy";
    case Infected:
        return "Infected";
    case Isolated:
        return "Isolated";
    case Contagious:
        return "Contagious";
    case Immune:
        return "Immune";
    default:
        return "Unknown";
    }
}
