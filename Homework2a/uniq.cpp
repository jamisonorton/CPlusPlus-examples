#include <iostream>
using std::cin, std::cerr, std::cout, std::endl, std::istream, std::getline;

#include <string>
using std::string;

#include <fstream>
using std::ifstream;

#include <unordered_set>
using std::unordered_set;

int main(int argc, char const* argv[]) {
    unordered_set<string> unique_lines;
    istream* input = &cin;
    ifstream file;
    

    if (argc > 1) {
        file.open(argv[1]);
        if (!file) {
            cerr << "Error: Could not open file " << argv[1] << std::endl;
            return 1;
        }
        input = &file;
    }
    string line;
    while (getline(*input, line)) {
        if (unique_lines.find(line) == unique_lines.end()) {
            cout << line << endl;
            unique_lines.insert(line);
        }
    }
    file.close();

    return 0;
}