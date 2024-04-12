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
    // Create Clients.txt
    ofstream clientsFile("Clients.txt");
    clientsFile.close();

    // Create Employee.txt
    ofstream employeeFile("Employee.txt");
    employeeFile.close();

    // Create Admin.txt
    ofstream adminFile("Admin.txt");
    adminFile.close();

    return 0;
}