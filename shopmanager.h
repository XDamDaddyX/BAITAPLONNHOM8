// ShopManager.h
#ifndef SHOPMANAGER_H
#define SHOPMANAGER_H

#include <vector>
#include "product.h"
#include "cart.h"
#include "user.h"

class ShopManager {
private:
    std::vector<Product*> products;
    Cart currentCart;
    Customer* currentCustomer;
public:
    ShopManager();
    ~ShopManager();
    void setupShop();
    void displayMenu();
};

#endif