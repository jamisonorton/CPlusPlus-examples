//  :)
#include <iostream>
using std::cout, std::endl, std::cin, std::cerr;

int main(int argc, char *argv[]) {
    if (argc < 3) {
        std::cerr << "Please give me 2 arguments" << endl;
        return 1;
    }
    else if (argc >= 3) {
        std::cerr << "You gave too many arguments" << endl;
        return 1;
    }
    else {
        int a = atoi(argv[1]);
        int b = atoi(argv[2]);
        int product = a * b;

        cout << a << " * " << b << product << endl;
    }
}