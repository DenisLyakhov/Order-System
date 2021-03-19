#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include "product.h"

using namespace std;
#include <string>
#include <vector>

enum orStatus {Recieved, Cancelled, Completed, Processing};

class Order {
public:
    vector<Product> orderProducts;
    orStatus orderStatus;
    string orderAddress;
    string orderID;


public:
    Order();
    Order(string ID, string address);

    string get_order_status();
    string get_order_address();
    string get_order_num();
    void show_all_products();

    void change_order_status();
    void cancel_order();
    void change_order_address();
    void subtract_product_from_order();
    void add_product_to_order(Product newProduct);
    void add_product(vector<Product> products);
};

#endif // ORDER_H
