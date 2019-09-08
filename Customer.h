//
//  Customer.h
//  store_backend
//
//  Created by Xiaoyu Wu on 10/31/18.
//  Copyright © 2018 Xiaoyu Wu. All rights reserved.
//

#ifndef Customer_h
#define Customer_h

#include "Product.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Customer
{
private:
    //members of customer:
    int id;
    string name;
    bool credit;
    double balance;
    vector<Product> productsPurchased;  // a list of purchased products
public:
    //constructor
    Customer(int customerID, string customerName, bool customerCredit=false);
    
    //a accessor function to get customer ID
    int getID() const;
    
    //a accessor function to get customer name
    string getName() const;
    
    //a mutator function to set customer name
    void setName(string newName);
    
    //a accessor function to get true: has credit/ false: do not have credit
    bool getCredit() const;
    
    //a mutator function to set if customer has credit or not
    void setCredit(bool hasCredit);
    
    //a accessor function to get balance
    double getBalance() const;
    
    //a mutator function to process payment
    void processPayment(double amount);
    
    //a mutator function to process purchase
    void processPurchase(double amount, Product product);
    
    //a accessor function to get product purchased list
    string getProductsPurchased() const;
};

// an overloading<< function to print customer's members(ID, name...)
ostream& operator<<(ostream& os, Customer c);

#endif /* Customer_h */
