#ifndef AI_H
#define AI_H

#include "Structures.h"

class Ai
{
private:
    enum { BEST = 100, WORST = -100, TIE = 0, INF = 1000000000 };

public:
    Move BestPlay(int player);
};

extern Ai ai;

class Los
{

public:
    Move RandPlay(int player);
    int Rand();
};

extern Los los;

#endif
