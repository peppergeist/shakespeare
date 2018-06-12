#include <string>
#include <vector>

/**
 * @brief      Counts the number of quotes in a file.
 *
 * @param[in]  filename  The filename to count the quotes in.
 *
 * @return     Number of quotes in file.
 */
int count_quotes_in_file(std::string filename);

/**
 * @brief      Gets the random quote from a file.
 *
 * @param[in]  filename  The filename to get a quote from.
 *
 * @return     The random quote from the file.
 */
std::string get_random_quote_from_filename(std::string filename);

/**
 * @brief      Fetches all files from a specific group.
 *
 * @param[in]  group  The group file to read from.
 *
 * @return     A vector of all filenames to fetch a quote from.
 */
std::vector<std::string> fetch_files_from_group(std::string group);
