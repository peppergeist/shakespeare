#include <cstdlib>
#include <dirent.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int count_quotes_in_file(std::string filename)
{
    std::ifstream file("dat/" + filename);
    std::string line;
    int total_quotes = -1;

    while (std::getline(file, line))
    {
        if (line == "%")
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
    int quote_index = rand() % count_quotes_in_file(filename);
    bool quote_read = false;
    std::ifstream file("dat/" + filename);
    std::string line;
    std::string quote = "";

    while (std::getline(file, line) && !quote_read)
    {
        if (line == "%")
        {
            if (quotes_counted == quote_index)
            {
                /* read lines until entire quote is consumed */
                while(std::getline(file, line) && !quote_read)
                {
                    if (line == "%")
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

std::vector<std::string> fetch_files(std::string directory)
{
    DIR *dir;
    struct dirent *ent;
    std::vector<std::string> filenames;

    if ((dir = opendir(directory.c_str())) != NULL)
    {
        while ((ent = readdir (dir)) != NULL)
        {
            /* ignore directories like . and .. */
            if (!strcmp(ent->d_name, ".") || !strcmp(ent->d_name, ".."))
            {
                continue;
            }

            filenames.push_back(ent->d_name);
        }
    }
    else
    {
        perror("Could not open directory.");
        exit(1);
    }

    closedir(dir);
    return filenames;
}

int main(int argc, char * argv[])
{
    srand(time(NULL));
    std::vector<std::string> filenames = fetch_files("dat");
    std::string filename = filenames[rand() % filenames.size()];
    printf("%s", get_random_quote_from_filename("hamlet").c_str());


    printf("\n");
    return 0;
}
