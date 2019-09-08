//
//  Store.h
//  store_backend
//
//  Created by Xiaoyu Wu on 10/31/18.
//  Copyright © 2018 Xiaoyu Wu. All rights reserved.
//

#ifndef Store_h
#define Store_h

#include "Product.h"
#include "Customer.h"
#include <string>

using namespace std;

class Store
{
private:
    string storeName;   //name of store
    vector<Product> products;   //product list
    vector<Customer> customers;   //customer list
public:
    //constructor
    Store();
    
    //constructor
    Store(string name);
    
    //a accessor function to get store name
    string getName() const;
    
    //a mutator function to set store name
    void setName(string name);
    
    //a mutator function to add new product to product
    void addProduct(int productID, string productName);
    
    //a accessor function to get product list
    Product& getProduct(int productID);
    
    //a mutator function to add new customer to customer(default credit is false)
    void addCustomer(int customerID, string customerName, bool credit=false);
    
    //a accessor function to get customer list
    Customer& getCustomer(int customerID);
    
    //a mutator function to fine matching product to take shipment
    void takeShipment(int productID, int quantity, double cost);
    
    //a mutator function to find matching customer to process payment
    void takePayment(int customerID, double amount);
    
    //a mutator function to sell product
    void sellProduct(int customerID, int productID, int quantity);
    
    //a accessor function to print product in product list
    string listProducts();
    
    //a accessor function to print customer in customer list
    string listCustomers();
    
};

#endif /* Store_h */
