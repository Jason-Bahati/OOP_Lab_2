#ifndef GROUPEDBYKEY_H
#define GROUPEDBYKEY_H
#include "ShelfCount.h"

// Sort order that groups by aisle, then by descending value, then by slot

struct GroupedByKey
{
    bool operator()(const ShelfCount& a, const ShelfCount& b) const;
};

#endif