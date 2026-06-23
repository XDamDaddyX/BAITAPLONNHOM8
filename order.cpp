
#include "order.h"
#include <iostream>

Order::Order(int id, Customer* c, Cart ct, Payment* p, Shipping* s)
    : orderId(id), customer(c), cart(ct), payment(p), shipping(s) {}

void Order::generateReceipt() {
    std::cout << "\n--- Order Receipt ---\n";
    std::cout << "Order ID: " << orderId << "\n";
    std::cout << "Customer: " << customer->getUsername() << "\n";
    cart.viewCart();
    double subtotal = cart.calculateTotal();
    shipping->displayShipping();
    double total = subtotal + shipping->getCost();
    std::cout << "Total Amount: $" << total << "\n";
    payment->processPayment(total);
    std::cout << "---------------------\n";
}