#include <iostream>

// Enum definition with corrected bit values
typedef enum e_logger_level {
    e_ERROR   = 0x01,  // 0001
    e_WARNING = 0x02,  // 0010
    e_INFO    = 0x04,  // 0100
    e_DEBUG   = 0x08,  // 1000
} e_logger_level_t;

// Logger mode (Bitwise OR of all enabled modes)
int logger_mode_;

// Log print function
void logprint(e_logger_level_t level, const std::string& message) {
    if (logger_mode_ & level) {  // Check if the level is enabled
        switch(level) {
            case e_ERROR:
                std::cout << "[ERROR] " << message << std::endl;
                break;
            case e_WARNING:
                std::cout << "[WARNING] " << message << std::endl;
                break;
            case e_INFO:
                std::cout << "[INFO] " << message << std::endl;
                break;
            case e_DEBUG:
                std::cout << "[DEBUG] " << message << std::endl;
                break;
            default:
                std::cout << "[UNKNOWN] " << message << std::endl;
                break;
        }
    }
}

int main() {
    int e_ERROR_enable = 1 <<0;
    int e_WARNING_enable = 1<<1;
    int e_INFO_enable = 1<<2;
    int e_DEBUG_enable = 1<<3;
    // Logger mode (Bitwise OR of all enabled modes)
    logger_mode_ = static_cast<int>(e_ERROR_enable | e_WARNING_enable | e_INFO_enable | e_DEBUG_enable);  // enable all levels for now
    logprint(e_ERROR, "This is an error message.");
    logprint(e_WARNING, "This is a warning message.");
    logprint(e_INFO, "This is an informational message.");
    logprint(e_DEBUG, "This is a debug message.");
    return 0;
}