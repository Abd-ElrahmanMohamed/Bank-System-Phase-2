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
        FilesHelper::saveEmployee();
    }

    void addAdmin(Admin admin) {
       FilesHelper::saveEmployee();
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
        FilesHelper::clearFile();
    }

    void removeAllEmployees() {

        FilesHelper::clearFile();
    }

    void removeAllAdmins() {
        FilesHelper::clearFile();
    }
};