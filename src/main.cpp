#include <iostream>
#include <fstream>
#include <string>
#include <string_view>
#include "globals.hpp"

#ifndef logging 
    #include "logging.hpp"
#endif

#include "encryption.hpp"
int main() {
    logging::log(logging::INFO, __func__, __LINE__, "Program just started");
    
    //check if it's been setup initially (e.g. folder ~/.config/password_manager/passwordmaanger.rc exists);
    if (!(std::ifstream { globals::g_initialisationFileLocation  })) {
        logging::log(logging::ERROR, __func__, __LINE__, "Failed to open file, Exiting");
        return 1;
    }
    else {
        logging::log(logging::INFO, __func__, __LINE__, "File opened successfully");
    }
    
    encryptFile();

    return 0;
}
