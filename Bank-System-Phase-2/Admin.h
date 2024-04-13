#pragma once
#include <iostream>
#include <string>
#include <vector>
#include"Employee.h"
#include "Validation.h"
using namespace std;
class Admin : public Employee {
private:
   vector <Employee> employees;
public:
    //Constructors:
    Admin(int id, string name, string password, double salary) : Employee(id, name, password, salary) {}
    //methods
  
    void addEmployee(Employee& employee) {
        employees.push_back (employee);
    }

    Employee* SearchEmployee(int id) {
        for (auto& employee : employees) {
            if (employee.getID() == id) {
                return& employee;
            }
        }
        return nullptr;
    }

    void listEmployee() {
        cout << "Employee:\n";
        for (auto& employee : employees) {
            cout << "ID: " << employee.getID() << ", Name: " << employee.getName() << ", Balance: " << employee.getSalary() << endl;
        }
    }

    void editEmployee(int id, string name, string password, double salary) {
        for (auto& employee : employees) {
            if (employee.getID() == id) {
                employee.setName(name);
                employee.setPassword(password);
                employee.setSalary(salary);
                cout << "Employee information updated successfully.\n";
            }
            else
            {
                cout << "Employee not found\n";
            }
        }
    }


};