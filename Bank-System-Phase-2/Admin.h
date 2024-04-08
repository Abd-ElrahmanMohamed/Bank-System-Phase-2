#pragma once
#include <iostream>
#include <string>
#include"Employee.h"
#include "Validation.h"
using namespace std;
class Admin : public Employee {
public:
    //Constructors:
    Admin(int id, string name, string password, double salary) : Employee(id, name, password, salary) {
    }
};