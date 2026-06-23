// Cart.cpp
#include "Cart.h"
#include <iostream>

void Cart::addProduct(Product* p, int q) {
    items.push_back(CartItem(p, q));
}

void Cart::viewCart() {
    for (auto& item : items) {
        std::cout << item.getProduct()->getName() << " x" << item.getQuantity() << " = $" << item.getTotalPrice() << "\n";
    }
}

double Cart::calculateTotal() {
    double total = 0;
    for (auto& item : items) total += item.getTotalPrice();
    return total;
}

void Cart::clearCart() { items.clear(); }