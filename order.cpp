#include <order.h>
#include <product.h>

#include <algorithm>
#include<bits/stdc++.h>
#include<string.h>

using namespace std;

void get_product_name_helper(Product p) {  // function:
  cout << p.getProductName() << endl;
}

Order::Order(){}

Order::Order(string ID, string address){
    orderID = ID;
    orderAddress = address;
    orderStatus = Recieved;
}

string Order::get_order_status(){
    if(orderStatus == Cancelled)
        return "Cancelled";
    else if(orderStatus == Completed)
        return "Completed";
    else if(orderStatus == Processing)
        return "Processing";
    else
        return "Recieved";
}

string Order::get_order_address(){
    return orderAddress;
}

string Order::get_order_num(){
    return orderID;
}

void Order::show_all_products(){
    cout << "Showing all products:" << endl;
    for_each(orderProducts.begin(), orderProducts.end(), get_product_name_helper);

}

void Order::change_order_status(){

    cout << "You can change order status:" << endl << endl;
    cout << "1) CANCELLED" << endl;
    cout << "2) PROCESSING" << endl;
    cout << "3) COMPLETED" << endl;
    cout << "4) RECIEVED" << endl << endl;

    int status;

    cout << "Choose an option: ";

    cin >> status;

    if(status == 1)
        orderStatus = Cancelled;
    else if(status == 2)
        orderStatus = Processing;
    else if(status == 3)
        orderStatus = Completed;
    else
        orderStatus = Recieved;

    cout << "\nYou successfully change order status." << endl << endl;

}

void Order::cancel_order(){

    orderStatus = Cancelled;

    cout << "You have cancelled order." << endl << endl;
}

void Order::change_order_address(){

    cout << "You can change order address: " << endl << endl;

    string address;

    if(orderStatus == Recieved){
        cout << "Enter new address: ";
        cin.ignore();
        getline(cin, address);
        cout << "\n";
        orderAddress = address;
    } else {
        cout << "Your order is already processing. You can't change address.";
    }


}

void Order::subtract_product_from_order(){

    if(orderProducts.size() != 0){
        int i = 1;

        show_all_products();
        cout << "Select a product you want to delete: ";
        cin >> i;

        orderProducts.erase(orderProducts.begin() + i - 1);
    } else {
        cout << "Your order is empty" << endl;
    }


}

void Order::add_product_to_order(Product newProduct){
    orderProducts.push_back(newProduct);
}

void Order::add_product(vector<Product> products){
    for_each(products.begin(), products.end(), get_product_name_helper);
    int num = -1;

        cout << "Select a product you want to add: ";
        cin >> num;
        cout << endl;

        if(num <= 0 or num > products.size()){
            cout << "You have entered invalid value." << endl;
        } else {
            add_product_to_order(products[num-1]);
        }
}




