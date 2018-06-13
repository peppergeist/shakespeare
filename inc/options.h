#ifndef OPTIONS_H
#define OPTIONS_H

#include <iostream>
#include <string>

#define DBOUT( x )  if (options::debug_mode_on) \
                    { std::cout << "[DEBUG] " << x << std::endl; }

namespace options
{

static int major_version = 0;
static int minor_version = 9;

extern bool debug_mode_on; /* defined in options.cpp */

static std::string primary_data_path = "/usr/local/opt/shakespeare-quote/dat/";
static std::string secondary_data_path = "dat/";

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
