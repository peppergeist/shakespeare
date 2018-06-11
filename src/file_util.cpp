#include <fstream>
#include <iostream>
#include <vector>
#include "file_util.h"
#include "random_gen.h"

int count_quotes_in_file(std::string filename)
{
    std::ifstream file("dat/" + filename);
    if (!file.good())
    {
        std::cout << "[ERROR] Cannot open specific file to get quote."
            << std::endl;
        exit(EXIT_FAILURE);
    }
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
        exit(1);
    }

    return total_quotes;
}

std::string get_random_quote_from_filename(std::string filename)
{
    int quotes_counted = 0;
    int quote_index = get_random_number(0, count_quotes_in_file(filename) - 1);
    bool quote_read = false;
    std::ifstream file("dat/" + filename);
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
    std::ifstream group_file("dat/groups/" + group);
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
