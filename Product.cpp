//
//  Product.cpp
//  store_backend
//
//  Created by Xiaoyu Wu on 10/31/18.
//  Copyright © 2018 Xiaoyu Wu. All rights reserved.
//

#include "Product.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

Product::Product(int productID, string productName)
{
    id = productID;
    if (productName == "")
    {
        throw runtime_error("error1");
    }
    else{
        name = productName;
    }
    inventory = 0;
    numSold = 0;
    totalPaid = 0.0;
    description = "";
}

int Product::getID() const
{
    return id;
}

string Product::getName() const
{
    return name;
}

void Product::setName(string newName)
{
    if(newName == "")
    {
        throw runtime_error("error");
    }
    else{
        name = newName;
    }
}

string Product::getDescription() const
{
    return description;
}

void Product::setDescription(string newDescription)
{
    description = newDescription;
}

int Product::getNumberSold() const
{
    return numSold;
}

double Product::getTotalPaid() const
{
    return totalPaid;
}

int Product::getInventoryCount() const
{
    return inventory;
}

void Product::addShipment(int shipmentQuantity, double shipmentCost)
{
    if(shipmentQuantity < 0 || shipmentCost < 0)
    {
        throw runtime_error("error");
    }
    else{
        inventory = inventory + shipmentQuantity;
        totalPaid = totalPaid + shipmentCost;
    }
}

void Product::reduceInventory(int purchaseQuantity)
{
    if(inventory < purchaseQuantity || purchaseQuantity < 0)
    {
        throw runtime_error("error in reduceInventory");
    }
    else{
        inventory = inventory - purchaseQuantity;
        numSold = numSold + purchaseQuantity;
    }
//    cout << "reduceInv" << endl;
//    cout << name << " " << inventory << " " << numSold << endl;
}

double Product::getPrice() const
{
    double price;
    const double makeUp = 1.25;
    if (inventory + numSold <= 0)
    {
        throw runtime_error("Price: Unavailable");
    }
    price = (totalPaid / (inventory + numSold)) * makeUp;
    return price;
}

ostream& operator<< (ostream& os, Product& p)
{
    os << "Product Name: " << p.getName() << endl;
    os << "Product ID: " << p.getID() << endl;
    os << "Description: " << p.getDescription() << endl;
    os << "Inventory: " << p.getInventoryCount() << endl;
    os << "Number Sold: " << p.getNumberSold() << endl;
    os << "Total Paid: " << p.getTotalPaid() << endl;
    try
    {
        os << "Price: " << p.getPrice() << endl;
    }
    catch(runtime_error &e)
    {
        os << e.what() << endl;
    }
    return os;
}
