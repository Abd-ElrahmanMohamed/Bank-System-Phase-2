#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
using namespace std;
class Parser {
public:
    //Methods:
    static vector<string> split(string line) {
        vector<string> tokens;
        istringstream iss(line);
        string token;
        while (getline(iss, token, '#')) {
            tokens.push_back(token);
        }
        return tokens;
    }

    static Client parseToClient(string line) {
        vector<string> tokens = split(line);
        Client client = Client(0, "", "", 0);
        if (tokens.size() == 4) {
            client.setID(stoi(tokens[0]));
            client.setName(tokens[1]);
            client.setPassword(tokens[2]);
            client.setBalance(stod(tokens[3]));
        }
        return client;
    }

    static Employee parseToEmployee(string line) {
        vector<string> tokens = split(line);
        Employee employee = Employee(0, "", "", 0);
        if (tokens.size() == 4) {
            employee.setID(stoi(tokens[0]));
            employee.setName(tokens[1]);
            employee.setPassword(tokens[2]);
            employee.setSalary(stod(tokens[3]));
        }
        return employee;
    }

    static Admin parseToAdmin(string& line) {
        vector<string> tokens = split(line);
        Admin admin = Admin(0, "", "", 0);
        if (tokens.size() == 4) {
            admin.setID(stoi(tokens[0]));
            admin.setName(tokens[1]);
            admin.setPassword(tokens[2]);
            admin.setSalary(stod(tokens[3]));
        }
        return admin;
    }
};