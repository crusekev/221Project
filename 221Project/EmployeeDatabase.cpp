//
//  EmployeeDatabase.cpp
//  221Project
//
//  Created by Kevin Cruse on 3/19/20.
//  Copyright © 2020 Kevin Cruse. All rights reserved.
//

#include "EmployeeDatabase.h"
#include "CustomerList.h"
#include "Store.h"
#include "EmployeeRecord.h"

// Default constructor
EmployeeDatabase::EmployeeDatabase() {
    std::cout << "Constructor function reached\n";
    m_pRoot = NULL;
    return;
}

// Destructor
EmployeeDatabase::~EmployeeDatabase() {
    std::cout << "Destructor function reached\n";
    destroyTree(m_pRoot);
    return;
}

//  This function will take a pointerto a completed EmployeeRecord object and insert the object into the binary tree
bool EmployeeDatabase::addEmployee(EmployeeRecord *e) {
    std::cout << "addEmployee function reached\n";
    EmployeeRecord *temp, *back;
    temp = m_pRoot;
    back = NULL;
    while(temp != NULL) {
        back = temp;
        if(e->getID() < temp->getID()) {
            temp = temp->m_pLeft;
        }
        else {
            temp = temp->m_pRight;
        }
        if(back == NULL) {
            m_pRoot = e;
        }
        else {
            if(e->getID() < back->getID()) {
                back->m_pLeft = e;
            }
            else {
                back->m_pRight = e;
            }
        }
    }
    return true;
}

// This function will take an employee ID as an argument. It will search the tree and return a pointer to the employee whose ID matches the function argument. It will return NULL if it fails to find the employee in the tree
EmployeeRecord *EmployeeDatabase::getEmployee(int ID) {
    std::cout << "getEmployee function reached\n";
    EmployeeRecord *temp;
    temp = m_pRoot;
    while((temp != NULL) && (temp->getID() != ID)) {
        if(ID < temp->getID()) {
            temp = temp->m_pLeft;
        }
        else {
            temp = temp->m_pRight;
        }
    }
    if(temp == NULL) {
        return NULL;
    }
    else {
        return DupNode(temp);
    }
}

// This function will take an employee ID as an argument. It will search the tree, locate (if it exists) the employee record, remove it from the tree and return it. It will return NULL if it failed to find the employee. Note, care must be taken when the EmployeeRecord removed has twochildren. See the notes below on how to handle this occurance. NOTE: This function was not properly tested and probably has errors when deleting a node that has two children
EmployeeRecord *EmployeeDatabase::removeEmployee(int ID) {
    std::cout << "removeEmployee function reached\n";
    EmployeeRecord *temp, *back, *delParent, *delNode;
    temp = m_pRoot;
    back = NULL;
    // Find the node to delete
    while((temp != NULL) && (ID != temp->getID())) {
        back = temp;
        if(ID < temp->getID()) {
            temp = temp->m_pLeft;
        }
        else {
            temp = temp->m_pRight;
        }
    }
    // Didn't find the one to delete
    if(temp == NULL) {
        return NULL;
    }
    else {
        // Use these pointers in case we need to reuse temp and back below
        delNode = temp;
        delParent = back;
    }
    // Case 1: Deleting node with no children or one child
    if(delNode->m_pRight == NULL) {
        // If deleting root
        if(delParent == NULL) {
            m_pRoot = delNode->m_pLeft;
            delNode->m_pLeft = NULL;
            return delNode;
        }
        else {
            if(delParent->m_pLeft == delNode) {
                delParent->m_pLeft = delNode->m_pLeft;
            }
            else {
                delParent->m_pRight = delNode->m_pLeft;
            }
            delNode->m_pLeft = NULL;
            return delNode;
        }
    }
    // There is at least one child
    else {
        // Only 1 child and it is on the right
        if(delNode->m_pLeft == NULL) {
            // Deleting the root
            if(delParent == NULL) {
                m_pRoot = delNode->m_pRight;
                delNode->m_pRight = NULL;
                return delNode;
            }
            else {
                if(delParent->m_pLeft == delNode) {
                    delParent->m_pLeft = delNode->m_pRight;
                }
                else {
                    delParent->m_pRight = delNode->m_pRight;
                }
                delNode->m_pRight = NULL;
                return delNode;
            }
        }
        // Deleting node with two children
        else {
            // Make a copy of the node to be "deleted" for returning after overwriting delNode
            EmployeeRecord *retNode = DupNode(delNode);
            retNode->destroyCustomerList();
            // Find the replacement value. Locate the node containing the largest value smaller than the key of the node to be deleted
            temp = delNode->m_pLeft;
            back = delNode;
            while(temp->m_pRight != NULL) {
                back = temp;
                temp = temp->m_pRight;
            }
            // Copy the replacement values into the node to be "deleted"
            char *fName = new char[32];
            char *lName = new char[32];
            m_pRoot->getName(fName, lName);
            delNode = new EmployeeRecord(m_pRoot->getID(), fName, lName, m_pRoot->getDept(), m_pRoot->getSalary());
            m_pRoot->getCustomerList();
            m_pRoot->removeCustomerList();
            // Remove the replacement node from the tree
            if(back == delNode) {
                back->m_pLeft = delNode->m_pLeft;
            }
            else {
                back->m_pRight = temp->m_pLeft;
            }
            delete temp; // Dispose of this node
            return retNode; // Return the copy
        }
    }
}

// This function shall call the private printEmployeeRecords() function passing in the root of the tree. This shall initialize a recursive traversal to print all records in the tree
void EmployeeDatabase::printEmployeeRecords() {
    std::cout << "printEmployeeRecords() function reached\n";
    printEmployeeRecords(m_pRoot);
}

// This function shall take a char array specifying the name of the data file. It will read and build the database. This functionis provided by the instructor
 bool EmployeeDatabase::buildDatabase(char *dataFile) {
    std::cout << "buildDatabase function reached\n";
    bool OK = true;
    int numEmp, id, dept, numStores, sID;
    double sal;
    EmployeeRecord *empRec;
    CustomerList *theList;
    Store *theStore;
    char inStr[128];
    char fName[32];
    char lName[32];
    char sName[64];
    char sAddr[64];
    char sSt[32];
    char sCity[32];
    char sZip[12];
    

    inFile.open(dataFile, ifstream::in);
    if(!inFile.is_open())
    {
        // inFile.is_open() returns false if the file could not be found or
        //    if for some other reason the open failed.
        cout << "Unable to open file" << dataFile << "\nProgram terminating...\n";
        cout << "Press Enter to continue...";
        getc(stdin);
        return false;
    }

    // Get number of employees
    getNextLine(inStr, 128);
    numEmp = atoi(inStr);
    for(int i=0; i<numEmp; i++)
    {
        // Instantiate an EmployeeRecord
        empRec = new EmployeeRecord();
        // Read and set the ID
        getNextLine(inStr, 128);
        id = atoi(inStr);
        empRec->setID(id);
        // Read and set the name
        getNextLine(fName, 32);
        getNextLine(lName, 32);
        empRec->setName(fName, lName);
        // Read and set the Department ID
        getNextLine(inStr, 128);
        dept = atoi(inStr);
        empRec->setDept(dept);
        // Read and set the Salary
        getNextLine(inStr, 128);
        sal = atof(inStr);
        empRec->setSalary(sal);
        // Get the customer list
        theList = empRec->getCustomerList();
        // Get the number of stores
        getNextLine(inStr, 128);
        numStores = atoi(inStr);
        for(int j=0; j<numStores; j++)
        {
            // Read the store ID
            getNextLine(inStr, 128);
            sID = atoi(inStr);
            // Read the store name
            getNextLine(sName, 64);
            // Read the store address
            getNextLine(sAddr, 64);
            // Read the store city
            getNextLine(sCity, 32);
            // Read the store state
            getNextLine(sSt, 32);
            // Read the store zip
            getNextLine(sZip, 11);
            // Create a new Store object
            theStore = new Store(sID, sName, sAddr, sCity, sSt, sZip);
            theList->addStore(theStore);
        }
        cout.flush();
        addEmployee(empRec);
    }
    inFile.close();
    return true;    // Successfully built the database
}

bool EmployeeDatabase::getNextLine(char *line, int lineLen) {
    std::cout << "getNextLine function reached\n";
    int    done = false;
    while(!done)
    {
        inFile.getline(line, 128);
        
        if(inFile.good())    // If a line was successfully read
        {
            if(strlen(line) == 0)  // Skip any blank lines
                continue;
            else if(line[0] == '#')  // Skip any comment lines
                continue;
            else return true;    // Got a valid data line so return with this line
        }
        else
        {
            strcpy(line, "");
            return false;
        }
    } // end while
    return false;
}

// This function overloads the public printEmployeeRecords() function and shall perform an in-order recursive traversal of the entire tree and print all data on all employees in the database
void EmployeeDatabase::printEmployeeRecords(EmployeeRecord *rt) {
    std::cout << "printEmployeeRecords(EmployeeRecord *rt) function reached\n";
    if(rt != NULL) {
        printEmployeeRecords(rt->m_pLeft);
        rt->printRecord();
        printEmployeeRecords(rt->m_pRight);
    }
}

// This function shall recursively traverse the entire tree and delete all nodes in the tree
void EmployeeDatabase::destroyTree(EmployeeRecord *rt) {
    std::cout << "destroyTree function reached\n";
    if(rt == NULL) {
        return;
    }
    if(rt->m_pLeft != NULL) {
        destroyTree(rt->m_pLeft);
    }
    if(rt->m_pRight != NULL) {
        destroyTree(rt->m_pRight);
    }
    delete rt;
    return;
}

// Duplicate a node in the tree.  This is used to allow returning a complete structure from the tree without giving        access into the tree through the pointers
EmployeeRecord *EmployeeDatabase::DupNode(EmployeeRecord *rt) {
    std::cout << "DupNode function reached\n";
    EmployeeRecord *dupNode = new EmployeeRecord();
    *dupNode = *rt;
    dupNode->m_pLeft = NULL;
    dupNode->m_pRight = NULL;
    return dupNode;
}
