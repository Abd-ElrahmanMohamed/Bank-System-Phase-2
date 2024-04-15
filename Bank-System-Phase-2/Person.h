#pragma once
#include <iostream>
#include <string>
#include "Validation.h"
using namespace std;
class Person {
protected:
    //Attributes:
    int id;
    string name, password;

public:
    //Construtors:
    Person(int id, string name, string password) {
        setID(id);
        setPassword(password);
        setName(name);
    }
    //Setters:
    void setID(int id) {
        this->id = id;
    }
    void setName(string name) {
        if (Validation::ValidateName(name))
            this->name = name;
        else
            cout << " Error : Invalid name format." << endl;
    }
    void setPassword(string password) {
        if (Validation::ValidatePassword(password))
            this->password = password;
        else
            cout << " Error : Invalid password format." << endl;
    }
    //Getters:
    int getID() {
        return id;
    }
    string getName() {
        return name;
    }
    string getPassword() {
        return password;
    }
    //Methods:
    virtual void display() {
        cout << " ID : " << getID() << endl;
        cout << " Name : " << getName() << endl;
        cout << " Password : " << getPassword() << endl;
    }
};