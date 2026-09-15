#include <iostream>
#include <string>
#include <sstream>
#include "PhysicalGood.h"
#include "DurableGood.h"

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

        os << ", " << warrantyMonths << " month warranty";
        return os.str();

    }