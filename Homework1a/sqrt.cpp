#include <cstdlib>  // atof
#include <iostream>
using std::abs;  
using std::cout;
using std::endl;

const double EPSILON = 0.0001;

int main(int argc, char* argv[]) {
    double n = atof(argv[1]);
    double high = n;
    double low = 0;
    double mid = low + (high - low) / 2;
    
    if (high < 0) {
        printf("Input must be greater than 0\n");
        return 1;
    }
    else {
        while (abs((mid * mid) - n) > EPSILON) {
            mid = low + (high - low) / 2;
            if (mid * mid > n) {
                high = mid;
            }
            else if (mid * mid < n) {
                low = mid;
            }
            cout << mid << " (" << mid * mid << ")" << endl;
        }
    }
    return 0;
}