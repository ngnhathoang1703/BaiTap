#include "Intern.h"

void Intern::AddData()
{
	Employee::AddData();
	cout << "Nhap vao chuyen nganh: ";   getline(cin, Major);
	cout << "Nhap vao hoc ky: ";   cin >> Semester;   cin.ignore();
	cout << "Nhap truong dai hoc: ";    getline(cin, UniversityName);
}

void Intern::ShowMe()
{
	Employee::ShowInfo();
	cout << "Major: " << Major << endl;
	cout << "Semester: " << Semester << endl;
	cout << "UniversityName: " << UniversityName << endl;
}

void Intern::SetMajors(const string& major)
{
	Major = major;
}

void Intern::SetSemester(const int& semester)
{
	Semester = semester;
}

void Intern::SetUniversity(const string& uni)
{
	UniversityName = uni;
}

string Intern::GetMajors()
{
	return Major;
}

int Intern::GetSemester()
{
	return Semester;
}

string Intern::GetUniversity()
{
	return UniversityName;
}

Intern::~Intern()
{

}