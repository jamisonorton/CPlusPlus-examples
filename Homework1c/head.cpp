#include <iostream>
using std::cout, std::cin, std::cerr, std::getline, std::endl, std::stoi;

#include <string>
using std::string;

#include <fstream>
using std::ifstream, std::istream;

void printLines(istream& input, int n) {
    string line;
    for (int i=0; i < n && getline(input, line); ++i) {
        cout << line << endl;
    }
}

int main(int argc, char const* argv[]) {
    int n = 10;
    string filename;

    if (argc == 1) {
        //program should read 10 lines from standard output
        printLines(cin, n);
    }
    else if (argc == 2) {
        //program should read the default 10 lines from the input file
        string arg1 = argv[1];
        if (arg1[0] == '-') {
            n = stoi(arg1.substr(1));  // Remove the '-' and convert to integer
            printLines(cin, n);
        } 
        else {
            filename = argv[1];
            ifstream file(filename);
            if (!file) {
                cerr << "ERROR: can't open " << argv[1] << endl;
            }
            printLines(file, n);
        }
    }
    else if (argc == 3) {
        //program should read the file and use n lines
        string arg1 = argv[1];
        if (arg1[0] == '-') {
            n = stoi(arg1.substr(1));  // Remove the '-' and convert to integer
            filename = argv[2];
            ifstream file(filename);
            if (!file) {
                cerr << "Error: File '" << filename << "' could not be opened." << endl;
                return 1;
            }
            printLines(file, n);
        }
    }
    else {
        cerr << "Error: Too many arguments!" << endl;
    }

    return 0;
}
