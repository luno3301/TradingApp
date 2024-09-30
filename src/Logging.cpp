#include "../includes/Logging.h"
#include "../includes/UserAuth.h"
void Logging::LogData(std::string str) {
    std::fstream log;
    int pos;

    std::string output;
    std::string user_path = "../userdata/" + input_login + ".txt";
    std::string log_path = "../userdata/" + input_login + ".log";

    log.open(log_path, std::fstream::app);
    std::time_t result = std::time(nullptr);
    output = std::ctime(&result) + str;
    if((pos = output.find('\n')) != std::string::npos)
        output.erase(pos);
    log << str + "\t" + output << std::endl;
    log.close();
}

bool Logging::containsWord(const std::string& text, const std::string& word) {
    std::regex pattern("\\b" + word + "\\b");
    return std::regex_search(text, pattern);
}
