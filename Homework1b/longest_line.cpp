#include <iostream>
using std::cout, std::cin, std::cerr, std::getline, std::endl, std::stoi;

#include <string>
using std::string;

#include <fstream>
using std::ifstream, std::ofstream;

#include <sstream>
using std::stringstream;

// int countWords (string word) {
//     stringstream word_stream(word);
//     int total = 0;
//     int num;
//     while (word_stream >> num) {
//         total += num;
//     }
//     return total;
// }

// int main (int argc, char *argv[]) {

//     if (argc < 2) {
//         cerr << "you need both an input and output file" << endl;
//         exit(1);
//         }

//     ifstream infile(argv[1]);
//     if (!infile.is_open()) {
//         cerr << "unable to open file" << argv[1] << endl;
//         exit(2);
//     }    

//     string line;
//     while (getline(infile, line)) {
//         cout << countWords(line) << endl;
//     }

//     return 0;

//     infile.close();
// }

int main(int argc, char *argv[]) {
    string line;
    ifstream infile(argv[1]);

    while (getline(infile, line)) {
        stringstream stream(line);
        string word;
        int wordCount = 0;

        while (stream >> word) {
            ++wordCount;
        }   
    cout << wordCount << endl;
    }

    return 0;
}