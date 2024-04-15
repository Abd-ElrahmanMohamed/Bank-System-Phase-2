#pragma once
#include <iostream>
#include <string>
#include <vector>
#include"Employee.h"
#include "Validation.h"
using namespace std;
class Admin : public Employee {
private:
    //Attributes:
    vector<Employee*> employees;

public:
    //Constructors:
    Admin(int id, string name, string password, double salary) : Employee(id, name, password, salary) {}
    
    //Methods:
    void addEmployee(Employee& employee) {
        employees.push_back(&employee);
    }

    Employee* searchEmployee(int id) {
        for (Employee* employee : employees) {
            if (employee->getID() == id)
                return employee;
        }
        return nullptr;
    }

    void listEmployees() {
        cout << " Employees : " << endl;
        for (Employee* employee : employees) {
            employee->display();
        }
    }

    void editEmplyee(int id, string name, string password, double Salary) {
        Employee* employee = searchEmployee(id);
        if (employee) {
            employee->setName(name);
            employee->setPassword(password);
            employee->setSalary(salary);
            cout << " Employee details updated successfully." << endl;
        }
        else {
            cout << " Client not found. " << endl;
        }
    }
};