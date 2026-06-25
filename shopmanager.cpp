// shopmanager.cpp
#include "shopmanager.h"
#include "payment.h"
#include "shipping.h"
#include "order.h"
#include <iostream>

ShopManager::ShopManager() { currentCustomer = nullptr; }

ShopManager::~ShopManager() {
    for (auto p : products) delete p;
    for (auto c : registeredCustomers) delete c;
}

void ShopManager::setupShop() {
    products.push_back(new Electronics(1, "Laptop Gaming", 1200.00, 24));
    products.push_back(new Clothing(2, "Oversize T-Shirt", 25.50, "XL"));
    products.push_back(new Book(3, "C++ Programming", 45.00, "Bjarne Stroustrup"));
    
    registeredCustomers.push_back(new Customer("admin", "123"));
}

void ShopManager::start() {
    authMenu();
}

void ShopManager::authMenu() {
    int choice;
    do {
        std::cout << "\n=== WELCOME TO ONLINE SHOP ===\n";
        std::cout << "1. Login\n2. Register\n0. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        if (choice == 1) loginAccount();
        else if (choice == 2) registerAccount();
    } while (choice != 0 && currentCustomer == nullptr);
}

void ShopManager::registerAccount() {
    std::string u, p;
    std::cout << "\n--- REGISTER ---\n";
    std::cout << "Enter username: ";
    std::cin >> u;
    std::cout << "Enter password: ";
    std::cin >> p;

    for (auto c : registeredCustomers) {
        if (c->getUsername() == u) {
            std::cout << "Username already exists!\n";
            return;
        }
    }
    registeredCustomers.push_back(new Customer(u, p));
    std::cout << "Registration successful!\n";
}

void ShopManager::loginAccount() {
    std::string u, p;
    std::cout << "\n--- LOGIN ---\n";
    std::cout << "Enter username: ";
    std::cin >> u;
    std::cout << "Enter password: ";
    std::cin >> p;

    for (auto c : registeredCustomers) {
        if (c->getUsername() == u && c->checkPassword(p)) {
            currentCustomer = c;
            std::cout << "Login successful! Welcome " << u << "\n";
            mainMenu();
            return;
        }
    }
    std::cout << "Invalid username or password!\n";
}

void ShopManager::updateAddress() {
    std::string addr;
    std::cout << "\n--- UPDATE SHIPPING ADDRESS ---\n";
    std::cout << "Current Address: " << currentCustomer->getAddress() << "\n";
    std::cout << "Enter new address (use_underscores_or_no_spaces): ";
    std::cin >> addr;
    currentCustomer->setAddress(addr);
    std::cout << "Address updated successfully!\n";
}

void ShopManager::mainMenu() {
    int choice;
    do {
        std::cout << "\n=== ONLINE SHOPPING SYSTEM ===\n";
        std::cout << "Hello: " << currentCustomer->getUsername() << "\n";
        std::cout << "Address: " << currentCustomer->getAddress() << "\n";
        std::cout << "------------------------------\n";
        std::cout << "1. View Products\n2. Add to Cart\n3. View Cart\n4. Update Address\n5. Checkout\n0. Logout\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        
        if (choice == 1) {
            std::cout << "\n--- Product List ---\n";
            for (auto p : products) p->displayProduct();
        } else if (choice == 2) {
            int id, qty;
            std::cout << "Enter Product ID: ";
            std::cin >> id;
            std::cout << "Enter Quantity: ";
            std::cin >> qty;
            bool found = false;
            for (auto p : products) {
                if (p->getId() == id) {
                    currentCart.addProduct(p, qty);
                    std::cout << "Successfully added to cart!\n";
                    found = true;
                    break;
                }
            }
            if (!found) std::cout << "Invalid Product ID!\n";
        } else if (choice == 3) {
            std::cout << "\n--- Your Cart ---\n";
            currentCart.viewCart();
            std::cout << "Subtotal: $" << currentCart.calculateTotal() << "\n";
        } else if (choice == 4) {
            updateAddress();
        } else if (choice == 5) {
            if (currentCart.calculateTotal() == 0) {
                std::cout << "Your cart is empty!\n";
            } else {
                Shipping ship(currentCustomer->getAddress(), 15.0);
                CashOnDelivery pay;
                Order order(9991, currentCustomer, currentCart, &pay, &ship);
                order.generateReceipt();
                currentCart.clearCart();
            }
        }
    } while (choice != 0);
    
    currentCustomer = nullptr;
    std::cout << "Logged out...\n";
}
