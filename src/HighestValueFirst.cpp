#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <functional>
#include "HighestValueFirst.h"


bool HighestValueFirst::operator()(const ShelfCount& a, const ShelfCount& b) const 
{
    if (a.getValueOnHand() != b.getValueOnHand()) return a.getValueOnHand() > b.getValueOnHand();
        return a.compareTo(b) < 0;
}