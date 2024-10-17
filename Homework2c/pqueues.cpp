#include <iostream>
using std::cout, std::cin, std::cerr, std::getline, std::endl, std::stoi;

#include <string>
using std::string;

#include <queue>
using std::priority_queue;

#include "input.h"

class Person {
public:
    string name;
    int priority;

    Person(string n, int p) : name(n), priority(p) {}

    bool operator<(const Person& other) const {
        return priority < other.priority;
    }
};

int main(int argc, char const* argv[]) {
    string action, name, inputPriority;
    int priority;
    priority_queue<Person> queue;

    while (input("What do you want to do? ", action)) {
        if (action == "add") {
            input("Name: ", name);
            input("Priority ", inputPriority);
            priority = stoi(inputPriority);
            queue.push(Person(name, priority));
        }
        else if (action == "take") {
            if (queue.empty()) {
                cout << "There are no more people in line" << endl;
            } else {
                Person next = queue.top();
                cout << (next.priority < 10 ? "0" : "") << next.priority << " - " << next.name << endl;
                queue.pop();
            }
        }
        else {
            cerr << action << " isn't a valid operation" << endl;
        }

    }

    return 0;
}
