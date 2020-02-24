//
//  CustomerList.cpp
//  Assignment1
//
//  Created by Kevin Cruse on 2/20/20.
//  Copyright © 2020 Kevin Cruse. All rights reserved.
//

#include "CustomerList.h"
#include "EmployeeRecord.h"

// constructor
CustomerList::CustomerList() {
    std::cout << "Function reached 1\n";
    m_pHead = NULL;
}

// destructor
CustomerList::~CustomerList() {
    std::cout << "Function reached 2\n";
    Store *temp;
    while(m_pHead != NULL) {
        temp = m_pHead;
        m_pHead = m_pHead->m_pNext;
        delete temp;
    }
}

// this function takes a pointer to a Store object which already contains all data on a store. It inserts the Store object into the linked list in order, sorted by the store ID. It returns TRUE if the Store was successfully added to the list.
bool CustomerList::addStore(Store *s) {
    std::cout << "Function reached 3\n";
    Store *temp, *back, *newNode;
    newNode = new Store(*s);
    newNode->m_pNext = NULL;
    if (m_pHead == NULL) {
        m_pHead = newNode;
    }
    else {
        temp = m_pHead;
        back = NULL;
        while ((temp != NULL) && (temp->getStoreID() < s->getStoreID())) {
            back = temp;
            temp = temp->m_pNext;
        }
        if (back == NULL) {
            newNode->m_pNext = m_pHead;
            m_pHead = newNode;
        }
        else {
            back->m_pNext = newNode;
            newNode->m_pNext = temp;
        }
    }
    return true;
}

// this function takes an integer store ID as an argument. It searches the list, locates the Store object with that ID if one is present, removes it from the list and returns the Store object. The function returns NULL if it failed to find the Store in the list.
Store *CustomerList::removeStore(int ID) {
    std::cout << "Function reached 4\n";
    Store *temp, *back;
    temp = m_pHead;
    back = NULL;
    while((temp != NULL) && (ID != temp->getStoreID())) {
        back = temp;
        temp = temp->m_pNext;
    }
    if (temp != NULL) {
        if (back == NULL) {
            m_pHead = m_pHead->m_pNext;
            return temp;
        }
        else {
            back->m_pNext = temp->m_pNext;
            return temp;
        }
    }
    else {
        return NULL;
    }
}

// this function takes an integer store ID. It searches the list, locates the Store object, if present, and returns a pointer to the Store object. It returns NULL if the Store was not found in the list.
Store *CustomerList::getStore(int ID) {
    std::cout << "Function reached 5\n";
    Store *temp;
    temp = m_pHead;
    while ((temp != NULL) && (ID != temp->getStoreID())) {
        temp = temp->m_pNext;
    }
    if (temp != NULL) {
        Store *copy = new Store;
        *copy = *temp;
        copy->m_pNext = NULL;
        copy->printStoreInfo();
        return copy;
    }
    else {
        return NULL;
    }
}

// this function takes a list of arguments defining changes in the store data. The first argument gives the store ID. The remaining arguments are char arrays containing the new data on that store. The function searches the list and locates the store then updates all data for that store. The function returns TRUE if it successfully updated the data or FALSE if it failed to find the store.
bool CustomerList::updateStore(int ID, char *name, char *addr, char *city, char *st, char *zip) {
    std::cout << "Function reached 6\n";
    Store *temp;
    if (m_pHead == NULL) {
        return false;
    }
    temp = m_pHead;
    while ((temp != NULL) && (ID != temp->getStoreID())) {
        temp = temp->m_pNext;
    }
    if (temp != NULL) {
        temp->setStoreName(name);
        temp->setStoreAddress(addr);
        temp->setStoreCity(city);
        temp->setStoreState(st);
        temp->setStoreZip(zip);
    }
    else {
        return false;
    }
    return true;
}

// this function prints all data on each store in the list
void CustomerList::printStoresInfo() {
    std::cout << "Function reached 7\n";
    Store *temp;
    if (m_pHead == NULL) {
        std::cout << "List empty" << std::endl;
    }
    else {
        temp = m_pHead;
        while(temp != NULL) {
            temp->printStoreInfo();
            temp=temp->m_pNext;
        }
    }
}
