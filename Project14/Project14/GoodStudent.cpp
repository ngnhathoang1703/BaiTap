#include "GoodStudent.h"

void GoodStudent::setGpa(const float& gpa) {
	this->Gpa = gpa;
}

void GoodStudent::setReward(const string &reward) {
	this->BestReward = reward;
}

float GoodStudent::getGpa() {
	return this->Gpa;
}

string GoodStudent::bestReward() {
	return this->BestReward;
}

void GoodStudent::showInfo() {
	Student::showInfo();
	cout << " -GPA: " << this->Gpa << " -Best Reward: " << BestReward;
}

void GoodStudent::addData() {
	Student::addData();
	cout << "Nhap GPA: "; cin >> this->Gpa; cin.ignore();
	cout << "Nhap vao giai thuong: "; getline(cin, this->BestReward);
}

GoodStudent::~GoodStudent() {

}