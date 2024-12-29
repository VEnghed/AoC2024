#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>

unsigned int leftList[1000] = {0};
unsigned int rightList[1000] = {0};
unsigned int similarityScore = 0;

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

    for (size_t i = 0; i < 1000; i++) {
        unsigned int multiplier = 0;

        for (size_t j = 0; j < 1000; j++) {
            if (rightList[j] == leftList[i]) {
                multiplier++;
            }
        }

        similarityScore += multiplier * leftList[i];
    }

    std::cout << similarityScore << std::endl;

    inputStream.close();
    return 0;
}