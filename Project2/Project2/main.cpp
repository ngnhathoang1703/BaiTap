#include <iostream>
#include <string>
#include <vector>
using namespace std;

class TaiLieu
{
private:
	string MaTaiLieu;
	string TenNhaXuatBan;
	int SoBanPhatHanh;
public:
	TaiLieu(string matailieu, string nhaxuatban, int soluongban)
	{
		MaTaiLieu = matailieu;
		TenNhaXuatBan = nhaxuatban;
		SoBanPhatHanh = soluongban;
	}

	string getMaTaiLieu()
	{
		return MaTaiLieu;
	}

	string getNhaXuatBan()
	{
		return TenNhaXuatBan;
	}

	int getSoLuong()
	{
		return SoBanPhatHanh;
	}

	virtual string getPosition()
	{
		return "Tai Lieu";
	}
};

class Sach : public TaiLieu
{
private:
	string TenTacGia;
	int SoTrang;
public:
	Sach(string matailieu, string nhaxuatban, int soluongban, string tacgia, int sotrang) : TaiLieu(matailieu, nhaxuatban, soluongban)
	{
		TenTacGia = tacgia;
		SoTrang = sotrang;
	}
	
	string getTacGia()
	{
		return TenTacGia;
	}

	int getSoTrang()
	{
		return SoTrang;
	}

	string getPosition()
	{
		return "Sach";
	}
};

class TapChi : public TaiLieu
{
private:
	string SoPhatHanh;
	string ThangPhatHanh;
public:
	TapChi(string matailieu, string nhaxuatban, int soluongban, string so, string thang) : TaiLieu(matailieu, nhaxuatban, soluongban)
	{
		SoPhatHanh = so;
		ThangPhatHanh = thang;
	}

	string getSoPhatHanh()
	{
		return SoPhatHanh;
	}

	string getThangPhatHanh()
	{
		return ThangPhatHanh;
	}

	string getPosition()
	{
		return "Tap Chi";
	}
};

class Bao : public TaiLieu
{
private:
	string NgayPhatHanh;
public:
	Bao(string matailieu, string nhaxuatban, int soluongban, string ngay) : TaiLieu(matailieu, nhaxuatban, soluongban)
	{
		NgayPhatHanh = ngay;
	}

	string getNgayPhatHanh()
	{
		return NgayPhatHanh;
	}

	string getPosition()
	{
		return "Bao";
	}
};

class QuanLySach
{
private:
	vector<TaiLieu*> tatCaTaiLieu;
public:
	void AddTaiLieu(TaiLieu *tailieu)
	{
		tatCaTaiLieu.push_back(tailieu);
	}

	void XoaTaiLieuTheoMa(string maTaiLieu)
	{
		for (int i = 0; i < tatCaTaiLieu.size(); i++)
		{
			if (tatCaTaiLieu[i]->getMaTaiLieu() == maTaiLieu)
			{
				tatCaTaiLieu.erase(tatCaTaiLieu.begin() + i);
				cout << "da xoa tai lieu " << maTaiLieu << endl;
			}
			else
				cout << "khong tim thay tai lieu de xoa" << endl;
		}
	}

	void HienThiThongTin()
	{
		cout << "so luong tai lieu la " << tatCaTaiLieu.size() << endl;
		for (int i = 0; i < tatCaTaiLieu.size(); i++)
		{
			cout << i + 1 << ".   "  << tatCaTaiLieu[i]->getMaTaiLieu() << "   Loai Tai Lieu    " << tatCaTaiLieu[i]->getPosition() << endl;
		}
	}

	void TimKiemTheoLoai(string loaiTaiLieu)
	{
		if (loaiTaiLieu == "a")
		{
			for (int i = 0; i < tatCaTaiLieu.size(); i++)
			{
				if (tatCaTaiLieu[i]->getPosition() == "Sach")
				{
					cout << "vi tri tai lieu: " << i << "ma tai lieu: " << tatCaTaiLieu[i]->getMaTaiLieu() << endl;
				}
			}
		}
		else if (loaiTaiLieu == "b")
		{
			for (int i = 0; i < tatCaTaiLieu.size(); i++)
			{
				if (tatCaTaiLieu[i]->getPosition() == "Tap Chi")
				{
					cout << "vi tri tai lieu: " << i << "ma tai lieu: " << tatCaTaiLieu[i]->getMaTaiLieu() << endl;
				}
			}
		}
		else
		{
			for (int i = 0; i < tatCaTaiLieu.size(); i++)
			{
				if (tatCaTaiLieu[i]->getPosition() == "Bao")
				{
					cout << "vi tri tai lieu: " << i << "ma tai lieu: " << tatCaTaiLieu[i]->getMaTaiLieu() << endl;
				}
			}
		}
	}
};

int main()
{
	QuanLySach management;
	cout << "Chuong trinh quan ly sach" << endl;
	while (1)
	{
		cout << "nhan phim 1 de them tai lieu moi" << endl;
		cout << "nhan phim 2 de xoa tai lieu theo ma" << endl;
		cout << "nhan phim 3 de hien thi thong tin ve tai lieu" << endl;
		cout << "nhan phim 4 de tim kiem tai lieu theo loai" << endl;
		int numberInput;
		cin >> numberInput;
		cin.ignore();

		switch (numberInput)
		{
		case 1:
		{
			cout << "nhan phim a de them vao 1 cuon Sach" << endl;
			cout << "nhan phim b de them vao 1 cuon Tap Chi" << endl;
			cout << "nhan phim c de them vao 1 tap Bao" << endl;

			string jobInput;
			getline(cin, jobInput);

			if (jobInput == "a")
			{
				cout << "nhap vao ma tai lieu: " << endl;
				string ma;
				getline(cin, ma);

				cout << "nhap vao ten nha xuat ban: " << endl;
				string nhaXuatBan;
				getline(cin, nhaXuatBan);

				cout << "nhap vao so ban phat hanh: " << endl;
				int soLuong;
				cin >> soLuong;
				cin.ignore();

				cout << "nhap vao ten tac gia: " << endl;
				string tacGia;
				getline(cin, tacGia);

				cout << "nhap vao so trang: " << endl;
				int soTrang;
				cin >> soTrang;
				cin.ignore();

				TaiLieu* tailieusach = new TaiLieu(ma, nhaXuatBan, soLuong);
				Sach sach(ma, nhaXuatBan, soLuong, tacGia, soTrang);
				tailieusach = &sach;

				management.AddTaiLieu(tailieusach);
			}

			else if (jobInput == "b")
			{
				cout << "nhap vao ma tai lieu: " << endl;
				string ma;
				getline(cin, ma);

				cout << "nhap vao ten nha xuat ban: " << endl;
				string nhaXuatBan;
				getline(cin, nhaXuatBan);

				cout << "nhap vao so ban phat hanh: " << endl;
				int soLuong;
				cin >> soLuong;
				cin.ignore();

				cout << "nhap vao so phat hanh: " << endl;
				string soPhatHanh;
				getline(cin, soPhatHanh);

				cout << "nhap vao ngay phat hanh: " << endl;
				string thangPhatHanh;
				getline(cin, thangPhatHanh);

				TaiLieu* taiLieuTapChi = new TaiLieu(ma, nhaXuatBan, soLuong);
				TapChi tapChi(ma, nhaXuatBan, soLuong, soPhatHanh, thangPhatHanh);
				taiLieuTapChi = &tapChi;

				management.AddTaiLieu(taiLieuTapChi);
			}

			else
			{
				cout << "nhap vao ma tai lieu: " << endl;
				string ma;
				getline(cin, ma);

				cout << "nhap vao ten nha xuat ban: " << endl;
				string nhaXuatBan;
				getline(cin, nhaXuatBan);

				cout << "nhap vao so ban phat hanh: " << endl;
				int soLuong;
				cin >> soLuong;
				cin.ignore();

				cout << "nhap vao ngay phat hanh: " << endl;
				string ngayPhatHanh;
				getline(cin, ngayPhatHanh);

				TaiLieu* taiLieuBao = new TaiLieu(ma, nhaXuatBan, soLuong);
				Bao bao(ma, nhaXuatBan, soLuong, ngayPhatHanh);
				taiLieuBao = &bao;

				management.AddTaiLieu(taiLieuBao);
			}
			break;
		}

		case 2: 
		{
			cout << "nhap vao ma tai lieu can xoa :" << endl;
			string matailieu;
			getline(cin, matailieu);
			management.XoaTaiLieuTheoMa(matailieu);
			break;
		}

		case 3:
		{			
			management.HienThiThongTin();
			break;
		}

		case 4:
		{
			cout << "nhan phim a de tim kiem Sach" << endl;
			cout << "nhan phim b de tim kiem Tap Chi" << endl;
			cout << "nhan phim c de tim kiem Bao" << endl;
			string loaiTaiLieu;
			getline(cin, loaiTaiLieu);
			management.TimKiemTheoLoai(loaiTaiLieu);
			break;
		}

		default:
			return 0;
		}

	}

	return 0;
}