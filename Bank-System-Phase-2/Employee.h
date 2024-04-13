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
    vector <Client> clients;
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

    void addClient(Client& Client) {
        clients.push_back (Client);
    }

    Client* SearchClient(int id) {
        for (auto& Client : clients) {
            if (Client.getID() == id) {
                return& Client;
            }
        }
        return nullptr;
    }

    void listClients() {
        cout << "Clients:\n";
        for (auto& Client : clients) {
            cout << " ID : " << Client.getID() << endl;
            cout << " Name : " << Client.getName() << endl;
            cout << " Balance : " << Client.getBalance() << "$" << endl;
        }
    }

    void editClient(int id, string name, string password, double balance) {
        for (auto& Client : clients) {
            if (Client.getID() == id) {
                Client.setName(name);
                Client.setPassword(password);
                Client.setBalance(balance);
                cout << " Client information updated successfully." << endl;
            }
            else
                cout << " Client not found." << endl;
            
        }
    }
};