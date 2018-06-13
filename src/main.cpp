#include <iostream>
#include <string>
#include <vector>
#include "file_util.h"
#include "options.h"
#include "random_gen.h"

int main(int argc, char * argv[])
{
    options::debug_mode_on = options::parse_for_debug(argc, argv);

    DBOUT("Debug mode is ON.");

    if (options::parse_for_version(argc, argv))
    {
        std::cout << "shakespeare-quote, version "
        << options::major_version << "." << options::minor_version << "\n"
            << std::endl;
    }

    std::string filename = options::parse_for_work(argc, argv);
    if (filename != "")
    {
        filename = format_work_filename(filename);
        DBOUT("Work specified: " << filename << ".");
        std::cout << get_random_quote_from_filename(filename) << std::endl;
    }
    else
    {
        DBOUT("Work not specified.");
        filename = options::parse_for_group(argc, argv);
        filename = format_group_filename(filename);
        DBOUT("Fetching files from group " << filename << ".");
        std::vector<std::string> filenames = fetch_files_from_group(filename);
        std::cout <<
            get_random_quote_from_filename(filenames[
                get_random_number(0, filenames.size() - 1)]) << std::endl;
    }

    return 0;
}
