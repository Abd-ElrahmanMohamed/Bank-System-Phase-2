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
    
    //Methods:
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
            cout << " ID : " << employee.getID() << endl;
            cout << " Name : " << employee.getName() << endl;
            cout << " Balance : " << employee.getSalary() << "$" << endl;
        }
    }

    void editEmployee(int id, string name, string password, double salary) {
        for (auto& Employee : employees) {
            if (Employee.getID() == id) {
                Employee.setName(name);
                Employee.setPassword(password);
                Employee.setSalary(salary);
                cout << " Employee information updated successfully." << endl;
            }
            else
            {
                cout << " Employee not found." << endl;
            }
        }
    }


};