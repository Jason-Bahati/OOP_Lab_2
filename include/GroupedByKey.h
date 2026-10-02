#ifndef GROUPEDBYKEY_H
#define GROUPEDBYKEY_H
#include "ShelfCount.h"

struct GroupedByKey
{
    bool operator()(const ShelfCount& a, const ShelfCount& b) const;
};

#endif