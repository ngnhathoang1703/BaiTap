#include <iostream>
#include <string>
#include <vector>
using namespace std;

class CanBo
{
private:
	string Name;
	int Age;
	string Gender;
	string Addr;

public:
	CanBo(string name, int age, string gender, string addr) : Name(name), Age(age), Gender(gender), Addr(addr)
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

	string getGender()
	{
		return Gender;
	}

	string getAddr()
	{
		return Addr;
	}

	virtual string getPosition()
	{
		return "Can Bo";
	}

	virtual ~CanBo()
	{
		
	}
};

class CongNhan : public CanBo
{
private:
	int Level;

public:

	CongNhan(string name, int age, string gender, string addr, int level): CanBo(name, age, gender, addr), Level(level)
	{		
	}

	int getLevel()
	{
		return Level;
	}

	string getPosition()
	{
		return "Cong Nhan";
	}

	~CongNhan()
	{

	}
};

class KySu : public CanBo
{
private:
	string Major;

public:
	KySu(string name, int age, string gender, string addr, string major) : CanBo(name, age, gender, addr), Major(major)
	{
	}

	string getMajor()
	{
		return Major;
	}

	string getPosition()
	{
		return "Ky Su";
	}
	
};

class NhanVien : public CanBo
{
private: 
	string Work;

public:
	NhanVien(string name, int age, string gender, string addr, string work) : CanBo(name, age, gender, addr), Work(work)
	{
		
	}

	string getWork()
	{
		return Work;
	}

	string getPosition()
	{
		return "Nhan Vien";
	}
};

class QuanLyCanBo
{
private:
	vector<CanBo*> tatCaThanhVien;

public:

	void addCanBo(CanBo *canbo)
	{
		tatCaThanhVien.push_back(canbo);
	}

	void timKiemTheoTen(const string &name)
	{
		for (int i = 0; i < tatCaThanhVien.size(); i++)
		{
			if (name == tatCaThanhVien[i]->getName())
			{
				cout << "Tim thay can bo " << name << endl;
			}
			else
				cout << "Khong tim thay can bo " << name << endl;
		}
	}

	void hienThiThongTin()
	{
		cout << "So luong can bo la " << tatCaThanhVien.size() << endl;
		for (int i = 0; i < tatCaThanhVien.size(); i++)
		{
			cout << i + 1 << ".   " << tatCaThanhVien[i]->getName() << "   Vi tri    " << tatCaThanhVien[i]->getPosition() << endl;
		}
	}

	~QuanLyCanBo()
	{
		for (int i = 0; i < tatCaThanhVien.size(); i++)
		{
			delete tatCaThanhVien[i];
		}

		tatCaThanhVien.clear();
	}
};

int main()
{
	QuanLyCanBo management;
	cout << "Chuong trinh quan ly can bo \n" << endl;
	while (1)
	{
		cout << "Nhan phim 1 de them can bo" << endl;
		cout << "Nhan phim 2 de them tim kiem can bo theo ten" << endl;
		cout << "Nhan phim 3 de hien thi thong tin ve danh sach can bo" << endl;
		cout << "Nhan phim 4 de thoat khoi chuong trinh" << endl;

		int numberInput;
		cin >> numberInput;
		cin.ignore();

		switch (numberInput)
		{
			case 1:
			{
				cout << "Nhan phim a de them vao 1 cong nhan" << endl;
				cout << "Nhan phim b de them vao 1 ky su" << endl;
				cout << "Nhan phim c de them vao 1 nhan vien" << endl;

				string jobInput;
				getline(cin, jobInput);

				cout << "Nhap vao ten: " << endl;
				string ten;
				getline(cin, ten);

				cout << "Nhap vao tuoi: " << endl;
				int tuoi;
				cin >> tuoi;
				cin.ignore();

				cout << "Nhap vao gioi tinh: " << endl;
				string gioiTinh;
				getline(cin, gioiTinh);

				cout << "Nhap vao dia chi: " << endl;
				string diaChi;
				getline(cin, diaChi);

				if (jobInput == "a")
				{
					cout << "Nhap vao trinh do: " << endl;
					int trinhDo;
					cin >> trinhDo;
					cin.ignore();

					CanBo* canBoCongNhan = new CongNhan(ten, tuoi, gioiTinh, diaChi, trinhDo);		

					management.addCanBo(canBoCongNhan);
				}

				else if (jobInput == "b")
				{
					cout << "Nhap vao chuyen nganh dao tao: " << endl;
					string chuyenNganh;
					getline(cin, chuyenNganh);

					CanBo* canBoKySu = new KySu(ten, tuoi, gioiTinh, diaChi, chuyenNganh);

					management.addCanBo(canBoKySu);
				}

				else
				{
					cout << "Nhap vao cong viec: " << endl;
					string congViec;
					getline(cin, congViec);

					CanBo* canBoNhanVien = new NhanVien(ten, tuoi, gioiTinh, diaChi, congViec);

					management.addCanBo(canBoNhanVien);
				}
				break;
			}

			case 2:
			{
				cout << "Nhap vao ten can bo can tim: " << endl;
				string name;
				getline(cin, name);
				management.timKiemTheoTen(name);
				break;
			}

			case 3:
			{
				management.hienThiThongTin();
				break;
			}

			case 4:
				return 0;
		}
	}
	return 0;
}