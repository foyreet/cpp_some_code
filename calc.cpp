#include <iostream>
using namespace std;
// Calculator
int main() {
    char operation;
    double x, y;
    cin >> operation;
    cin >> x >> y;
    if (operation == '+') {
        cout << x + y;
    } else if (operation == '-') {
        cout << x - y;
    } else if (operation == '*') {
        cout << x * y;
    } else if (operation == '/') {
        cout << x / y;
    }
}
