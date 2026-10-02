#ifndef HIGHESTVALUEFIRST_H
#define HIGHESTVALUEFIRST_H
#include "ShelfCount.h"

// Sort order that puts the highest valueOnHand first

struct HighestValueFirst
{
    bool operator()(const ShelfCount& a, const ShelfCount& b) const;
};

#endif