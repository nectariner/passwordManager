#include <fstream>
#include <iostream>
#include <string>
#include "encryption.hpp"
#include "globals.hpp"

#ifndef logging
    #define logging
    #include "logging.hpp"
#endif

namespace caesarCipher {
    void unencrypt(int key) {
        std::cout << "in unencrypt\n";
        std::ifstream file { globals::g_initialisationFileLocation };
        std::string test;
        while (!(file.eof())){
            std::getline(file, test);
            std::cout << test << "\n";
        }
    }   
}
    
bool encryptFile() {
    logging::log(logging::INFO, __func__, __LINE__);
    std::string strInput;

    logging::log(logging::INFO, __func__, __LINE__, "Contents of current line are: ");
    int numOfLines { 0 };
    std::ifstream myFile { globals::g_initialisationFileLocation };
    while (!(myFile.eof())) {
        std::getline(myFile, strInput);   
        std::cout << strInput << std::endl;
        numOfLines++;
    }
    std::cout << "num of lines: " << numOfLines << "\n";
    
    caesarCipher::unencrypt(2);

  
    return true;
}