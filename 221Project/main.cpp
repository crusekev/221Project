//
//  main.cpp
//  221Project
//
//  Created by Kevin Cruse on 2/1/20.
//  Copyright © 2020 Kevin Cruse. All rights reserved.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string>
#include "EmployeeRecord.h"
#include "Store.h"
#include "CustomerList.h"

int main() {
//    EmployeeRecord *rec1 = new EmployeeRecord();
//    char fName[32];
//    char lName[32];
//    EmployeeRecord *rec2 = new EmployeeRecord(1234, fName, lName, 4321, 100000);
//    EmployeeRecord *employeeRecord = new EmployeeRecord;
//    employeeRecord->getName(fName, lName);
//    employeeRecord->setName(fName, lName);
//    double salary = 100;
//    int dept = 123;
//    EmployeeRecord employee;
//    employee.getSalary();
//    employee.setSalary(salary);
//    employee.getDept();
//    employee.setDept(dept);
//    employee.printRecord();
//    char fName[32], lName[32];
//    Store *pointer1 = new Store(59, "Friendly", "2402 Viking", "Jasper", "Al", "35501");
//    Store *pointer2 = new Store(198, "ZedHead", "225 Georgia", "Jasper", "Al", "35504");
//    Store *pointer3 = new Store(46, "Ranner", "6500 Walden", "Huntsville", "Al", "35806");
//    EmployeeRecord *rec1 = new EmployeeRecord();
//    rec1->getCustomerList()->addStore(pointer1);
//    rec1->getCustomerList()->addStore(pointer2);
//    rec1->getCustomerList()->addStore(pointer3);
//    rec1->getCustomerList()->printStoresInfo();
//    rec1->getCustomerList()->updateStore(59, "FAS", "2402 Viking", "Jasper", "Al", "35501");
//    rec1->getCustomerList()->printStoresInfo();
//    rec1->getCustomerList()->getStore(46);
//    rec1->getCustomerList()->removeStore(46);
//    rec1->getCustomerList()->printStoresInfo();
//    rec1->setName((char *)"John", (char *)"Doe");
//    cout.flush();
//    // Test getName()
//    cout << "Testing getName(). " ;
//    rec1->getName(fName, lName);
//    cout << "Result = " << fName << " " << lName << "\n";
//    if((strcmp(fName, "John") == 0) && (strcmp(lName, "Doe") == 0))
//        cout << "getName appears to work.\n";
//    else
//        cout << "Failed to retrieve correct employee name.\n";
    
    CustomerList *StoreList;
    Store *myStore;

    StoreList = new CustomerList;

    Store *ptr1 = new Store(59, "Friendly", "2402 Viking", "Jasper", "Al", "35501");
    Store *ptr2 = new Store(198, "ZedHead", "225 Georgia", "Jasper", "Al", "35504");
    Store *ptr3 = new Store(46, "Ranner", "6500 Walden", "Huntsville", "Al", "35806");

    StoreList->addStore(ptr1);
    StoreList->addStore(ptr2);
    StoreList->addStore(ptr3);

    StoreList->printStoresInfo();

    cout << "\nChanging Fridendly to FAS" << endl;

    StoreList->updateStore(59, "FAS", "2402 Viking", "Jasper", "Al", "35501");

    StoreList->printStoresInfo();

    cout << "\nGetting store 46" << endl;

    StoreList->getStore(46);

    cout << "\n Deleteing 46" << endl;

    StoreList->removeStore(46);

    StoreList->printStoresInfo();

    StoreList->~CustomerList();
    return 0;
}
