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
  

    Client client1(101, "Mohamed", "password", 2000);
    Client client2(100, "Mohamedd", "password", 20000);
   // client.display();
   cout << "==================================\n" << endl;

    Employee employee(201, "AbdElrahman", "password", 6000);
   /* employee.display();*/

    cout << "==================================\n" << endl;
    employee.addClient(client1);
    employee.addClient(client2);

    cout << "==================================\n" << endl;

    employee.listClients();
<<<<<<< HEAD
    employee.searchClient(1);
=======
    employee.SearchClient(101);
>>>>>>> dddd25435d631e3bda553f0f38e226c6f4329b8d

    
   cout << "==================================\n" << endl;

   employee.editClient(2, "Charlie", "newpass", 3000);

    employee.listClients();

    
    
    
   // client.display();
    
   /* Admin admin(301, "AdminUser", "adminpass", 10000);
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