#include <iostream>
using std::cout, std::cin, std::cerr, std::getline, std::endl, std::stoi;

#include <string>
using std::string;

#include <queue>
using std::priority_queue;

#include "input.h"

struct Person {
    string name;
    int priority;
};

int main(int argc, char const* argv[]) {
    string action;
    string name;
    string inputPriority;
    int priority;

    priority_queue<Person> names;

    while (input("What do you want to do? ", action)) {
        if (action == "add") {
            input("Name: ", name);
            input("Priority ", inputPriority) || (priority = stoi(inputPriority));
            names.push({name, priority});
        }

        else if (action == "take") {
            if (names.empty()) {
                cout << "There are no more people in line" << endl;
            }
            else {
                Person next = names.top();
                cout << (next.priority < 10 ? "0" : "") << next.priority << "-" << next.name << endl;
                names.pop();
            }
        }
        else {
            cerr << action << " isn't a valid operation" << endl;
        }

    }

    return 0;
}
