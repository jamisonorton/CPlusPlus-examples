#include <iostream>
using std::cout;
using std::endl;

int main(int argc, char* argv[]) {
    int start = atoi(argv[1]);
    int end = atoi(argv[2]);
    int divisor = atoi(argv[3]);

    if (argv[1] < argv[2]) {
        //work on the first starting number being divisible by the divisor
        for (int i=start*divisor;i<=end;i=i+divisor){
            cout << i << endl;
        }
    }
    // else if (argv[1] > argv[2]) {
    //     for (int i=start;i>=end;i=i-divisor) {
    //         cout << i << endl;
    //     }
    // }
    return 0;
}