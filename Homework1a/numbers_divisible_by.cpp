#include <iostream>
using std::cout;
using std::endl;

int main(int argc, char* argv[]) {
    int start = atoi(argv[1]);
    int end = atoi(argv[2]);
    int divisor = atoi(argv[3]);

    if (argv[1] < argv[2]) {
        for (int i=start/divisor;i<=end;i=i+divisor){
            cout << i << endl;
        }
    }
    
    // else if (argv[1] > argv[2]) {
    //     for (int i=start;i>=end;i=i-divisor) {
    //         cout << i << endl;
    //     }
    // }
    // cout << start << endl << start/2 << endl << end << endl;
    // return 0;
    // Condition to check for 3 numbers and print the error
    // if (argc < 4) {
    //     printf("divisible requires 3 arguments\n");
    //     // cerr << "prod requires 3 arguments" << endl;
    //     return 1;
    // }
    // else if (argv[1] < argv[2]) {
    //     cout << "Find the divisors" << endl;
    // }
    // // making floats work for decimal numbers
    // int a = atof(argv[1]);
    // int b = atof(argv[2]);
    // int c = atof(argv[3]);
    // int divisible = a / b;
    // // Final display
    // cout << divisible << endl;
    // return 0;
}