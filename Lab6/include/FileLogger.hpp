#ifndef FILE_LOGGER_H
#define FILE_LOGGER_H

#include "Observer.hpp"
#include <fstream>

class FileLogger : public Observer {
public:
    FileLogger();
    ~FileLogger();
    void update(const std::string& message) override;
private:
    std::ofstream logFile;
};

#endif