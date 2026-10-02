#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include "CountLog.h"

CountLog::CountLog(std::string path) : writer(path)
{
    this->path = path;
    writer << "LOG OPENED" << std::endl;
    count = 0;
    isClosed = false;
}

void CountLog::write(const ShelfCount& r)
{
    count++;
    writer << std::right << std::setw(3) << count << " " << r.ToString() << std::endl;

}

void CountLog::close()
{
    if (!isClosed) {
        writer << "LOG CLOSED, " << count << " lines written" << std::endl;

        writer.close();

        isClosed = true;
    }
}

CountLog::~CountLog()
{
    close();
}

std::string CountLog::getPath() const { return path; }
int CountLog::getCount() const { return count; }
bool CountLog::getIsClosed() const { return isClosed; }

