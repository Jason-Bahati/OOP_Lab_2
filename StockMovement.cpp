#include <iostream>
#include <string>
#include <sstream>
#include "StockMovement.h"


StockMovement::StockMovement(int Seq, std::string Kind, int Count)
{
    seq = Seq;
    kind = Kind;
    count = Count;
}

std::string StockMovement::Describe()
{
    std::ostringstream os;
    os << "    move " << seq << ": " << kind <<  " " << count;
    return os.str();
}

int StockMovement::getSeq() const{
    return seq;
}

std::string StockMovement::getKind() const{
    return kind;
}

int StockMovement::getCount() const{
    return count;
}

