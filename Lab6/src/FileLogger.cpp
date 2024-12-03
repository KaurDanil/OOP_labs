#include "FileLogger.hpp"
#include <iostream>

FileLogger::FileLogger() {
    logFile.open("log.txt", std::ios::app); // Open in append mode
    if (!logFile.is_open()) {
        std::cerr << "Failed to open log file." << std::endl;
    }
}

FileLogger::~FileLogger() {
    if (logFile.is_open()) {
        logFile.close();
    }
}

void FileLogger::update(const std::string& message) {
    if (logFile.is_open()) {
        logFile << message << std::endl;
    }
}