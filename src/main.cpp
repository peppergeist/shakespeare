#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "file_util.h"
#include "random_gen.h"

std::string parse_flags(int argc, char * argv[])
{
    if (argc == 1)
    {
        return "all";
    }
    if (argc == 2)
    {
        std::cout << "[ERROR] Too few arguments provided to parse."
            << std::endl;
        exit(EXIT_FAILURE);
    }
    else if (argc > 3)
    {
        std::cout << "[ERROR] Too many arguments provided to parse."
            << std::endl;
        exit(EXIT_FAILURE);
    }

    if (!strcmp(argv[1], "-g") || !strcmp(argv[1],  "--group"))
    {
        return argv[2];
    }
    else if (!strcmp(argv[1], "-w") || !strcmp(argv[1], "--work"))
    {
        return std::string(std::string("%") + argv[2]);
    }

    /* if all else fails, return "all" anyway */
    return "all";
}

int main(int argc, char * argv[])
{

    std::string group = "all"; /* default to fetching all files */
    if (argc > 1)
    {
        group = parse_flags(argc, argv);
    }

    /* '%' identifier means only pick from specific file instead of group */
    if (group[0] == '%')
    {
        std::cout << get_random_quote_from_filename(group.substr(1))
            << std::endl;
    }
    else
    {
        std::vector<std::string> filenames = fetch_files_from_group(group);
        std::string filename = filenames[
        get_random_number(0, filenames.size() - 1)];
        std::cout << get_random_quote_from_filename(filename) << std::endl;
    }

    return 0;
}
