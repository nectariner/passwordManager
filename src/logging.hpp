#include<array>

namespace logging{
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
}