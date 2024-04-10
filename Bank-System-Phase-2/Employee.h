#pragma once
#include <iostream>
#include <string>
#include "Person.h"
#include "Client.h"
using namespace std;
class Employee : public Person {
protected:
    //Attributs:
    double salary;
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
};