#include <iostream>
using std::cout, std::cin, std::cerr, std::getline, std::endl, std::stoi;

#include <string>
using std::string;

#include <fstream>
using std::ifstream, std::ofstream;

#include <sstream>
using std::stringstream;

int countWords (string str) {
    int c = 0;

    stringstream ss(str);
    string word;
    while (ss >> word) {
        c++;
    }
    return c;
}

int main (int argc, char *argv[]) {
    ifstream infile(argv[1]);
    if (!infile.is_open()) {
        cerr << "unable to open file" << argv[1] << endl;
        exit(2);
    }    
    else {
        string line;
        string longestLine;
        int maxWordCount = 0;
        while (getline(infile, line)) {
            if (maxWordCount < countWords(line)) {
                maxWordCount = countWords(line);
                longestLine = line;
            }
        }
        cout << longestLine << endl;
        
        infile.close();
    }

    return 0;
}