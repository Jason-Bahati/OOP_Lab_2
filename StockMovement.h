#ifndef STOCKMOVEMENT_H
#define STOCKMOVEMENT_H
#include <string>

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