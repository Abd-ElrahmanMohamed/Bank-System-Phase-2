#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
using namespace std;
int main()
{
    cout << "|<<<<WELCOME>>>>|\n" << endl;
    Client client(101, "Mohamed", "password", 2000);
    client.display();
    cout << "==================================\n" << endl;

    Employee employee(201, "AbdElrahman", "password", 6000);
    employee.display();
    cout << "==================================\n" << endl;

    Admin admin(301, "AdminUser", "adminpass", 10000);
    admin.display();
    return 0;
}