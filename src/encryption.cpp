#include <fstream>
#include <iterator>
#include <iostream>
#include <string>
#include "encryption.hpp"
#include "globals.hpp"
#include <filesystem>

#ifndef logging
    #define logging
    #include "logging.hpp"
#endif

//TODO: get file handling into one function called multiple times
//REVIEW: Good way of making decrypt just encrypt with "- key" call

namespace caesarCipher {
    bool decryptFile(int key) {
        logging::log(logging::INFO, __func__, __LINE__);
        std::ifstream encryptedFile { globals::g_fileLocation.data() };
        while (true) {
            std::string encryptedLine;
            std::string decryptedLine;
            std::getline(encryptedFile, encryptedLine);
            if(encryptedFile.eof()){
                break;
            }
            for (std::string::iterator it = encryptedLine.begin(); it != encryptedLine.end(); ++it){
                decryptedLine += static_cast<char>(*(it) - key);
            }
            std::cout << decryptedLine << "\n";

        }
            return true;
    }


    //return true if successful encrypt, else return null or false
    //TODO: log an error if it fails
    bool encryptFile(int key) {
        logging::log(logging::INFO, __func__, __LINE__);
        std::ifstream permFile { globals::g_fileLocation.data() };
        if(!(permFile)) {
            std::cout << "FAILEDTOOPENPERFMFILE\n";
        }

        std::ofstream newFile { globals::g_tempFileLocation.data(), std::ios::trunc};
        if(!(newFile)){
            std::cout <<"FAILEDTOOPENNEWFILE\n";
        }

        logging::logFileContents(logging::INFO, __func__, globals::g_fileLocation,  "\nNOTE: this is before encrpytion\n");

 //open file
        //string to store the contents of the current line in
        std::string lineContents;

        //read line by line until EOF, then break
        while (true) {
            std::string encryptedLine;
            std::getline(permFile, lineContents);
            if (permFile.eof())
                break;
            //iterate over the contents of the string and increase by the key (caesar cipher)
            for (std::string::iterator it = lineContents.begin(); it != lineContents.end(); ++it){
                encryptedLine += static_cast<char>(*(it) + key);
            }
            //output
            //TODO: needs to be written to file
            newFile << encryptedLine;
            newFile << "\n";
        }
        permFile.close();
        newFile.close();


        //all written to tempFile now remove old and move new
        //TODO:Come up with a better way to do this with the globals essentially
//        constexpr std::string_view moveTempToPerm { "mv /tmp/.passwordManagerTemp /home/$USER/nextcloud/passwordManager/testEnv/passwordManager/passwordManagerrc" };

        //REVIEW: is there a better way to do this?
        system("mv /tmp/.passwordManagerTemp ./testEnv/passwordManager/passwordManagerrc");
        logging::logFileContents(logging::INFO, __func__, globals::g_fileLocation, "\nNOTE: This is after encryption");

        return true;
    }
}
