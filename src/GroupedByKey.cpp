#include <iostream>
#include <functional>
#include "GroupedByKey.h"

bool GroupedByKey::operator()(const ShelfCount& a, const ShelfCount& b) const
{
    int byAisle = a.getAisle().compare(b.getAisle());
    if (byAisle != 0) return byAisle < 0;

    if (a.getValueOnHand() != b.getValueOnHand()){
        return a.getValueOnHand() > b.getValueOnHand();
    }

    return a.getSlot() < b.getSlot();
}