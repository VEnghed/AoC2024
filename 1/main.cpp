#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>

unsigned int leftList[1000] = {0};
unsigned int rightList[1000] = {0};
unsigned int totalDiff = 0;

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
    // Current line in the file
    unsigned int lineIndex = 0;

    while (std::getline(inputStream, readLine)) {
        leftList[lineIndex] = (unsigned int)std::stoi(readLine.substr(0, 7));
        rightList[lineIndex] = (unsigned int)std::stoi(readLine.substr(7, readLine.length() - 1));

        lineIndex++;
    }

    std::sort(leftList, leftList + std::size(leftList));
    std::sort(rightList, rightList + std::size(rightList));

    for (size_t i = 0; i < 1000; i++)
        totalDiff += abs(leftList[i] - rightList[i]);

    std::cout << totalDiff << "\n";

    inputStream.close();
    return 0;
}