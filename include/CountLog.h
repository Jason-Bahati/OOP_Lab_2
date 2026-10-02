#ifndef COUNTLOG_H
#define COUNTLOG_H
#include <fstream>
#include <string>
#include "ShelfCount.h"

// A write-only log file that closes itself when it goes out of scope

class CountLog
{
    private:
        std::ofstream writer;
        std::string path;
        int count;
        bool isClosed;

    public:
        CountLog(std::string path);
        ~CountLog();

        CountLog(const CountLog&) = delete;
        CountLog& operator=(const CountLog&) = delete;

        std::string getPath() const;
        int getCount() const;
        bool getIsClosed() const;

        void write(const ShelfCount& r);
        void close();
};

#endif