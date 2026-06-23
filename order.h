#ifndef ORDER_H
#define ORDER_H

#include "user.h"
#include "cart.h"
#include "payment.h"
#include "shipping.h"

class Order {
private:
    int orderId;
    Customer* customer;
    Cart cart;
    Payment* payment;
    Shipping* shipping;
public:
    Order(int id, Customer* c, Cart ct, Payment* p, Shipping* s);
    void generateReceipt();
};

#endif