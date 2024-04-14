#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include "FileManager.h"
using namespace std;
int main() {
    FileManager fileManager;

    cout << "|<<<<WELCOME>>>>|\n" << endl;
    
    Client client(101, "Mohamed", "password", 2000);
    Employee employee(201, "AbdElrahman", "password", 6000);
    Admin admin(301, "AdminUser", "adminpass", 10000);

    cout << "==================================\n" << endl;

    fileManager.addClient(client);
    fileManager.addEmployee(employee);
    fileManager.addAdmin(admin);

    cout << "==================================\n" << endl;

    fileManager.getAllClients();
    fileManager.getAllEmployees();
    fileManager.getAllAdmins();

    cout << "==================================\n" << endl;

    fileManager.removeAllClients();
    fileManager.removeAllEmployees();
    fileManager.removeAllAdmins();

    return 0;
}