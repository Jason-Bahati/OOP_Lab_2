#include <iostream>
#include <string>
#include <sstream>
#include "IDiscountable.h"
#include "PhysicalGood.h"
#include "PerishableGood.h"


    std::string PerishableGood::Category()
    {
        return "Perishable";
    }

    double PerishableGood::HandlingFee()
    {
        return ShippingCost() + SurchargeFee;
    }

    bool PerishableGood::IsOnSale() const
    {
        if(shelfLifeDays <= 3) {
            return true;
        }
    }

    double PerishableGood::SalePrice()
    {
        if (IsOnSale() == true){
            return getUnitPrice() * 0.70;
        }

        return getUnitPrice();
    }

    std::string PerishableGood::Describe()
    {
        std::ostringstream os;

        os << ", " << shelfLifeDays << " days left";
        return os.str();
    }