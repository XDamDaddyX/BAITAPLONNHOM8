// CartItem.h
#ifndef CARTITEM_H
#define CARTITEM_H

#include "Product.h"

class CartItem {
private:
    Product* product;
    int quantity;
public:
    CartItem(Product* p, int q);
    Product* getProduct();
    int getQuantity();
    double getTotalPrice();
};

#endif