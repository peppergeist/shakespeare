#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <iostream>
#include <string>
#include "file_util.h"
#include "options.h"
#include "random_gen.h"

std::string format_filename(std::string filename)
{
    DBOUT("Converting filename " << filename << ".");
    std::transform(filename.begin(), filename.end(),
        filename.begin(), ::tolower);
    for (int i = 0; i < filename.length(); ++i)
    {
        if (filename[i] == ' ')
        {
            filename[i] = '-';
        }
    }

    DBOUT("Filename converted to " << filename << ".");

    return filename;
}

std::string get_file_path_from_filename(std::string filename)
{
    DBOUT("Getting file " << filename << " in path "
        << options::primary_data_path << ".");

    std::ifstream file(options::primary_data_path + filename);

    if (!file.good())
    {
        DBOUT("File not found in primary data path. "
            << "Looking for file " << filename << " in path "
            << options::secondary_data_path << ".");

        file.open(options::secondary_data_path + filename);

        if (!file.good())
        {
            DBOUT("Could not find file " << filename
                << " in either data path. Aborting.");

            std::cerr << "[ERROR] Cannot open specific file to get quote."
                << std::endl;
            exit(EXIT_FAILURE);
        }
        else
        {
            return options::secondary_data_path + filename;
        }
    }

    return options::primary_data_path + filename;
}

int count_quotes_in_file(std::string filename)
{
    std::ifstream file(get_file_path_from_filename(filename));

    std::string line;
    int total_quotes = -1;

    while (std::getline(file, line))
    {
        if (line[0] == '%')
        {
            ++total_quotes;
        }
    }

    if (total_quotes == 0)
    {
        std::cerr << "Found 0 quotes in file. Aborting." << std::endl;
        exit(1);
    }

    DBOUT("Found " << total_quotes << " quotes in file " << filename << ".");

    return total_quotes;
}

std::string get_random_quote_from_filename(std::string filename)
{
    int quotes_counted = 0;
    DBOUT("Rolling random number for quote to fetch.");
    int quote_index = get_random_number(0, count_quotes_in_file(filename) - 1);
    bool quote_read = false;
    std::ifstream file(get_file_path_from_filename(filename));
    std::string line;
    std::string quote = "";

    while (std::getline(file, line) && !quote_read)
    {
        if (line[0] == '%')
        {
            if (quotes_counted == quote_index)
            {
                /* read lines until entire quote is consumed */
                while(std::getline(file, line) && !quote_read)
                {
                    if (line[0] == '%')
                    {
                        quote_read = true;
                    }
                    else
                    {
                        if (line[0] != '#')
                        {
                            quote += line + "\n";
                        }
                    }
                }
            }
            else
            {
                ++quotes_counted;
            }
        }
    }

    return quote;
}

std::vector<std::string> fetch_files_from_group(std::string group)
{
    std::ifstream group_file(get_file_path_from_filename("groups/" + group));
    std::string line;
    std::vector<std::string> filenames;

    while (std::getline(group_file, line))
    {
        if (line[0] != '#')
        {
            filenames.push_back(line);
        }
    }

    return filenames;
}
