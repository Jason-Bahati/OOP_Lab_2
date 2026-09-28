#include <iostream>
#include <string>
#include <sstream>
#include "PhysicalGood.h"
#include "DurableGood.h"

    DurableGood::DurableGood
    (std::string sku, std::string name, double unitPrice, int quantityOnHand, double weightPounds, int warrantyMonths) 
    : PhysicalGood(sku, name, unitPrice, quantityOnHand, weightPounds), warrantyMonths(warrantyMonths) {}

    std::string DurableGood::Category()
    {
        return "Durable";
    }

    double DurableGood::HandlingFee()
    {
        return ShippingCost();
    }

    std::string DurableGood::Describe()
    {
        std::ostringstream os;

        os << PhysicalGood::Describe() << ", " << warrantyMonths << " month warranty";
        return os.str();

    }