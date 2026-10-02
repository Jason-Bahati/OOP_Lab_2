#ifndef HIGHESTVALUEFIRST_H
#define HIGHESTVALUEFIRST_H
#include "ShelfCount.h"

struct HighestValueFirst
{
    bool operator()(const ShelfCount& a, const ShelfCount& b) const;
};

#endif