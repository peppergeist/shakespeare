#include <iostream>
#include <string>
#include "options.h"

std::string parse_for_group(int argc, char * argv[])
{
    for (int i = 1; i < argc; ++i)
    {
        if (!strcmp(argv[i], "-g") || !strcmp(argv[i], "--group"))
        {
            if (i + 1 < argc)
            {
                return argv[i + 1];
            }
            else
            {
                std::cout << "[ERROR] Error while parsing for group. "
                    << "Flag must be followed by a file name." << std::endl;
                exit(EXIT_FAILURE);
            }
        }
    }

    return "all";
}

std::string parse_for_work(int argc, char * argv[])
{
    for (int i = 1; i < argc; ++i)
    {
        if (!strcmp(argv[i], "-w") || !strcmp(argv[i], "--work"))
        {
            if (i + 1 < argc)
            {
                return argv[i + 1];
            }
            else
            {
                std::cout << "[ERROR] Error while parsing for work. "
                    << "Flag must be followed by a file name." << std::endl;
                exit(EXIT_FAILURE);
            }
        }
    }

    return "";
}

bool parse_for_debug(int argc, char * argv[])
{
    for (int i = 1; i < argc; ++i)
    {
        if (!strcmp(argv[i], "-d") || !strcmp(argv[i], "--debug"))
        {
            return true;
        }
    }

    return false;
}

bool parse_for_version(int argc, char * argv[])
{
    for (int i = 1; i < argc; ++i)
    {
        if (!strcmp(argv[i], "-v") || !strcmp(argv[i], "--version"))
        {
            return true;
        }
    }

    return false;
}
