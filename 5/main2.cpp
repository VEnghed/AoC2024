#include <fstream>
#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <vector>

unsigned int result = 0;

std::list<std::pair<int, int>> rules;
std::list<std::vector<int>> updates;

int isCorrect(std::vector<int> update) {
    bool updateIsCorrect = true;
    for (auto const &rule : rules) {
        int firstPos = -1;
        int secondPos = -1;

        for (int i = 0; i < update.size(); i++) {
            if (update[i] == rule.first)
                firstPos = i;
            if (update[i] == rule.second)
                secondPos = i;
        }

        updateIsCorrect &= firstPos == -1 || secondPos == -1 || secondPos > firstPos;
    }

    return updateIsCorrect * update[update.size() / 2];
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

    bool readingUpdates;

    while (std::getline(inputStream, readLine)) {
        if (readLine == "") {
            readingUpdates = true;
            continue;
        }

        if (!readingUpdates) {
            int a, b = 0;
            for (size_t i = 0; i < readLine.length(); i++)
                if (readLine[i] == '|') {
                    a = std::stoi(readLine.substr(0, i));
                    b = std::stoi(readLine.substr(i + 1, readLine.length() - i));

                    rules.push_back(std::pair<int, int>(a, b));
                }

        } else {
            updates.push_back(std::vector<int>());
            int lastDelimiterIndex = 0;
            for (size_t i = 0; i <= readLine.length(); i++)
                if (readLine[i] == ',' || !readLine[i]) {
                    updates.back().push_back(std::stoi(readLine.substr(!lastDelimiterIndex ? 0 : lastDelimiterIndex + 1, i - lastDelimiterIndex)));
                    lastDelimiterIndex = i;
                }
        }
    }

    std::cout << "Read " << rules.size() << " rules and " << updates.size() << " updates." << std::endl;

    int correctUpdates = 0;

    for (auto const &update : updates)
        correctUpdates += isCorrect(update);

    std::cout << correctUpdates << std::endl;

    return 0;
}