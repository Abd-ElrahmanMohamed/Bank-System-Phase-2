#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
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
		vector<string> clients;
		string line;
		ifstream file("Clients.txt");
		if (file.is_open()) {
			while (getline(file, line)) {
				clients.push_back(line);
			}
			file.close();
		}
		else {
			cout << " Unable to open file\n";
		}
		return clients;
	}

	vector<Employee> getAllEmployees() {
		vector<string> employees;
		string line;
		ifstream file("Employees.txt");
		if (file.is_open()) {
			while (getline(file, line)) {
				employees.push_back(line);
			}
			file.close();
		}
		else {
			cout << " Unable to open file\n";
		}
		return employees;
	}

	vector<Employee> getAllAdmins() {
		vector<string> admins;
		string line;
		ifstream file("Admin.txt");
		if (file.is_open()) {
			while (getline(file, line)) {
				admins.push_back(line);
			}
			file.close();
		}
		else {
			cout << " Unable to open file\n";
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