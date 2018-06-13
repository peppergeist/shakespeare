#ifndef FILE_UTIL_H
#define FILE_UTIL_H

#include <string>
#include <vector>

/**
 * @brief      Formats a filename to an expected format.
 *
 * @param[in]  filename  The filename, unformatted or formatted.
 *
 * @return     The filename in all lowercase with hyphens instead of spaces.
 */
std::string format_filename(std::string filename);

/**
 * @brief      Gets the specific file path for a given filename.
 *
 * @param[in]  filename  The filename to find the path for.
 *
 * @return     The full path of the given filename.
 */
std::string get_file_path_from_filename(std::string filename);

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

#endif
