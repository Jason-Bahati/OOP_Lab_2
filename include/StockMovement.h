#ifndef STOCKMOVEMENT_H
#define STOCKMOVEMENT_H
#include <string>

// Records one completed change in quantity on a StockItem

class StockMovement
{
    private:
        int seq;
        std::string kind;
        int count;

    public:
        StockMovement(int Seq, std::string Kind, int Count);

        std::string Describe();

        int getSeq() const;
        std::string getKind() const;
        int getCount() const;
        

};

#endif