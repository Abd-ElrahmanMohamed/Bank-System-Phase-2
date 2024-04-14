#pragma once
#include <iostream>
#include <string>
using namespace std;
class Validation {
public:
    //Methods:
    static bool ValidateName(string name) {
        if (!(name.size() >= 5 && name.size() <= 20)) {
            return false;
        }

        for (int i = 0; i < name.size(); i++) {
            if (!(name[i] >= 'a' && name[i] <= 'z' || name[i] >= 'A' && name[i] <= 'Z')) {
                return false;
            }
        }
        return true;
    }

    static bool ValidatePassword(string password) {
        return password.size() >= 8 && password.size() <= 20;
    }

    static bool ValidateBalance(double balance) {
        return balance >= 1500;
    }

    static bool ValidateSalary(double salary) {
        return salary >= 5000;
    }
};