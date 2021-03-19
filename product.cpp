#include <product.h>

Product::Product(){}

Product::Product(string name, int price){
    productName = name;
    productPrice = price;
}

string Product::getProductName(){
    return productName;
}

int Product::getProductPrice(){
    return productPrice;
}
