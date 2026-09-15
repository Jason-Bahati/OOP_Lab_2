#ifndef STOCKITEM_H
#define STOCKITEM_H
#include <string>
#include <vector>
#include "IReportable.h"
#include "StockMovement.h"

class StockItem : public IReportable
{
    private:
        std::string sku, name;
        int quantityOnHand, nextSeq;
        double unitPrice;
        std::vector<StockMovement> history;
    
    public:
        std::string getSku() const;
        std::string getName() const;
        double getUnitPrice() const;
        int getQuantityOnHand() const;
        int getMoveCount() const;

        
        virtual std::string Category() = 0;
        virtual double HandlingFee() = 0;
        double ExtendedValue();
        bool Receive(int count);
        bool Release(int count);
        std::string MovementLines();
        virtual std::string Describe();
        std::string ReportLine() override; 
        std::string ToString();
        
    protected:

        StockItem(std::string sku, std::string name, double unitPrice, int quantityOnHand);
};

#endif