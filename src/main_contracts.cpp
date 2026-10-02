#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include "ShelfCount.h"
#include "HighestValueFirst.h"
#include "GroupedByKey.h"
#include "CountLog.h"

std::string tf(bool b) { return b ? "True" : "False"; }

int main() 
{
    std::cout << "=== RIVER CITY SUPPLY ===" << std::endl << std::endl;

    std::vector<ShelfCount> records;
    records.push_back(ShelfCount("DAIRY", 3, 21.50));
    records.push_back(ShelfCount("DRY", 1, 19.00));
    records.push_back(ShelfCount("DAIRY", 1, 15.00));
    records.push_back(ShelfCount("DRY", 1, 19.00));   
    records.push_back(ShelfCount("DAIRY", 3 , 18.75));
    records.push_back(ShelfCount("FROZEN", 2, 30.00));
    records.push_back(ShelfCount("DRY", 4, 12.50));

    std::cout << "Seven records created, in this order:" << std::endl;

    for (int i = 0; i < records.size(); i++) {
        std::cout << " " << std::right << std::setw(2) 
        << (i + 1) << " " << records[i].ToString() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Contract 1: Equals and GetHashCode" << std::endl;
    std::cout << " " << std::left << std::setw(50) << "Record 1 equals record 5 (same key, new value)?"
    << std::right << std::setw(6) << tf(records[0] == records[4]) << std::endl;

    std::cout << " " << std::left << std::setw(50) << "Record 2 equals record 4 (identical)?"
    << std::right << std::setw(6) << tf(records[1] == records[3]) << std::endl;

    std::cout << " " << std::left << std::setw(50) << "Record 1 equals record 3?"
    << std::right << std::setw(6) << tf(records[0] == records[2]) << std::endl;

    std::cout << " " << std::left << std::setw(50) << "Record 2 and record 4 are the same objects?"
    << std::right << std::setw(6) << tf(&records[1] == &records[3]) << std::endl;

    std::cout << " " << std::left << std::setw(50) << "Equal records report equal hash codes?"
    << std::right << std::setw(6) << tf(std::hash<ShelfCount>()(records[0]) == std::hash<ShelfCount>()(records[4])) << std::endl;

    std::unordered_set<ShelfCount> recordSet;
    for (int i = 0; i < records.size(); i++) {
        recordSet.insert(records[i]);
    }
    std::vector<ShelfCount> distinct(recordSet.begin(), recordSet.end());

    std::cout << " " << std::left << std::setw(50) << "Records created:"
    << std::right << std::setw(6) << records.size() << std::endl;
    std::cout << " " << std::left << std::setw(50) << "Distinct records in the set:"
    << std::right << std::setw(6) << recordSet.size() << std::endl;
    std::cout << std::endl;

    std::cout << "Contract 2: CompareTo, the natural order" << std::endl;
    std::sort(distinct.begin(), distinct.end());
    for (int i = 0; i < distinct.size(); i++) {
        std::cout << "  " << distinct[i].ToString() << std::endl;
    }
    std::cout << std::endl;

   
    std::cout << "Contract 3: a comparer, chosen at the call site" << std::endl;
    std::cout << "  HighestValueFirst" << std::endl;
    std::sort(distinct.begin(), distinct.end(), HighestValueFirst());
    for (int i = 0; i < distinct.size(); i++) {
        std::cout << "    " << distinct[i].ToString() << std::endl;
    }

    std::cout << "  GroupedByKey" << std::endl;
    std::sort(distinct.begin(), distinct.end(), GroupedByKey());
    for (int i = 0; i < distinct.size(); i++) {
        std::cout << "    " << distinct[i].ToString() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Contract 4: cleanup that runs even when the code throws" << std::endl;
    std::sort(distinct.begin(), distinct.end(), HighestValueFirst());

    CountLog* log = nullptr;
    int linesBeforeFault = 0;

    try {
        log = new CountLog("count-log.txt");
        for (int i = 0; i < 3; i++) {
            log->write(distinct[i]);
        }
        linesBeforeFault = log->getCount();
        throw std::runtime_error("scanner fault after 3 writes");
    }
    catch (std::runtime_error& ex) {
        std::cout << " Caught: " << ex.what() << std::endl;
        log->close();  // the moment a using-block's exit would have called Dispose
    }

    bool closedItself = log->getIsClosed();

    bool safeTwice = true;
    try {
        log->close();
    }
    catch (...) {
        safeTwice = false;
    }

    std::cout << " " << std::left << std::setw(50) << "The log closed itself?"
    << std::right << std::setw(6) << tf(closedItself) << std::endl;
    std::cout << " " << std::left << std::setw(50) << "Closing it a second time was safe?"
    << std::right << std::setw(6) << tf(safeTwice) << std::endl;
    std::cout << " " << std::left << std::setw(50) << "Lines the log wrote before the fault:"
    << std::right << std::setw(6) << linesBeforeFault << std::endl;

    std::cout << " count-log.txt now says:" << std::endl;
    std::ifstream in("count-log.txt");
    std::string line;
    while (std::getline(in, line)) {
        std::cout << "    " << line << std::endl;
    }

    delete log;
    
    return 0;
}