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
        vector<string> result;
        stringstream ss(line);
        string item;
        while (getline(ss, item, '#')) {
            result.push_back(item);
        }
        return result;
    }

    static Client parseToClient(string line) {
        vector<string> tokens = split(line);
        int id = stoi(tokens[0]);
        string name = tokens[1];
        string password = tokens[2];
        double balance = stod(tokens[3]);
        return Client(id, name, password, balance);
    }

    static Employee parseToEmployee(string line) {
        vector<string> tokens = split(line);
        int id = stoi(tokens[0]);
        string name = tokens[1];
        string password = tokens[2];
        double salary = stod(tokens[3]);
        return Employee(id, name, password, salary);
    }

    static Admin parseToAdmin(string line) {
        vector<string> tokens = split(line);
        int id = stoi(tokens[0]);
        string name = tokens[1];
        string password = tokens[2];
        double salary = stod(tokens[3]);
        return Admin(id, name, password, salary);
    }
};