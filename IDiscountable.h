#ifndef IDISCOUNTABLE_H
#define IDISCOUNTABLE_H


class IDiscountable
{
    public:
        virtual bool IsOnSale() const = 0;

        virtual double SalePrice() = 0;

        virtual ~IDiscountable() = default;
};

#endif