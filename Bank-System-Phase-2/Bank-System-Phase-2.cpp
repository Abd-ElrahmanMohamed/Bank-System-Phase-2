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
    cout << "|<<<<WELCOME>>>>|\n" << endl;
  
    Client client(101, "Mohamed", "password", 20000);
    client.display();
    cout << "==================================\n" << endl;
    Employee employee(201, "AbdElrahman", "password", 5000);
    employee.display();
    cout << "==================================\n" << endl;
    Admin admin(301, "AdminUser", "adminpass", 10000);
    admin.display();
   cout << "=============================================================\n" << endl;
    FileManager fileManager;
    fileManager.addClient(client);
    fileManager.addEmployee(employee);
    fileManager.addAdmin(admin);

    cout << "==================================\n" << endl;

    fileManager.getAllClients();
    fileManager.getAllEmployees();
    fileManager.getAllAdmins();


    fileManager.removeAllClients();
    fileManager.removeAllEmployees();
    fileManager.removeAllAdmins();

    return 0;
}