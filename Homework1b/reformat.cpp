#include <iostream>
using std::cout, std::cin, std::cerr, std::getline, std::endl, std::stod;

#include <string>
using std::string;

#include <fstream>
using std::ifstream, std::ofstream;

int main (int argc, char *argv[]) {
    string fname = "";
    string lname = "";
    int points;
    double factor;
    
    //first arg is input file, 2nd arg is output
    if (argc < 3) {
        cerr << "you need both an input and output file" << endl;
        exit(1);
        }

    ifstream infile(argv[1]);
    if (!infile.is_open()) {
        cerr << "unable to open file" << argv[1] << endl;
        exit(2);
    }

    ofstream outfile(argv[2]);
    if (!outfile.is_open()) {
        cerr << "unable to open file" << argv[2] << endl;
        exit(3);
    }
// read the infile and output it with the correct sequence. Also while loop makes sure that it does every line 1 time until the end of the file
    string line;
    while (infile >> fname >> lname >> points >> factor) {
        outfile << lname << ", " << fname << ": " << points * factor << endl;
    }
    return 0;

    infile.close();
    outfile.close();
}