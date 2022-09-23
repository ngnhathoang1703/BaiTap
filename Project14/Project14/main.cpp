#include "Manage.h"

int main() {
    int temp;
    Manage m;
    while (true)
    {
        cout << "==================================================\n";
        cout << "1-Them moi nhan vien\n2-Xoa nhan vien\n3-Tim kiem\n4-Hien thi danh sach\n5-Tuyen dung"
            << "\n0-Thoat\nMoi ban nhap: ";
        cin >> temp;
        cout << "========\n";
        switch (temp) {
        case cmd_exit: {
            cout << "Close the program..." << endl;
            system("cls");
            return 0;
        }
        case cmd_add:
            m.addData();
            break;
        case cmd_remove: {
            string tmp_phone;       
            cout << "Nhap so dien thoai cua sinh vien can xoa: ";
            cin >> tmp_phone;
            if (tmp_phone == "0") break;           
            m.delData(tmp_phone);
            break;
        }
        case cmd_find: {
            string tmp_phone;
            cout << "Nhap so dien thoai cua sinh vien can tim kiem: ";
            cin >> tmp_phone;
            if (tmp_phone == "0") break;

            m.findData(tmp_phone);
            break;
        }
        case cmd_showlist: {
            m.showList();
            break;
        }
        case cmd_recruit: {
            int tmp;
            cout << "Nhap so luong sinh vien can tuyen dung (3-10): ";
            cin >> tmp;
            m.recruitFunc(tmp);
            break;
        }
        default:
            break;
        }
    }
    cout << "Close the program..." << endl;
    return 0;
}