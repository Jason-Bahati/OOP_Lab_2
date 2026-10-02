#ifndef IDISCOUNTABLE_H
#define IDISCOUNTABLE_H
/*
    Contract for anything that can go on sale at a discounted price
    must be declared as a pure virtual function since the interface keyword
    doesn't exist in C++    
*/
class IDiscountable
{
    public:
        virtual bool IsOnSale() const = 0;

        virtual double SalePrice() = 0;

        virtual ~IDiscountable() = default;
      
};

#endif