#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include "IReportable.h"
#include "StockMovement.h"
#include "StockItem.h"

StockItem::StockItem(std::string sku, std::string name, double unitPrice, int quantityOnHand)
{
    this->sku = sku;
    this->name = name;

    if (unitPrice < 0) {
        this->unitPrice = 0;
    }
    else {
        this->unitPrice = unitPrice;
    }

    if (quantityOnHand < 0) {
        this->quantityOnHand = 0;
    }
    else {
        this->quantityOnHand = quantityOnHand;
    }

    nextSeq = 1;
}


double StockItem::ExtendedValue()
{
    return (unitPrice + HandlingFee()) * quantityOnHand;
}




bool StockItem::Receive(int count)
{
    if (count <= 0) {
        return false;
    }
    else {
        this->quantityOnHand = this->quantityOnHand + count;
        StockMovement s(nextSeq, "Received", count);
        history.push_back(s);
        nextSeq++;
        return true;
    }
}

bool StockItem::Release(int count)
{
    if (count <= 0 || count > this->quantityOnHand) {
        return false;
    }
    else {
        this->quantityOnHand = this->quantityOnHand - count;
        StockMovement s(nextSeq, "Released", count);
        history.push_back(s);
        nextSeq++;
        return true;
    }
}

std::string StockItem::MovementLines() 
{
    std::string str;

    for (int i = 0; i < history.size(); i++) {
        if (str.empty()) {
            str.append(history[i].Describe());
        }
        else {
            str.append("\n");
            str.append(history[i].Describe());
        }
    }

    return str;
}


std::string StockItem::Describe() 
{
    std::ostringstream os;
    os << sku << " " << name << " " << "(" << Category() << ")";
    return os.str();
}

std::string StockItem::ToString() 
{
    return Describe();
}

std::string StockItem::ReportLine()
{
    std::ostringstream os;
    os << " " << std::left << std::setw(7) << getSku() 
    << " " << std::setw(21) << getName() 
    << " " << std::setw(10) << Category() 
    << " " << std::right << std::setw(4) << getQuantityOnHand() 
    << " $" << std::fixed << std::setprecision(2) << std::setw(11) << ExtendedValue();

    return os.str();
}


int StockItem::getMoveCount() const{
    return static_cast<int>(history.size());
}


std::string StockItem::getSku() const{ return sku; }
std::string StockItem::getName() const { return name; }
double StockItem::getUnitPrice() const { return unitPrice; }
int StockItem::getQuantityOnHand() const { return quantityOnHand; }
