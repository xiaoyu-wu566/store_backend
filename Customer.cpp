//
//  Customer.cpp
//  store_backend
//
//  Created by Xiaoyu Wu on 10/31/18.
//  Copyright © 2018 Xiaoyu Wu. All rights reserved.
//

#include "Customer.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

Customer::Customer(int customerID, string customerName, bool customerCredit)
{
    if(customerName == "")
    {
        throw runtime_error("error2");
    }
    else
    {
        id = customerID;
        name = customerName;
        balance = 0.0;
        credit = customerCredit;
        vector<Product> productsPurchased = {};
    }
}

int Customer::getID() const
{
    return id;
}

string Customer::getName() const
{
    return name;
}

void Customer::setName(string newName)
{
    if(newName == "")
    {
        throw runtime_error("error3");
    }
    else
    {
        name = newName;
    }
}

bool Customer::getCredit() const
{
    return credit;
}

void Customer::setCredit(bool hasCredit)
{
    credit = hasCredit;
}

double Customer::getBalance() const
{
    return balance;
}

void Customer::processPayment(double amount)
{
    if (amount < 0)
    {
        throw runtime_error("error");
    }
    else
    {
        balance = balance + amount;
    }
}

void Customer::processPurchase(double amount, Product product)
{
    if(amount < 0)
    {
        throw runtime_error("error");
    }
    else
    {
        if(credit == true)
        {
            balance = balance - amount;
        }
        else
        {
            if (balance >= amount)
            {
                balance = balance - amount;
            }
            else
            {
                throw runtime_error("error");
            }
        }
        //cout << id << " " << balance << endl;
        productsPurchased.push_back(product);
    }
}

string Customer::getProductsPurchased() const
{
    string productNameAndID = "";
    for(int i = 0; i < productsPurchased.size(); ++i)
    {
        productNameAndID = productNameAndID + "Product Name: " + productsPurchased.at(i).getName()
        + '\n' + "Product ID: " + to_string(productsPurchased.at(i).getID()) + '\n' + '\n';
    }
    return productNameAndID;
}

ostream& operator<<(ostream& os, Customer c)
{
    os << "Customer Name: " << c.getName() << endl;
    os << "Customer ID: " << c.getID() << endl;
    if(c.getCredit() == 1)
    {
        os << "Has Credit: true" << endl;
    }
    else
    {
        os << "Has Credit: false" << endl;
    }
    os << "Balance: " << c.getBalance() << endl;
    os << "Products Purchased --" << endl << endl;
    os << c.getProductsPurchased();
    return os;
}
