
#include "shipping.h"
#include <iostream>


Shipping::Shipping(std::string a, double c) : address(a), cost(c) {}

void Shipping::displayShipping() {
    std::cout << "Shipping to: " << address << " (Cost: $" << cost << ")\n";
}

double Shipping::getCost() { return cost; }