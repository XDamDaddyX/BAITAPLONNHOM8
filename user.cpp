// user.cpp
#include "user.h"
#include <iostream>

User::User(std::string u, std::string p) : username(u), password(p) {}
std::string User::getUsername() { return username; }
bool User::checkPassword(std::string p) { return password == p; }

Customer::Customer(std::string u, std::string p) : User(u, p), address("Chua co dia chi") {}
void Customer::displayRole() { std::cout << "Role: Customer\n"; }
void Customer::setAddress(std::string addr) { address = addr; }
std::string Customer::getAddress() { return address; }

Admin::Admin(std::string u, std::string p) : User(u, p) {}
void Admin::displayRole() { std::cout << "Role: Admin\n"; }
