#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <string_view>
#include <sstream>
#include "globals.hpp"

#ifndef logging 
    #include "logging.hpp"
#endif

#include "encryption.hpp"

void displayHelpMessage() {
    std::cout << "PasswordManager\n";
    std::cout << "Usage - passwordManager Mode METHOD KEY\n";
    std::cout << "\te.g. passwordManager encrypt caesar 11\n";

    std::cout << "\nModes -\tencrpyt\n\tunencrypt\n\tinitialise\n";
}

int main(int argc, char *argv[]) {
    logging::log(logging::INFO, __func__, __LINE__, "Program just started");

    //get the fileLocation, has to be done at runtime so hard to make it global really
    std::string fileLocation;
    fileLocation = { std::getenv("XDG_CONFIG_HOME") };
    fileLocation += '/';
    fileLocation += globals::g_fileLocationRelative.data() ;

    // FLOW:
    // Program called with arguments in the form of MODE -> METHOD -> KEY
    // e.g. "passwordManager encrypt caesar 12"
    //
    // if this is valid then assign arguments to variables
    // if not then print help message

    //no Arguments given
    //NOTE: This needs to be done differently as argc can be equal to 0 with no args
    if (argc < 4) {
        logging::log(logging::INFO, __func__, __LINE__, "no Arguments given");
        displayHelpMessage();
        //TODO: return codes relating to ways the program exits
        return 0;
    }


    //initialise variables that are arguments when running the program

    //encrypt or decrypt
    //std::string mode {};
    //mode = static_cast<std::string>(argv[1]);
    //std::cout << mode << '\n';
    std::string_view mode { argv[1] };

    std::string_view method { argv[2] };

    //password / key (e.g. 2 for caesar cipher)
    std::stringstream convert{ argv[3] }; // set up a stringstream variable named convert, initialized with the input from argv[1]

	int key {};
	if (!(convert >> key)) // do the conversion
		key = 0; // if conversion fails, set myint to a default value

    std::cout << mode << '\n';
    std::cout << method << '\n';
    std::cout << key << '\n';

    //check if it's been setup initially (e.g. folder ~/.config/password_manager/passwordmaanger.rc exists);
    //if (!(std::ifstream { fileLocation })) {
    //    logging::log(logging::ERROR, __func__, __LINE__, "Failed to open file, Exiting");
    //    return 1;
    //}
    //else {
    //    logging::log(logging::INFO, __func__, __LINE__, "File opened successfully");
    //}



    if (mode == "encrypt"){

        if (method == "caesarcipher"){
            if (caesarCipher::checkIsEncrypted(fileLocation)) {
                std::cout << "File is already encrypted, exiting\n";
                //TODO: make enums for exit codes
                std::exit(1);
            }

           caesarCipher::encryptFile(key, fileLocation);
        } else {
            std::cout << "invalid encryption method\n";
            std::exit(3);
        }
    } else if (mode == "decrypt"){
        if (method == "caesarcipher"){
            if (!(caesarCipher::checkIsEncrypted(fileLocation))) {
                std::cout << "File is already decrypted, exiting\n";
                //TODO: make enums for exit codes
                std::exit(1);
            }
            caesarCipher::decryptFile(key, fileLocation);
        } else {
            std::cout << "invalid decrypt method\n";
            std::exit(4);
        }
    }


    logging::log(logging::INFO, __func__, __LINE__,"end of program, returning 0" );
    return 0;
}
