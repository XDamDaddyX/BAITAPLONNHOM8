
#ifndef USER_H
#define USER_H

#include <string>

class User {
protected:
    std::string username;
    std::string password;
public:
    User(std::string u, std::string p);
    virtual ~User() = default;
    virtual void displayRole() = 0;
    std::string getUsername();
};

class Customer : public User {
public:
    Customer(std::string u, std::string p);
    void displayRole() override;
};

class Admin : public User {
public:
    Admin(std::string u, std::string p);
    void displayRole() override;
};

#endif