#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Nguoi
{
private:
	string Name;
	int Age;
	string Work;
	string ID;

public:
	Nguoi(string hoten, int tuoi, string congviec, string id) : Name(hoten), Age(tuoi), Work(congviec), ID(id)
	{

	}

	string getName()
	{
		return Name;
	}

	int getAge()
	{
		return Age;
	}

	string getWork()
	{
		return Work;
	}

	string getID()
	{
		return ID;
	}

	~Nguoi()
	{

	}
};

class HoGiaDinh
{
private:
	int n_Mems;
	vector<Nguoi> member;

public:
	HoGiaDinh(int n_mems) : n_Mems(n_mems)
	{

	}

	int getNumberOfMems()
	{
		return n_Mems;
	}

	void AddMems(const Nguoi& nguoi)
	{
		member.push_back(nguoi);
	}

	void showInfo()
	{
		for (int i = 0; i < n_Mems; i++)
		{
			cout << "Ten cua thanh vien thu " << i + 1 << " la: " << member[i].getName() << endl;
			cout << "Tuoi cua thanh vien thu " << i + 1 << " la: " << member[i].getAge() << endl;
			cout << "Nghe nghiep cua thanh vien thu " << i + 1 << " la: " << member[i].getWork() << endl;
			cout << "CMND cua thanh vien thu " << i + 1 << " la: " << member[i].getID() << endl;
		}
	}

	~HoGiaDinh()
	{

	}
};

class KhuPho
{
private:
	vector<HoGiaDinh> khupho;

public:
	KhuPho()
	{

	}

	void AddHoGiaDinh(const HoGiaDinh& giadinh)
	{
		khupho.push_back(giadinh);
	}

	int getNumsOfFamily()
	{
		return khupho.size();
	}

	HoGiaDinh getFamHaveIndex(int i)
	{
		return khupho[i];
	}
};

int main()
{
	cout << "Chuong trinh quan ly khu pho." << endl;
	KhuPho management;

	while (true)
	{
		cout << "Nhan phim 1 de nhap vao so ho gia dinh" << endl;
		cout << "Nhan phim 2 de hien thi thong tin cua cac ho trong khu pho" << endl;
		cout << "Nhan phim 3 de ket thuc chuong trinh" << endl;
		
		int n = 0;
		cin >> n;
		cin.ignore();

		switch (n) 
		{
			case 1:
			{			
				cout << "Nhap vao tu ban phim so ho gia dinh: ";
				int n = 0;
				cin >> n;
				cin.ignore();
				int m = management.getNumsOfFamily();
				cout << "Hien tai trong danh sach da co " << m << " ho gia dinh." << endl;
				for (int i = m; i < m + n; i++)
				{
					cout << "Nhap vao so thanh vien cua gia dinh thu " << i + 1 << " : ";
					int n = 0;
					cin >> n;
					cin.ignore();

					HoGiaDinh giaDinh(n);
					for (int i = 0; i < n; i++)
					{
						cout << "Nhap vao ten cua thanh vien thu " << i + 1 << " : ";
						string ten;
						getline(cin, ten);

						cout << "Nhap vao tuoi cua thanh vien thu " << i + 1 << " : ";
						int tuoi;
						cin >> tuoi;
						cin.ignore();

						cout << "Nhap vao cong viec cua thanh vien thu " << i + 1 << " : ";
						string congViec;
						getline(cin, congViec);

						cout << "Nhap vao so CMND cua thanh vien thu " << i + 1 << " : ";
						string id;
						getline(cin, id);

						Nguoi thanhvien(ten, tuoi, congViec, id);

						giaDinh.AddMems(thanhvien);
					}

					management.AddHoGiaDinh(giaDinh);
				}

				break;
			}

			case 2:
			{
				cout << "Hien tai trong danh sach co " << management.getNumsOfFamily() << " ho gia dinh" << endl;
				cout << "Nhap vao tu ban phim ho gia dinh n de hien thi thong tin: " << endl << "n = ";
				int n;
				cin >> n;				
				while (n <= 0 || n > management.getNumsOfFamily())
				{
					cout << "n khong hop le, xin moi nhap lai!!" << endl << "n = ";
					cin >> n;
				}

				management.getFamHaveIndex(n - 1).showInfo();
				break;
			}

			case 3: 
				return 0;
		}
	}

	return 0;
}