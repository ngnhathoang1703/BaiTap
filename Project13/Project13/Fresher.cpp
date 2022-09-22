#include "Fresher.h"
#include "Employee.h"

string Fresher::GetGradDate()
{
	return GraduationDate;
}

string Fresher::GetGradRank()
{
	return GraduationRank;
}

string Fresher::GetEdu()
{
	return Education;
}

void Fresher::AddData()
{
	Employee::AddData();
	cout << "Nhap ngay tot nghiep: ";   getline(cin, GraduationDate);
	cout << "Nhap loai tot nghiep: ";   getline(cin, GraduationRank);
	cout << "Nhap truong dai hoc: ";    getline(cin, Education);
}

void Fresher::ShowMe()
{
	Employee::ShowInfo();
	cout << "Graduation date: " << GetGradDate() << endl;
	cout << "Graduation Rank: " << GetGradRank() << endl;
	cout << "Eduation: " << GetEdu() << endl;
}

Fresher::~Fresher()
{

}