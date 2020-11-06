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
    bool decryptFile(int key, std::string fileLocation) {
        logging::log(logging::INFO, __func__, __LINE__);
        std::ifstream encryptedFile { fileLocation };

        std::string encryptedLine;
        std::string decryptedLine;
        while (true) {
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
    bool encryptFile(int key, std::string fileLocation) {
        logging::log(logging::INFO, __func__, __LINE__);
        std::ifstream permFile { fileLocation };

        if(!(permFile)) {
            std::cout << "FAILEDTOOPENPERFMFILE\n";
        }

        //check if file is encrypted
        //this also gets rid of the first line so no need to skip it afterwards
        //if it's not encrypted, then encrypt
        //if it is then warn the user and exit
        //check if the file is already encrypted, fail if it is and don't encrypt again
        std::ofstream newFile { globals::g_tempFileLocation.data(), std::ios::trunc};
        if(!(newFile)){
            std::cout <<"FAILEDTOOPENNEWFILE\n";
        }

        logging::logFileContents(logging::INFO, __func__, fileLocation,  "\nNOTE: this is before encrpytion\n");

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
        system("mv /tmp/.passwordManagerTemp /home/fred/.config/passwordManager/passwordManagerrc");
        logging::logFileContents(logging::INFO, __func__, fileLocation, "\nNOTE: This is after encryption");

        return true;
    }

    //return true if it is already encrypted, false if not
    //check if the first line of the file is [[passwordManager]], if it isn't then it's already encrypted
    bool checkIsEncrypted(std::string fileLocation){
        //check if the file is already encrypted, fail if it is and don't encrypt again
        std::string firstLine;

        //REVIEW: does this need to be put in globals??
        constexpr std::string_view fileHeader { "[[passwordManager]]" };
        std::ifstream file { fileLocation };
        std::getline(file, firstLine);
        if (firstLine == fileHeader){
            std::cout << "they're equal\n";
            return false;
        } else {
            return true;
        }
    }
}
