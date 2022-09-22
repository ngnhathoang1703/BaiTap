#pragma once
#ifndef __MANAGE_H__
#define __MANAGE_H__

#include "Experience.h"
#include "Intern.h"
#include "Fresher.h"

class Manage 
{
private:
    vector<Employee*> v;
public:
    ~Manage();
    void AddMem();
    void ShowList(const int&);
    void ChangeData(const string&);
    void RemoveEmployee(const string&);
    void FindData(const string&);
    bool CheckSameID();
    void AddCertificater(const string&);
    void ShowCertifi(const string&);
};

#endif