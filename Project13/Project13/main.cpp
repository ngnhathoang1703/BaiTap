#include "Manage.h"


int main()
{
	Manage m;
	cout << "Chuong trinh quan ly nhan su cong ty.";
	while (true)
	{
		cout << "Bam phim 0 de thoat khoi chuong trinh" << endl;
		cout << "Bam phim 1 de them nhan vien moi" << endl;
		cout << "Bam phim 2 de xoa nhan vien" << endl;
		cout << "Bam phim 3 de tim kiem" << endl;
		cout << "Bam phim 4 de hien thi danh sach" << endl;
		cout << "Bam phim 5 de them chung chi" << endl;
		cout << "Bam phim 6 de hien thi chung chi" << endl;
		cout << "Nhap vao tu ban phim: ";
		int a;
		cin >> a;
		cin.ignore();
		switch (a)
		{
			case 0:
			{
				cout << "Ket thuc chuong trinh" << endl;
				return 0;
			}
	
			case 1:
			{
				m.AddMem();
				break;
			}

			case 2:
			{
				string tmp;
				cout << "Nhap ID cua nhan vien can xoa: "; getline(cin, tmp);
				m.RemoveEmployee(tmp);
				break;
			}

			case 3:
			{
				string tmp;
				cout << "Nhap ID cua nhan vien can tim: "; getline(cin, tmp);
				m.FindData(tmp);
			}

			case 4:
			{
				int a;
				cout << "0-All; 1-Experience; 2-Fresher; 3-Intern: ";
				cin >> a;
				cin.ignore();
				m.ShowList(a);
				break;
			}

			case 5:
			{
				string tmp;
				cout << "Nhap vao ID cua nhan vien can them chung chi: ";
				getline(cin, tmp);
				m.AddCertificater(tmp);
				break;
			}

			case 6:
			{
				string tmp;
				cout << "Nhap vao ID cua nhan vien can hien thi chung chi: ";
				getline(cin, tmp);
				m.ShowCertifi(tmp);
				break;
			}
		}
	}
	return 0;
}
