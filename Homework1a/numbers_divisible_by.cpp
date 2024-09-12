#include <iostream>
using std::cout;
using std::endl;

int main(int argc, char* argv[]) {
    int start = atoi(argv[1]);
    int end = atoi(argv[2]);
    int divisor = atoi(argv[3]);

//why does it work when I use start and end but not argv[1] and argv[2]
//if statement for when the start number is smaller than the end number
    if (start < end) {
        for (int i = start; i <= end; i++){
            if (i % divisor == 0) {
                cout << i << endl;
            }
        }
    }
    else {
        for (int i = start; i >= end; i--) {
            if (i % divisor == 0) {
                cout << i << endl;
            }
        }
    }
    return 0;
}