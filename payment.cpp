
#include "payment.h"
#include <iostream>

void CreditCardPayment::processPayment(double amount) {
    std::cout << "Processing Credit Card payment of $" << amount << "\n";
}

void CashOnDelivery::processPayment(double amount) {
    std::cout << "Cash on Delivery selected for $" << amount << "\n";
}