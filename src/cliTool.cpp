#include "backend.hpp"

//debug
#include <iostream>
#include <fstream>
#include <array>
#include <string>


void outputHelpMessage(){
    std::cout << "passwordManager\n";
    std::cout << "Usage: \"passwordManager add google.com myUsername myPassword -n \"this is for old account\" -t \"Y64VEVMBTSXCYIWRSHRNDZW62MPGVU2G\"\"\n\n";
    return;
}

int main(int argc, char* argv[]) {
//    FileHandler fileHandler;
    //help message

    if ((argc < 3) || (argc > 9)){
        std::cout << "invalid number of arguments\n";
        outputHelpMessage();
    }

    FileHandler fileHandler;
    // This whole block handles input and optional flags
    if (strcmp(argv[1], "add") == 0) {
        AccountEntry accountEntry { argv[2], argv[3], argv[4] };

        for (int i = 5; i < argc; i++){
            if (strcmp(argv[i], "-t") == 0) {
                accountEntry.updateTotpSecret(argv[i + 1]);
            }
             if (strcmp(argv[i], "-n") == 0) {
                 accountEntry.updateNotes(argv[i + 1]);
            }
        }
        std::cout << accountEntry.getJsonEntry().dump(4);
        writeSingleEntryToFile(fileHandler, accountEntry);
        return 0;
    } else if (strcmp(argv[1], "get") == 0){
        if (strcmp(argv[2], "all") == 0) {
            json allEntries = fileHandler.getAllEntries();
            if (allEntries.is_null()) {
                std::cout << "No Entries, try add one with passwordManager add google.com myUsername myPassword\n";
            } else{
                std::cout << allEntries.dump(4) << '\n';
            }
        }
    }


//    AccountEntry accountEntry = AccountEntry("google.com","myUser", "myPass");
//    AccountEntry newAccount = AccountEntry("Facebook.com", "fred-cook", "abc123", "this is my totpSecret", "these are my notes");


    
//    outputAccountEntries(allAccountEntries);

    return 0;
}
