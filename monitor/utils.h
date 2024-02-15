/**
* @file utils.h
* @author Kinvy
* @email kinvy66@163.com
* @date: 2024/2/15 11:32
* @version: 1.0
* @description: 
**/
#ifndef LIGHTMONITOR_UTILS_H
#define LIGHTMONITOR_UTILS_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace lmonitor {
class ReadFile {
public:
    explicit ReadFile(const std::string& name) : ifs_(name) {}
    ~ReadFile() { ifs_.close(); }

    /**
     * @brief
     * @param args
     * @return
     */
    bool ReadLine(std::vector<std::string>* args);
    static std::vector<std::string> GetStatsLines(const std::string& stat_file,
                                                  const int line_count) {
        std::vector<std::string> stats_lines;
        std::ifstream buffer(stat_file);
        for (int line_num = 0; line_num < line_count; ++line_num) {
            std::string line;
            std::getline(buffer, line);
            if (line.empty()) {
                break;
            }
            stats_lines.push_back(line);
        }
        return stats_lines;
    }

private:
    std::ifstream ifs_;
};
}

#endif //LIGHTMONITOR_UTILS_H
