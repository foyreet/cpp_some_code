#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Animal {
public:
    Animal(string name, int age) : name(name), age(age) {}

    void infoAboutAnimal() {
        cout << "Name:" << name << " Age:" << age << endl;
    }

    void setName(string name) {
        this->name = name;
    }

    virtual void voice() const = 0; // чисто виртуальная функция
// protected здесь нужен для доступа к членам класса в производных классах
protected:
    string name;
    int age;
};

class Pets: public Animal{
public:
    Pets(string name, int age) : Animal(name, age) {}

    void Voice() const override {
       cout << "I'm a pet" << endl;
    }
};

class Wild: public Animal{
public:
    Wild(string name, int age) : Animal(name, age) {}

    void Voice() const override {
       cout << "I'm a wild animal" << endl;
    }
};

class Dog: public Pets {
public:
    Dog(string name, int age) : Pets(name, age) {}

    // деструктор выполнится перед удалением объекта
    ~Dog()  {
        cout << "Объект Dog удалён" << endl;
    }

    void voice() const override {
        cout << "Dog: " << "Gav, gav" << endl;
    }
};

class Cat: public Pets {
public:
    Cat(string name, int age) : Pets(name, age) {}

    void voice() const override {
       cout << "Cat: " << "Meow, Meow" << endl;
    }
};

class Wolf: public Wild{
public:
    Wolf(string name, int age) : Wild(name, age) {}

    void voice() const override { // signature
       cout << "Wolf: " << "Wou, wou" << endl;
    }
};



int main() {
    Dog dog("Bobik", 5);
    Cat cat("Musya", 4);
    Wolf wolf("Tren", 6);

    animals.push_back(new Dog("Bobik", 5));
    animals.push_back(new Cat("Musya", 4));
    animals.push_back(new Wolf("Tren", 6));

    for (const auto& animal : animals) {
        animal->voice();
        cout << "Address: " << &animal << endl;
    }

    // Освобождение памяти
    for (auto* animal : animals) {
        delete animal;
    }

    int* a = new int(12);

    delete a;
}
