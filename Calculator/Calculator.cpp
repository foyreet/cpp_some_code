#include <iostream>
#include <string>
#include "Calculator.h"
using namespace std;
class Calculator {
private:
   int value;

public:
    Calculator::Calculator(int val) : value(val) {}

    Calculator Calculator::operator+(const Calculator& other) const {
        return Calculator(value + other.value);
    }
    Calculator Calculator::operator-(const Calculator& other) const {
        return Calculator(value - other.value);
    }
    Calculator Calculator::operator*(const Calculator& other) const {
        return Calculator(value * other.value);
    }
    Calculator Calculator::operator/(const Calculator& other) const {
        return Calculator(value / other.value);
    }
    Calculator Calculator::operator%(const Calculator& other) const {
        return Calculator(value % other.value);
    }
    // Операции сравнения
    bool Calculator::operator==(const Calculator& other) const {
        return value == other.value;
    }
    bool Calculator::operator!=(const Calculator& other) const {
        return value != other.value;
    }
    bool Calculator::operator<(const Calculator& other) const {
        return value < other.value;
    }
    bool Calculator::operator<=(const Calculator& other) const {
        return value <= other.value;
    }
    bool Calculator::operator>(const Calculator& other) const {
        return value > other.value;
    }
    bool Calculator::operator>=(const Calculator& other) const {
        return value >= other.value;
    }

    int Calculator::getValue() const {
        return value;
    }

    friend ostream& operator<<(ostream& os, const Calculator& calc) {
        os << calc.value;
        return os;
    }

    friend istream& operator>>(istream& is, Calculator& calc) {
        is >> calc.value;
        return is;
    }
};

int main() {
    Calculator calc1, calc2;
    string operation;
    cin >> calc1 >> calc2;
    cin >> operation;
    if (operation == '+') {
        cout << calc1 + calc2;
    } else if (operation == '-') {
        cout << calc1 - calc2;
    } else if (operation == '*') {
        cout << calc1 * calc2;
    } else if (operation == '/') {
        cout << calc1 / calc2;
    } else if (operation == '%') {
        cout << calc1 % calc2;
    }
    if (operation == "==") {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}