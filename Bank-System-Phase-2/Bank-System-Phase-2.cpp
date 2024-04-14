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
    client.display();
    cout << "==================================\n" << endl;

    Employee employee(201, "AbdElrahman", "password", 6000);
    employee.display();
    cout << "==================================\n" << endl;

    employee.editClient(101, "Mohamedd", "passwordd", 20000);
    
    
    
    client.display();
    
    /*Admin admin(301, "AdminUser", "adminpass", 10000);
    admin.display();

    cout << "==================================\n" << endl;*/





























    /*fileManager.addClient(client);
    fileManager.addEmployee(employee);
    fileManager.addAdmin(admin);

    cout << "==================================\n" << endl;

    fileManager.getAllClients();
    fileManager.getAllEmployees();
    fileManager.getAllAdmins();


    fileManager.removeAllClients();
    fileManager.removeAllEmployees();
    fileManager.removeAllAdmins();*/

    return 0;
}