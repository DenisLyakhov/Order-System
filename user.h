#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include <order.h>

// Interfejs

class User {
public:
    string userID;
    string fullName;

public:


    virtual void edit_my_data() = 0;
    virtual void show_all_orders(vector<Order> orders) = 0;
    virtual void show_order(int orderNum, vector<Order> orders) = 0;
    virtual void cancel_order(int orderNum, vector<Order>& orders) = 0;
    virtual void edit_order(int orderNum, vector<Order>& orders, vector<Product> products) = 0;

};

#endif // USER_H
