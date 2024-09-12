#include <iostream>
using std::cout, std::endl, std::cin;


int main(int argc, char* argv[]) {
    // Condition to check for 2 numbers and print the error
    if (argc < 3) {
        printf("prod requires 2 arguments\n");
        // cerr << "prod requires 2 arguments" << endl;
        return 1;
    }
    // making floats work for decimal numbers
    float a = atof(argv[1]);
    float b = atof(argv[2]);
    float product = a * b;

    // Final display
    cout << a << " * " << b << " = " << product << endl;
    return 0;
}