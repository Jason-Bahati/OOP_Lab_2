#ifndef SERVICEITEM_H
#define SERVICEITEM_H
#include "IDiscountable.h"
#include "StockItem.h"
#include <string>

class ServiceItem : public IDiscountable, public StockItem
{
    private:
        double laborHours;
    
    public:
        ServiceItem(std::string sku, std::string name, double unitPrice, int quantityOnHand, double laborHours);

        std::string Category() override;
        double HandlingFee() override;
        double SalePrice() override;
        std::string Describe() override;

        double getLaborHours() const;
        bool IsOnSale() const override;

};

#endif