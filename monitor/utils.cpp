/**
* @file utils.cpp
* @author Kinvy
* @email kinvy66@163.com
* @date: 2024/2/15 11:32
* @version: 1.0
* @description: 
**/
#include "utils.h"

namespace lmonitor {

bool ReadFile::ReadLine(std::vector<std::string>* args) {
    std::string line;
    std::getline(ifs_, line);
    if (ifs_.eof() || line.empty()) {
        return false;
    }

    std::istringstream line_ss(line);
    while (!line_ss.eof()) {
        std::string word;
        line_ss >> word;
        args->push_back(word);
    }
    return true;
}
