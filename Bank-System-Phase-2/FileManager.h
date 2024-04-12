#pragma once
#include <iostream>
#include <string>
#include <vector>
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
        FilesHelper::saveEmployee("Employee.txt", "EmployeeLastId.txt",employee);
    }

    void addAdmin(Admin admin) {
        FilesHelper::saveEmployee("Admin.txt", "AdminLastId.txt", admin);
    }

    void getClients() {
        FilesHelper::getAllClients();
    }

    void getEmployees() {
        FilesHelper::getAllEmployees();
    }

    void getAdmins() {
        FilesHelper::getAllAdmins();
    }

    void removeAllClients() {
        FilesHelper::clearFile("Clients.txt", "ClientLastId.txt");
    }

    void removeAllEmployees() {
        FilesHelper::clearFile("Employee.txt", "EmployeeLastId.txt");
    }

    void removeAllAdmins() {
        FilesHelper::clearFile("Admin.txt", "AdminLastId.txt");
    }
};