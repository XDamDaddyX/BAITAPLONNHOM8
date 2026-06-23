// Cart.h
#ifndef CART_H
#define CART_H

#include <vector>
#include "CartItem.h"

class Cart {
private:
    std::vector<CartItem> items;
public:
    void addProduct(Product* p, int q);
    void viewCart();
    double calculateTotal();
    void clearCart();
};

#endif