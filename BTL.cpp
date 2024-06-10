#include <iostream>
#include <string>

using namespace std;

// Khai báo lớp HocSinh
class HocSinh {
private:
    string ten;
    int maSo;
    float diemTK;
public:
	HocSinh(){
	}
    // Hàm tạo
    HocSinh(string tenHS, int maSoHS, float diemTKHS) : ten(tenHS), maSo(maSoHS), diemTK(diemTKHS) {}

    // Phương thức hiển thị thông tin học sinh
    void hienThiThongTin() const {
        cout << "Ten: " << ten << ", Ma so: " << maSo << ", DiemTK: " << diemTK << endl;
    }

    // Getter cho tên học sinh
    string layTen() const {
        return ten;
    }

    // Getter cho mã số học sinh
    int layMaSo() const {
        return maSo;
    }

    // Getter cho điểm học sinh
    float layDiem() const {
        return diemTK;
    }

    // Phương thức sửa thông tin học sinh
    void suaThongTin(string tenMoi, float diemMoi) {
        ten = tenMoi;
        diemTK = diemMoi;
    }
};

// Hàm tìm kiếm học sinh theo mã số
int timKiemHocSinh(const HocSinh danhSach[], int soLuong, int maSo) {
    for (int i = 0; i < soLuong; ++i) {
        if (danhSach[i].layMaSo() == maSo) {
            return i; // Trả về chỉ số của học sinh trong danh sách
        }
    }
    return -1; // Trả về -1 nếu không tìm thấy
}

// Hàm sắp xếp danh sách học sinh theo điểm
void sapXepDanhSachHocSinh(HocSinh danhSach[], int soLuong) {
    for (int i = 0; i < soLuong - 1; ++i) {
        for (int j = i + 1; j < soLuong; ++j) {
            if (danhSach[i].layDiem() < danhSach[j].layDiem()) {
                swap(danhSach[i], danhSach[j]);
            }
        }
    }
}

// Khai báo lớp GiaoVien
class GiaoVien {
private:
    string ten;
    string monDay;
public:
    // Hàm tạo
    GiaoVien(){
	}
    GiaoVien(string tenGV, string monDayGV) : ten(tenGV), monDay(monDayGV) {}

    // Phương thức hiển thị thông tin giáo viên
    void hienThiThongTin() const {
        cout << "Ten: " << ten << ", Mon day: " << monDay << endl;
    }

    // Getter cho tên giáo viên
    string layTen() const {
        return ten;
    }

    // Getter cho môn dạy
    string layMonDay() const {
        return monDay;
    }

    // Setter cho tên giáo viên
    void datTen(const string& tenMoi) {
        ten = tenMoi;
    }

    // Setter cho môn dạy
    void datMonDay(const string& monDayMoi) {
        monDay = monDayMoi;
    }
};

// Hàm thêm mới giáo viên vào danh sách
void themGiaoVien(GiaoVien danhSachGiaoVien[], int& soLuongGiaoVien) {
    if (soLuongGiaoVien < 100) {
        string ten;
        string monDay;
        cout << "Nhap ten giao vien: ";
        cin >> ten;
        cout << "Nhap mon day cua giao vien: ";
        cin >> monDay;
        danhSachGiaoVien[soLuongGiaoVien++] = GiaoVien(ten, monDay);
    } else {
        cout << "Danh sach giao vien da day.\n";
    }
}

// Hàm hiển thị danh sách giáo viên
void hienThiDanhSachGiaoVien(const GiaoVien danhSachGiaoVien[], int soLuongGiaoVien) {
    cout << "Danh sach giao vien:\n";
    for (int i = 0; i < soLuongGiaoVien; ++i) {
        danhSachGiaoVien[i].hienThiThongTin();
    }
}

// Hàm sửa thông tin giáo viên
void suaGiaoVien(GiaoVien danhSachGiaoVien[], int soLuongGiaoVien, const string& tenCanSua) {
    for (int i = 0; i < soLuongGiaoVien; ++i) {
        if (danhSachGiaoVien[i].layTen() == tenCanSua) {
            string tenMoi, monDayMoi;
            cout << "Nhap ten moi cho giao vien: ";
            cin >> tenMoi;
            cout << "Nhap mon day moi cho giao vien: ";
            cin >> monDayMoi;
            danhSachGiaoVien[i].datTen(tenMoi);
            danhSachGiaoVien[i].datMonDay(monDayMoi);
            cout << "Thong tin giao vien da duoc cap nhat.\n";
            return;
        }
    }
    cout << "Khong tim thay giao vien co ten " << tenCanSua << ".\n";
}

// Hàm xóa giáo viên khỏi danh sách
void xoaGiaoVien(GiaoVien danhSachGiaoVien[], int& soLuongGiaoVien, const string& tenCanXoa) {
    int viTriXoa = -1;
    for (int i = 0; i < soLuongGiaoVien; ++i) {
        if (danhSachGiaoVien[i].layTen() == tenCanXoa) {
            viTriXoa = i;
            break;
        }
    }
    if (viTriXoa != -1) {
        for (int i = viTriXoa; i < soLuongGiaoVien - 1; ++i) {
            danhSachGiaoVien[i] = danhSachGiaoVien[i + 1];
        }
        soLuongGiaoVien--;
        cout << "Da xoa giao vien " << tenCanXoa << " khoi danh sach.\n";
    } else {
        cout << "Khong tim thay giao vien co ten " << tenCanXoa << ".\n";
    }
}

// Hàm tìm kiếm giáo viên trong danh sách
void timKiemGiaoVien(const GiaoVien danhSachGiaoVien[], int soLuongGiaoVien, const string& tenCanTim) {
    bool timThay = false;
    cout << "Ket qua tim kiem:\n";
    for (int i = 0; i < soLuongGiaoVien; ++i) {
        if (danhSachGiaoVien[i].layTen() == tenCanTim) {
            danhSachGiaoVien[i].hienThiThongTin();
            timThay = true;
        }
    }
    if (!timThay) {
        cout << "Khong tim thay giao vien co ten " << tenCanTim << ".\n";
    }
}

// Hàm sắp xếp danh sách giáo viên theo tên
void sapXepTheoTen(GiaoVien danhSachGiaoVien[], int soLuongGiaoVien) {
    for (int i = 0; i < soLuongGiaoVien - 1; ++i) {
        for (int j = i + 1; j < soLuongGiaoVien; ++j) {
            if (danhSachGiaoVien[i].layTen() > danhSachGiaoVien[j].layTen()) {
                swap(danhSachGiaoVien[i], danhSachGiaoVien[j]);
            }
        }
    }
    cout << "Da sap xep danh sach giao vien theo ten.\n";
}
class LopHoc {
private:
    string maLop;
    string giaoVienChuNhiem;
public:
    // Hàm tạo
    LopHoc(string maLop, string giaoVien) : maLop(maLop), giaoVienChuNhiem(giaoVien) {}

    // Phương thức hiển thị thông tin lớp học
    void hienThongTin() const {
        cout << "Ma lop: " << maLop << ", Giao vien chu nhiem: " << giaoVienChuNhiem << endl;
    }

    // Getter cho mã lớp
    string layMaLop() const {
        return maLop;
    }

    // Setter cho mã lớp
    void datMaLop(const string& maLopMoi) {
        maLop = maLopMoi;
    }

    // Getter cho tên giáo viên chủ nhiệm
    string layGiaoVienChuNhiem() const {
        return giaoVienChuNhiem;
    }

    // Setter cho tên giáo viên chủ nhiệm
    void datGiaoVienChuNhiem(const string& giaoVienMoi) {
        giaoVienChuNhiem = giaoVienMoi;
    }
};



int main() {
   
    HocSinh *danhSachHocSinh = new HocSinh[100];
    int soLuongHocSinh = 0;
    
    
    GiaoVien *danhSachGiaoVien = new GiaoVien[100];
    int soLuongGiaoVien = 0;
    int luaChon;

    do {
        cout << "\n=== MENU CHINH ===\n";
        cout << "1. Quan ly hoc sinh\n";
        cout << "2. Quan ly giao vien\n";
        cout << "3. Thoat\n";
        cout << "Nhap lua chon cua ban: ";
        cin >> luaChon;

        switch (luaChon) {
            case 1:
                int luaChon;
    do {cout<<"\n=== MENU QUAN LY HOC SINH =="<<endl;
        cout << "1. Them Hoc Sinh\n2. Sua Thong Tin Hoc Sinh\n3. Xoa Hoc Sinh\n4. Tim Kiem Hoc Sinh\n5. Sap Xep Danh Sach Hoc Sinh\n0. Quay lai\n";
        cout << "Nhap lua chon cua ban: ";
        cin >> luaChon;
        switch (luaChon) {
            case 1: {
                string tenHS;
                int maSoHS;
                float diemHS;
                cout << "Nhap ten hoc sinh: ";
                cin.ignore();
                getline(cin, tenHS);
                cout << "Nhap ma so hoc sinh: ";
                cin >> maSoHS;
                cout << "Nhap diem Tong Ket hoc sinh: ";
                cin >> diemHS;
                danhSachHocSinh[soLuongHocSinh++] = HocSinh(tenHS, maSoHS, diemHS);
                break;
            }
            case 2: {
                int maSoHS;
                cout << "Nhap ma so hoc sinh can sua: ";
                cin >> maSoHS;
                int index = timKiemHocSinh(danhSachHocSinh, soLuongHocSinh, maSoHS);
                if (index != -1) {
                    string tenMoi;
                    float diemMoi;
                    cout << "Nhap ten moi cua hoc sinh: ";
                    cin.ignore();
                    getline(cin, tenMoi);
                    cout << "Nhap diem moi cua hoc sinh: ";
                    cin >> diemMoi;
                    danhSachHocSinh[index].suaThongTin(tenMoi, diemMoi);
                    cout << "Thong tin hoc sinh sau khi sua: " << endl;
                    danhSachHocSinh[index].hienThiThongTin();
                } else {
                    cout << "Khong tim thay hoc sinh co ma so " << maSoHS << endl;
                }
                break;
            }
            case 3: {
                int maSoHS;
                cout << "Nhap ma so hoc sinh can xoa: ";
                cin >> maSoHS;
                int index = timKiemHocSinh(danhSachHocSinh, soLuongHocSinh, maSoHS);
                if (index != -1) {
                    for (int i = index; i < soLuongHocSinh - 1; ++i) {
                        danhSachHocSinh[i] = danhSachHocSinh[i + 1];
                    }
                    soLuongHocSinh--;
                    cout << "Da xoa hoc sinh co ma so " << maSoHS << endl;
                } else {
                    cout << "Khong tim thay hoc sinh co ma so " << maSoHS << endl;
                }
                break;
            }
            case 4: {
                int maSoHS;
                cout << "Nhap ma so hoc sinh can tim: ";
                cin >> maSoHS;
                int index = timKiemHocSinh(danhSachHocSinh, soLuongHocSinh, maSoHS);
                if (index != -1) {
                    cout << "Thong tin hoc sinh can tim: " << endl;
                    danhSachHocSinh[index].hienThiThongTin();
                } else {
                    cout << "Khong tim thay hoc sinh co ma so " << maSoHS << endl;
                }
                break;
            }
           case 5:
                sapXepDanhSachHocSinh(danhSachHocSinh, soLuongHocSinh);
                cout << "Danh sach hoc sinh sau khi sap xep:" << endl;
                for (int i = 0; i < soLuongHocSinh; ++i) {
                    danhSachHocSinh[i].hienThiThongTin();
                }
                break;
            case 0:
                cout << "Ket thuc chuong trinh.";
                break;
            default:
                cout << "Lua chon khong hop le. Vui long chon lai.";
                break;
        }
    } while (luaChon != 0);

    // Giải phóng bộ nhớ sau khi sử dụng
    delete[] danhSachHocSinh;
                break;
            case 2:
            
   
    do {
        cout << "\n=== MENU QUAN LY GIAO VIEN ===\n";
        cout << "1. Them moi giao vien\n";
        cout << "2. Hien thi danh sach giao vien\n";
        cout << "3. Sua thong tin giao vien\n";
        cout << "4. Xoa giao vien\n";
        cout << "5. Tim kiem giao vien\n";
        cout << "6. Sap xep danh sach giao vien theo ten\n";
        cout << "7. Quay lai\n";
        cout << "Nhap lua chon cua ban: ";
        cin >> luaChon;

        switch (luaChon) {
            case 1: {
                if (soLuongGiaoVien < 100) {
                    themGiaoVien(danhSachGiaoVien, soLuongGiaoVien);
                } else {
                    cout << "Danh sach giao vien da day.\n";
                }
                break;
            }
            case 2: {
                hienThiDanhSachGiaoVien(danhSachGiaoVien, soLuongGiaoVien);
                break;
            }
            case 3: {
                string tenCanSua;
                cout << "Nhap ten giao vien can sua: ";
                cin >> tenCanSua;
                suaGiaoVien(danhSachGiaoVien, soLuongGiaoVien, tenCanSua);
                break;
            }
            case 4: {
                string tenCanXoa;
                cout << "Nhap ten giao vien can xoa: ";
                cin >> tenCanXoa;
                xoaGiaoVien(danhSachGiaoVien, soLuongGiaoVien, tenCanXoa);
                break;
            }
            case 5: {
                string tenCanTim;
                cout << "Nhap ten giao vien can tim: ";
                cin >> tenCanTim;
                timKiemGiaoVien(danhSachGiaoVien, soLuongGiaoVien, tenCanTim);
                break;
            }
            case 6: {
                sapXepTheoTen(danhSachGiaoVien, soLuongGiaoVien);
                  hienThiDanhSachGiaoVien(danhSachGiaoVien, soLuongGiaoVien);

                break;
            }
            case 7:
                cout << "Quay lai menu chinh.\n";
                break;
            default:
                cout << "Lua chon khong hop le. Vui long nhap lai.\n";
        }
    } while (luaChon != 7);

    

                break;
            case 3:
                cout << "Ket thuc chuong trinh.\n";
                break;
            default:
                cout << "Lua chon khong hop le. Vui long nhap lai namdz.\n";
        }
    } while (luaChon != 3);

    return 0;

    
}
