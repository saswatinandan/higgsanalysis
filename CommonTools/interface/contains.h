#ifndef contains_h
#define contains_h

#include <set>    // std::set
#include <string> // std::string
#include <vector> // std::vector

/**
 * @brief Check if a certain string is contained in a given vector/set of strings
 */
bool
contains(const std::vector<std::string> & list_of_strings,
         const std::string & keyWord);
bool
contains(const std::set<std::string> & list_of_strings,
         const std::string & keyWord);

#endif // contains_h
