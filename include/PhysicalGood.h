#ifndef PHYSICAlGOOD_H
#define PHYSICAlGOOD_H
#include "StockItem.h"
#include <string>

class PhysicalGood : public StockItem
{
    private:
        double weightPounds;

    protected:
        PhysicalGood(std::string sku, std::string name, double unitPrice, int quantityOnHand, double weightPounds);

    public:
        double ShippingCost();
        std::string Describe() override;

        double WeightPounds() const;
        static const double HandlingRate;
};

#endif