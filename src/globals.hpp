#ifndef GLOBALS_INCLUDED
    #define GLOBALS_INCLUDED
    namespace globals {
        constexpr std::string_view g_applicationName { "passwordManager" };

        //testEnv data CHANGE FOR PRODUCTION
        //    constexpr std::string_view g_fileLocation { "testEnv/passwordManager/passwordManagerrc" };
        constexpr std::string_view g_fileLocation { "testEnv/passwordManager/passwordManagerrc" };
        constexpr std::string_view g_tempFileLocation { "/tmp/.passwordManagerTemp" };

    }

#endif
