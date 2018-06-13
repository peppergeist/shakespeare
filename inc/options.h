#ifndef OPTIONS_H
#define OPTIONS_H

#include <string>

namespace options
{
/**
 * @brief      Parses input for group flag, returns it if it is present.
 *
 * @param[in]  argc  The argument count.
 * @param      argv  The argument vector.
 *
 * @return     The filename of the group to use if present, otherwise "all".
 */
std::string parse_for_group(int argc, char * argv[]);

/**
 * @brief      Parses input for work flag, returns it if it is present.
 *
 * @param[in]  argc  The argument count.
 * @param      argv  The argument vector.
 *
 * @return     The filename of the work to use if present, otherwise "".
 */
std::string parse_for_work(int argc, char * argv[]);

/**
 * @brief      Parses input for debug flag, returns true if it is present.
 *
 * @param[in]  argc  The argument count.
 * @param      argv  The argument vector.
 *
 * @return     True if debug flag is present, false otherwise.
 */
bool parse_for_debug(int argc, char * argv[]);

/**
 * @brief      Parses input for version flag, returns true if it is present.
 *
 * @param[in]  argc  The argument count.
 * @param      argv  The argument vector.
 *
 * @return     True if version flag is present, false otherwise.
 */
bool parse_for_version(int argc, char * argv[]);
};

#endif
