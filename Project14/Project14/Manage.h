#pragma once
#ifndef __MANAGE_H__
#define __MANAGE_H__

#include "LibBase.h"
#include "NormalStudent.h"
#include "GoodStudent.h"

class Manage
{
private:
    vector<shared_ptr<Student>> v;
    int numberGoodStudent = 0;
    int numberNormalStudent = 0;

public:
    ~Manage();
    void addData();
    void delData(const string&);
    void findData(const string&);
    void showList();
    void showMemberData(const string&);
    void changeData(const string&);
    void recruitFunc(const int&);
    void showPassedGoodStudent(int, const int&);                         //nhap vao so luong sinh vien pass
    void showPassedNormalStudent(int, const int&);                       //nhap vao so luong sinh vien pass
    //void selectionSort();
};

#endif // !__MANAGE_H__
