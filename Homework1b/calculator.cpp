#include <iostream>
using std::cout, std::cin, std::getline, std::endl, std::stod;

#include <string>
using std::string;

int main() {
    string op;
    string left, right = "";
    string add = "add";
    string subtract = "subtract";
    string multiply = "multiply";
    string divide = "divide";
    string mod = "mod";

    cout << "operation: ";
    getline(cin, op);

    while (op != "") {
        if (op != "add" && op != "subtract" && op != "multiply" && op != "divide" && op != "mod") {
            cout << op << " isn't a valid operation" << endl;
            cout << "operation: ";
            getline(cin, op);
        }

        if (op == "add") {
            cout << "left operand: ";
            getline(cin, left);
            cout << "right operand: ";
            getline(cin, right);
            double num1 = stod(left);
            double num2 = stod(right);
            cout << num1 + num2 << endl;
            cout << "operation: ";
            getline(cin, op);
        }

        if (op == "subtract") {
            cout << "left operand: ";
            getline(cin, left);
            cout << "right operand: ";
            getline(cin, right);
            double num1 = stod(left);
            double num2 = stod(right);
            cout << num1 - num2 << endl;
            cout << "operation: ";
            getline(cin, op);
        }

        if (op == "multiply") {
            cout << "left operand: ";
            getline(cin, left);
            cout << "right operand: ";
            getline(cin, right);
            double num1 = stod(left);
            double num2 = stod(right);
            cout << num1 * num2 << endl;
            cout << "operation: ";
            getline(cin, op);
        }

        if (op == "divide") {
            cout << "left operand: ";
            getline(cin, left);
            cout << "right operand: ";
            getline(cin, right);
            double num1 = stod(left);
            double num2 = stod(right);
            cout << num1 / num2 << endl;
            cout << "operation: ";
            getline(cin, op);
        }

        if (op == "mod") {
            cout << "left operand: ";
            getline(cin, left);
            cout << "right operand: ";
            getline(cin, right);
            int num1 = stoi(left);
            int num2 = stoi(right);
            cout << num1 % num2 << endl;
            cout << "operation: ";
            getline(cin, op);
        }
    }

    if (op == "") {
        return 0;
    }
    return 0;
}