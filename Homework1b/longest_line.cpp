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
        int c = 0;
        while (getline(infile, line)) {
            c++;
            cout << countWords(line) << endl;
        }
        infile.close();
    }

    return 0;
}