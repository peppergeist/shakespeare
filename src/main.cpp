#include <iostream>
#include <string>
#include <vector>
#include "file_util.h"
#include "options.h"
#include "random_gen.h"

#define MAJOR_VERSION 0.9
#define MINOR_VERSION 0

int main(int argc, char * argv[])
{
    if (parse_for_version(argc, argv))
    {
        std::cout << "shakespeare-quote, version " << MAJOR_VERSION << "."
            << MINOR_VERSION << std::endl << std::endl;
    }

    bool debug_on = parse_for_debug(argc, argv);

    std::string filename = parse_for_work(argc, argv);
    if (filename != "")
    {
        std::cout << get_random_quote_from_filename(filename) << std::endl;
    }
    else
    {
        filename = parse_for_group(argc, argv); /* by default will be "all" */
        std::vector<std::string> filenames = fetch_files_from_group(filename);
        std::cout <<
            get_random_quote_from_filename(filenames[
                get_random_number(0, filenames.size() - 1)]) << std::endl;
    }

    return 0;
}
