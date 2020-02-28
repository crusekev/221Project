//
//  Store.h
//  221Project
//
//  Created by Kevin Cruse on 2/19/20.
//  Copyright © 2020 Kevin Cruse. All rights reserved.
//

#pragma once

#include <string.h>
#include <iostream>

using namespace std;

class Store
{
    private:
        int m_iStoreID;
        char m_sStoreName[64];
        char m_sAddress[64];
        char m_sCity[32];
        char m_sState[32];
        char m_sZip[11];

    public:
        Store *m_pNext;
        Store(); // Default constructor
        Store(int ID, char *name, char *addr, char *city, char *st, char *zip); // Constructor
        ~Store(); // Destructor
        int getStoreID(); // Get/Set store ID
        void setStoreID(int ID);
        char *getStoreName(); // Get/Set store name
        void setStoreName(char *name);
        char *getStoreAddress(); // Get/Set store address
        void setStoreAddress(char *addr);
        char *getStoreCity(); // Get/Set store city
        void setStoreCity(char *city);
        char *getStoreState(); // Get/Set store state
        void setStoreState(char *state);
        char *getStoreZip(); // Get/Set store zip code
        void setStoreZip(char *zip);
        void printStoreInfo(); // Print all info on this store
};
