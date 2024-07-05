#include <iostream>
#include <map>
using namespace std;

class Person {
private:
    string name;
    int age;
public:
    Person(string name, int age) {
        this->name = name;
        this->age = age;
    }

    string InfoAboutPerson() {
        string info = "name: " + name + "age: " + to_string(age);
        return info;
    }

};

class Queue {
private:
    int index;
    map<int, Person> queue_store;
public:
    Queue() {
        index = 1;
    }

    void addPerson(Person person) {
        queue_store.insert(make_pair(index, person));
        index++;
    }

    void showQueue() {
        for (auto& person : queue_store) {
            cout << "id: " << person.first << " info about person: " << person.second.InfoAboutPerson() << endl;
        }
    }

    void deletePerson() {
        queue_store.erase(queue_store.size());
    }

};

int main() {
    Person person1("Grisha ", 19);
    Person person2("Lisa ", 11);
    Person person3("Misha ", 23);
    Queue queue;
    queue.addPerson(person1);
    queue.addPerson(person2);
    queue.addPerson(person3);
    queue.deletePerson();
    queue.showQueue();

}