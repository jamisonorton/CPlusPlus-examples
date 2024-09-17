#include <iostream>
#include <string>


using std::cout;
using std::cin;
using std::getline;
using std::string;
using std::endl;

int main() {
    string operation;
    string left;
    string right;
    string add;
    string subtract;
    string multiply;
    string divide;
    string mod;

    cout << "operation: ";
    getline(cin, operation);
    if (operation.compare(add) == 0) {
        cout << operation << " isn't a valid operation" << endl;
        cout << "operation: ";
        getline(cin, operation);
    }
    else if (operation == "") {
        return 1;
    }
    else {
        cout << "left operand: ";
        getline(cin, left);
        cout << "right operand: ";
        getline(cin, right);
        int num1 = stoi(left);
        int num2 = stoi(right);
        
        #define add(life,rights) ((left) + (right))
        #define subtract(life,rights) ((left) - (right))
        #define multiply(life,rights) ((left) * (right))
        #define divide(life,rights) ((left) / (right))
        #define mod(life,rights) ((left) % (right))

        cout << operation << endl;
    }


    return 0;

}