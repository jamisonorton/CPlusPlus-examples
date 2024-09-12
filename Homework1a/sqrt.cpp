#include <cstdlib>  // atof
#include <iostream>
using std::abs;  
using std::cout;
using std::endl;

const double EPSILON = 0.0001;

int main(int argc, char* argv[]) {
    int start = 0;
    double val = atof(argv[1]);

    //upper bound
    int firstUpper = val * val;
    if (firstUpper > val) {
        int secondUpper = (val - 1) * (val - 1);
        cout << secondUpper << endl;
    }
}
