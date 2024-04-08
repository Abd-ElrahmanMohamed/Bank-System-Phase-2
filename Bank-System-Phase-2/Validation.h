#pragma once
#include <iostream>
#include <string>
using namespace std;
class Validation {
public:
    //Methods:
    static bool ValidateName(const string& name) {
        return name.size() >= 5 && name.size() <= 20 && Alphapatic(name);
    }

    static bool ValidatePassword(const string& password) {
        return password.size() >= 8 && password.size() <= 20;
    }

    static bool ValidateBalance(double balance) {
        return balance >= 1500;
    }

    static bool ValidateSalary(double salary) {
        return salary >= 5000;
    }

    static bool Alphapatic(const string& newName) {
        for (char n : newName) {
            if (!isalpha(n)) {
                return false;
            }
        }
        return true;
    }
};