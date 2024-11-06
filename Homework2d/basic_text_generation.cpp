#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

// Function to train the model
unordered_map<string, vector<string> > trainModel(istream& in) {
    unordered_map<string, vector<string> > wordMap;
    string prev = "";
    string curr;

    // Read words from the input stream
    while (in >> curr) {
        // Add the current word to the vector associated with the previous word
        wordMap[prev].push_back(curr);
        // Move to the next pair (prev becomes curr)
        prev = curr;
    }

    return wordMap;
}
// Function to generate text
void generateText(unordered_map<string, vector<string> > wordMap, int numWords, string firstWord, ostream& out) {
    srand(time(0));
    for (size_t i = 0; i < numWords; i++) {
        vector<string> bucket = wordMap[firstWord];
        string nextWord = bucket[rand() % bucket.size()];
        out << nextWord << " ";
        firstWord = nextWord;
    }
    out << endl;
}

int main(int argc, char const* argv[]) {
    // Example input for training
    istringstream sampleText("one fish two fish red fish blue fish");
    string filename;
    int numWords;
    string startingWord;

    filename = argv[1];
    ifstream file(filename);
    if (!file) {
        cerr << "ERROR: can't open " << argv[1] << endl;
    }

    numWords = stoi(argv[2]);

    // Train the model
    auto wordMap = trainModel(file);

    // Display the contents of the map to check correctness
    // for (const auto& pair : wordMap) {
    //     cout << pair.first << ": ";
    //     for (const auto& word : pair.second) {
    //         cout << word << " ";
    //     }
    //     cout << endl;
    // }
    generateText(wordMap, numWords, "", cout);
    return 0;
}