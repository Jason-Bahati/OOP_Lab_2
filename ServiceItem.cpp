#include <iostream> 
#include <sstream>
#include <string>
#include "IDiscountable.h"
#include "StockItem.h"
#include "ServiceItem.h"

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
}

double ServiceItem::SalePrice()
{
    if (SalePrice() == true){
        return getUnitPrice() * 0.85;
    }
    return getUnitPrice();
}

    std::string ServiceItem::Describe()
    {
        std::ostringstream os;

        os << ", " << laborHours << " labor hours";
        return os.str();
    }

