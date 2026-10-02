#ifndef IREPORTABLE_H
#define IREPORTABLE_H
#include <string>
/*
    Contract for any class that can produce one line of report text
    must be declared as a pure virtual function since the interface keyword
    doesn't exist in C++
*/

class IReportable
{
    public:
        virtual std::string ReportLine() = 0;

        virtual ~IReportable() = default;

};

#endif
