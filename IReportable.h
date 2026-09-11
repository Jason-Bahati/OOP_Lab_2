#ifndef IREPORTABLE_H
#define IREPORTABLE_H
#include <string>


class IReportable
{
    public:
        virtual std::string ReportLine() = 0;

        virtual ~IReportable() = default;
};

#endif
