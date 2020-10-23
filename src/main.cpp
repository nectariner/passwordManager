#include <iostream>
#include <fstream>
#include "logging.h"

int main() {
    constexpr std::string_view g_applicationName { "passwordManager" };
    
    //testEnv data CHANGE FOR PRODUCTION
    constexpr std::string_view g_initialisationFileLocation { "testEnv/passwordManager/passwordManagerrc" };
    
    logging::log(logging::INFO, __func__, __LINE__, "Program just started");
    
    //check if it's been setup initially (e.g. folder ~/.config/password_manager/passwordmaanger.rc exists);
    std::ifstream configFile { g_initialisationFileLocation.data(), std::ios::in };
    if (!configFile) {
        logging::log(logging::ERROR, __func__, __LINE__, "Failed to open file");
    }
    else {
        logging::log(logging::ERROR, __func__, __LINE__, "File opened successfully");
    }

    return 0;
}