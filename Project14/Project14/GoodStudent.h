#pragma once
#ifndef __GOOD_H__
#define __GOOD_H__

#include "LibBase.h"
#include "Student.h"

class GoodStudent : public Student{
private:
	float Gpa;
	string BestReward;

public:
	void setGpa(const float&);
	void setReward(const string&);
	float getGpa();
	string bestReward();

	void showInfo();
	void addData();
	~GoodStudent();
};

#endif // !__GOOD_H__
