#include <admin.h>
#include <ctime>
#include <sstream>
#include <string>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include<bits/stdc++.h>



void get_order_num_helper(Order o) {  // function:
  cout << "# " << o.get_order_num() << endl;
  o.show_all_products();
}

Admin::Admin(string name, string tempID){
    fullName = name;

    this->userID = tempID;
}

Admin::Admin(string name){
    fullName = name;

    std::time_t timeID = std::time(nullptr);

    std::stringstream ss;
    ss << timeID;

    this->userID = "A" + ss.str();

}


Order Admin::get_order(int orderNum, vector<Order> orders){

    while(orderNum <= 0 or orderNum > orders.size()){
        cout << "Your order number is invalid. Please enter a valid number: ";
        cin >> orderNum;
    }
    return orders.at(orderNum - 1);
}

void Admin::edit_my_data(){
    cout << "You can change your name: ";
    string name;
    cin >> name;

    this->fullName = name;

    cout << endl << "You have succesfully changed your name.\n\n\n" << endl;
}

void Admin::show_all_orders(vector<Order> orders){
    int i = 1;
    bool opt = false;
    cout << "Showing all orders:" << endl;
    for (auto o : orders) {
        cout << "# " << i << " " << o.get_order_num() << endl;
        show_order(i, orders);
        cout << "\n" << endl;
        i++;
     }

    if(!opt)
        cout << "You have no orders" << endl;

    cout << "\n\n\n" << endl;
}

void Admin::show_order(int orderNum, vector<Order> orders){
    Order o = get_order(orderNum, orders);
    o.show_all_products();
}

void Admin::cancel_order(int orderNum, vector<Order>& orders){
        orders[orderNum-1].cancel_order();
        cout << "You have succesfully cancelled order\n\n\n" << endl;
}


void Admin::edit_order(int orderNum, vector<Order>& orders, vector<Product> products){
    orders[orderNum-1].change_order_status();

    cout << "---------------------------\n\n\n";
}


//void Admin::show_order(int orderNum){}
