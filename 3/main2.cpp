#include <fstream>
#include <iostream>
#include <map>
#include <regex>
#include <sstream>
#include <string>

unsigned int result = 0;
unsigned int readSymbols = 0;
std::map<int, int> cmdMap;

int main() {

    std::string filename = "input.txt";
    std::ifstream inputStream(filename);

    // Check if file opened properly
    if (!inputStream.is_open()) {
        std::cout << "Error opening file!" << std::endl;
        return 1;
    }

    // The currently read line
    std::string readLine;

    std::map<int, int> cmdMap;

    std::regex mulFunc_regex("mul\\(\\d+\\,\\d+\\)");
    std::regex enable_regex("do\\(\\)");
    std::regex disable_regex("don't\\(\\)");

    int lineoffset = 0;

    while (std::getline(inputStream, readLine)) {

        // mul commands
        auto mulFunc_begin = std::sregex_iterator(readLine.begin(), readLine.end(), mulFunc_regex);
        auto mulFunc_end = std::sregex_iterator();

        for (std::regex_iterator i = mulFunc_begin; i != mulFunc_end; ++i) {
            std::smatch match = *i;
            std::string match_str = match.str().substr(4, match.str().length() - 5);
            int commaIndex = 0;

            while (match_str[++commaIndex] != 44) {
            }

            cmdMap.insert(std::pair<int, int>(match.position() + lineoffset, std::stoi(match_str.substr(0, commaIndex)) * std::stoi(match_str.substr(commaIndex + 1, match_str.length() - commaIndex))));
        }

        // do commands
        auto doFunc_begin = std::sregex_iterator(readLine.begin(), readLine.end(), enable_regex);
        auto doFunc_end = std::sregex_iterator();

        for (std::regex_iterator i = doFunc_begin; i != doFunc_end; ++i) {
            std::smatch match = *i;

            cmdMap.insert(std::pair<int, int>(match.position() + lineoffset, -1));
        }

        // don't commands
        auto dontFunc_begin = std::sregex_iterator(readLine.begin(), readLine.end(), disable_regex);
        auto dontFunc_end = std::sregex_iterator();

        for (std::regex_iterator i = dontFunc_begin; i != dontFunc_end; ++i) {
            std::smatch match = *i;

            cmdMap.insert(std::pair<int, int>(match.position() + lineoffset, -2));
        }

        lineoffset += readLine.length();
    }

    bool enable = true;
    for (auto const &[key, val] : cmdMap) {

        std::cout << key << "\n";
        switch (val) {
        case -2:
            enable = false;
            break;
        case -1:
            enable = true;
            break;
        default:

            result += val * enable;
        }
    }
    std::cout << result << std::endl;
    return 0;
}