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

    }   


    //return true if successful encrypt, else return null or false
    //TODO: log an error if it fails
    bool encryptFile(int key) {
        logging::log(logging::INFO, __func__, __LINE__);
        std::ifstream myFile { globals::g_initialisationFileLocation };
        logging::logFileContents(logging::INFO, __func__, __LINE__, "\nNOTE: this is before encrpytion\n");

 //open file
        std::ifstream file { globals::g_initialisationFileLocation, std::ios::out };
        //string to store the contents of the current line in
        std::string lineContents;

        //read line by line until EOF, then break
        while (true) {
            std::string encryptedLine;
            std::getline(file, lineContents);
            if (file.eof())
                break;
            std::cout << lineContents << "\n";
            //iterate over the contents of the string and increase by the key (caesar cipher)
            for (std::string::iterator it = lineContents.begin(); it != lineContents.end(); ++it){
                encryptedLine += static_cast<char>(*(it) + key);
            }
            //output
            //TODO: needs to be written to file
            std::cout << "encryptedLine = " << encryptedLine << "\n";
        }
        return true;
    }
}
