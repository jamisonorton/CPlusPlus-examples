#include <iostream>
using std::cin, std::cerr, std::cout, std::endl, std::istream, std::getline;

#include <fstream>
using std::ifstream;

#include <vector>
using std::vector, std::string;

#include <string>
using std::string;

void insertionSort(vector<string>& lines) {
    for (size_t i = 1; i < lines.size(); ++i) {
        string key = lines[i];
        size_t j = i;
        // Shift elements of lines[0..i-1] that are greater than key
        while (j > 0 && lines[j - 1] > key) {
            lines[j] = lines[j - 1];
            --j;
        }
        lines[j] = key;
    }
}

int main(int argc, char const* argv[]) {
    vector<string> lines;
    
    if (argc > 1) {
        // If a filename is provided as a command-line argument
        ifstream inputFile(argv[1]);
        if (inputFile.is_open()) {
            string line;
            while (std::getline(inputFile, line)) {
                lines.push_back(line);
            }
            inputFile.close();
        } else {
            std::cerr << "Could not open the file." << std::endl;
            return 1;
        }
    } else {
        // Read lines from standard input (cin)
        string line;
        while (getline(cin, line)) {
            lines.push_back(line);
        }
    }

    // Sort the lines using insertion sort
    insertionSort(lines);

    // Print the sorted lines to standard output (cout)
    for (const auto& line : lines) {
        cout << line << endl;
    }

    return 0;
}