#include <iostream>
#include <string>
using namespace std;

class Animal {
public:
    Animal(string name, int age) : name(name), age(age) {}

    void infoAboutAnimal() {
        cout << "Name:" << name << " Age:" << age << endl;
    }
// protected здесь нужен для доступа к членам класса в производных классах
protected:
    string name;
    int age;
};

class Pets: public Animal{
public:
    Pets(string name, int age) : Animal(name, age) {}

    void sayPets() {
        cout << "I'm a pet" << endl;
    }
};

class Wild: public Animal{
public:
    Wild(string name, int age) : Animal(name, age) {}

    void sayWild() {
        cout << "I'm a wild animal" << endl;
    }
};
class Dog: public Pets {
public:
    Dog(string name, int age) : Pets(name, age) {}

    void sayDog() {
        cout << "Dog " << name << " Gav, gav" << endl;
    }
};

class Cat: public Pets {
public:
    Cat(string name, int age) : Pets(name, age) {}

    void sayCat() {
        cout << "Cat " << name << " Mya, Mya" << endl;
    }
};

class Wolf: public Wild{
public:
    Wolf(string name, int age) : Wild(name, age) {}

    void sayWolf() {
        cout << "Wolf " << name << " Wou, wou" << endl;
    }
};



int main() {
    Dog dog("Bobik", 5);
    Cat cat("Musya", 4);
    Wolf wolf("Tren", 6);
    dog.infoAboutAnimal();
    dog.sayDog();
    dog.sayPets();
    cat.infoAboutAnimal();
    cat.sayCat();
    cat.sayPets();
    wolf.infoAboutAnimal();
    wolf.sayWild();
    wolf.sayWolf();
}
