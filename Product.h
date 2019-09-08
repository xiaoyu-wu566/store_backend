//
//  Product.h
//  store_backend
//
//  Created by Xiaoyu Wu on 10/31/18.
//  Copyright © 2018 Xiaoyu Wu. All rights reserved.
//

#ifndef Product_h
#define Product_h

#include <string>
#include <iostream>
using namespace std;

class Product
{
private:
    //members of product:
    int id;
    int inventory;
    int numSold;
    string name;
    string description;
    double totalPaid;
public:
    //constructor
    Product(int productID, string productName);
    
    //accessor function to get product ID
    int getID() const;
    
    //accessor function to get product name
    string getName() const;
    
    //mutator function to set product name
    void setName(string newName);
    
    //accessor function to get product description
    string getDescription() const;
    
    //mutator function to set description
    void setDescription(string newDescription);
    
    //accessor function to get number of sold
    int getNumberSold() const;
    
    //accessor function to get total paid
    double getTotalPaid() const;
    
    //accessor function to get inventory
    int getInventoryCount() const;
    
    //a mutator member function to add shipment
    void addShipment(int shipmentQuantity, double shipmentCost);
    
    //a mutator member function to reduce inventory
    void reduceInventory(int purchaseQuantity);
    
    //a accessor function to get price
    double getPrice() const;
};

// a overloading<< function to print product's member(ID, name...)
ostream& operator<<(ostream& os, Product& p);

#endif /* Product_h */
