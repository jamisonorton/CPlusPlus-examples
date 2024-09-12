#include <iostream>
using std::cout;
using std::endl;

int main(int argc, char* argv[]) {
    int start = atoi(argv[1]);
    cout << start << endl;

    while (start > 1) {
        if (start % 2 == 0) {
            start /= 2;
            cout << start << endl;
        }
        else {
            start = 3 * start + 1;
            cout << start << endl;
        }
    }
    return 0;
}