#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>

unsigned int result = 0;
std::string gameBoard[140];

std::string getColumn(int col) {
    std::string rtn = "";

    for (size_t i = 0; i < 140; i++)
        rtn += gameBoard[i][col];

    return rtn;
}

std::string getAscDiag(int row, int col) {
    std::string rtn = "";

    while (row >= 0 && col <= 139)
        rtn += gameBoard[row--][col++];

    return rtn;
}

std::string getDescDiag(int row, int col) {
    std::string rtn = "";

    while (row <= 139 && col <= 139)
        rtn += gameBoard[row++][col++];

    return rtn;
}

std::regex xmas_regex("XMAS");

int getXmasCount(std::string str) {
    int matches = 0;
    std::string currString = str;

    auto xmas_begin = std::sregex_iterator(currString.begin(), currString.end(), xmas_regex);
    auto xmas_end = std::sregex_iterator();

    matches += std::distance(xmas_begin, xmas_end);

    std::reverse(currString.begin(), currString.end());

    xmas_begin = std::sregex_iterator(currString.begin(), currString.end(), xmas_regex);
    xmas_end = std::sregex_iterator();

    matches += std::distance(xmas_begin, xmas_end);

    return matches;
}

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

    int row = 0;
    while (std::getline(inputStream, readLine))
        gameBoard[row++] = readLine;

    // check rows
    for (size_t i = 0; i < 140; i++) {
        std::string currString = gameBoard[i];

        result += getXmasCount(currString);
    }

    // check columns
    for (size_t i = 0; i < 140; i++) {
        std::string currString = getColumn(i);

        result += getXmasCount(currString);
    }

    // check NW ascending diagonals
    for (size_t i = 0; i < 140; i++) {
        std::string currString = getAscDiag(i, 0);

        result += getXmasCount(currString);
    }

    // check SE ascending diagonals
    for (size_t i = 1; i < 140; i++) {
        std::string currString = getAscDiag(139, i);

        result += getXmasCount(currString);
    }

    // check SW descending diagonals
    for (size_t i = 0; i < 140; i++) {
        std::string currString = getDescDiag(i, 0);

        result += getXmasCount(currString);
    }

    // check NW descending diagonals
    for (size_t i = 1; i < 140; i++) {
        std::string currString = getDescDiag(0, i);

        result += getXmasCount(currString);
    }

    std::cout << result << std::endl;
    return 0;
}