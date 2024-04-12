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
        FilesHelper::saveEmployee(0,"",employee);
    }


    void addAdmin(const Admin& admin) {
        FilesHelper::saveEmployee(admin);
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
        FilesHelper::clearFile("Clients.txt", "ClientsLastId.txt");
    }

    void removeAllEmployees() {
        FilesHelper::clearFile("Employee.txt", "EmployeeLastId.txt");
    }

    void removeAllAdmins() {
        FilesHelper::clearFile("Admin.txt", "AdminLastId.txt");
    }
};