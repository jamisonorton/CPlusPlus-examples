#include <iostream>
using std::cout;
using std::endl;

int main(int argc, char* argv[]) {
    int start = atoi(argv[1]);
    int end = atoi(argv[2]);
    int divisor = atoi(argv[3]);

//why does it work when I use start and end but not argv[1] and argv[2]
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

// /*  If you subtract from start the modulo of the divisor then add the divisor 
//     for incrementing up it will give you the correct starting value and now
//     you only have to modulo for the first given number 
//     i.e going 3 to 16 with divisor 2 We start at 3 when we subtract (3%2) you get 2
//     then add the divisor (2) which starts you at 4 which is divisible by 
//     the divisor */
//     if (start < end) {
//         start = start - (start % divisor) + divisor;
//         for (int i = start; i <= end; i += divisor)
//         cout << i << endl;
//     }
// /*  If you subtract from start the modulo of the divisor for incrementing 
//     down it will give you the correct starting value and now
//     you only have to modulo for the first given number
//     i.e going 15 to 3 with divisor 2 We start at 15 and subtract 15%2 (1) 
//     starting you at 14 which is divisible by the divisor */
//     else {
//         start = start - (start % divisor);
//         for (int i = start; i >= end; i -= divisor)
//         cout << i << endl;
//     }