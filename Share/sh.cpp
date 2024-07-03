//
// Created by Григорий Ердяков on 03.07.2024.
//


#include <iostream>
#include <vector>

using namespace std;

class People {
private:
    string name;
    int age;
    int salary;
    vector<string> black_list;

    bool checkPerson(string person_name) {
        for (string bannedPerson : black_list) {
            if (person_name == bannedPerson) {
                return false;
            }
        }

        return true;
    }

public:
    People(string name, int age, int salary) {
        this->name = name;
        this->age = age;
        this->salary = salary;
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
};

int main() {
    People person_1("Mikhail", 23, 100);
    person_1.addNegativePerson("Bob");
    person_1.addNegativePerson("Steve");

    person_1.sayHello("Bob");
    person_1.sayHello("Adam");

}