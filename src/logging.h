#include <cstdio>
#include <string>
#include <array>

namespace logging{
    //need logLevel and logLevelNames need to match always
    //This is to be able to convert level (int) to char[] and print log level name
    enum logLevel {
        INFO,
        WARNING,
        ERROR,
    };
    
    

    std::array<std::string, static_cast<int>(ERROR + 1)> logLevelNames {
        "INFO",
        "WARNING",
        "ERROR"
    };
    
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

    template <typename T> void log(int logLevel, T func_name) {
        printf("[%s %s %s] In function %s\n", enumToString(logLevel).c_str(),__DATE__, __TIME__,  func_name);
    }
}