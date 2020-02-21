//
//  CustomerList.h
//  Assignment1
//
//  Created by Kevin Cruse on 2/20/20.
//  Copyright © 2020 Kevin Cruse. All rights reserved.
//

#pragma once
#include "Store.h"
#include <iostream>

class CustomerList {
private:
    Store *m_pHead;
public:
    CustomerList();
    ~CustomerList();
    CustomerList *getCustomerList();
    bool addStore(Store *s);
    Store *removeStore(int ID);
    Store *getStore(int ID);
    bool updateStore(int ID, char *name, char *addr, char *city, char *st, char *zip);
    void printStoresInfo();
};
