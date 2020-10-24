#include <iostream>
#include <fstream>
#include <string>


#include "logging.hpp"
#include "encryption.hpp"

int main() {
    constexpr std::string_view g_applicationName { "passwordManager" };
    
    //testEnv data CHANGE FOR PRODUCTION
    constexpr std::string_view g_initialisationFileLocation { "testEnv/passwordManager/passwordManagerrc" };
    
    logging::log(logging::INFO, __func__, __LINE__, "Program just started");
    
    //check if it's been setup initially (e.g. folder ~/.config/password_manager/passwordmaanger.rc exists);
    const std::ifstream configFile { g_initialisationFileLocation.data(), std::ios::in };
    if (!configFile) {
        logging::log(logging::ERROR, __func__, __LINE__, "Failed to open file");
    }
    else {
        logging::log(logging::INFO, __func__, __LINE__, "File opened successfully");
        encryptFile(); 
    }
    //std::string strInput;
    //std::getline(configFile, strInput);
    //std::cout << strInput << '\n';
//    bool test = encryption::encryptFile(configFile);
    
    return 0;
}