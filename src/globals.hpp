
#ifndef GLOBALS_INCLUDED
#define GLOBALS_INCLUDED
    namespace globals {
        constexpr std::string_view g_applicationName { "passwordManager" };

        //testEnv data CHANGE FOR PRODUCTION
        //TODO: Change this to be not hardcoded
        constexpr std::string_view g_fileLocation { "/home/fred/nextcloud/passwordManager/testEnv/passwordManager/passwordManagerrc" };
        constexpr std::string_view g_tempFileLocation { "/tmp/.passwordManagerTemp" };

        constexpr std::string_view g_helpMessage { "PasswordManager\nUsage: passwordManager MODE METHOD KEY\ne.g. passwordManager encrypt caesar 11\n" };

//        void displayHelpMessage() {
//            std::cout << "PasswordManager\n";
//            std::cout << "Usage:\tpasswordManager Mode METHOD KEY\n";
//            std::cout << "\te.g. passwordManager encrypt caesar 11\n";
//
//        }



    }

#endif
