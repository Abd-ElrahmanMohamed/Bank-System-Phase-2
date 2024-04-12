#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include "DataSourceInterface.h"
#include "FilesHelper.h"
using namespace std;
class FileManager : public DataSourceInterface
{
public:
	//Methods: 
    void addClient(Client client) {
        FilesHelper::saveClient(client);
    }

    void addEmployee(Employee employee) {
        FilesHelper::saveEmployee(employee);
    }

    void addAdmin(Admin admin) {
        FilesHelper::saveAdmin(admin);
    }

    vector<Client> getClients() {
        return FilesHelper::getAllClients();
    }

    vector<Employee> getEmployees() {
        return FilesHelper::getAllEmployees();
    }

    vector<Employee> getAdmins() {
        return FilesHelper::getAllAdmins();
    }

    void removeAllClients() {
        ofstream File("Clients.txt");
        ofstream IdFile("EmployeeLastId.txt");
        File.close();
        IdFile.close();

        FilesHelper::clearFile("Clients.txt", "ClientsLastId.txt");
    }

    void removeAllEmployees() {

        FilesHelper::clearFile("Employees.txt");
    }

    void removeAllAdmins() {
        FilesHelper::clearFile("Admins.txt");
    }
};