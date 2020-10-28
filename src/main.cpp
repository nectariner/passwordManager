#include <iostream>
#include <fstream>
#include <string>
#include <string_view>
#include "globals.hpp"

#ifndef logging 
    #include "logging.hpp"
#endif

#include "encryption.hpp"
int main(int argc, char *argv[], char *envp[]) {
    //out first environment variable
//    std::cout << envp[1];

    std::cout << argc << "\n";
//    std::cout << argv[1] << "\n";
    //testing
    //no arguments given, set test data because this is a cli tool
    //in future it needs to just say "needs arguments"
    int key {};
    if (argc == 1) {
        int key { 1 };
    }
    // else get it from the args

    logging::log(logging::INFO, __func__, __LINE__, "Program just started");
    
    //check if it's been setup initially (e.g. folder ~/.config/password_manager/passwordmaanger.rc exists);
    if (!(std::ifstream { globals::g_initialisationFileLocation  })) {
        logging::log(logging::ERROR, __func__, __LINE__, "Failed to open file, Exiting");
        return 1;
    }
    else {
        logging::log(logging::INFO, __func__, __LINE__, "File opened successfully");
    }
    
    encryptFile(key);

    logging::log(logging::INFO, __func__, __LINE__,"end of program, returning 0\n" );
    return 0;
}
