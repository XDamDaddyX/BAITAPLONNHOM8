// shopmanager.h
#ifndef SHOPMANAGER_H
#define SHOPMANAGER_H

#include <vector>
#include "product.h"
#include "cart.h"
#include "user.h"

class ShopManager {
private:
    std::vector<Product*> products;
    std::vector<Customer*> registeredCustomers;
    Cart currentCart;
    Customer* currentCustomer;
public:
    ShopManager();
    ~ShopManager();
    void setupShop();
    void start();
    void authMenu();
    void mainMenu();
    void registerAccount();
    void loginAccount();
    void updateAddress();
};

#endif
