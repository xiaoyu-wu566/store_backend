//
//  main.cpp
//  store_backend
//
//  Created by Xiaoyu Wu on 10/31/18.
//  Copyright © 2018 Xiaoyu Wu. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
#include "Product.h"
#include "Customer.h"
#include "Store.h"

using namespace std;

int main() {
    string s = "Clueless";
    Product p(123, s);
    try
    {
        
//
//        p.setDescription("This does some fun stuff.");
//        p.setName("Knowing");
//        p.addShipment(155, 1317.5);
//        p.addShipment(200, 500);
//        p.reduceInventory(175);
//        //p.reduceInventory(-1);;
////        cout << "here" << endl;
//        //p.reduceInventory(181);
//        //cout << p << endl;
//        p.addShipment(1000, 100);
//        p.reduceInventory(500);
//        stringstream ss;
//        ss << p;
//        //cout << p;
//        Customer c1(987,"Ms Jackson",true);
//        Customer c2(725,"Newt Salamander");
//        c1.setCredit(false);
//        c2.setCredit(true);
//        c1.setName("Miss Reveille");
//        c2.setName("Ole Sarge");
//        c1.processPayment(5);
//        c1.processPayment(30);
//        //c1.processPayment(-15);
//        Product p(555,"Widget Gidget");
//        p.addShipment(50, 50);
//        c2.processPurchase(25,p);
//        c1.processPurchase(25,p);
//        c1.processPurchase(25,p);
//        cout << c1;
//        cout << c2;
        Store s;
//        cout << s.getName() << endl;
//        Store s2("Things to Buy");
//        cout << s2.getName() << endl;
        s.addProduct(123,"towel");
        s.getProduct(123).setDescription("For drying.");
       // s.addProduct(234,"mask");
//        s.getProduct(234).setDescription("For hiding.");
        //s.getProduct(555);
       // s.addCustomer(789, "Jane Grooves");
        s.takeShipment(123,200,400);
        //s.takeShipment(555,2,-2);
        s.addCustomer(987,"Joe Blockhead",true);
        s.takePayment(987,600);
        s.sellProduct(987,123,10);
//        cout << s.listProducts() << endl;
        Store s2;
        s2.addProduct(234,"mask");
        cout << s2.listProducts() << endl;
//        Store s1;
//        cout << s1.listProducts() << endl;
        //s.takePayment(555,25);
        //s.getCustomer(555);
//        cout << "start main after" << endl;
//        cout << s.getCustomer(987).getID() << endl;
//        cout << s.getCustomer(987).getName() << endl;
//        cout << s.getCustomer(987).getCredit() << endl;
//        cout << s.getCustomer(987).getBalance() << endl;
//        cout << s.getCustomer(987).getProductsPurchased() << endl;
//
//        cout << s.getProduct(123).getID() << endl;
//        cout << s.getProduct(123).getName() << endl;
//        cout << s.getProduct(123).getInventoryCount()<< endl;
//        cout << s.getProduct(123).getTotalPaid() << endl;
//        cout << s.getProduct(123).getNumberSold() << endl;
//        cout << s.getProduct(123).getDescription() << endl;

//        cout << p << endl;
    } catch (runtime_error& e) {
        cout << e.what() << endl;
        cout << "error caught"<<endl;
    }
    //cout << p << endl;
//    Product p2(283,"Something");
//    cout << p2 << endl;
//    p.addShipment(1000, 100);
//    p.reduceInventory(500);
//    cout << p << endl;
    return 0;
}
