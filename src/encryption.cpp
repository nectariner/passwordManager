#include <fstream>
#include <iterator>
#include <iostream>
#include <string>
#include "encryption.hpp"
#include "globals.hpp"

#ifndef logging
    #define logging
    #include "logging.hpp"
#endif

namespace caesarCipher {
    bool unencrypt(int key) {
        std::cout << "in unencrypt\n";
        std::ifstream file { globals::g_initialisationFileLocation, std::ios::out };

        std::string test;
        while (true) {
            std::string encryptedLine;
            std::getline(file, test);
            if (file.eof())
                break;
            std::cout << test << "\n";
            //for (int i = 0; i < test.size(); i++){
            for (std::string::iterator it = test.begin(); it != test.end(); ++it){
                encryptedLine += static_cast<char>(*(it) + key);
            }
            std::cout << "encryptedLine = " << encryptedLine << "\n";
        }
    }   
}
    
bool encryptFile(int key) {
    //aim for all responsibilities to be done by the function such as user input
    logging::log(logging::INFO, __func__, __LINE__);
//    int userInputForKey { 0 };
//    std::cout << "Please enter a key to encrypt via caesar cipher\n";
//    std::cin >> userInputForKey;
//    std::string lineOfFile;

    logging::log(logging::INFO, __func__, __LINE__, "Contents of current line are: ");
    int numOfLines { 0 };
    std::ifstream myFile { globals::g_initialisationFileLocation };
    logging::logFileContents(logging::INFO, __func__, "\nthis is before encrpytion\n");
    return true;
}
