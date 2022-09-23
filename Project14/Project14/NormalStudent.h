#pragma once
#pragma once
#ifndef __NORMAL_H__
#define __NORMAL_H__

#include "LibBase.h"
#include "Student.h"

class NormalStudent : public Student {
private:
	float engScore;
	float entryTestScore;

public:
	void setEngScore(const float&);
	void setEntryTestScore(const float&);
	float getEngScore();
	float getEntryTestScore();

	void showInfo();
	void addData();
	~NormalStudent();
};

#endif // !__NORMAL_H__
