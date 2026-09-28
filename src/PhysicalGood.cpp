#include <iostream>
#include <string>
#include <sstream>
#include "PhysicalGood.h"
#include "StockItem.h"

PhysicalGood::PhysicalGood(std::string sku, std::string name, double unitPrice, int quantityOnHand, double weightPounds) 
: StockItem(sku, name, unitPrice, quantityOnHand), weightPounds(weightPounds)
{

    if (weightPounds < 0) {
        this->weightPounds = 0;
    }

}

const double PhysicalGood::HandlingRate = 0.60;

double PhysicalGood::ShippingCost()
{
    return this->weightPounds * HandlingRate;
}

std::string PhysicalGood::Describe()
{
    std::ostringstream os;
    os << StockItem::Describe() << ", " << weightPounds << " lb";
    return os.str();
}
