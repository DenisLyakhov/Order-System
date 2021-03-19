#ifndef ADMIN_H
#define ADMIN_H

#include <user.h>

class Admin: User{
public:
    Admin(string name);
    Admin(string name, string tempID);

    void edit_my_data();
    void show_all_orders(vector<Order> orders);
    void show_order(int orderNum, vector<Order> orders);
    void cancel_order(int orderNum, vector<Order>& orders);
    void edit_order(int orderNum, vector<Order>& orders, vector<Product> products);

private:
    Order get_order(int orderNum, vector<Order> orders);
};
#endif // ADMIN_H
