#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <string_view>
#include "globals.hpp"

#ifndef logging 
    #include "logging.hpp"
#endif

void displayHelpMessage() {
    std::cout << "PasswordManager\n";
    std::cout << "Usage - passwordManager Mode METHOD KEY\n";
    std::cout << "\te.g. passwordManager encrypt caesar 11\n";

    std::cout << "\nModes -\tencrpyt\n\tunencrypt\n\tinitialise\n";
}

#include "encryption.hpp"
int main(int argc, char *argv[]) {
    logging::log(logging::INFO, __func__, __LINE__, "Program just started");

    // FLOW:
    // Program called with arguments in the form of MODE -> METHOD -> KEY
    // e.g. "passwordManager encrypt caesar 12"
    //
    // if this is valid then assign arguments to variables
    // if not then print help message

    //no Arguments given
    //NOTE: This needs to be done differently as argc can be equal to 0 with no args
    if (argc == 1) {
        logging::log(logging::INFO, __func__, __LINE__, "no Arguments given");
        displayHelpMessage();
        //TODO: return codes relating to ways the program exits
        return 0;
    }


    //initialise variables that are arguments when running the program

    //encrypt or decrypt
    std::string mode {};
    mode = static_cast<std::string>(argv[1]);
    std::cout << mode << '\n';

    //for now just caesar cipher
    char method {};

    //password / key (e.g. 2 for caesar cipher)
    int key{};

//    for (int i = 0; i < argc; i++){
//        if (argv[argc][1] == 'm' )
//        std::cout << static_cast<char>((argv[argc])[1]);
//    }


//    std::cout << argv[1] << "\n";
    //testing
    //no arguments given, set test data because this is a cli tool
    //in future it needs to just say "needs arguments"
    if (argc == 1) {
        key = 1 ;
    } else{
        //TODO: parseArguments and set them as const
        key = 1;
    }

    //check if it's been setup initially (e.g. folder ~/.config/password_manager/passwordmaanger.rc exists);
    if (!(std::ifstream { globals::g_fileLocation.data() })) {
        logging::log(logging::ERROR, __func__, __LINE__, "Failed to open file, Exiting");
        return 1;
    }
    else {
        logging::log(logging::INFO, __func__, __LINE__, "File opened successfully");
    }

    caesarCipher::encryptFile(key);
//    caesarCipher::decryptFile(key);


    logging::log(logging::INFO, __func__, __LINE__,"end of program, returning 0" );
    return 0;
}
