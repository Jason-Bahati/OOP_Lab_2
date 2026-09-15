#include <iostream>
#include <string>
#include <sstream>
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

int StockItem::getMoveCount() const{
    return static_cast<int>(history.size());
}

bool StockItem::Receive(int count)
{
    if (count <= 0) {
        return false;
    }

    this->quantityOnHand = this->quantityOnHand + count;
    StockMovement s(nextSeq, name, count);
    history.push_back(s);
    nextSeq++;
    return true;
}
