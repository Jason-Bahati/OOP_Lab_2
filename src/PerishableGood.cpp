#include <iostream>
#include <string>
#include <sstream>
#include "IDiscountable.h"
#include "PhysicalGood.h"
#include "PerishableGood.h"


    PerishableGood::PerishableGood
    (std::string sku, std::string name, double unitPrice, int quantityOnHand, double weightPounds, int shelfLifeDays) 
    : PhysicalGood(sku, name, unitPrice, quantityOnHand, weightPounds), shelfLifeDays(shelfLifeDays) {}


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
        else {
            return false;
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
        os << PhysicalGood::Describe() << ", " << shelfLifeDays << " days left";
        return os.str();
    }