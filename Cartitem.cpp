
#include "CartItem.h"

CartItem::CartItem(Product* p, int q) : product(p), quantity(q) {}
Product* CartItem::getProduct() { return product; }
int CartItem::getQuantity() { return quantity; }
double CartItem::getTotalPrice() { return product->getPrice() * quantity; }