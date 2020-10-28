#ifndef GLOBALS_INCLUDED
    #define GLOBALS_INCLUDED
    namespace globals {
            constexpr std::string_view g_applicationNamepp { "passwordManager" };

        //testEnv data CHANGE FOR PRODUCTION
        //    constexpr std::string_view g_initialisationFileLocation { "testEnv/passwordManager/passwordManagerrc" };
            constexpr std::string_view g_initialisationFileLocation { "testEnv/passwordManager/passwordManagerrc" } ;

        }

#endif
