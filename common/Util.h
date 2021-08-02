#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <vector>

#define MAX_32BIT_INT 2147483647

namespace burgerkv {

class Util {
public:
    static char* strToCharStar(const std::string & str);
    
    static void split(const std::string& str, std::vector<std::string>& result, const std::string& sep = "", int maxsplit = -1);
    static bool isdigit(const std::string& str);
private:
    static void split_whitespace(const std::string& str, std::vector<std::string>& result, int maxsplit);
};

} // namespace burgerkv



#endif // UTIL_H