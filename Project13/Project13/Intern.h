#pragma once
#ifndef __INTERN_H__
#define __INTERN_H__

#include "LibBase.h"
#include "Employee.h"

class Intern : public Employee
{
private:
	string Major;
	int Semester;
	string UniversityName;

public:
    void AddData();
    void ShowMe();
    void SetMajors(const string&);
    void SetSemester(const int&);
    void SetUniversity(const string&);
    string GetMajors();
    int GetSemester();
    string GetUniversity();
    ~Intern();
};

#endif // !__INTERN_H__
