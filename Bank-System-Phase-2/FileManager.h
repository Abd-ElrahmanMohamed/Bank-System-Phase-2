#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include "Parser.h"
#include "DataSourceInterface.h"
using namespace std;
class FileManager : public DataSourceInterface
{
public:
	//Methods: 
	void addClient(Client client) {
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

	void addEmployee(Employee employee) {
		ofstream file("Employee.txt", ios::app);
		if (file.is_open()) {
			file << employee.getID() << "#" << employee.getName() << "#" << employee.getPassword() << "#" << employee.getSalary() << endl;
			file.close();
			cout << " Employee added successfully.\n";
		}
		else {
			cout << " Unable to open Employee.txt for writing.\n";
		}
	}

	void addAdmin(Admin admin) {
		ofstream file("Admin.txt", ios::app);
		if (file.is_open()) {
			file << admin.getID() << "#" << admin.getName() << "#" << admin.getPassword() << "#" << admin.getSalary() << endl;
			file.close();
			cout << " Admin added successfully.\n";
		}
		else {
			cout << " Unable to open Admin.txt for writing.\n";
		}
	}

	vector<Client> getAllClients() {
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
			cout << "Unable to open Clients.txt for reading." << std::endl;
		}
		return clients;
	}

	vector<Employee> getAllEmployees() {
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
			cout << "Unable to open Employees.txt for reading." << std::endl;
		}
		return employees;
	}

	vector<Employee> getAllAdmins() {
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
			cout << "Unable to open Admins.txt for reading." << std::endl;
		}
		return admins;
	}

	void removeAllClients() {
		ofstream file("Clients.txt", ios::trunc);
		file.close();
	}

	void removeAllEmployees() {
		ofstream file("Employee.txt", ios::trunc);
		file.close();
	}

	void removeAllAdmins() {
		ofstream file("Admin.txt", ios::trunc);
		file.close();
	}
};