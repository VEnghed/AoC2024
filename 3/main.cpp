#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>

int result = 0;

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

    std::regex mulFunc_regex("mul\\(\\d+\\,\\d+\\)");

    while (std::getline(inputStream, readLine)) {
        auto mulFunc_begin = std::sregex_iterator(readLine.begin(), readLine.end(), mulFunc_regex);
        auto mulFunc_end = std::sregex_iterator();

        for (std::regex_iterator i = mulFunc_begin; i != mulFunc_end; ++i) {
            std::smatch match = *i;
            std::string match_str = match.str().substr(4, match.str().length() - 5);
            int commaIndex = 0;

            while (match_str[++commaIndex] != 44) {
            }

            // std::cout << std::stoi(match_str.substr(0, commaIndex)) << "\t" << std::stoi(match_str.substr(commaIndex + 1, match_str.length() - commaIndex)) << std::endl;
            result += std::stoi(match_str.substr(0, commaIndex)) * std::stoi(match_str.substr(commaIndex + 1, match_str.length() - commaIndex));
        }
    }
    std::cout << result << std::endl;
    return 0;
}