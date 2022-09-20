#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef enum
{
	EXPERIENCE = 0,
	FRESHER,
	INTERN
}t_EmployeeType;

class Employee
{
private:
	string ID;
	string FullName;
	string BirthDay;
	string Phone;
	string Email;
	t_EmployeeType Employee_type;
	vector<Certificate> ListCertificate;

public:
	Employee(string id, string name, string birthday, string phone, string email, t_EmployeeType employee_type)
		: ID(id), FullName(name), BirthDay(birthday), Phone(phone), Email(email), Employee_type(employee_type)
	{

	}

	string GetID()
	{
		return ID;
	}

	string GetFullName()
	{
		return FullName;
	}

	string GetBirthDay()
	{
		return BirthDay;
	}

	string GetPhone()
	{
		return Phone;
	}

	string GetEmail()
	{
		return Email;
	}

	t_EmployeeType GetEmPloyeeType()
	{
		return Employee_type;
	}

	void showInfo()
	{
		cout << "ID: " << GetID() << endl;
		cout << "Full name: " << GetFullName() << endl;
		cout << "Birth day: " << GetBirthDay() << endl;
		cout << "Phone: " << GetPhone() << endl;
		cout << "Email: " << GetEmail() << endl;
		cout << "Employee type: " << GetEmPloyeeType() << endl;
	}

	virtual AddData()
	{

	}

	virtual ~Employee()
	{

	}
};

class Experience : public Employee
{
private:
	int ExpInYear;
	string ProSkill;

public:
	Experience(string id, string name, string birthday, string phone, string email, t_EmployeeType employee_type, int expInYear, string proSkill)
		: Employee(id, name, birthday, phone, email, employee_type), ExpInYear(expInYear), ProSkill(proSkill)
	{

	}

	int GetExpInYear()
	{
		return ExpInYear;
	}

	string GetProSkill()
	{
		return ProSkill;
	}

	void ShowMe()
	{
		Employee::showInfo();
		cout << "Exp in year: " << GetExpInYear() << endl;
		cout << "Pro skill: " << GetProSkill() << endl;
	}

	~Experience()
	{

	}
};

class Fresher : public Employee
{
private:
	string Graduation_date;
	string Graduation_rank;
	string Education;

public:
	Fresher(string id, string name, string birthday, string phone, string email, t_EmployeeType employee_type, string gradDate, string gradRank, string edu)
		: Employee(id, name, birthday, phone, email, employee_type), Graduation_date(gradDate), Graduation_rank(gradRank), Education(edu)
	{

	}

	string GetGradDate()
	{
		return Graduation_date;
	}

	string GetGradRank()
	{
		return Graduation_rank;
	}

	string GetEdu()
	{
		return Education;
	}

	void ShowMe()
	{
		Employee::showInfo();
		cout << "Graduation date: " << GetGradDate() << endl;
		cout << "Graduation Rank: " << GetGradRank() << endl;
		cout << "Eduation: " << GetEdu() << endl;
	}

	~Fresher()
	{

	}
};

class Certificate
{
private:
	string CertificatedID;
	string CertificateName;
	string CertificateRank;
	string CertificatedDate;

public:
	Certificate(string certificatedID, string certificateName, string certificateRank, string certificatedDate)
		:CertificatedID(certificatedID), CertificateName(certificateName), CertificateRank(certificateRank), CertificatedDate(certificatedDate)
	{

	}

	string GetCertificatedID()
	{
		return CertificatedID;
	}

	string GetCertificateName()
	{
		return CertificateName;
	}

	string GetCertificateRank()
	{
		return CertificateRank;
	}

	string GetCertificatedDate()
	{
		return CertificatedDate;
	}

	~Certificate()
	{

	}
};

int main()
{
	return 0;
}
