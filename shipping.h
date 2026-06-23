
#ifndef SHIPPING_H
#define SHIPPING_H

#include <string>

class Shipping {
private:
    std::string address;
    double cost;
public:
    Shipping(std::string a, double c);
    void displayShipping();
    double getCost();
};

#endif