#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>

unsigned int result = 0;
std::string gameBoard[140];

bool evaluatePosition(int row, int col) {
    std::string diag1 = "";
    diag1 += gameBoard[row][col];
    diag1 += gameBoard[row + 1][col + 1];
    diag1 += gameBoard[row + 2][col + 2];

    std::string diag2 = "";
    diag2 += gameBoard[row + 2][col];
    diag2 += gameBoard[row + 1][col + 1];
    diag2 += gameBoard[row][col + 2];

    return (diag1 == "MAS" || diag1 == "SAM") && (diag2 == "MAS" || diag2 == "SAM");
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

    for (size_t i = 0; i < 138; i++)
        for (size_t j = 0; j < 138; j++)
            result += evaluatePosition(i, j);

    std::cout << result << std::endl;

    return 0;
}