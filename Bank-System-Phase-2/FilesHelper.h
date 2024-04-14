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
            cerr << "Unable to open file: " << fileName << endl;
        }
    }

    static int getLast(string fileName) {
        int lastId = 0;
        ifstream file(fileName);
        if (file.is_open()) {
            file >> lastId;
            file.close();
        }
        else {
            cerr << "Unable to open file: " << fileName << endl;
        }
        return lastId;
    }

    static void saveClient(Client& client) {
        int id = getLast("ClientLastId.txt") + 1;
        saveLast("ClientLastId.txt", id);
        ofstream file("Clients.txt", ios::app);
        if (file.is_open()) {
            file << client.getID() << "#" << client.getName() << "#" << client.getPassword() << "#" << client.getBalance() << endl;
            file.close();
            cout << " File Clients.txt added successfully." << endl;
        }
        else {
            cout << " Unable to open Clients.txt for writing." << endl;
        }
    }

    static void saveEmployee(string fileName, string lastIdFile, Employee employee) {
        int id = getLast(lastIdFile) + 1;
        saveLast(lastIdFile, id);
        ofstream file(fileName, ios::app);
        if (file.is_open()) {
            file << employee.getID() << "#" << employee.getName() << "#" << employee.getPassword() << "#" << employee.getSalary() << endl;
            file.close();
            cout << " File " << fileName << " added successfully." << endl;
        }
        else {
            cout << " Error: Unable to open " << fileName << " for writing." << endl;
        }
    }

    static void getClients() {
        ifstream file("Clients.txt");
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                Client client = Parser::parseToClient(line);
                cout << "Client Info : " << endl;
                cout << "ID : " << client.getID() << endl;
                cout << "Name : " << client.getName() << endl;
                cout << "Password : " << client.getPassword() << endl;
                cout << "Balance : " << client.getBalance() << "$" << endl;
                cout << "==================================\n" << endl;
            }
            file.close();
        }
        else {
            cout << "Unable to open file: Clients.txt" << endl;
        }
    }

    static void getEmployees() {
        ifstream file("Employee.txt");
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                Employee employee = Parser::parseToEmployee(line);
                cout << "Employee Info : " << endl;
                cout << "ID : " << employee.getID() << endl;
                cout << "Name : " << employee.getName() << endl;
                cout << "Password : " << employee.getPassword() << endl;
                cout << "Balance : " << employee.getSalary() << "$" << endl;
                cout << "==================================\n" << endl;
            }
            file.close();
        }
        else {
            cout << "Unable to open file: Employee.txt" << endl;
        }
    }

    static void getAdmins() {
        ifstream file("Admin.txt");
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                Admin admin = Parser::parseToAdmin(line);
                cout << "Admin Info : " << endl;
                cout << "ID : " << admin.getID() << endl;
                cout << "Name : " << admin.getName() << endl;
                cout << "Password : " << admin.getPassword() << endl;
                cout << "Balance : " << admin.getSalary() << "$" << endl;
                cout << "==================================\n" << endl;
            }
            file.close();
        }
        else {
            cout << "Unable to open file: Admin.txt" << endl;
        }
    }

    static void clearFile(string fileName, string lastIdFile) {
        ofstream file(fileName,ios::trunc);
        file.close();
        cout << " File " << fileName << " cleared successfully." << endl;

        ofstream idFile(lastIdFile, ios::trunc);
        idFile.close();
        cout << " File " << lastIdFile << " cleared successfully." << endl;
    }
};