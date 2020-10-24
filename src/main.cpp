#include <iostream>
#include <fstream>
#include <string>


#ifndef logging 
    #include "logging.hpp"
#endif

#include "encryption.hpp"

int main() {
    constexpr std::string_view g_applicationName { "passwordManager" };
    
    //testEnv data CHANGE FOR PRODUCTION
    constexpr std::string_view g_initialisationFileLocation { "testEnv/passwordManager/passwordManagerrc" };
    
    logging::log(logging::INFO, __func__, __LINE__, "Program just started");
    
    //check if it's been setup initially (e.g. folder ~/.config/password_manager/passwordmaanger.rc exists);
    std::ifstream inFile { g_initialisationFileLocation.data()  };
    if (!inFile) {
        logging::log(logging::ERROR, __func__, __LINE__, "Failed to open file, Exiting");
        return 1;
    }
    else {
        logging::log(logging::INFO, __func__, __LINE__, "File opened successfully");
        bool sucessfulEncrypt { encryptFile(inFile) };
    }
    
    return 0;
}