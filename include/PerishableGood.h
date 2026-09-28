#ifndef PERISHABLEGOOD_H
#define PERISHABLEGOOD_H
#include "PhysicalGood.h"
#include "IDiscountable.h"
#include <string>

class PerishableGood : public IDiscountable, public PhysicalGood
{
    private:
        int shelfLifeDays;
    
    public:
        PerishableGood(std::string sku, std::string name, double unitPrice, int quantityOnHand, double weightPounds, int shelfLifeDays);

        std::string Category() override;
        double HandlingFee() override;
        double SalePrice() override;
        std::string Describe() override;

        static const double SurchargeFee;
        int ShelfLifeDays() const;
        bool IsOnSale() const override;
};

#endif