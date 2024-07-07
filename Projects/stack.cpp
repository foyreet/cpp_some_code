#include <iostream>
using namespace std;

class Stack {
private:
    int index;
    static int size; // общий для всех экземпляров класса
    int arr[10];
public:

    Stack() {
        int index = 0;
    }

    Stack(int initArr[size]) {
        for (int i = 0; i < size; i++) {
            arr[i] = 0;
        }
    }

    void inputArr() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << endl;
        }
    }

    void push(int number) {
        arr[index] = number;
        index++;
    }

    void pop() {
        for (int i = index - 1; i < size - 1; i++) {
            arr[i] = arr[i+1];
        }
    }
};

int Stack::size = 10;

int main() {
    int initArr[10];
    Stack stack(initArr);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.pop();
    stack.inputArr();

}