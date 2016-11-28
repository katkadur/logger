#include <iostream>
#include "Logger.h"

int main(){
    Logger loggerNew;
    loggerNew.initColumns({"flywheel 1", "flywheel 2", "normal wheel"});
    loggerNew.initFile("loggerTest.csv");
    loggerNew.setValue("flywheel 1", 3.1415);
    loggerNew.setValue("flywheel 2", 0);
    loggerNew.flush();
    loggerNew.setValue("normal wheel", "space above me");
    loggerNew.flush();
    loggerNew.setValue("flywheel 1", "katareina");
    loggerNew.flush();
    loggerNew.setValue("normal wheel", 798);
    loggerNew.flush();
    loggerNew.setValue("normal wheel", 525600);
    loggerNew.flush();
    loggerNew.close();
}
