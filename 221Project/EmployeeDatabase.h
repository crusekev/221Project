//
//  EmployeeDatabase.h
//  221Project
//
//  Created by Kevin Cruse on 3/19/20.
//  Copyright © 2020 Kevin Cruse. All rights reserved.
//

#pragma once
#include "EmployeeRecord.h"
#include <fstream>

class EmployeeDatabase {
private:
    EmployeeRecord *m_pRoot;
    std::ifstream inFile;
    void printEmployeeRecords(EmployeeRecord *rt);
    void destroyTree(EmployeeRecord *rt);
public:
    EmployeeDatabase();
    ~EmployeeDatabase();
    bool addEmployee(EmployeeRecord *e);
    EmployeeRecord *getEmployee(int ID);
    EmployeeRecord *removeEmployee(int ID);
    void printEmployeeRecords();
    bool buildDatabase(char *dataFile);
    bool getNextLine(char *line, int lineLen);
    EmployeeRecord *DupNode(EmployeeRecord *rt);
};
