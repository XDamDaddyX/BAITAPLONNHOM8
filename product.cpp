// Product.cpp
#include "Product.h"
#include <iostream>

Product::Product(int i, std::string n, double p) : id(i), name(n), price(p) {}
int Product::getId() { return id; }
std::string Product::getName() { return name; }
double Product::getPrice() { return price; }

Electronics::Electronics(int i, std::string n, double p, int w) : Product(i, n, p), warranty(w) {}
void Electronics::displayProduct() {
    std::cout << "[" << id << "] Electronics: " << name << " - $" << price << " (Warranty: " << warranty << " months)\n";
}

Clothing::Clothing(int i, std::string n, double p, std::string s) : Product(i, n, p), size(s) {}
void Clothing::displayProduct() {
    std::cout << "[" << id << "] Clothing: " << name << " - $" << price << " (Size: " << size << ")\n";
}

Book::Book(int i, std::string n, double p, std::string a) : Product(i, n, p), author(a) {}
void Book::displayProduct() {
    std::cout << "[" << id << "] Book: " << name << " - $" << price << " (Author: " << author << ")\n";
}