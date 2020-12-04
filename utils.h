#pragma once

#include <memory>
#include <stdexcept>
#include <string>
#include <sstream>
#include <array>
#include <regex>

namespace utils {
    inline std::string exec_cmd(const char* cmd) {
        std::array<char, 128> buffer;
        std::string result;
        std::unique_ptr<FILE, decltype(&_pclose)> pipe(_popen(cmd, "r"), _pclose);
        if (!pipe) {
            return "";
        }
        while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
            result += buffer.data();
        }
        return result;
    }

    inline char* char_ptr_to_lower(char* str)
    {
        unsigned char* mystr = (unsigned char*)str;

        while (*mystr) {
            *mystr = tolower(*mystr);
            mystr++;
        }
        return str;
    }
}