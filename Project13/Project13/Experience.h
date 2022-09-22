#pragma once
#ifndef __EXPERIENCE_H__
#define __EXPERIENCE_H__

#include "LibBase.h"
#include "Employee.h"

class Experience : public Employee
{
private:
	int ExpInYear;
	string ProSkill;

public:
	void SetExpInYear(const int&);
	void SetProSkill(const string&);
	int GetExpInYear();
	string GetProSkill();
	void AddData();
	void ShowMe();
	~Experience();
};

#endif