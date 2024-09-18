#include <iostream>
using std::cout, std::cin, std::getline, std::endl, std::stod;

#include <string>
using std::string;

#include <tuple>
using std::tuple, std::get;

enum Operator {ADD, SUBTRACT, MULTIPLY, DIVIDE, MOD, BLANK, INVALID};

tuple <Operator, int, int> userInput () {
    string op;
    Operator operation;
    string left, right = "";
    
    cout << "operation: ";
    getline(cin, op);
    if (op == "") {
        return tuple <Operator, int, int> (BLANK, 0,0);
    }

    cout << "left operand: ";
    getline(cin, left);
    cout << "right operand: ";
    getline(cin, right);
    double num1 = stod(left);
    double num2 = stod(right);

    if (op == "add") operation = ADD;
    else if (op == "subtract") operation = SUBTRACT;
    else if (op == "multiply") operation = MULTIPLY;
    else if (op == "divide") operation = DIVIDE;
    else if (op == "mod") operation = MOD;
    else operation = INVALID;

    return tuple <Operator, int, int> (operation, num1, num2);
}

int main() {
    string op;
    string left, right = "";

    tuple <Operator, int, int> input = userInput();

    while (get<0>(input) != BLANK) {
        switch (get<0>(input)) {

        case ADD:
            cout << get<1>(input) + get<2>(input) << endl;
            break;
        case SUBTRACT:
            cout << get<1>(input) - get<2>(input) << endl;
            break;
        case MULTIPLY:
            cout << get<1>(input) * get<2>(input) << endl;
            break;
        case DIVIDE:
            cout << get<1>(input) / get<2>(input) << endl;
            break;
        case MOD:
            cout << get<1>(input) % get<2>(input) << endl;
            break;

        default:
            cout << INVALID << "ins't a valid operation." << endl;
            break;
        }
        input = userInput();
    }
    return 0;
}