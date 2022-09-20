#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ThiSinh
{
private:
	string SoBaoDanh;
	string HoTen;
	string DiaChi;
	int MucUuTien;

public:
	ThiSinh(string soBaoDanh, string hoTen, string diaChi, int mucUuTien)
	{
		SoBaoDanh = soBaoDanh;
		HoTen = hoTen;
		DiaChi = diaChi;
		MucUuTien = mucUuTien;
	}

	string GetSoBaoDanh()
	{
		return SoBaoDanh;
	}

	string GetHoTen()
	{
		return HoTen;
	}

	string GetDiaChi()
	{
		return DiaChi;
	}

	int GetMucUuTien()
	{
		return MucUuTien;
	}

	virtual string GetKhoi()
	{
		return "Khoi Thi Cua Thi Sinh";
	}
};

class KhoiA : public ThiSinh
{
private:
	vector <string> monThi;
};