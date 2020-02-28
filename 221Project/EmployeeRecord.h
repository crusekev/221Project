//
//  EmployeeRecord.cpp
//  221Project
//
//  Created by Kevin Cruse on 2/1/20.
//  Copyright © 2020 Kevin Cruse. All rights reserved.
//
// This a database of all of a company's sales representatives
// This database is capable of maintaining the employee ID, employee name, department, and annual salary of each sales representative

#pragma once
#include "CustomerList.h"

class EmployeeRecord {
private:
    int m_iEmployeeID; // stores the employee's id as an int
    char m_sLastName[32]; // an array of the employee's last name
    char m_sFirstName[32]; // an array of the employee's first name
    int m_iDeptID; // stores the employee's department id as an int
    double m_dSalary; // stores the employee's salary as a double
    CustomerList *m_pCustomerList;
public:
    EmployeeRecord(); // default constructor
    EmployeeRecord(int ID, char *fName, char *lName, int dept, double sal); // parameterized constructor
    ~EmployeeRecord(); // destructor
    int getID();
    void setID(int ID);
    void getName(char *fName, char *lName);
    void setName(char *fName, char *lName);
    int getDept();
    void setDept(int d);
    double getSalary();
    void setSalary(double sal);
    void printRecord();
    CustomerList *getCustomerList(); // returns the pointer to the EmployeeRecord's CustomerList object
};
