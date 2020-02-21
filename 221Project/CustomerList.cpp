//
//  CustomerList.cpp
//  Assignment1
//
//  Created by Kevin Cruse on 2/20/20.
//  Copyright © 2020 Kevin Cruse. All rights reserved.
//

#include "CustomerList.h"
#include "EmployeeRecord.h"

CustomerList::CustomerList() {
    std::cout << "Function reached 1\n";
    m_pHead = NULL;
}
CustomerList::~CustomerList() {
    std::cout << "Function reached 2\n";
    Store *temp;
    while(m_pHead != NULL) {
        temp = m_pHead;
        m_pHead = m_pHead->m_pNext;
        delete temp;
    }
}

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
