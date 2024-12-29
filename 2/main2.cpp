#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "helpers.h"

int score = 0;

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

    while (std::getline(inputStream, readLine)) {
        int j = 0;
        char step = 0;
        int stepBuffer[32] = {0};

        for (size_t i = 0; i < readLine.length() + 1; i++)
            if (readLine[i] == 32 || !readLine[i]) {
                stepBuffer[step++] = std::stoi(readLine.substr(j, i - j));
                j = i + 1;
            }

        score += checkSteps(stepBuffer, step) | checkStepsSkip(stepBuffer, step);
    }
    std::cout << score << std::endl;

    inputStream.close();
    return 0;
}