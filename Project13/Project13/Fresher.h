#pragma once
#ifndef __FRESHER_H__
#define __FRESHER_H__

#include "LibBase.h"
#include "Employee.h"

class Fresher : public Employee
{
private:
	string GraduationDate;
	string GraduationRank;
	string Education;

public:
	string GetGradDate();
	string GetGradRank();
	string GetEdu();
	void SetGradDate(const string&);
	void SetGradRank(const string&);
	void SetEdu(const string&);
	void AddData();
	void ShowMe();
	~Fresher();
};

#endif