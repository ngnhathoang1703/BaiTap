#include "Manage.h"

void Manage::addData()
{
    int a;
    cout << "0-Back - 1-Good student - 2-Normal student: ";
    cin >> a;
    switch (a) {
    case EXIT_T:
        return;
    case GOOD_T: {
        shared_ptr<GoodStudent> p(new GoodStudent);
        p->addData();
        v.push_back(p);
        numberGoodStudent++;
        break;
    }
    case NORMAL_T: {
        shared_ptr<NormalStudent> p(new NormalStudent);
        p->addData();
        v.push_back(p);
        numberNormalStudent++;
        break;
    }
    default:
        cout << "Nhap sai! Nhap so trong khoang 0 - 2\n";
        break;
    }

    int q;
    cout << "Ban co muon nhap tiep? 1-Yes/0-No: "; cin >> q;
    if (q == YES) {
        Manage::addData();
    }
}

void Manage::delData(const string& name)
{
    int count = 0;
    if (v.empty()) {
        cout << "No data in list!" << endl;
        return;
    }
    for (int i = 0; i < v.size(); i++) {
        if (v[i]->getPhone() == name) {
            count++;
            if (v[i]->getLevel() == good) {
                numberGoodStudent--;
            }
            else if (v[i]->getLevel() == normal) {
                numberNormalStudent--;
            }
            v.erase(v.begin() + i);
            break;
        }
    }
    if (count == 0) {
        cout << "Can not find student has name: " << name << " in list!" << endl;
        return;
    }
    cout << "Delete done!" << endl;
}

void Manage::findData(const string& name)
{
    int count = 0;
    if (v.empty()) {
        cout << "No data in list!" << endl;
        return;
    }
    for (int i = 0; i < v.size(); i++) {
        if (v[i]->getFullName() == name) {
            cout << i + 1 << ". ";
            count++;
            showMemberData(name);
        }
    }
    if (count == 0) {
        cout << "Can not find student has name: " << name << " in list!" << endl;
        return;
    }
}

void Manage::showList() {
    for (int i = 0; i < v.size(); i++)
    {
        v[i]->showInfo();
    }
}

void Manage::showMemberData(const string& name)
{
    if (v.empty()) {
        cout << "No data in list!"<<endl;
        return;
    }

    for (int i = 0; i < v.size(); i++) {
        if (v[i]->getFullName() == name) {
            if (v[i]->getLevel() == good) {
                shared_ptr<GoodStudent> p = dynamic_pointer_cast<GoodStudent>(v[i]);
                p->showInfo();
            }
            if (v[i]->getLevel() == normal) {
                shared_ptr<NormalStudent> p = dynamic_pointer_cast<NormalStudent>(v[i]);
                p->showInfo();
            }
            break;
        }
    }
}

void Manage::changeData(const string& name)
{
    if (!v.empty()) {
        cout << "Danh sang khong co du lieu!" << endl;
        return;
    }
    for (int i = 0; i < v.size(); i++) {
        if (v[i]->getFullName() == name) {
            v[i]->addData();
        }
    }
}

void Manage::recruitFunc(const int& numberRecruit) {
    if (v.empty()) {
        cout << "No data in list!\n";
        return;
    }
    if (numberRecruit <= numberGoodStudent) {
        cout << "Danh sach sinh vien trung tuyen:\n";
        Manage::showPassedGoodStudent(0, numberRecruit);
    }
    else if (numberRecruit > numberGoodStudent) {
        int temp = numberRecruit - numberGoodStudent;
        cout << "Danh sach sinh vien trung tuyen:\n";
        Manage::showPassedGoodStudent(0, numberGoodStudent);
        if (temp >= numberNormalStudent) {
            Manage::showPassedNormalStudent(numberGoodStudent, numberNormalStudent);
        }
        else if (temp < numberNormalStudent) {
            Manage::showPassedNormalStudent(numberGoodStudent, temp);
        }
    }
}

void Manage::showPassedGoodStudent(int start_index, const int& numberPassed) {
    vector< shared_ptr<GoodStudent>> v1;
    for (int i = 0; i < v.size(); i++) {
        if (v[i]->getLevel() == good) {
            v1.push_back(dynamic_pointer_cast<GoodStudent>(v[i]));
        }
    }
    sort(v1.begin(), v1.end());
    for (int j = 0; j < numberPassed; j++) {
        cout << start_index + j + 1 << ". ";
        v1[j]->showInfo();
    }
}

void Manage::showPassedNormalStudent(int start_index, const int& numberPassed) {
    vector< shared_ptr<NormalStudent>> v2;
    for (int i = 0; i < v.size(); i++) {
        if (v[i]->getLevel() == normal) {
            v2.push_back(dynamic_pointer_cast<NormalStudent>(v[i]));
        }
    }
    sort(v2.begin(), v2.end());
    for (int j = 0; j < numberPassed; j++) {
        cout << start_index + j + 1 << ". ";
        v2[j]->showInfo();
    }
}

//void Manage::selectionSort() {              //  < : GIAM DAN, > : TANG DAN
//    //sort Name: A->B->C->....  tang dan
//    for (int i_start = 0; i_start < v.size(); i_start++)
//    {
//        int minIndex = i_start;
//        for (int i_current = i_start + 1; i_current < v.size(); i_current++)
//        {
//            if (v[minIndex]->getFullName() > v[i_current]->getFullName())
//            {
//                minIndex = i_current;
//            }
//        }
//        swap(v[i_start], v[minIndex]);
//    }
//
//    for (int i_start = 0; i_start < v.size() - 1; i_start++)
//    {
//        int minIndex = i_start;
//        for (int i_current = i_start + 1; i_current < v.size(); i_current++)
//        {
//            if (v[minIndex]->getFullName() == v[i_current]->getFullName()) {
//                if (v[minIndex]->getPhone() < v[i_current]->getPhone()) {
//                    minIndex = i_current;
//                }
//            }
//        }
//        swap(v[i_start], v[minIndex]);
//    }
//}

Manage::~Manage() {

}