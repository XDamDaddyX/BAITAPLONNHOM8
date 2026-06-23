// ShopManager.cpp
#include "shopmanager.h"
#include "payment.h"
#include "shipping.h"
#include "order.h"
#include <iostream>

ShopManager::ShopManager() { currentCustomer = nullptr; }

ShopManager::~ShopManager() {
    for (auto p : products) delete p;
    delete currentCustomer;
}

void ShopManager::setupShop() {
    products.push_back(new Electronics(1, "Laptop Gaming", 1200.00, 24));
    products.push_back(new Clothing(2, "Oversize T-Shirt", 25.50, "XL"));
    products.push_back(new Book(3, "C++ Programming", 45.00, "Bjarne Stroustrup"));
    currentCustomer = new Customer("thangtay_dev", "password123");
}

void ShopManager::displayMenu() {
    int choice;
    do {
        std::cout << "\n=== ONLINE SHOPPING SYSTEM ===\n";
        std::cout << "1. View Products\n2. Add to Cart\n3. View Cart\n4. Checkout\n0. Exit\n";
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
            if (currentCart.calculateTotal() == 0) {
                std::cout << "Your cart is empty!\n";
            } else {
                Shipping ship("Ho Chi Minh City", 15.0);
                CashOnDelivery pay;
                Order order(9991, currentCustomer, currentCart, &pay, &ship);
                order.generateReceipt();
                currentCart.clearCart();
            }
        }
    } while (choice != 0);
    std::cout << "Exiting system...\n";
}