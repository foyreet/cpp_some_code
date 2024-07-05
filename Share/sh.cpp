//
// Created by Григорий Ердяков on 03.07.2024.
//


#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

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

    int getPrice() const {
        return price;
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

    bool buyCar(int id, Car& boughtCar) {
        auto it = sellingCars.find(id);
        if (it != sellingCars.end()) {
            boughtCar = it->second;
            sellingCars.erase(it);
            return true;
        } else {
            return false;
        }
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

class Bank{
private:
    int money;
    int account;
public:
    Bank() {
        account = 0;
    }
    Bank(int money, int account) {
        this->money = money;
        this->account = account;
    }

    void putMoney(int money) {
        account += money;
    }

    void takeMoney(int money) {
        account -= money;
    }

    void showAccount() {
        cout << "Account: "<< account << endl;
    }

    int getAccount() const {
        return account;
    }

};
int main() {
    Person person("Mikhail", 23, 100000);

    Store store;
    Car boughtCar;
    Car car_1("BMW", 90000, 2020, "black");
    Car car_2("Mercedes", 100000, 2021, "red");

    store.addCar(car_1);
    store.addCar(car_2);

    Bank bank;
    bank.putMoney(20000);
    bank.takeMoney(1000);
    bank.showAccount();

    int carPrice = car_1.getPrice();
    int accountBalance = bank.getAccount();

    int id = 1;
    if (store.buyCar(id, boughtCar)) {
        cout << "Success purchase car: " << boughtCar.infoAboutCar() << endl;
    } else {
        cout << "Failed purchase car: " << id << endl;
    }

    if (carPrice <= accountBalance) {
        cout << "You can buy a car" << endl;
    } else {
        cout << "You can't buy a car" << endl;
    }
    if (accountBalance - carPrice > 0) {
        cout << "Your Account: " << accountBalance - carPrice << endl;
    } else {
        cout << "Take out a loan: " << abs(accountBalance - carPrice) << endl;
    }
    cout << "Update list of cars: " << endl;
    store.showCars();

}
