#include "Manage.h"

Manage::~Manage() {
    if (!v.empty()) {
        for (Employee* i : v) {
            delete(i);
        }
    }
}

void Manage::AddMem()
{
    int a;
    cout << "1-Experience - 2-Fresher - 3-Intern: ";
    cin >> a;
    switch (a) {
    case EXIT_T:
        return;
    case EXPERIENCE_T: {
        Experience* p = new Experience;
        p->AddData();
        p->SetEmPloyeeType(EXPERIENCE);
        v.push_back(p);
        break;
    }
    case FRESHER_T: {
        Fresher* p = new Fresher;
        p->AddData();
        p->SetEmPloyeeType(FRESHER);
        v.push_back(p);
        break;
    }
    case INTERN_T: {
        Intern* p = new Intern;
        p->AddData();
        p->SetEmPloyeeType(INTERN);
        v.push_back(p);
        break;
    }
    default:
        cout << "Nhap sai! Nhap so trong khoang 0 - 3\n";
        break;
    }
    if (Manage::CheckSameID()) {
        Employee* tmp = v[v.size() - 1];
        v.pop_back();
        delete(tmp);
    }
    int q;
    cout << "Ban co muon nhap tiep? 1-Yes/0-No: "; cin >> q;
    if (q == YES) {
        Manage::AddMem();
    }
}

void Manage::ShowList(const int& type)
{
    if (v.size() == 0)
    {
        cout << "Danh sach trong!" << endl;
        cout << "Ban co muon nhap vao thong tin nhan vien ? 1-Yes/0-No: " << endl;
        int q;
        do
        {
            cout << "q = ";
            cin >> q; cin.ignore();
            if (q == YES)
            {
                Manage::AddMem();
            }
            else if (q == NO)
                return;
            else
                cout << "Nhap sai! Xin moi nhap lai" << endl;
        } while ((q != 1) && (q != 0));
    }
  
    if (type == SHOW_ALL) 
    {
        for (int i = 0; i < v.size(); i++) 
        {
            cout << i + 1 << ": ";
            if (v[i]->GetEmPloyeeType() == EXPERIENCE)
            {
                Experience* p = dynamic_cast<Experience*>(v[i]);
                if (p != nullptr)
                {
                    p->ShowInfo();
                }
            }

            if (v[i]->GetEmPloyeeType() == FRESHER)
            {
                Fresher* p = dynamic_cast<Fresher*>(v[i]);
                if (p != nullptr)
                {
                    p->ShowInfo();
                }
            }

            if (v[i]->GetEmPloyeeType() == INTERN)
            {
                Intern* p = dynamic_cast<Intern*>(v[i]);
                if (p != nullptr) 
                { 
                    p->ShowInfo();
                }
                    
            }
        }
    }

    else if (type == SHOW_EXPERIENCE) {
        uint8_t count = 0;
        for (int i = 0; i < v.size(); i++) {
            if (v[i]->GetEmPloyeeType() == EXPERIENCE) 
            {
                count++;
                cout << i + 1 << ": ";
                Experience* p = dynamic_cast<Experience*>(v[i]);
                if (p != nullptr)
                {
                    p->ShowInfo();
                }
            }
        }
        if (count == 0) { cout << "Khong co nhan su Experience trong danh sach!" << endl; }
    }

    else if (type == SHOW_FRESHER) 
    {
        uint8_t count = 0;
        for (int i = 0; i < v.size(); i++) {
            if (v[i]->GetEmPloyeeType() == FRESHER) 
            {
                count++;
                cout << i + 1 << ": ";
                Fresher* p = dynamic_cast<Fresher*>(v[i]);
                if (p != nullptr)
                {
                    p->ShowInfo();
                }
            }
        }
        if (count == 0) { cout << "Khong co nhan su Fresher trong danh sach!" << endl; }
    }

    else if (type == SHOW_INTERN)
    {
        uint8_t count = 0;
        for (int i = 0; i < v.size(); i++) {
            if (v[i]->GetEmPloyeeType() == INTERN) {
                count++;
                cout << i + 1 << ": ";
                Intern* p = dynamic_cast<Intern*>(v[i]);
                if (p != nullptr)
                {
                    p->ShowInfo();
                }
            }
        }
        if (count == 0) { cout << "Khong co nhan su Intern trong danh sach!" << endl; }
    }
}

void Manage::ChangeData(const string& id)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (id == v[i]->GetID())
        {
            v[i]->AddData();
        }

        break;
    }
}

void Manage::RemoveEmployee(const string& id)
{

}

void Manage::FindData(const string&)
{

}

bool Manage::CheckSameID()
{
    try {
        if (v.size() > 1) 
        {
            for (int i = 0; i < v.size() - 1; i++) 
            {
                if (v[i]->GetID() == v[v.size() - 1]->GetID())
                {
                    throw MyException("ID bi trung. Moi nhap lai");
                }
            }
        }
    }
    catch (MyException& e) 
    {
        cout << e.what() << endl;
        return true;
    }

    return false;
}
void Manage::AddCertificater(const string&)
{

}
void Manage::ShowCertifi(const string&)
{

}
