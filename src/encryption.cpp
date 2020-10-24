#include <fstream>
#include <iostream>
#include <string>
#include "encryption.hpp"

#ifndef logging
    #define logging
    #include "logging.hpp"
#endif
    

bool encryptFile(std::ifstream& myFile) {
    logging::log(logging::INFO, __func__, __LINE__);
    std::string strInput;
    

    logging::log(logging::INFO, __func__, __LINE__, "Contents of current line are: \"");
    int numOfLines { 0 };
    while (!(myFile.eof())) {
        std::getline(myFile, strInput);   
        std::cout << strInput << std::endl;
        numOfLines++;
    }
    std::cout << "num of lines: " << numOfLines << "\n";
  
    return true;
}