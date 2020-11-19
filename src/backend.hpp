#include <string>
#include "../lib/json.hpp"

using json = nlohmann::json;

class AccountEntry {
    private:
        json m_accountEntryJson;
        std::string m_service;
        std::string m_username;
        std::string m_password;
        std::string m_totpAnswer { "" }; //set to null as default
        std::string m_totpSecret { "" };
        std::string m_notes;

    public:
        AccountEntry(std::string service,
                     std::string username,
                     std::string password
        );

        AccountEntry(std::string service,
                     std::string username,
                     std::string password,
                     std::string totpSecret,
                     std::string notes
        );

        void updateService(std::string service);
        void updateUsername(std::string newUsername);
        void updatePassword(std::string newPassword);
        void updateTotpSecret(std::string newTotpSecret);
        void updateNotes(std::string newNotes);

        std::string getUsername() const;
        std::string getPassword() const;
        std::string getTotpSecret() const;
        std::string getTotpAnswer() const;
        std::string getNotes() const;

        json getJsonEntry();
        std::string getService();
};


class FileHandler{
    private:
        std::string m_filePath;

    public:
        FileHandler();
        json getService(std::string key);
        std::ifstream openFile();

        json getAllEntries();
        std::string getFilePath();

};

//interface between Filehander and Account entry objects
void writeSingleEntryToFile(FileHandler fileHandler, AccountEntry accountEntry);
