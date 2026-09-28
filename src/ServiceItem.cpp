#include <iostream> 
#include <sstream>
#include <string>
#include <iomanip>
#include "IDiscountable.h"
#include "StockItem.h"
#include "ServiceItem.h"

ServiceItem::ServiceItem
(std::string sku, std::string name, double unitPrice, int quantityOnHand, double laborHours)
 : StockItem(sku, name, unitPrice, quantityOnHand), laborHours(laborHours) {}


std::string ServiceItem::Category()
{
    return "Service";
}

double ServiceItem::HandlingFee()
{
    return 0;
}

bool ServiceItem::IsOnSale() const
{
    if(laborHours >= 2) {
        return true;
    }
    return false;   
}

double ServiceItem::SalePrice()
{
    if (IsOnSale() == true){
        return getUnitPrice() * 0.85;
    }
    return getUnitPrice();
}

    std::string ServiceItem::Describe()
    {
        std::ostringstream os;

        os << StockItem::Describe() << ", " << std::fixed 
        << std::setprecision(1) << laborHours << " labor hours";

        return os.str();
    }

