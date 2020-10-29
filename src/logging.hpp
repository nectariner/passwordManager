#include<array>
#include "globals.hpp"

namespace logging {
    //need logLevel and logLevelNames need to match always
    //This is to be able to convert level (int) to char[] and print log level name
    enum logLevel {
        INFO,
        WARNING,
        ERROR,
    };
    
    //Set the array size equal to the value of error + 1 (error always has to have to highest value / last enum, or have to change the below static_cast)
    std::array<std::string, static_cast<int>(ERROR + 1)> logLevelNames {
        "INFO",
        "WARNING",
        "ERROR"
    };
    
    //converts the value of the enum type from an int to a string
    //string isn't an issue because of SSO
    std::string enumToString(int enumVal){
        //TODO: make these std::string_views and constexpr
        switch (enumVal) {
            case 0 :
                return "INFO";
                break;
            case 1 :
                return "WARNING";
                break;
            case 2:
                return "ERROR";
                break;
        }
        return "ERROR CONVERTING TO ENUMVAL";
    }

    //layout of logging goes : LOGGINGLEVEL -> DATE -> TIME -> FUNCTIONNAME -> LINE -> EXTRAINFO
    template <typename T, typename Y> void log(int logLevel, T funcName, Y line, const char* extraInfo = "no info given") {
        printf("[%s %s %s] In function %s Line-%d %s\n", enumToString(logLevel).c_str(),__DATE__, __TIME__,  funcName, line, extraInfo);
    }

    //can be used to show the contents of the file at any given time in a pretty format
    //return false if fails (should then be logged ERROR)
    template <typename functionName>
    bool logFileContents(int logLevel, functionName funcName, std::string_view fileName, const char* extraInfo = ""){
        std::ifstream file { fileName.data(), std::ios::in };
        std::string line;
        std::cout << "\n\n===================logFileContents Start===================\n\n";
        printf("[%s %s %s] In function %s Line-%d %s\n", enumToString(logLevel).c_str(),__DATE__, __TIME__,  funcName, 10, extraInfo);
        int numOfLines { 0 };
        while (true) {
            std::getline(file, line);
            if (file.eof())
                break;
            else {
                numOfLines++;
                std::cout << line << "\n";
            }
        }
        std::cout << "\nnumber of lines in file = " << numOfLines;
        std::cout << extraInfo;
        std::cout << "\n===================logFileContents End=====================\n\n";
        return true;
    }


}
//logFileContents(1, __func__, __LINE__, fileName);

//TODO: validation function / namespace for checking if a file was opened successfully and returns something like a boolean or int depending on what went wrong (if it failed) e.g. doesn't exist, no read permissions, no write permissions (although write permissions won't always fail)
