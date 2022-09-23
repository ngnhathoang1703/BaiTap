#pragma once
#ifndef __STUDENT_H
#define __STUDENT_H

#include "LibBase.h"
#include "Exception.h"

class Student {
    string fullName;
    string DoB;
    gender sex;
    string phoneNumber;
    string univerName;
    level gradeLevel;
public:
    int STT;
    virtual ~Student() {}
    void setFullName(const string&);
    void setDoB(const string&);
    void setGender(const gender&);
    void setPhone(const string&);
    void setUni(const string&);
    void setLevel(const level&);
    string getFullName();
    string getDoB();
    gender getSex();
    string getPhone();
    string getUni();
    level getLevel();

    bool checkName(const string&);
    bool checkDate(const string&);
    bool checkPhone(const string&);

    virtual void addData();
    virtual void showInfo();
};

#endif // !__STUDENT_H
