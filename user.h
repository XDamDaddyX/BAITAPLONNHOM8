// user.h
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
    bool checkPassword(std::string p);
};

class Customer : public User {
private:
    std::string address;
public:
    Customer(std::string u, std::string p);
    void displayRole() override;
    void setAddress(std::string addr);
    std::string getAddress();
};

class Admin : public User {
public:
    Admin(std::string u, std::string p);
    void displayRole() override;
};

#endif
