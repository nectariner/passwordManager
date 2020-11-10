
#ifndef GLOBALS_INCLUDED
#define GLOBALS_INCLUDED
    namespace globals {
        constexpr std::string_view g_applicationName { "passwordManager" };
        constexpr std::string_view g_fileLocationRelative { "passwordManager/passwordManagerrc" };
        constexpr std::string_view g_tempFileLocation { "/tmp/.passwordManagerTemp" };
        constexpr std::string_view g_helpMessage { "PasswordManager\nUsage: passwordManager MODE METHOD KEY\ne.g. passwordManager encrypt caesar 11\n" };

        enum EXITCODES {
            PERMISSIONERR
        };
    }



#endif
