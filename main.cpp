#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <ctime>

class Logger{
private:
    std::ofstream logFile;
    std::vector<std::string> columnNames;
    std::map<std::string, std::string> columnValues;
public:
 /*   Logger(){
//        myfile.open("peter.csv");
    }*/

    void printTime(){
        time_t ctt = time(0);
        char cstr[128];
        std::strftime (cstr, sizeof(cstr), "%c", std::localtime(&ctt));
        logFile << cstr;
    }

    void openFile(const char* fileName){
        logFile.open(fileName);
        logFile << "Time Stamp";
        std::vector<std::string>::iterator v = columnNames.begin();
        while (v != columnNames.end()){
            logFile << "," << *v;
            v++;
        }
        logFile << std::endl;
    }


    void initColumn(std::string currentColumnName){
        columnNames.push_back (currentColumnName);
    }

    void setValue(std::string columnName, std::string columnInput){
    //need to make sure that the user input matches up twice
        columnValues[columnName] = columnInput;
    }

    void flush(){
        printTime();
        std::vector<std::string>::iterator v = columnNames.begin();
        while (v != columnNames.end()){
            logFile << "," << columnValues[*v];
            v++;
        }
        logFile << std::endl;
        columnValues.clear();
    }

    void close(){
        logFile.close();
    }
};

int main(){
//    Logger logger = Logger();


    Logger logger;
    logger.initColumn("motor");
    logger.initColumn("motor2");
    logger.openFile("skusamm.csv");
    logger.setValue("motor", "78");
    logger.setValue("motor2", "90");
    logger.flush();
    logger.setValue("motor2", "621");
    logger.flush();
    logger.close();

}
