//this is the interface for all the other programs, this shouldnt do anything, just provide the means

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

#include "backend.hpp"

using json = nlohmann::json;
//AccountEntry methods

AccountEntry::AccountEntry(std::string service, std::string username, std::string password){
    m_service = service;
    m_username = username;
    m_password = password;
    m_totpSecret = "";
    m_notes = "";
}

AccountEntry::AccountEntry(std::string service, std::string username, std::string password, std::string totpSecret, std::string notes){
    m_service = service;
    m_username = username;
    m_password = password;
    m_totpSecret = totpSecret;
    m_notes = notes;

    std::cout << "uhhh constructor worked\n";
    return;
}

void AccountEntry::updateService(std::string newService){
    m_service = newService;
}

void AccountEntry::updateUsername(std::string newUsername){
            m_username = newUsername;
}
void AccountEntry::updatePassword(std::string newPassword){
            m_password = newPassword;
}
void AccountEntry::updateTotpSecret(std::string newTotpSecret){
            m_totpSecret = newTotpSecret;
}
void AccountEntry::updateNotes(std::string newNotes){
            m_notes = newNotes;
}

std::string AccountEntry::getUsername() const { return m_username; }
std::string AccountEntry::getPassword() const { return m_password; }
std::string AccountEntry::getTotpSecret() const { return m_totpSecret; }
std::string AccountEntry::getTotpAnswer() const { return m_totpAnswer; }
std::string AccountEntry::getNotes() const { return m_notes; }

json AccountEntry::getJsonEntry() {
    json jsonEntry = {
    {getService(), {
    {"username", getUsername()},
    {"password", getPassword()},
    {"Totp Answer", getTotpAnswer()},
    {"Notes", getNotes()}
    }}};
    return jsonEntry;
}

json FileHandler::getAllEntries(){
    std::ifstream file { getFilePath() };
    json allEntries;
    if (!(file.peek() == std::ifstream::traits_type::eof())) {
        file >> allEntries;
    }
    return allEntries;
}


std::ifstream FileHandler::openFile(){
    std::ifstream file { "/home/fred/.config/passwordManager/passwordManagerrc", std::ios::app };
    return file;
}

FileHandler::FileHandler(){
    m_filePath = std::getenv("XDG_CONFIG_HOME");
    m_filePath += "/passwordManager/passwordManagerrc";
}
std::string FileHandler::getFilePath() {
    return m_filePath;
}

std::string AccountEntry::getService(){
    return m_service;
}

void writeSingleEntryToFile(FileHandler fileHandler, AccountEntry accountEntry){
    json allEntries = fileHandler.getAllEntries();
    std::ofstream file { fileHandler.getFilePath(), std::ios::trunc};
    allEntries[accountEntry.getService()] = accountEntry.getJsonEntry()[accountEntry.getService()];
    file << allEntries.dump(4);
    return;
}




//FileHandler methods

//FileHandler::FileHandler(){
//
//}


//    AccountEntry::AccountEntry(std::string_view username, std::string_view password, std::string_view notes=""){
//        m_username = username;
//        m_password = password;
//        m_notes = notes;
//        std::cout << "uhhh constructor worked\n";
//        return;
//    }
//
//    AccountEntry::std::string_view m_getUsername(){
//        return m_username;
//    }
//    AccountEntry::std::string_view m_getPassword(){
//        return m_password;
//    }
//    AccountEntry::std::string_view m_getNotes(){
//        return m_notes;
//    }
//
//
//Filehandler::FileHandler() {
//    std::cout << "in the constructor\n";
//}
//return a reference to a file stream
//also performs error checking to check if it is possible etc


//private:
//    std::string_view fileLocationRelative { "passwordManager/passwordManagerrc" };
//    std::string_view m_fullFilePath;
//
//public:
//     std::string_view calcFileLocation(){
//        std::string fileLocation { std::getenv("XDG_CONFIG_HOME") };
//        fileLocation += '/';
//        fileLocation += fileLocationRelative;
//        return static_cast<std::string_view>(fileLocation);
//    }
//   std::ifstream openFile() {
//        std::ifstream storageFile { "/home/fred/.config/passwordManager/passwordManagerrc" };
//        return storageFile;
//    }
//
//    //read from file line by line and get all entries
//    //for now just return test data
// //   std::vector<AccountEntry> getAccountEntries(){
// //       std::vector<AccountEntry> testData;
// //       testData.push_back(AccountEntry("myUser", "myPass"));
// //       std::cout << "didnt break in getAccountEntries\n";
// //       return testData;
// //   }
//
//};
//
////namespace caesarCipher {
// //   std::vector<std::string>
////}
////
//FileHandler::FileHandler(){
//    std::cout << "constructor worked\n";
//}
