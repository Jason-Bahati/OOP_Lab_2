#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cctype>
#include "IReportable.h"
#include "StockItem.h"
#include "Shop.h"
#include "IDiscountable.h"

Shop::Shop(std::string name) 
{
    this->name = name;
}

bool Shop::Add(StockItem* item) 
{
    if (item != nullptr && Find(item->getSku()) == nullptr){
        items.push_back(item);
        return true;
    }
    else {
        return false;
    }
}

StockItem* Shop::Find(std::string sku)
{
    for (int i = 0; i < items.size(); i++){
        if (items[i]->getSku().compare(sku) == 0){
            return items[i];
        }
    }
    return nullptr;
}

double Shop::TotalValue()
{
    double sum = 0;

    for (int i = 0; i < items.size(); i++) {
        sum = sum + items[i]->ExtendedValue();
    }
    return sum;
}

double Shop::SaleValue()
{
    double total = 0;
    for (int i = 0; i < items.size(); i++) {
        IDiscountable* d;
        d = dynamic_cast<IDiscountable*>(items[i]);

        if (d != nullptr) {
            total += (d->SalePrice() + items[i]->HandlingFee()) * items[i]->getQuantityOnHand();
        }
        else {
            total += items[i]->ExtendedValue();
        }
    }
    return total;
}

int Shop::SignedCount()
{
    int total = 0;
    for (int i = 0; i < items.size(); i++) {
        IDiscountable* d;
        d = dynamic_cast<IDiscountable*>(items[i]);

        if (d != nullptr) {
            total++;
        }
    }
    return total;
}

int Shop::OnSaleCount()
{
    int total = 0;
    for (int i = 0; i < items.size(); i++) {
        IDiscountable* d;
        d = dynamic_cast<IDiscountable*>(items[i]);

        if (d != nullptr && d->IsOnSale() == true){
            total++;
        }
    }
    return total;
}

void Shop::SortByValue()
{
    for (int i = 0; i < items.size() - 1; i++){
        int best = i;
        for (int j = i + 1; j < items.size(); j++){
            if (Beats(items[j], items[best])){
                best = j;
            }
        }
        if (best != i) {
            StockItem* hold = items[i];
            items[i] = items[best];
            items[best] = hold;
        }
    }
}

bool Shop::Beats(StockItem* a, StockItem* b)
{
    std::string str1 = a->getName();
    std::string str2 = b->getName();
    if (a->ExtendedValue() != b->ExtendedValue()){
        return a->ExtendedValue() > b->ExtendedValue();
    } 
    if (str1.compare(str2) < 0) {
        return true;
    }
    else {
        return false;
    }
}

std::string Shop::ReportLine() 
{
    std::ostringstream os;

    os << getName() << ": " << items.size() << " items, $" 
    << std::fixed << std::setprecision(2) << TotalValue() << " on hand";

    return os.str();
}

void Shop::PrintReport()
{
    std::cout << std::string(60, '=') << std::endl;

    //Title
    std::string upper = this->name;
    for (int i = 0; i < upper.size(); i++) {
        upper[i] = toupper(upper[i]);
    }
    std::cout << "  " << upper << " : INVENTORY REPORT" << std::endl;


    std::cout << std::string(60, '=') << std::endl;
    

    //heading row
    std::cout << " " << std::left << std::setw(7) << "SKU" 
    << " " << std::setw(21) << "ITEM" 
    << " " << std::setw(10) << "CATEGORY" 
    << " " << std::right << std::setw(4) << "QTY" 
    << "  "<< std::setw(11) << "VALUE" << std::endl;


    std::cout << std::string(60, '-') << std::endl;


    for (int i = 0; i < items.size(); i++) {
        std::cout << items[i]->ReportLine() << std::endl;
    }


    std::cout << std::string(60, '-') << std::endl;

    //Three line summary
    std::cout << " " << std::left << std::setw(46) << "Records on file:"
    << " " << std::right << std::setw(11) << items.size() << std::endl;

    std::cout << " " << std::left << std::setw(46) << "Total value on hand:"
    << "$" << std::right << std::fixed << std::setprecision(2) << std::setw(11) 
    << TotalValue() << std::endl;

    std::cout << " " << std::left << std::setw(46) << "Value if every sale price were taken:"
    << "$" << std::right << std::fixed << std::setprecision(2) << std::setw(11) 
    << SaleValue() << std::endl;

    std::cout << std::string(60, '=') << std::endl;

}

std::string Shop::getName() const { return name; }
int Shop::getCount() const { return static_cast<int>(items.size());}
