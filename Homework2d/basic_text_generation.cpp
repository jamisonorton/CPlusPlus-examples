#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

// Function to train the model
std::unordered_map<std::string, std::vector<std::string>> trainModel(std::istream& in) {
    std::unordered_map<std::string, std::vector<std::string>> wordMap;
    std::string prev = "";
    std::string curr;

    // Read words from the input stream
    while (in >> curr) {
        // Add the current word to the vector associated with the previous word
        wordMap[prev].push_back(curr);
        // Move to the next pair (prev becomes curr)
        prev = curr;
    }

    return wordMap;
}

int main() {
    // Example input for training
    std::istringstream sampleText("one fish two fish red fish blue fish");

    // Train the model
    auto wordMap = trainModel(sampleText);

    // Display the contents of the map to check correctness
    for (const auto& pair : wordMap) {
        std::cout << pair.first << ": ";
        for (const auto& word : pair.second) {
            std::cout << word << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}