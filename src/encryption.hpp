namespace caesarCipher {
    bool encryptFile(int key, std::string fileLocation);
    bool decryptFile(int key, std::string fileLocation);
    bool checkIsEncrypted(std::string fileLocation);
}
