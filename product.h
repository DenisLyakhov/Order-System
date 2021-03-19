#ifndef PRODUCT_H
#define PRODUCT_H

using namespace std;
#include <string>

class Product{
private:
    string productName;
    int productPrice;

public:
    Product();
    Product(string name, int price);
    string getProductName();
    int getProductPrice();
};

#endif // PRODUCT_H
