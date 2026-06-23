// Product.h
#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
protected:
    int id;
    std::string name;
    double price;
public:
    Product(int i, std::string n, double p);
    virtual ~Product() = default;
    virtual void displayProduct() = 0;
    int getId();
    std::string getName();
    double getPrice();
};

class Electronics : public Product {
private:
    int warranty;
public:
    Electronics(int i, std::string n, double p, int w);
    void displayProduct() override;
};

class Clothing : public Product {
private:
    std::string size;
public:
    Clothing(int i, std::string n, double p, std::string s);
    void displayProduct() override;
};

class Book : public Product {
private:
    std::string author;
public:
    Book(int i, std::string n, double p, std::string a);
    void displayProduct() override;
};

#endif