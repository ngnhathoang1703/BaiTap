#include "NormalStudent.h"

void NormalStudent::setEngScore(const float& score){
	this->engScore = score;
}

void NormalStudent::setEntryTestScore(const float& score){
	this->entryTestScore = score;
}

float NormalStudent::getEngScore(){
	return engScore;
}

float NormalStudent::getEntryTestScore(){
	return entryTestScore;
}


void NormalStudent::showInfo(){
	Student::showInfo();
	cout << " -English Score: " << this->engScore << " -Entry Test Score: " << this->entryTestScore; 
}

void NormalStudent::addData(){
	Student::addData();
	cout << "Nhap vao diem TOEIC: "; cin >> this->engScore; cin.ignore();
	cout << "Nhap vao diem thi test: "; cin >> this->entryTestScore; cin.ignore();
}

NormalStudent::~NormalStudent(){

}
