//
//  CustomerList.h
//  221Project
//
//  Created by Kevin Cruse on 2/20/20.
//  Copyright © 2020 Kevin Cruse. All rights reserved.
//

#pragma once
#include "Store.h"
#include <iostream>

// this class defines and maintains an ordered linked list of instances of the class Store
class CustomerList {
private:
    Store *m_pHead; // pointer to a class of type CustomerList
public:
    CustomerList(); // constructor
    ~CustomerList(); // destructor
    CustomerList *getCustomerList();
    bool addStore(Store *s); // adds a store to the list
    Store *removeStore(int ID); // removes store from the list
    Store *getStore(int ID); // get a store from the list
    bool updateStore(int ID, char *name, char *addr, char *city, char *st, char *zip); // update a store in the list
    void printStoresInfo(); // this function prints all data on each store in the list
};
