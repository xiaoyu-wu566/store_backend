//
//  Store.cpp
//  store_backend
//
//  Created by Xiaoyu Wu on 10/31/18.
//  Copyright © 2018 Xiaoyu Wu. All rights reserved.
//

#include "Store.h"
#include "Product.h"
#include <string>
#include <vector>
#include <sstream>

using namespace std;

Store::Store()
{
    storeName = "";
    products = {};
    customers = {};
}

Store::Store(string name)
{
    storeName = name;
    products = {};
    customers = {};
}

string Store::getName() const
{
    return storeName;
}

void Store::setName(string name)
{
    storeName = name;
}

void Store::addProduct(int productID, string productName)
{
    for(int i = 0; i < products.size(); ++i)
    {
        if(products.at(i).getID() == productID || products.at(i).getName() == productName)
        {
            throw runtime_error("have already exist");
        }
    }
    Product addP(productID, productName);
    products.push_back(addP);
}

Product& Store::getProduct(int productID)
{
    for(int i = 0; i < products.size(); ++i)
    {
        if(products.at(i).getID() == productID)
        {
            return products.at(i);
        }
    }
    throw runtime_error("error: no matching!!");
}

void Store::addCustomer(int customerID, string customerName, bool credit)
{
    for(int i = 0; i < customers.size(); ++i)
    {
        if(customers.at(i).getName() == customerName || customers.at(i).getID() == customerID)
        {
            throw runtime_error("customer have already exist");
        }
    }
    Customer addC(customerID, customerName, credit);
    customers.push_back(addC);
}

Customer& Store::getCustomer(int customerID)
{
    for(int i = 0; i < customers.size(); ++i)
    {
        if(customers.at(i).getID() == customerID)
        {
            return customers.at(i);
        }
    }
    throw runtime_error("error: no matching..!");
}

void Store::takeShipment(int productID, int quantity, double cost)
{
    for(int i = 0; i < products.size(); ++i)
    {
        if(products.at(i).getID() == productID)
        {
            products.at(i).addShipment(quantity, cost);
            return;
        }
    }
    throw runtime_error("error: no matching?!");
}

void Store::takePayment(int customerID, double amount)
{
    for(int i = 0; i < customers.size(); ++i)
    {
        if(customers.at(i).getID() == customerID)
        {
            customers.at(i).processPayment(amount);
            return;
        }
    }
    throw runtime_error("error: no matching...!");
}

void Store::sellProduct(int customerID, int productID, int quantity)
{
    Customer& c = getCustomer(customerID);
    Product& p = getProduct(productID);
    p.reduceInventory(quantity);
    double amount = p.getPrice() * quantity;
    c.processPurchase(amount, p);
}

string Store::listProducts()
{
        stringstream ss;
        for(int i = 0; i < products.size(); ++i)
        {
            ss << products.at(i) << endl;
        }
        string listp = ss.str();
        return listp;
}

string Store::listCustomers()
{
    stringstream ss;
    for(int i = 0; i < customers.size(); ++i)
    {
        ss << customers.at(i) << endl;
    }
    string listc = ss.str();
    return listc;
}
