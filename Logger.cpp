#include "Logger.h"
#include <ctime>

//used for timestamp
void Logger::printTime(){
    time_t ctt = time(0);
    char cstr[128];
    std::strftime (cstr, sizeof(cstr), "%c", std::localtime(&ctt));
    logFile << cstr;
}

// construct header row (doesn't print)
std::string Logger::header(){
    std::stringstream mystream;
    mystream << "Time Stamp";
    for (const auto col : columnNames){
        mystream << "," << col;
    }
    return mystream.str();
}

void Logger::initFile(const std::string fileName) {
    std::string myHeader = header();
    bool isHeaderThere = false;
    std::ifstream existing(fileName.c_str());
    if (existing.good()) {
        //file already exists, no need to add headers
        isHeaderThere = true;
    }
    else{
        //the header isn't there
    }
    existing.close();
    logFile.open(fileName, std::ios_base::app); //opens it to append
    if (!isHeaderThere){ //ensures that the header won't be printed every time the file is opened
        logFile << header() << std::endl;
    }
}


void Logger::initColumns(std::vector<std::string> columns){
    columnNames = columns;
}

void Logger::setValue(std::string columnName, std::string columnInput){
    columnValues[columnName] = columnInput;
}

void Logger::setValue(std::string columnName, double columnInput){
    std::stringstream doubleToString;
    doubleToString << columnInput;
    setValue(columnName, doubleToString.str());
}

void Logger::flush(){
    printTime();
    std::vector<std::string>::iterator v = columnNames.begin();
    while (v != columnNames.end()){
        logFile << "," << columnValues[*v];
        v++;
    }
    logFile << std::endl;
    columnValues.clear();
}

void Logger::close(){
    logFile.close();
}

