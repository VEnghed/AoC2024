#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

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

    int currVal = 0;

    while (std::getline(inputStream, readLine)) {
        int lastVal = 0;
        bool increasing = true;
        bool decreasing = true;
        bool stepsOK = true;

        int j = 0;

        for (size_t i = 0; i < readLine.length() + 1; i++)
            if (readLine[i] == 32 || !readLine[i]) {
                currVal = std::stoi(readLine.substr(j, i - j));
                j = i + 1;
                if (lastVal != 0) {
                    stepsOK &= abs(currVal - lastVal) < 4 && currVal != lastVal;
                    increasing &= currVal > lastVal;
                    decreasing &= currVal < lastVal;
                }

                lastVal = currVal;
            }

        score += stepsOK && (increasing || decreasing);
    }
    std::cout << score << std::endl;

    inputStream.close();
    return 0;
}