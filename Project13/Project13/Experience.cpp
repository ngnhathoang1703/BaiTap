#include "Experience.h"

int Experience::GetExpInYear()
{
	return ExpInYear;
}

string Experience::GetProSkill()
{
	return ProSkill;
}

void Experience::ShowMe()
{
	Employee::ShowInfo();
	cout << "Exp in year: " << GetExpInYear() << endl;
	cout << "Pro skill: " << GetProSkill() << endl;
}

void Experience::AddData()
{
	Employee::AddData();
	cout << "Nhap vao so nam kinh nghiem: "; cin >> ExpInYear; cin.ignore();
	cout << "Nhap vao pro skill: "; getline(cin, ProSkill);
}

Experience::~Experience()
{

}