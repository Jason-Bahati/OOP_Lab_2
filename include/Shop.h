#ifndef SHOP_H
#define SHOP_H

#include "IReportable.h"
#include "StockItem.h"
#include <string>
#include <vector>

class Shop : public IReportable
{
    private:
        std::string name;
        std::vector<StockItem*> items;

        static bool Beats(StockItem* a, StockItem* b);
    
    public:
        Shop(std::string name);

        bool Add(StockItem* item);
        StockItem* Find(std::string sku);
        double TotalValue();
        double SaleValue();
        int SignedCount();
        int OnSaleCount();
        void SortByValue();
        std::string ReportLine() override;
        void PrintReport();

        std::string getName() const;
        int getCount() const;
    };

#endif