// Payment.h
#ifndef PAYMENT_H
#define PAYMENT_H

class Payment {
public:
    virtual ~Payment() = default;
    virtual void processPayment(double amount) = 0;
};

class CreditCardPayment : public Payment {
public:
    void processPayment(double amount) override;
};

class CashOnDelivery : public Payment {
public:
    void processPayment(double amount) override;
};

#endif