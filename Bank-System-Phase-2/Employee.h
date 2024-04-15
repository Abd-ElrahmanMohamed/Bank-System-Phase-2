#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Person.h"
#include "Client.h"
#include "Validation.h"

using namespace std;
class Employee : public Person {
protected:
    //Attributs:
    double salary;
    vector <Client*> clients;

public:
    //Consttructors:
    Employee(int id, string name, string password, double salary) : Person(id, name, password), salary(0) {
        setSalary(salary);
    }
    //Setters:
    void setSalary(double salary) {
        if (Validation::ValidateSalary(salary))
            this->salary = salary;
        else
            cout << " Error : Salary must be at least 5000." << endl;
    }
    //Getters:
    double getSalary() {
        return salary;
    }
    //Methods:
    void display() {
        Person::display();
        cout << " Salary : " << getSalary() << "$" << endl;
    }

    void addClient(Client& client) {
        clients.push_back(&client);
    }

    Client* searchClient(int id) {
        for (Client* client : clients) {
            if (client->getID() == id)
                return client;
        }
        return nullptr;
    }

    void listClients() {
        cout << " Clients " << name << " : " << endl;
        for (Client* client : clients) {
            client->display();
        }
    }

    void editClient(int id, string name, string password, double balance) {
        Client* client = searchClient(id);
        if (client) {
            client->setName(name);
            client->setPassword(password);
            client->setBalance(balance);
            cout << " Client details updated successfully." << endl;
        }
        else {
            cout << " Client not found. " << endl;
        }
    }
};
