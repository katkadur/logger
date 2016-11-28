#ifndef LOGGER_H
#define LOGGER_H

#include <fstream>
#include <vector>
#include <map>
#include <sstream>

/* This logger takes input from a user and prints it to a csv file (which can be imported into a spreadsheet)
// Every log is appeneded to the file of choice and timestamp is always included in the first cell
// The main public members are initFile, initColumns, setValue, and flush
// Very first thing to do is initialize Columns (before even initializing file)
// standard syntax is initColumns({array of column names})
// example:
//      initColumns({"motor 1", "motor 2", "flywheel"})
// next step is to initialize the file -- standard syntax is initFile(filename)
// example:
//      initFile("loggerTest.csv")
// this will create and open a csv file called LoggerTest
// in the example, the columns would be:
//      timestamp, motor 1, motor 2, flywheel
// to log values, use the setValue function -- standard syntax is setValue(column name, value to log)
// example:
//      setValue("motor 1", 78) OR setValue("motor 1", "78")
//      setValue("motor 2", 3.14)
//      setValue("flywheel", "woo-hoo")
// setValue is capable of logging strings and numbers
// the last (and most important step) is to flush, which will actually print the values into the file
// standard synatx for flush is flush()
// example:
//      flush()
// Yay, now you've logged something!!
*/

class Logger{
private:
    std::ofstream logFile;
    std::vector<std::string> columnNames;
    std::map<std::string, std::string> columnValues;
    void printTime();
    std::string header();


public:
    void initFile(const std::string fileName);
    void initColumns(std::vector<std::string> columns);
    void setValue(std::string columnName, std::string columnInput);
    void setValue(std::string columnName, double columnInput);
    void flush();
    void close();
};

#endif // LOGGER_H
