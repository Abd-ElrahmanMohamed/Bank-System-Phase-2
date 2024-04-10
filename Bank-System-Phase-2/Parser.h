#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "Person.h"
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
using namespace std;
class Parser {
public:
    //Methods:
    static vector<string> split(string& line) {
        vector<string> tokens;
        istringstream iss(line);
       string token;
        while (getline(iss, token, ',')) {
            tokens.push_back(token);
        }
        return tokens;
    }

    static Client parseToClient(string& line) {
        vector<string> tokens = split(line);
        Client client;
        if (tokens.size() == 4) {
            client.getID() = tokens[0];
            client.getName() = tokens[1];
            client.getPassword() = tokens[2];
            client.getBalance() = stod(tokens[3]);
        }
        return client;
    }

    static Employee parseToEmployee(string& line) {
        vector<string> tokens = split(line);
        Employee employee;
        if (tokens.size() == 4) {
            employee.getID() = tokens[0];
            employee.getName() = tokens[1];
            employee.getPassword() = tokens[2];
            employee.getSalary() = stod(tokens[3]);
        }
        return employee;
    }

    static Admin parseToAdmin(string& line) {
        vector<string> tokens = split(line);
        Admin admin;
        if (tokens.size() == 4) {
            admin.getID() = tokens[0];
            admin.getName() = tokens[1];
            admin.getPassword() = tokens[2];
            admin.getSalary() = stod(tokens[3]);
        }
        return admin;
    }
};