#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef enum
{
	VALID = 0,
	INVALID
} t_check;

class Nguoi
{
private:
	string HoTen;
	int Age;
	string Country;
	string ID;
	int luongCung;
	int luongThuong;
	int tienPhat;

public:
	Nguoi(string ten, int tuoi, string que, string id, int coban, int thuong, int phat)
		: HoTen(ten), Age(tuoi), Country(que), ID(id), luongCung(coban), luongThuong(thuong), tienPhat(phat)
	{

	}

	string getName()
	{
		return HoTen;
	}

	int getAge()
	{
		return Age;
	}

	string getCountry()
	{
		return Country;
	}

	string getID()
	{
		return ID;
	}

	int getLuongCung()
	{
		return luongCung;
	}

	int getLuongThuong()
	{
		return luongThuong;
	}

	int getTienPhat()
	{
		return tienPhat;
	}

	~Nguoi()
	{

	}
};

class CBGV
{
private:
	vector <Nguoi> danhSach;

public:
	CBGV()
	{

	}

	void AddMem(const Nguoi& nguoi)
	{
		danhSach.push_back(nguoi);
	}

	void RemoveMem(const string &ten)
	{
		for (int i = 0; i < danhSach.size(); i++)
		{
			if (ten == danhSach[i].getName())
			{				
				cout << "Da xoa giao vien " << ten << " khoi danh sach!" << endl;
				danhSach.erase(danhSach.begin() + i);
				return;
			}
		}

		cout << "Khong tim thay giao vien " << ten << " trong danh sach de xoa!" << endl;
	}

	int LuongGV(const string &ten)
	{
		for (int i = 0; i < danhSach.size(); i++)
		{
			if (ten == danhSach[i].getName())
			{
				return danhSach[i].getLuongCung() + danhSach[i].getLuongThuong() - danhSach[i].getTienPhat();
			}
		}

		return INVALID;
	}

	int GetNumOfMems()
	{
		return danhSach.size();
	}

	t_check CheckDupID(const string &id)
	{
		for (int i = 0; i < danhSach.size(); i++)
		{
			if (id == danhSach[i].getID())
			{
				return INVALID;
			}
		}
		
		return VALID;
	}

	void ShowInfo(const string &ten)
	{
		for (int i = 0; i < danhSach.size(); i++)
		{
			if (ten == danhSach[i].getName())
			{
				cout << "Thong tin giao vien " << ten << " la: ";
				cout << "Ten: " << ten << endl;
				cout << "Tuoi: " << danhSach[i].getAge() << endl;
				cout << "Que quan: " << danhSach[i].getCountry() << endl;
				cout << "Ma so giao vien: " << danhSach[i].getID() << endl;
				cout << "Muc luong cung: " << danhSach[i].getLuongCung() << endl;
				cout << "Muc luong thuong: " << danhSach[i].getLuongThuong() << endl;
				cout << "So tien phat: " << danhSach[i].getTienPhat() << endl;
				return;
			}
		}

		cout << "Khong tim thay giao vien " << ten << " trong danh sach!" << endl;
	}

	~CBGV()
	{

	}
	
};

int main()
{
	CBGV listGV;
	cout << "Chuong trinh quan ly thong tin giao vien" << endl;

	while (true)
	{	
		cout << "\nBam phim 1 de them giao vien vao danh sach quan ly" << endl;
		cout << "Bam phim 2 de xoa 1 giao vien khoi danh sach quan ly" << endl;
		cout << "Bam phim 3 de hien thi thong tin giao vien trong danh sach quan ly" << endl;
		cout << "Bam phim 4 de tinh luong thuc linh cua mot giao vien trong danh sach quan ly" << endl;
		cout << "Bam phim 5 de thoat khoi chuong trinh" << endl;
		cout << "Moi ban nhan phim : ";
		int n;
		cin >> n;
		cin.ignore();
		while (n < 1 || n > 4)
		{
			cout << "Phim nhap vao khong hop le. Moi ban nhap lai" << endl;
			cin >> n;
			cin.ignore();
		}	

		system("cls");

		switch (n)
		{
			case 1:
			{
				cout << "Moi ban nhap vao thong tin cua giao vien:" << endl;
				cout << "Nhap vao ten cua giao vien: ";
				string ten;
				getline(cin, ten);
				cout << "Nhap vao tuoi cua giao vien: ";
				int tuoi;
				cin >> tuoi;
				cin.ignore();
				cout << "Nhap vao que quan cua giao vien: ";
				string queQuan;
				getline(cin, queQuan);
				cout << "Nhap vao ma so giao vien: ";
				string id;
				getline(cin, id);

				t_check check = listGV.CheckDupID(id);
				if (check == INVALID)
				{
					cout << "Ma so giao vien bi trung, xin moi ban nhap lai" << endl;
					getline(cin, id);
				}
				cout << "Nhap vao muc luong cung cua giao vien(vnd): ";
				int luongcung;
				cin >> luongcung;
				cin.ignore();
				cout << "Nhap vao muc luong thuong cua giao vien(vnd): ";
				int luongthuong;
				cin >> luongthuong;
				cin.ignore();
				cout << "Nhap vao so tien phat(vnd): ";
				int tienphat;
				cin >> tienphat;
				cin.ignore();

				Nguoi giaovien(ten, tuoi, queQuan, id, luongcung, luongthuong, tienphat);
				listGV.AddMem(giaovien);

				cout << "So luong giao vien trong danh sach la: " << listGV.GetNumOfMems() << endl;

				break;
			}

			case 2:
			{
				string name;
				cout << "Nhap vao ten giao vien can xoa khoi danh sach: ";
				getline(cin, name);
				listGV.RemoveMem(name);
				cout << "So luong giao vien con lai trong danh sach la: " << listGV.GetNumOfMems() << endl;
				break;
			}

			case 3:
			{
				string ten;
				cout << "Nhap vao ten giao vien can hien thi thong tin: " << endl;
				getline(cin, ten);
				listGV.ShowInfo(ten);
				break;
			}

			case 4:
			{
				string name;
				cout << "Nhap vao ten giao vien can tinh muc luong: ";
				getline(cin, name);
				int luong = listGV.LuongGV(name);
				if (luong == INVALID)
				{
					cout << "Giao vien khong ton tai trong danh sach!";
				}
				else
				{
					cout << "Muc luong thuc linh cua giao vien la: " << luong << " vnd" << endl;
				}
				break;
			}
			
			case 5:
				return 0;
		}
	}
	return 0;
}