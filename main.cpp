#include <iostream>
#include <stdio.h>
#include "product.h"
#include "client.h"
#include "admin.h"
#include "product.h"
#include <fstream>
#include "order.h"
#include <map>
#include <istream>
#include <sstream>
#include <cstdlib>
#include<bits/stdc++.h>
#include <string>
#include <vector>

#include <algorithm>

using namespace std;



void interface(){

    vector<Client> clients;

    Product p1("Banana", 10);
    Product p2("Lemon", 20);
    Product p3("Melon", 30);
    Product p4("Chocolate", 40);
    Product p5("Ice cream", 15);

    vector<Product> products;
    products.push_back(p1);
    products.push_back(p2);
    products.push_back(p3);
    products.push_back(p4);
    products.push_back(p5);

    vector<Order> orders;

    string temp;
    string tempID;

    cout << "Type any symbol if you want to create a new account" << endl;
    cout << "Or to launch tests type: tests" << endl;

    cin >> temp;

    if(temp == "tests"){



    } else {

        cout << "Enter your name: " << endl;
        cin >> tempID;

        Client c(tempID);

        clients.push_back(c);

        cout << "You successfully created a new account!\n\n\n" << endl;

        while(true){
            int option = 0;

            cout << "You have following options: " << endl;
            cout << "1) Edit your data." << endl;
            cout << "2) Show your orders." << endl;
            cout << "3) Cancel any order." << endl;
            cout << "4) Edit any order." << endl;
            cout << "5) Create a new order" << endl;
	    cout << "Enter corresponding number: " << endl;

            cin >> option;

            cout << "\n\n\n" << endl;

            if(option == 1){
                c.edit_my_data();
            } else if(option == 2){
                c.show_all_orders(orders);
            } else if(option == 3){
                int num;
                cout << "Enter your order num: " << endl;
                cin >> num;
                c.cancel_order(num, orders);
            } else if(option == 4){
                int num;
                cout << "Enter your order num: " << endl;
                cin >> num;
                c.edit_order(num, orders, products);
            } else if(option == 5){
                c.create_new_order(orders, products);
            } else {

            }
        }
    }


}

int main()
{   map<string,int> products;
    vector<Order> orders;

    fstream bclient, bproduct, border;
    bclient.open("bclient.txt", ios::in | ios::out);
    bproduct.open("bproduct.txt", ios::in | ios::out);
    border.open("border.txt", ios::in | ios::out);
    if(bproduct.good() == true)
    {
        string linep;
        string wordp;
        int price;
        stringstream iss;
        while(getline(bproduct,linep))
        {
            stringstream iss(linep);
            iss>>wordp;
            iss>>price;
            products.insert({wordp,price});

        }
    }
    if(border.good() == true)
    {
        string lineo;
        string adress;
        string wordo;
        int nrorder;
        string status;
        stringstream iss;
        while(getline(border,lineo))
        {
            stringstream iss(lineo);
            iss>>adress;
            iss>>nrorder;
            iss>>status;
        }
    }

    interface();

    // TESTY

    cout << "Testy------------------------" << endl;

    Product p1("Banana", 10);
    Product p2("Lemon", 20);
    Product p3("Melon", 30);
    Product p4("Chocolate", 40);
    Product p5("Ice cream", 15);

    //cout << p1.getProductPrice();

    vector<Product> arr1;
    arr1.push_back(p1);
    arr1.push_back(p2);
    arr1.push_back(p3);
    arr1.push_back(p4);
    arr1.push_back(p5);

    Order o("1", "os. Urocze");

    o.add_product_to_order(p1);
    o.add_product_to_order(p2);
    o.add_product_to_order(p3);
    o.add_product_to_order(p4);
    o.add_product_to_order(p5);

    cout << o.get_order_status() << endl;
    cout << o.get_order_address() << endl;
    cout << o.get_order_num() << endl;

    o.show_all_products();
    o.cancel_order();


    o.show_all_products();

    vector<Order> ordersTest;
    ordersTest.push_back(o);

    //ADMIN TEST
    Admin a("Hello");

    a.show_all_orders(ordersTest);

    cout << "!!!" << ordersTest[0].get_order_status() << "!!!" << endl;

    a.cancel_order(1, ordersTest);

    cout << "!!!" << ordersTest[0].get_order_status() << "!!!" << endl;


    Client c("Den");

    return 0;
}
