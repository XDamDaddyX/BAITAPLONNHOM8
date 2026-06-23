
#include "User.h"
#include <iostream>

User::User(std::string u, std::string p) : username(u), password(p) {}
std::string User::getUsername() { return username; }

Customer::Customer(std::string u, std::string p) : User(u, p) {}
void Customer::displayRole() { std::cout << "Role: Customer\n"; }

Admin::Admin(std::string u, std::string p) : User(u, p) {}
void Admin::displayRole() { std::cout << "Role: Admin\n"; }