#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include "file_util.h"
#include "random_gen.h"

int main(int argc, char * argv[])
{
    std::string group = "all"; /* default to fetching all files */
    std::vector<std::string> filenames = fetch_files_from_group(group);
    std::string filename = filenames[
        get_random_number(0, filenames.size() - 1)];
    std::cout << get_random_quote_from_filename(filename) << std::endl;
    return 0;
}
