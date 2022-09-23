#include "Student.h"

void Student::setFullName(const string& name) { this->fullName = name; }
void Student::setDoB(const string& dob) { this->DoB = dob; }
void Student::setGender(const gender& s) { this->sex = s; }
void Student::setPhone(const string& phone) { this->phoneNumber = phone; }
void Student::setUni(const string& univer) { this->univerName = univer; }
void Student::setLevel(const level& lv) { this->gradeLevel = lv; }
string Student::getFullName() { return this->fullName; }
string Student::getDoB() { return this->DoB; }
gender Student::getSex() { return this->sex; }
string Student::getPhone() { return this->phoneNumber; }
string Student::getUni() { return this->univerName; }
level Student::getLevel() { return this->gradeLevel; }
void Student::addData() {
    string tmp;
    cin.ignore();
    do {
        
        cout << "Nhap ten: ";
        getline(cin, tmp);
        if (tmp == "0") break;
    } while (!checkName(tmp));
    this->fullName = tmp;
    do {
        
        cout << "Nhap ngay sinh: ";
        cin >> tmp;
        if (tmp == "0") break;
    } while (!checkDate(tmp));
    this->DoB = tmp;
    int a;
    do {        
        cout << "Nhap gioi tinh: 0-nam, 1-nu: ";
        cin >> a; cin.ignore();
    } while ((a < 0) || (a > 2));
    setGender((gender)a);
    do {
        cout << "Nhap so dien thoai: ";
        cin >> tmp; cin.ignore();
        if (tmp == "0") break;
    } while (!checkPhone(tmp));
    this->phoneNumber = tmp;
    cout << "Nhap truong dai hoc: "; cin >> this->univerName;
}

void Student::showInfo() {
    cout << "Name: " << fullName << " - Birthday: " << DoB << " - Sex: " << sex <<
        " - Phone: " << phoneNumber << " - University: " << univerName << " - Level: " << gradeLevel;
}

bool Student::checkName(const string &name)
{
    try {
        stringstream ss(name);
        string token;
        while (ss >> token)
        {
            for (int i = 0; i < token.length(); i++) {
                if ((token[i] > 47) && (token[i] < 58)) {
                    throw NameException("In name!");
                }
            }
        }
    }
    catch (NameException& ex1) {
        cout << ex1.what() << endl;
        return false;
    }
    return true;
}
bool Student::checkDate(const string &date)
{
    try {
        stringstream ss(date);
        string token;
        while (ss >> token)
        {
            if (token.length() != 8) {
                throw DateException("In date! - dd/mm/yy");
            }
            if ((token[2] != '/') || (token[5] != '/')) {
                throw DateException("In date! - dd/mm/yy");
            }
            for (int i = 0; i < token.length(); i++) {
                if ((i != 2) && (i != 5)) {
                    if ((token[i] < 48) || (token[i] > 57)) {
                        throw DateException("In date! - dd/mm/yy");
                    }
                }
            }
        }
        stringstream ss1;
        int day, month, year;
        ss1 << date.substr(0, 2);
        ss1 >> day; ss1.clear();
        ss1 << date.substr(3, 2);
        ss1 >> month; ss1.clear();
        ss1 << date.substr(6, 2);
        ss1 >> year; ss1.clear();
        if ((day < 1) || (day > 31) || (month < 1) || (month > 12)) {
            throw DateException("Ngay khong hop le! Form: dd/mm/yy");
        }
    }
    catch (DateException& ex2) {
        cout << ex2.what() << endl;
        return false;
    }
    return true;
}
bool Student::checkPhone(const string &phone)
{
    try {
        stringstream ss(phone);
        string token;
        while (ss >> token)
        {
            if (token.length() != 10) {
                throw PhoneException("In phone number!");
            }
            for (int i = 0; i < token.length(); i++) {
                if ((token[i] < 48) || (token[i] > 57)) {
                    throw PhoneException("In phone number!");
                }
            }
        }
    }
    catch (PhoneException& ex3) {
        cout << ex3.what() << endl;
        return false;
    }
    return true;
}