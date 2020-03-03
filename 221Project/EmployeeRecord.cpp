//
//  EmployeeRecord.cpp
//  221Project
//
//  Created by Kevin Cruse on 2/1/20.
//  Copyright © 2020 Kevin Cruse. All rights reserved.
//
// This a database of all of a company's sales representatives
// This database is capable of maintaining the employee ID, employee name, department, and annual salary of each sales representative

#define _CRT_SECURE_NO_WARNINGS
#include "EmployeeRecord.h"
#include "CustomerList.h"
#include <iostream>
#include <string>

// default constructor
EmployeeRecord::EmployeeRecord() {
    std::cout << "Function reached 1\n";
    m_iEmployeeID = 0;
    strcpy(m_sLastName, "");
    strcpy(m_sFirstName, "");
    m_iDeptID = 0;
    m_dSalary = 0;
    m_pCustomerList = new CustomerList();
}
// parameterized constructor
EmployeeRecord::EmployeeRecord(int ID, char *fName, char *lName, int dept, double sal) {
    std::cout << "Function reached 2\n";
    m_iEmployeeID = ID;
    strcpy(m_sFirstName, fName);
    strcpy(m_sLastName, lName);
    m_iDeptID = dept;
    m_dSalary = sal;
    m_pCustomerList = new CustomerList();
}
// destructor
EmployeeRecord::~EmployeeRecord() {
    std::cout << "Function reached 3\n";
    while(m_pCustomerList != NULL) {
        delete m_pCustomerList;
    }
}

// getter function for the employee's id
int EmployeeRecord::getID() {
    std::cout << "Function reached 4\n";
    return m_iEmployeeID;
}

// setter function for the employee's id
void EmployeeRecord::setID(int ID) {
    std::cout << "Function reached 5\n";
    m_iEmployeeID = ID;
}

// getter function for the employee's name
void EmployeeRecord::getName(char *fName, char *lName) {
    std::cout << "Function reached 6\n";
    // copying the member variables into the pointers in the function args
    strcpy(fName, m_sFirstName);
    strcpy(lName, m_sLastName);
}

// setter function for the employee's name
void EmployeeRecord::setName(char *fName, char *lName) {
    std::cout << "Function reached 7\n";
    // copying the function arguments into the member variables
    strcpy(m_sFirstName, fName);
    strcpy(m_sLastName, lName);
}

// reference function, getter for dept id
int EmployeeRecord::getDept() {
    std::cout << "Function reached 8\n";
    // returns department id
    return m_iDeptID;
}

// setter for dept id
void EmployeeRecord::setDept(int d) {
    std::cout << "Function reached 9\n";
    // copying the function argument into the member variable m_iDeptID
    m_iDeptID = d;
}

// pointer function, getter for employee's salary
double EmployeeRecord::getSalary() {
    std::cout << "Function reached 10\n";
    // returns salary
    return m_dSalary;
}

// setter for employee's salary
void EmployeeRecord::setSalary(double sal) {
    std::cout << "Function reached 11\n";
    // copying the function argument into the member variable m_dSalary
    m_dSalary = sal;
}

// this function prints all of the employee's information
void EmployeeRecord::printRecord() {
    std::cout << "Function reached 12\n";
    std::cout << "Employee ID: " << m_iEmployeeID << std::endl;
    std::cout << "Last name: " << m_sLastName << std::endl;
    std::cout << "First name: " << m_sFirstName << std::endl;
    std::cout << "Department ID: " << m_iDeptID << std::endl;
    std::cout << "Salary: " << m_dSalary << std::endl;
}

// returns the pointer to the EmployeeRecord's CustomerList object
CustomerList *EmployeeRecord::getCustomerList() {
    return m_pCustomerList;
}
