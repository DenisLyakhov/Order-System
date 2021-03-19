#ifndef CLIENT_H
#define CLIENT_H

#include <user.h>

class Client: User{
public:
    Client(string name);
    Client(string name, string tempID);


    void edit_my_data();
    void show_all_orders(vector<Order> orders);
    void show_order(int orderNum, vector<Order> orders);
    void cancel_order(int orderNum, vector<Order>& orders);
    void edit_order(int orderNum, vector<Order>& orders, vector<Product> products);

    void create_new_order(vector<Order>& orders, vector<Product> products);




public:
    Order get_order(int orderNum, vector<Order> orders);
};

#endif // CLIENT_H
