#pragma once
#include <iostream>
#include <string>

namespace nebula {

class Log {
public:
    static void Info(const std::string& message) {
        std::cout << "[INFO] " << message << std::endl;
    }
    static void Error(const std::string& message) {
        std::cerr << "[ERROR] " << message << std::endl;
    }
};

} // namespace nebula
