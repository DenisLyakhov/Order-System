#include <client.h>
#include <ctime>
#include <sstream>
#include <string>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include<bits/stdc++.h>

void get_order_number_helper(Order o) {  // function:

      cout << "# " << o.get_order_num() << endl;
      o.show_all_products();
}

Client::Client(string name, string tempID){
    fullName = name;

    this->userID = tempID;
}

Client::Client(string name){
    fullName = name;

    std::time_t timeID = std::time(nullptr);

    std::stringstream ss;
    ss << timeID;

    this->userID = "C" + ss.str();

}


Order Client::get_order(int orderNum, vector<Order> orders){
    while(orderNum <= 0 or orderNum > orders.size()){
        cout << "Your order number is invalid. Please enter a valid number: ";
        cin >> orderNum;
    }
    return orders.at(orderNum - 1);
}

void Client::edit_my_data(){
    cout << "You can change your name: ";
    string name;
    cin >> name;

    this->fullName = name;

    cout << endl << "You have succesfully changed your name.\n\n\n" << endl;
}

void Client::show_all_orders(vector<Order> orders){
    int i = 1;
    bool opt = false;
    cout << "Showing all orders:" << endl;
    //for_each(orders.begin(), orders.end(), get_order_number_helper);
    for (auto o : orders) {
        if(o.orderID == userID){
            cout << "# " << i << " " << o.get_order_num() << endl;
            opt = true;
        }
        show_order(i, orders);
        cout << "\n" << endl;
        i++;
     }

    if(!opt)
        cout << "You have no orders" << endl;

    cout << "\n\n\n" << endl;
}

void Client::show_order(int orderNum, vector<Order> orders){
    Order o = get_order(orderNum, orders);
    if(userID == o.orderID){
        o.show_all_products();
    }
}

void Client::cancel_order(int orderNum, vector<Order>& orders){

    if(orders[orderNum-1].orderID == userID){
        if(orders[orderNum-1].get_order_status() != "Processing"){
            orders[orderNum-1].cancel_order();
            cout << "You have succesfully cancelled your order" << endl;
        } else {
            cout << "Your order is already in process. You can not cancel this order." << endl;
        }
    } else {
        cout << "You entered invalid order." << endl;
    }

    cout << "\n\n\n" << endl;
}

void Client::edit_order(int orderNum, vector<Order>& orders, vector<Product> products){
    int opt = -1;

    if(orders[orderNum-1].orderID == userID){
        while(opt != 0){
            cout << "You can: " << endl;
            cout << "1) " << "Change order address" << endl;
            cout << "2) " << "Subtract product from order" << endl;
            cout << "3) " << "Add another product to order" << endl;
            cout << "0) " << "Go back\nChoose an option: ";

            cin >> opt;

            cout << "\n\n\n";

            if(opt == 1){
                orders[orderNum-1].change_order_address();
            } else if(opt == 2){
                orders[orderNum-1].subtract_product_from_order();
            } else if(opt == 3){
                orders[orderNum-1].add_product(products);
            }
            cout << "----------------------------\n\n\n" << endl;
        }
    }
}

void Client::create_new_order(vector<Order>& orders, vector<Product> products){
    string temp;
    string ID = userID;

    Order newOrder(ID, "");

    cout << "Creating an order:" << endl;
    newOrder.add_product(products);

    while(temp != "n"){
        cout << "Do you want to add another product?(y/n): ";
        cin.ignore();
        getline(cin, temp);
        if(temp == "y"){
            newOrder.add_product(products);
        }
    }

    cout << "\n\n\n";

    newOrder.change_order_address();

    orders.push_back(newOrder);

    cout << "\n\n\n";
    cout << "You order has been created\n-------------------------\n\n\n";


}


