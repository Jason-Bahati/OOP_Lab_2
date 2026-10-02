#include <iostream>
#include <string>
#include <iomanip>
#include "AllHeaderFiles.h"

void Show(IReportable& r);

int main()
{

    int counter = 0;

    Shop shop("River City Supply");

    std::cout << "Opening catalog: ";
    Show(shop);
    std::cout<<std::endl<<std::endl;

    std::cout << "Loading five records..." << std::endl;

    PerishableGood* wildflowerHoney =  new PerishableGood("HON01", "Wildflower honey", 8.00, 12, 1.5, 2);
    DurableGood* castIronKettle = new DurableGood("KTL11", "Cast iron kettle", 24.00, 5, 4.0, 24);
    PerishableGood* farmChedderWedge = new PerishableGood("CHZ07", "Farm cheddar wedge", 3.50, 40, 0.5, 9);
    ServiceItem* knifeSharpening = new ServiceItem("SRV20", "Knife sharpening", 60.00, 2, 2.5);
    ServiceItem* giftWrapping = new ServiceItem("SRV21", "Gift wrapping", 15.00, 3, 1.0);

    shop.Add(wildflowerHoney);
    shop.Add(castIronKettle);
    shop.Add(farmChedderWedge);
    shop.Add(knifeSharpening);
    shop.Add(giftWrapping);

    PerishableGood* duplicateHoney = new PerishableGood("HON01", "Some other name", 1.0, 1, 1.0, 1);
        if (!shop.Add(duplicateHoney)) {
        std::cout << " REJECTED: duplicate SKU HON01" << std::endl;
        delete duplicateHoney;
    }

    std::cout << std::endl;
    std::cout << "Recording four movements..." << std::endl;

    StockItem* flower = shop.Find("HON01");
    if (flower != nullptr && flower->Receive(6)){
        counter++;
    }

    StockItem* kettle = shop.Find("KTL11");
    if (kettle != nullptr && kettle->Release(2)){
        counter++;
    }

 
    kettle = shop.Find("KTL11");
    if (kettle != nullptr && !kettle->Release(99)){
        std::cout << " REJECTED: release of 99 from KTL11" << std::endl;
    }

    StockItem* cheddar = shop.Find("CHZ07");
    if (cheddar != nullptr && !cheddar->Receive(-5)){
        std::cout << " REJECTED: receive of -5 into CHZ07" << std::endl;        
    }
    std::cout << std::endl;

    std::cout << "Records accepted: " << shop.getCount() << std::endl;
    std::cout << "Movements accepted: " << counter << std::endl;
    std::cout << std::endl;

    std::cout << "Top record: " << farmChedderWedge->ToString() << std::endl;
    std::cout << std::endl;

    shop.SortByValue();
    shop.PrintReport();

    std::cout << std::endl;
    
    std::cout << "Contract check" << std::endl;
    std::cout << " " << std::left << std::setw(46) << "Records signing IDiscountable:"
    << " " << std::right << std::setw(11) << shop.SignedCount() << std::endl;
    std::cout << " " << std::left << std::setw(46) << "Records on sale right now:"
    << " " << std::right << std::setw(11) << shop.OnSaleCount() << std::endl;
    
    std::cout << " " << std::left << std::setw(46) << "Difference between the two totals:"
    << " $" << std::right << std::fixed << std::setprecision(2) << std::setw(11)
    << (shop.TotalValue() - shop.SaleValue()) << std::endl << std::endl;



    std::cout << "Composition check" << std::endl;
    std::cout << " " << std::left << std::setw(46) << "Movements recorded by HON01:"
    << " " << std::right << std::setw(11) << wildflowerHoney->getMoveCount() << std::endl;
    if (wildflowerHoney->getMoveCount() > 0) {
        std::cout << wildflowerHoney->MovementLines() << std::endl;
    }
    
    std::cout << " " << std::left << std::setw(46) << "Movements recorded by KTL11:"
    << " " << std::right << std::setw(11) << castIronKettle->getMoveCount() << std::endl;
    if (castIronKettle->getMoveCount() > 0) {
        std::cout << castIronKettle->MovementLines() << std::endl;
    }
    
    std::cout << " " << std::left << std::setw(46) << "Movements recorded by CHZ07:"
    << " " << std::right << std::setw(11) << farmChedderWedge->getMoveCount() << std::endl;
    if (farmChedderWedge->getMoveCount() > 0) {
        std::cout << farmChedderWedge->MovementLines() << std::endl;
    }
    
    delete(wildflowerHoney);
    delete(castIronKettle);
    delete(farmChedderWedge);
    delete(knifeSharpening);
    delete(giftWrapping);
    
    
    
    return 0;
}

void Show(IReportable& r)
{
    std::cout << r.ReportLine();
}
//StockItem bad = new StockItem("X", "Nope", 1m, 1); // object of abstract class "StockItem" is not allowed