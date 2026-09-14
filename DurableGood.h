#ifndef DURABLEGOOD_H
#define DURABLEGOOD_H
#include "PhysicalGood.h"
#include <string>

class DurableGood : public PhysicalGood
{
    private:
        int warrantyMonths;
    
    public:
        DurableGood(std::string sku, std::string name, double unitPrice, int quantityOnHand, double weightPounds, int warrantyMonths);

        std::string Category() override;
        double HandlingFee() override;
        std::string Describe() override;

        int WarrantyMonths() const;

};

#endif