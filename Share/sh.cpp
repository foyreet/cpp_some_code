//
// Created by Григорий Ердяков on 03.07.2024.
//


#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Car {
private:
    string brand;
    int price;
    int year;
    string color;

public:
    Car() {

    }
    Car(string brand, int price, int year, string color) {
        this->brand = brand;
        this->price = price;
        this->year = year;
        this->color = color;
    }

    string infoAboutCar() {
        string info = "brand: " + brand + " year: " + to_string(year) + " color: " + color + " price: " + to_string(price);
        return info;
    }
};

// 12 -> car@123
// 4  -> car@54

class Store {
private:
    int index;
    unordered_map<int, Car> sellingCars;

public:
    Store() {
        index = 1;
    }

    void addCar(Car car) {
        sellingCars.insert(make_pair(index, car));
        index++;
    }

    void showCars() {
        for (auto& car : sellingCars) {
            cout << "id: " << car.first << " info about car: " << car.second.infoAboutCar() << endl;
        }
    }

    Car buyCar(int id) {

    }
};

class Person {
private:
    string name;
    int age;
    int money;
    vector<string> black_list;
    Car car;

    bool checkPerson(string person_name) {
        for (string bannedPerson : black_list) {
            if (person_name == bannedPerson) {
                return false;
            }
        }

        return true;
    }

public:
    Person(string name, int age, int money) {
        this->name = name;
        this->age = age;
        this->money = money;
    }

    void addNegativePerson(string person_name) {
        black_list.push_back(person_name);
    }

    void sayHello(string person_name) {
        if (!checkPerson(person_name)) {
            cout << person_name << " не здоровайся со мной больше" << endl;
            return;
        }

        cout << "Привет, " <<  person_name << " меня зовут " << name << endl;
    }

    void setCar(Car car) {
        this->car = car;
    }
};


int main() {
    Person person("Mikhail", 23, 100000);

    Store car_store;
    Car car_1("BMW", 90000, 2020, "black");
    Car car_2("Mercedes", 100000, 2021, "red");

    //

    car_store.addCar(car_1);
    car_store.addCar(car_2);

    car_store.showCars();

    Car car = car_store.buyCar(2);
    person.setCar(car);

}