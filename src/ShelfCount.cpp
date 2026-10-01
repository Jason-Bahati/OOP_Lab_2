#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <functional>
#include "ShelfCount.h"

ShelfCount::ShelfCount(std::string aisle, int slot, double valueOnHand)
{
    this->aisle = aisle;
    this->slot= slot;
    this->valueOnHand = valueOnHand;
}

bool ShelfCount::operator==(const ShelfCount& other) const {
return aisle == other.aisle && slot == other.slot;
}

bool ShelfCount::operator!=(const ShelfCount& other) const { return !(*this == other); }

bool ShelfCount::operator<(const ShelfCount& other) const { return compareTo(other) < 0; }

int ShelfCount::compareTo(const ShelfCount& other) const
{
    int str = aisle.compare(other.aisle);

    if (str != 0) {
        return str;
    }
    else {
        return slot - other.slot;
    }
}

std::string ShelfCount::ToString() const
{
    std::ostringstream os;

    os << std::left << std::setw(6) << aisle << " " << "#" << slot << " "
    << std::right << std::fixed << std::setprecision(2) << std::setw(8)
    << valueOnHand;

    return os.str();
}

std::string ShelfCount::getAisle() const { return aisle; }
int ShelfCount::getSlot() const { return slot; }
double ShelfCount::getValueOnHand() const { return valueOnHand; }