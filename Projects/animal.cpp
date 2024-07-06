#include <iostream>
#include <string>
using namespace std;

class Animal {
public:
    Animal(string name, int age) : name(name), age(age) {}

    void infoAboutAnimal() {
        cout << "Name:" << name << " Age:" << age << endl;
    }

    virtual void Voice() const {
        cout << "voice";
    }
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

    void Voice() const override {
        cout << "Dog: " << "Gav, gav" << endl;
    }
};

class Cat: public Pets {
public:
    Cat(string name, int age) : Pets(name, age) {}

    void Voice() const override {
       cout << "Cat: " << "Mya, Mya" << endl;
    }
};

class Wolf: public Wild{
public:
    Wolf(string name, int age) : Wild(name, age) {}

    void Voice() const override {
       cout << "Wolf: " << "Wou, wou" << endl;
    }
};



int main() {
    Dog dog("Bobik", 5);
    Cat cat("Musya", 4);
    Wolf wolf("Tren", 6);
    dog.infoAboutAnimal();
    dog.Voice();
    dog.Pets::Voice();
    cat.infoAboutAnimal();
    cat.Voice();
    cat.Pets::Voice();
    wolf.infoAboutAnimal();
    wolf.Voice();
    wolf.Wild::Voice();
}
