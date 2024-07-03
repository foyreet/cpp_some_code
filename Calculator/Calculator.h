
#ifndef CALCULATOR_H
#define CALCULATOR_H
class Calculator {
private:
    int value;
public:
    Calculator(int val = 0);

    Calculator operator+(const Calculator& other) const;
    Calculator operator-(const Calculator& other) const;
    Calculator operator*(const Calculator& other) const;
    Calculator operator/(const Calculator& other) const;
    Calculator operator%(const Calculator& other) const;

    bool operator==(const Calculator& other) const;
    bool operator!=(const Calculator& other) const;
    bool operator<(const Calculator& other) const;
    bool operator<=(const Calculator& other) const;
    bool operator>(const Calculator& other) const;
    bool operator>=(const Calculator& other) const;

    int getValue() const;
};

#endif
