#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::getline;
using std::string;
using std::endl;

int main() {
    string op;
    string left = "";
    string right = "";
    string add = "add";
    string subtract = "subtract";
    string multiply = "multiply";
    string divide = "divide";
    string mod = "mod";

    // int num1 = stoi(left);
    // int num2 = stoi(right);

    cout << "operation: ";
    getline(cin, op);

    if (op != "add" && op != "subtract" && op != "multiply" && op != "divide" && op != "mod") {
        cout << op << " isn't a valid operation" << endl;
    }

    if (op == "add") {
        cout << "left operand: ";
        getline(cin, left);
        cout << "right operand: ";
        getline(cin, right);
        int num1 = stoi(left);
        int num2 = stoi(right);
        cout << num1 + num2 << endl;
    }

    if (op == "subtract") {
        cout << "left operand: ";
        getline(cin, left);
        cout << "right operand: ";
        getline(cin, right);
        int num1 = stoi(left);
        int num2 = stoi(right);
        cout << num1 - num2 << endl;
    }

    if (op == "multiply") {
        cout << "left operand: ";
        getline(cin, left);
        cout << "right operand: ";
        getline(cin, right);
        int num1 = stoi(left);
        int num2 = stoi(right);
        cout << num1 * num2 << endl;
    }

    if (op == "divide") {
        cout << "left operand: ";
        getline(cin, left);
        cout << "right operand: ";
        getline(cin, right);
        int num1 = stoi(left);
        int num2 = stoi(right);
        cout << num1 / num2 << endl;
    }

    if (op == "mod") {
        cout << "left operand: ";
        getline(cin, left);
        cout << "right operand: ";
        getline(cin, right);
        int num1 = stoi(left);
        int num2 = stoi(right);
        cout << num1 % num2 << endl;
    }

    if (op == "") {
        return 1;
    }

    return 0;
}