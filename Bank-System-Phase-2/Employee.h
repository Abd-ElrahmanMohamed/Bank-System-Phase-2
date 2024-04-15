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
            if (client->getID() == id) {
                return client;
            }
        }
        return nullptr;
    }

    void listClients() {
        cout << "Clients:\n";
<<<<<<< HEAD
        for (Client* client : clients) {
            cout << " ID : " << client->getID() << endl;
            cout << " Name : " << client->getName() << endl;
            cout << " Balance : " << client->getBalance() << "$" << endl;
=======
        for (auto& Client : clients) {
            cout << " ID : " << Client.getID() << endl;
            cout << " Name : " << Client.getName() << endl;
            cout << " Balance : " << Client.getBalance() << "$" << endl;
            cout << endl;
>>>>>>> dddd25435d631e3bda553f0f38e226c6f4329b8d
        }
    }

    void editClient(int id, string name, string password, double balance) {
        Client* client = searchClient(id);
        if (client) {
            client->setName(name);
            client->setPassword(password);
            client->setBalance(balance);
                cout << " Client information updated successfully." << endl;
            }
            else{
                cout << " Client not found." << endl;

        }
    }
};
