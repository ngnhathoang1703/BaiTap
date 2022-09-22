#pragma once
#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__

#include "LibBase.h"
#include "Certificate.h"
#include "Exception.h"
class Employee
{
private:
	string ID;
	string FullName;
	string BirthDay;
	string Phone;
	string Email;
	t_EmployeeType Employee_type;
	vector<Certificate> ListCerti;

public:
	Employee();
	void SetID(const string&);
	void SetFullName(const string&);
	void SetBirthDay(const string&);
	void SetPhone(const string&);
	void SetEmail(const string&);
	void SetEmPloyeeType(const t_EmployeeType&);
	string GetID();
	string GetFullName();
	string GetBirthDay();
	string GetPhone();
	string GetEmail();
	t_EmployeeType GetEmPloyeeType();

	void PushCertifi(const Certificate&);
	void EraseCertifi(const int&);

	void ShowListCertifi();
	void ShowInfo();

	bool CheckName(string name);
	bool CheckDate(string date);
	bool CheckPhone(string phone);
	bool CheckMail(string mail, string mailTail = "@fsoft.com.vn");

	virtual void AddData();
	virtual ~Employee();
};

#endif