#include <iostream>
using namespace std;

class Stack {
private:
    int index;
    int stackSize;
    int* a;

    void initialize(int initialSize) {
        a = new int[initialSize];
        stackSize = initialSize;
        index = 0;
    }
public:

    Stack() {
        initialize(8);
    }
    Stack(int initialSize) {
        initialize(initialSize);
    }
    ~Stack() {
        delete[] a;
    }

    void push(int number) {
        if (index == stackSize) {
            int* temp = new int[stackSize * 2];
            for (int i = 0; i < stackSize; i++) {
                temp[i] = a[i];
            }
            delete[] a;
            a = temp;
            stackSize *= 2;
        }

        a[index] = number;
        index++;
    }

    int pop() {
        if (index == 0) {
            cout << "Stack is empty" << endl;
            return 0;
        }

        index--;
        return a[index];
    }

    int peek() {
        if (index == 0) {
            cout << "Stack is empty" << endl;
            return 0;
        }

        return a[index - 1];
    }
};

int main() {
    Stack stack(20);

    stack.push(12);
    stack.push(4);

    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;

    cout << "Finish" << endl;
}