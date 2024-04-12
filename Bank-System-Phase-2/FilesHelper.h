#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include "Parser.h"
using namespace std;
class FilesHelper
{
public:
	//Methods:
    static void saveLast(string fileName, int id) {
        ofstream file(fileName);
        if (file.is_open()) {
            file << id;
            file.close();
        }
        else {
            cout << "Error: Unable to open file " << fileName << " for writing." << endl;
        }
    }

    static int getLast(string fileName) {
        int id = 0;
        ifstream file(fileName);
        if (file.is_open()) {
            file >> id;
            file.close();
        }
        else {
            cout << "Error: Unable to open file " << fileName << " for reading." << endl;
        }
        return id;
    }

    static void saveClient(Client& client) {
        ofstream file("Clients.txt", ios::app);
        if (file.is_open()) {
            file << client.getID() << "#" << client.getName() << "#" << client.getPassword() << "#" << client.getBalance() << endl;
            file.close();
            cout << " Client added successfully.\n";
        }
        else {
            cout << " Unable to open Clients.txt for writing.\n";
        }
    }

    static void saveEmployee(string employeeFile, string lastIdFile, Employee employee) {
        int id = getLast(lastIdFile) + 1;
        saveLast(lastIdFile, id);
        ofstream file("Employee.txt", ios::app);
        if (file.is_open()) {
            file << id << "#" << employee.getName() << "#" << employee.getPassword() << "#" << employee.getSalary() << endl;
            file.close();
            cout << "Employee added successfully." << endl;
        }
        else {
            cout << "Error: Unable to open " << employeeFile << " for writing." << endl;
        }
    }

    static vector<Client> getAllClients() {
        vector<Client> clients;
        ifstream file("Clients.txt");
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                Client client = Parser::parseToClient(line);
                clients.push_back(client);
            }
            file.close();
        }
        else {
            cout << "Unable to open Clients.txt for reading." << endl;
        }
        return clients;
    }

    static vector<Employee> getAllEmployees() {
        vector<Employee> employees;
        ifstream file("Employees.txt");
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                Employee employee = Parser::parseToEmployee(line);
                employees.push_back(employee);
            }
            file.close();
        }
        else {
            cout << "Unable to open Employees.txt for reading." << endl;
        }
        return employees;
    }

    static vector<Employee> getAllAdmins() {
        vector<Employee> admins;
        ifstream file("Admins.txt");
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                Admin admin = Parser::parseToAdmin(line);
                admins.push_back(admin);
            }
            file.close();
        }
        else {
            cout << "Unable to open Admins.txt for reading." << endl;
        }
        return admins;
    }

    static void clearFile(string fileName, string lastIdFile) {
    
    }
};
