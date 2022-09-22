#include "Employee.h"

Employee::Employee()
{
	
}

void Employee::SetID(const string& id)
{
	ID = id;
}
void Employee::SetFullName(const string& name)
{
	FullName = name;
}
void Employee::SetBirthDay(const string& birthday)
{
	BirthDay = birthday;
}
void Employee::SetPhone(const string& phone)
{
	Phone = phone;
}
void Employee::SetEmail(const string& email)
{
	Email = email;
}
void Employee::SetEmPloyeeType(const t_EmployeeType& type)
{
	Employee_type = type;
}

string Employee::GetID()
{
	return ID;
}

string Employee::GetFullName()
{
	return FullName;
}

string Employee::GetBirthDay()
{
	return BirthDay;
}

string Employee::GetPhone()
{
	return Phone;
}

string Employee::GetEmail()
{
	return Email;
}

t_EmployeeType Employee::GetEmPloyeeType()
{
	return Employee_type;
}

void Employee::ShowInfo()
{
	cout << "ID: " << ID << endl;
	cout << "Full name: " << FullName << endl;
	cout << "Birth day: " << BirthDay << endl;
	cout << "Phone: " << Phone << endl;
	cout << "Email: " << Email << endl;
	cout << "Employee type: " << Employee_type << endl;
}

void Employee::AddData()
{
    string tmp_name, tmp_date, tmp_phone, tmp_mail;
    cout << "Nhap ID: "; cin >> this->ID;
    cin.ignore();
    do {
        cout << "Nhap ten: ";
        getline(cin, tmp_name);
        if (tmp_name == "0") break;
    } while (!CheckName(tmp_name));
    SetFullName(tmp_name);

    do {
        cout << "Nhap ngay sinh: ";
        getline(cin, tmp_date);
        if (tmp_name == "0") break;
    } while (!CheckDate(tmp_date));
    SetBirthDay(tmp_date);

    do {
        cout << "Nhap sdt: ";
        getline(cin, tmp_phone);
        if (tmp_name == "0") break;
    } while (!CheckPhone(tmp_phone));
    SetPhone(tmp_phone);

    do {
        cout << "Nhap email: ";
        getline(cin, tmp_mail);
        if (tmp_name == "0") break;
    } while (!CheckMail(tmp_mail));
    SetEmail(tmp_mail);
}

void Employee::PushCertifi(const Certificate& certi)
{
    ListCerti.push_back(certi);
}

void Employee::EraseCertifi(const int& index)
{
    if ((index < 1) || (index > ListCerti.size()))
    {
        cout << "Chi so nhap vao khong hop le" << endl;
    }
    else
    {
        ListCerti.erase(ListCerti.begin() + index);
    }
}

void Employee::ShowListCertifi()
{
    if (ListCerti.empty()) {
        cout << "Khong co du lieu!" << endl;
        return;
    }
    for (int i = 0; i < ListCerti.size(); i++) {
        cout << i + 1 << ". ";
        ListCerti[i].ShowCertifi();
    }
}

bool Employee::CheckName(string name)
{
    try {
        stringstream ss(name);
        string token;
        while (ss >> token)
        {
            for (int i = 0; i < token.length(); i++) {
                if ((token[i] > 47) && (token[i] < 58)) {
                    throw NameException("Invalid name!");
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
bool Employee::CheckDate(string date)
{
    try {
        stringstream ss(date);
        string token;
        while (ss >> token)
        {
            if (token.length() != 8) {
                throw DateException("Invalid date! - dd/mm/yy");
            }
            if ((token[2] != '/') || (token[5] != '/')) {
                throw DateException("Invalid date! - dd/mm/yy");
            }
            for (int i = 0; i < token.length(); i++) {
                if ((i != 2) && (i != 5)) {
                    if ((token[i] < 48) || (token[i] > 57)) {
                        throw DateException("Invalid date! - dd/mm/yy");
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
bool Employee::CheckPhone(string phone)
{
    try {
        stringstream ss(phone);
        string token;
        while (ss >> token)
        {
            if (token.length() != 10) {
                throw PhoneException("Invalid phone number!");
            }
            for (int i = 0; i < token.length(); i++) {
                if ((token[i] < 48) || (token[i] > 57)) {
                    throw PhoneException("Invalid phone number!");
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
bool Employee::CheckMail(string mail, string mailTail)
{
    try {
        stringstream ss(mail);                           
        string token;                                                    
        string temp = "";                               
        if (mailTail.length() == 0) {
            return false;
        }
        while (ss >> token)
        {
            if (token.length() < mailTail.length() + 1) {
                throw EmailException("Invalid email! Mail form: \"...\" + " + mailTail);
            }
            for (int i = token.length() - mailTail.length(); i < token.length(); i++) {
                temp += token[i];
            }
        }
        if (temp != mailTail) {
            throw EmailException("Invalid email! Mail form: \"...\" + " + mailTail);
        }
    }
    catch (EmailException& ex4) {
        cout << ex4.what() << endl;
        return false;
    }
    return true;
}

Employee::~Employee()
{

}