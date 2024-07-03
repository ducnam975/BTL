#include <iostream>
#include <string>
#include <windows.h>
#include<iomanip>

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
        cout << "Khong tim thay giao vien co ten: " << tenCanXoa << ".\n";
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
        cout << "Khong tim thay giao vien co ten: " << tenCanTim << ".\n";
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



// Khai báo lớp TaiLieuTaiNguyen
class TaiLieuTaiNguyen
{
private:
    string ten;
    int maSo;
    string MonHoc;
    string LopHoc;
public:
    // Hàm tạo
    TaiLieuTaiNguyen() {}
    TaiLieuTaiNguyen(string tenTL, int maSoTL, string MonHocTL, string LopHocTL) : ten(tenTL), maSo(maSoTL), MonHoc(MonHocTL), LopHoc(LopHocTL) {}

    // Phương thức hiển thị thông tin tài liệu
    void hienThiThongTin() const
    {
        cout << "Ten: " << ten << ", Ma so: " << maSo << ", Mon hoc: " << MonHoc << ", Lop hoc: " << LopHoc << endl;
    }

    // Getter cho tên tài liệu
    string layTen() const
    {
        return ten;
    }

    // Getter cho mã số tài liệu
    int laymaSo() const
    {
        return maSo;
    }

    // Getter cho môn học
    string layMonHoc() const
    {
        return MonHoc;
    }

    // Getter cho lớp học
    string layLopHoc() const
    {
        return LopHoc;
    }

    // Phương thức sửa thông tin tài liệu
    void suaThongTin(string tenMoi, int maSoMoi, string MonHocMoi, string LopHocMoi)
    {
        ten = tenMoi;
        maSo = maSoMoi;
        MonHoc = MonHocMoi;
        LopHoc = LopHocMoi;
    }
};

// Hàm tìm kiếm tài liệu theo mã số
int timKiemTaiLieuTaiNguyen(const TaiLieuTaiNguyen danhsach[], int soLuong, int maSo)
{
    for (int i = 0; i < soLuong; ++i)
    {
        if (danhsach[i].laymaSo() == maSo)
        {
            return i; // Trả về chỉ số của tài liệu trong danh sách
        }
    }
    return -1; // Trả về -1 nếu không tìm thấy
}
void sapXepDanhsachTaiLieuTaiNguyen(TaiLieuTaiNguyen danhsach[], int soLuong)
{
    for (int i = 0; i < soLuong - 1; ++i)
    {
        bool swapped = false; //Biến kiểm tra xem có sự hoán đổi nào không
        for (int j = i + 1; j < soLuong; ++j)
        {
            if (danhsach[i].layTen() > danhsach[j].layTen())
            {
                swap(danhsach[i], danhsach[j]);
                swapped = true; // Đánh dấu rằng đã có sự hoán đổi
            }
        }
        // Nếu không có sự hoán đổi nào xảy ra, danh sách đã được sắp xếp
        if (!swapped)
        {
            break;
        }
    }
    cout << "Da sap xep danh sach tai lieu tai nguyen theo ten.\n";
};
class LopHoc {
private:
    string maLop;
    string tengv;
public:
    // Hàm tạo
    LopHoc(){
	}
    LopHoc(string maLop, string tengv) : maLop(maLop), tengv(tengv) {}

    // Phương thức hiển thị thông tin lop hoc
    void hienThiThongTin() const {
        cout << "Ma Lop: " << maLop << ", Ten giao vien chu nhiem: " << tengv << endl;
    }

    // Getter cho mã lớp
    string layMa() const {
        return maLop;
    }

    // Getter cho tên giáo viên chủ nhiệm
    string layTen() const {
        return tengv;
    }

    // Setter cho tên giáo viên
    void datTen(const string& tenMoi) {
        tengv = tenMoi;
    }

    // Setter cho mã lớp
    void datMaMoi(const string& maMoi) {
        maLop = maMoi;
    }
};

// Hàm thêm mới giáo viên vào danh sách
void themLopHoc(LopHoc danhSachLopHoc[], int& soLuongLopHoc) {
    if (soLuongLopHoc < 100) {
        string tengv;
        string maLop;
        cout << "Nhap ma lop hoc: ";
        cin >> maLop;
        cout << "Nhap ten cua giao vien chu nhiem: ";
        cin >> tengv;
        danhSachLopHoc[soLuongLopHoc++] = LopHoc(maLop, tengv);
    } else {
        cout << "Danh sach lop hoc da day.\n";
    }
}

// Hàm hiển thị danh sách lop hoc
void hienThiDanhSachLopHoc(const LopHoc danhSachLopHoc[], int soLuongLopHoc) {
    cout << "Danh sach lop hoc:\n";
    for (int i = 0; i < soLuongLopHoc; ++i) {
        danhSachLopHoc[i].hienThiThongTin();
    }
}

// Hàm sửa thông tin lop hoc
void suaLopHoc(LopHoc danhSachLopHoc[], int soLuongLopHoc, const string& tenCanSua) {
    for (int i = 0; i < soLuongLopHoc; ++i) {
        if (danhSachLopHoc[i].layTen() == tenCanSua) {
            string maMoi,tenMoi;
            cout << "Nhap ma moi cho lop hoc: ";
            cin >> maMoi;
            cout << "Nhap ten moi cho giao vien: ";
            cin >> tenMoi;
            danhSachLopHoc[i].datTen(tenMoi);
            danhSachLopHoc[i].datMaMoi(maMoi);
            cout << "Thong tin lop hoc da duoc cap nhat.\n";
            return;
        }
    }
    cout << "Khong tim thay lop hoc co ma tren " << tenCanSua << ".\n";
}

// Hàm xóa lop hoc khỏi danh sách
void xoaLopHoc(LopHoc danhSachLopHoc[], int& soLuongLopHoc, const string& tenCanXoa) {
    int viTriXoa = -1;
    for (int i = 0; i < soLuongLopHoc; ++i) {
        if (danhSachLopHoc[i].layTen() == tenCanXoa) {
            viTriXoa = i;
            break;
        }
    }
    if (viTriXoa != -1) {
        for (int i = viTriXoa; i < soLuongLopHoc - 1; ++i) {
            danhSachLopHoc[i] = danhSachLopHoc[i + 1];
        }
        soLuongLopHoc--;
        cout << "Da xoa lop hoc " << tenCanXoa << " khoi danh sach.\n";
    } else {
        cout << "Khong tim thay ma lop: " << tenCanXoa << ".\n";
    }
}

// Hàm tìm kiếm lớp học trong danh sách
void timKiemLopHoc(const LopHoc danhSachLopHoc[], int soLuongLopHoc, const string& tenCanTim) {
    bool timThay = false;
    cout << "Ket qua tim kiem:\n";
    for (int i = 0; i < soLuongLopHoc; ++i) {
        if (danhSachLopHoc[i].layTen() == tenCanTim) {
            danhSachLopHoc[i].hienThiThongTin();
            timThay = true;
        }
    }
    if (!timThay) {
        cout << "Khong tim thay lop hoc: " << tenCanTim << ".\n";
    }
}

// Hàm sắp xếp danh sách lop hoc theo tên
void sapXepTheoTen(LopHoc danhSachLopHoc[], int soLuongLopHoc) {
    for (int i = 0; i < soLuongLopHoc - 1; ++i) {
        for (int j = i + 1; j < soLuongLopHoc; ++j) {
            if (danhSachLopHoc[i].layTen() > danhSachLopHoc[j].layTen()) {
                swap(danhSachLopHoc[i], danhSachLopHoc[j]);
            }
        }
    }
    cout << "Da sap xep danh sach lop hoc.\n";
}
// Class nhap diem cho hoc sinh
class Diem {
private:
    string hoTen;
    float diemToan, diemVan, diemAnh;
    float diemTB;
    string xepLoai;

public:
	// Hàm nhập điểm
    void nhapDiem() {
        cout << "Nhap ho ten hoc sinh: ";
        getline(cin, hoTen);
        cout << "Nhap diem Toan: ";
        cin >> diemToan;
        cout << "Nhap diem Van: ";
        cin >> diemVan;
        cout << "Nhap diem Anh: ";
        cin >> diemAnh;
        cin.ignore();
        tinhDiemTB();
        xepLoaiHocLuc();
    }
// Hàm tính điểm trung bình
    void tinhDiemTB() {
        diemTB = (diemToan + diemVan + diemAnh) / 3;
    }
// Hàm xếp loại học lực
    void xepLoaiHocLuc() {
        if (diemTB >= 9)
            xepLoai = "Xuat sac";
        else if (diemTB >= 8)
            xepLoai = "Gioi";
        else if (diemTB >= 7)
            xepLoai = "Kha";
        else if (diemTB >= 5)
            xepLoai = "Trung binh";
        else
            xepLoai = "Yeu";
    }
// Hàm hiển thị điểm học sinh
    void hienThiDiem() {
        cout << left << setw(20) << hoTen
             << setw(10) << diemToan
             << setw(10) << diemVan
             << setw(10) << diemAnh
             << setw(10) << fixed << setprecision(1) << diemTB
             << setw(15) << xepLoai << endl;
    }
// Hàm sửa điểm 
    void suaDiem(string mon, float diemMoi) {
        if (mon == "Toan")
            diemToan = diemMoi;
        else if (mon == "Van")
            diemVan = diemMoi;
        else if (mon == "Anh")
            diemAnh = diemMoi;
        tinhDiemTB();
        xepLoaiHocLuc();
    }
};
// Khai báo lớp PhuHuynh
class PhuHuynh
{
private:
    string tenPH;
    string tenHS;
    string SDT;
public:
    // Hàm tạo
    PhuHuynh() {}
    PhuHuynh(string tenPHH, string tenHSH, string SDTPH) : tenPH(tenPHH), tenHS(tenHSH), SDT(SDTPH) {}

    // Phương thức hiển thị thông tin phụ huynh
    void hienThiThongTin() const
    {
        cout << "Ten phu huynh: " << tenPH << ", Ten hoc sinh: " << tenHS << ", So dien thoai phu huynh: " << SDT << endl;
    }

    // Getter cho tên phụ huynh
    string layTenPH() const
    {
        return tenPH;
    }

    // Getter cho tên học sinh
    string layTenHS() const
    {
        return tenHS;
    }

    // Getter cho số điện thoại
    string laySDT() const
    {
        return SDT;
    }

    // Setter cho tên phụ huynh
    void datTenPH(const string& tenPHMoi)
    {
        tenPH = tenPHMoi;
    }

    // Setter cho tên học sinh
    void datTenHS(const string& tenHSMoi)
    {
        tenHS = tenHSMoi;
    }

    // Setter cho số điện thoại
    void datSDT(const string& SDTMoi)
    {
        SDT = SDTMoi;
    }
};

// Hàm thêm mới phụ huynh vào danh sách
void themPhuHuynh(PhuHuynh danhsachPhuHuynh[], int& soLuongPhuHuynh)
{
    if (soLuongPhuHuynh < 100)
    {
        string tenPH;
        string tenHS;
        string SDT;
        cout << "Nhap ten phu huynh: ";
        cin.ignore();
        getline(cin, tenPH);
        cout << "Nhap ten hoc sinh: ";
        getline(cin, tenHS);
        cout << "Nhap so dien thoai: ";
        getline(cin, SDT);
        danhsachPhuHuynh[soLuongPhuHuynh++] = PhuHuynh(tenPH, tenHS, SDT);
    }
    else
    {
        cout << "Danh sach phu huynh da day.\n";
    }
}

// Hàm hiển thị danh sách phụ huynh
void hienThiDanhsachPhuHuynh(const PhuHuynh danhsachPhuHuynh[], int soLuongPhuHuynh)
{
    cout << "Danh sach phu huynh:\n";
    for (int i = 0; i < soLuongPhuHuynh; ++i)
    {
        danhsachPhuHuynh[i].hienThiThongTin();
    }
}

// Hàm xóa phụ huynh khỏi danh sách
void xoaPhuHuynh(PhuHuynh danhsachPhuHuynh[], int& soLuongPhuHuynh, const string& tenCanXoa)
{
    int viTriXoa = -1;
    for (int i = 0; i < soLuongPhuHuynh; ++i)
    {
        if (danhsachPhuHuynh[i].layTenPH() == tenCanXoa)
        {
            viTriXoa = i;
            break;
        }
    }
    if (viTriXoa != -1)
    {
        for (int i = viTriXoa; i < soLuongPhuHuynh - 1; ++i)
        {
            danhsachPhuHuynh[i] = danhsachPhuHuynh[i + 1];
        }
        soLuongPhuHuynh--;
        cout << "Da xoa phu huynh " << tenCanXoa << " khoi danh sach.\n";
    }
    else
    {
        cout << "Khong tim thay phu huynh co ten " << tenCanXoa << ".\n";
    }
}

// Hàm tìm kiếm phụ huynh trong danh sách
void timKiemPhuHuynh(const PhuHuynh danhsachPhuHuynh[], int soLuongPhuHuynh, const string& tenCanTim)
{
    bool timThay = false;
    cout << "Ket qua tim kiem:\n";
    for (int i = 0; i < soLuongPhuHuynh; ++i)
    {
        if (danhsachPhuHuynh[i].layTenPH() == tenCanTim)
        {
            danhsachPhuHuynh[i].hienThiThongTin();
            timThay = true;
        }
    }
    if (!timThay)
    {
        cout << "Khong tim thay phu huynh co ten " << tenCanTim << ".\n";
    }
}

// Hàm sắp xếp danh sách phụ huynh theo tên phụ huynh
void sapXepTheoTen(PhuHuynh danhsachPhuHuynh[], int soLuongPhuHuynh)
{
    for (int i = 0; i < soLuongPhuHuynh - 1; ++i)
    {
        for (int j = i + 1; j < soLuongPhuHuynh; ++j)
        {
            if (danhsachPhuHuynh[i].layTenPH() > danhsachPhuHuynh[j].layTenPH())
            {
                PhuHuynh temp = danhsachPhuHuynh[i];
                danhsachPhuHuynh[i] = danhsachPhuHuynh[j];
                danhsachPhuHuynh[j] = temp;
            }
        }
    }
    cout << "Da sap xep danh sach phu huynh theo ten.\n";
}
const int THONG_BAO = 10000;
const int LIEN_LAC = 10000;

// Class để lưu thông tin thông báo
class ThongBao
{
public:
    string tieuDe;
    string noiDung;
    ThongBao() : tieuDe(""), noiDung("") {}
};

// Class để lưu thông tin liên lạc từ phụ huynh
class LienLac
{
public:
    string tenPhuHuynh;
    string hinhThuc; // Cuoc goi hoac tin nhan
    string noiDung;
    LienLac() : tenPhuHuynh(""), hinhThuc(""), noiDung("") {}
};

// Class để quản lý thông báo và liên lạc
class QuanLy
{
private:
    ThongBao danhSachThongBao[THONG_BAO];
    LienLac danhSachLienLac[LIEN_LAC];
    int soLuongThongBao;
    int soLuongLienLac;

public:
    QuanLy() : soLuongThongBao(0), soLuongLienLac(0) {}

    //Hàm tạo thông báo
    void taoThongBao(const string& tieuDe, const string& noiDung)
    {
        if (soLuongThongBao < THONG_BAO)
        {
            danhSachThongBao[soLuongThongBao].tieuDe = tieuDe;
            danhSachThongBao[soLuongThongBao].noiDung = noiDung;
            soLuongThongBao++;
            cout << "Thong bao da duoc gui: " << tieuDe << endl;
        }
        else
        {
            cout << "Danh sach thong bao da day!" << endl;
        }
    }

    //Hàm ghi nhận liên lạc
    void ghiNhanLienLac(const string& tenPhuHuynh, const string& hinhThuc, const string& noiDung)
    {
        if (soLuongLienLac < LIEN_LAC)
        {
            danhSachLienLac[soLuongLienLac].tenPhuHuynh = tenPhuHuynh;
            danhSachLienLac[soLuongLienLac].hinhThuc = hinhThuc;
            danhSachLienLac[soLuongLienLac].noiDung = noiDung;
            soLuongLienLac++;
            cout << "Da ghi nhan " << hinhThuc << " tu phu huynh: " << tenPhuHuynh << endl;
        }
        else
        {
            cout << "Danh sach lien lac da day!" << endl;
        }
    }

    //Hàm hiển thị thông báo
    void hienThiThongBao() const
    {
        cout << "\nDanh sach thong bao:\n";
        for (int i = 0; i < soLuongThongBao; i++)
        {
            cout << "Tieu de: " << danhSachThongBao[i].tieuDe << "\nNoi dung: " << danhSachThongBao[i].noiDung << endl;
        }
    }

    //Hàm hiển thị liên lạc
    void hienThiLienLac() const
    {
        cout << "\nDanh sach lien lac tu phu huynh:\n";
        for (int i = 0; i < soLuongLienLac; i++)
        {
            cout << "Phu huynh: " << danhSachLienLac[i].tenPhuHuynh << "\nHinh thuc: " << danhSachLienLac[i].hinhThuc << "\nNoi dung: " << danhSachLienLac[i].noiDung << endl;
        }
    }
};


int main()
{
   
    //Học sinh
    HocSinh *danhSachHocSinh = new HocSinh[1000];
    int soLuongHocSinh = 0;

    //Giáo viên
    GiaoVien *danhSachGiaoVien = new GiaoVien[1000];
    int soLuongGiaoVien = 0;
    //Lớp học
    LopHoc *danhSachLopHoc = new LopHoc[1000];
    int soLuongLopHoc = 0;
    // Nhập điểm 
    int soHocSinh= 0;
    Diem *dsHocSinh = new Diem[10000];  
    //Tài liệu tài nguyên
    TaiLieuTaiNguyen *danhsachTaiLieuTaiNguyen = new TaiLieuTaiNguyen[10000];
    int soLuongTaiLieuTaiNguyen = 0;

    //Phụ huynh
    PhuHuynh *danhsachPhuHuynh = new PhuHuynh[10000];
    int soLuongPhuHuynh = 0;

    int luaChon1;
    do
    {
        cout << "\n=== MENU CHINH ===\n";
        cout << "1. Quan ly hoc sinh\n";
        cout << "2. Quan ly giao vien\n";
        cout << "7. Quan ly Tai lieu tai nguyen\n";
        cout << "8. Quan ly phu huynh\n";
        cout << "9. Quan ly thong bao / Cuoc goi\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon cua ban: ";
        cin >> luaChon1;

        //Nhập lựa chọn
        switch (luaChon1)
        {
            case 1:
            {
                int luaChon;
                system("cls");//Clear screen
                do
                {
                    cout<<"\n=== MENU QUAN LY HOC SINH =="<<endl;
                    cout << "1. Them Hoc Sinh\n2. Sua Thong Tin Hoc Sinh\n3. Xoa Hoc Sinh\n4. Tim Kiem Hoc Sinh\n5. Sap Xep Danh Sach Hoc Sinh\n0. Quay lai\n";
                    cout << "Nhap lua chon cua ban: ";
                    cin >> luaChon;
                    switch (luaChon)
                    {
                        case 1:
                        {
                            system("cls");//Clear screen
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
                        case 2:
                        {
                            system("cls");//Clear screen
                            int maSoHS;
                            cout << "Nhap ma so hoc sinh can sua: ";
                            cin >> maSoHS;
                            int index = timKiemHocSinh(danhSachHocSinh, soLuongHocSinh, maSoHS);
                            if (index != -1)
                            {
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
                            }
                            else
                            {
                                cout << "Khong tim thay hoc sinh co ma so " << maSoHS << endl;
                            }
                            break;
                        }
                        case 3:
                        {
                            system("cls");//Clear screen
                            int maSoHS;
                            cout << "Nhap ma so hoc sinh can xoa: ";
                            cin >> maSoHS;
                            int index = timKiemHocSinh(danhSachHocSinh, soLuongHocSinh, maSoHS);
                            if (index != -1)
                            {
                                for (int i = index; i < soLuongHocSinh - 1; ++i)
                                {
                                    danhSachHocSinh[i] = danhSachHocSinh[i + 1];
                                }
                                soLuongHocSinh--;
                                cout << "Da xoa hoc sinh co ma so " << maSoHS << endl;
                            }
                            else
                            {
                                cout << "Khong tim thay hoc sinh co ma so " << maSoHS << endl;
                            }
                            break;
                        }
                        case 4:
                        {
                            system("cls");//Clear screen
                            int maSoHS;
                            cout << "Nhap ma so hoc sinh can tim: ";
                            cin >> maSoHS;
                            int index = timKiemHocSinh(danhSachHocSinh, soLuongHocSinh, maSoHS);
                            if (index != -1)
                            {
                                cout << "Thong tin hoc sinh can tim: " << endl;
                                danhSachHocSinh[index].hienThiThongTin();
                            }
                            else
                            {
                                cout << "Khong tim thay hoc sinh co ma so " << maSoHS << endl;
                            }
                            break;
                        }
                        case 5:
                        {
                            //system("cls");//Clear screen
                            sapXepDanhSachHocSinh(danhSachHocSinh, soLuongHocSinh);
                            cout << "Danh sach hoc sinh sau khi sap xep:" << endl;
                            for (int i = 0; i < soLuongHocSinh; ++i)
                            {
                                danhSachHocSinh[i].hienThiThongTin();
                            }
                            break;
                        }
                        case 0:
                        {
                            system("cls");//Clear screen
                            cout << "Ket thuc chuong trinh.";
                            break;
                        }
                        default:
                            cout << "Lua chon khong hop le. Vui long chon lai.";
                            break;
                    }
                } while (luaChon != 0);

                // Giải phóng bộ nhớ sau khi sử dụng
                delete[] danhSachHocSinh;
                break;
            }
            case 2:
            {
                system("cls");//Clear screen
                int luaChon;
                do
                {
                    cout << "\n=== MENU QUAN LY GIAO VIEN ===\n";
                    cout << "1. Them moi giao vien\n";
                    cout << "2. Hien thi danh sach giao vien\n";
                    cout << "3. Sua thong tin giao vien\n";
                    cout << "4. Xoa giao vien\n";
                    cout << "5. Tim kiem giao vien\n";
                    cout << "6. Sap xep danh sach giao vien theo ten\n";
                    cout << "0. Quay lai\n";
                    cout << "Nhap lua chon cua ban: ";
                    cin >> luaChon;
                    switch (luaChon)
                    {
                        case 1:
                        {
                            system("cls");//Clear screen
                            if (soLuongGiaoVien < 100)
                            {
                                themGiaoVien(danhSachGiaoVien, soLuongGiaoVien);
                            }
                            else
                            {
                                cout << "Danh sach giao vien da day.\n";
                            }
                            break;
                        }
                        case 2:
                        {
                            system("cls");//Clear screen
                            hienThiDanhSachGiaoVien(danhSachGiaoVien, soLuongGiaoVien);
                            break;
                        }
                        case 3:
                        {
                            system("cls");//Clear screen
                            string tenCanSua;
                            cout << "Nhap ten giao vien can sua: ";
                            cin >> tenCanSua;
                            suaGiaoVien(danhSachGiaoVien, soLuongGiaoVien, tenCanSua);
                            break;
                        }
                        case 4:
                        {
                            system("cls");//Clear screen
                            string tenCanXoa;
                            cout << "Nhap ten giao vien can xoa: ";
                            cin >> tenCanXoa;
                            xoaGiaoVien(danhSachGiaoVien, soLuongGiaoVien, tenCanXoa);
                            break;
                        }
                        case 5:
                        {
                            system("cls");//Clear screen
                            string tenCanTim;
                            cout << "Nhap ten giao vien can tim: ";
                            cin >> tenCanTim;
                            timKiemGiaoVien(danhSachGiaoVien, soLuongGiaoVien, tenCanTim);
                            break;
                        }
                        case 6:
                        {
                            system("cls");//Clear screen
                            sapXepTheoTen(danhSachGiaoVien, soLuongGiaoVien);
                            hienThiDanhSachGiaoVien(danhSachGiaoVien, soLuongGiaoVien);
                            break;
                        }
                        case 0:
                        {
                            system("cls");//Clear screen	
                            cout << "Ket thuc chuong trinh.";
                            break;
                        }
                        default:
                            cout << "Lua chon khong hop le. Vui long chon lai.";
                            break;
                    }
                } while (luaChon != 0);

                // Giải phóng bộ nhớ sau khi sử dụng
                delete[] danhSachGiaoVien;
                break;
            }
          case 3:
            {
                system("cls");//Clear screen
                int luaChon;
                do
                {
                    cout << "\n=== MENU QUAN LY LOP HOC ===\n";
                    cout << "1. Them moi lop hoc\n";
                    cout << "2. Hien thi danh sach lop hoc\n";
                    cout << "3. Sua thong tin lop hoc\n";
                    cout << "4. Xoa lop hoc\n";
                    cout << "5. Tim kiem lop hoc\n";
                    cout << "6. Sap xep danh sach lop hoc\n";
                    cout << "0. Quay lai\n";
                    cout << "Nhap lua chon cua ban: ";
                    cin >> luaChon;
                    switch (luaChon)
                    {
                        case 1:
                        {
                            system("cls");//Clear screen
                            if (soLuongLopHoc < 100)
                            {
                                themLopHoc(danhSachLopHoc, soLuongLopHoc);
                            }
                            else
                            {
                                cout << "Danh sach lop hoc da day.\n";
                            }
                            break;
                        }
                        case 2:
                        {
                            system("cls");//Clear screen
                            hienThiDanhSachLopHoc(danhSachLopHoc, soLuongLopHoc);
                            break;
                        }
                        case 3:
                        {
                            system("cls");//Clear screen
                            string tenCanSua;
                            cout << "Nhap ma lop hoc can sua: ";
                            cin >> tenCanSua;
                            suaLopHoc(danhSachLopHoc, soLuongLopHoc, tenCanSua);
                            break;
                        }
                        case 4:
                        {
                            system("cls");//Clear screen
                            string tenCanXoa;
                            cout << "Nhap ma lop hoc can xoa: ";
                            cin >> tenCanXoa;
                            xoaLopHoc(danhSachLopHoc, soLuongLopHoc, tenCanXoa);
                            break;
                        }
                        case 5:
                        {
                            system("cls");//Clear screen
                            string tenCanTim;
                            cout << "Nhap ma lop hoc can tim: ";
                            cin >> tenCanTim;
                            timKiemLopHoc(danhSachLopHoc, soLuongLopHoc, tenCanTim);
                            break;
                        }
                        case 6:
                        {
                            system("cls");//Clear screen
                            sapXepTheoTen(danhSachLopHoc, soLuongLopHoc);
                            hienThiDanhSachLopHoc(danhSachLopHoc, soLuongLopHoc);
                            break;
                        }
                        case 0:
                        {
                            system("cls");//Clear screen
                            cout << "Quay lai menu chinh.\n";
                            break;
                        }
                        default:
                            cout << "Lua chon khong hop le. Vui long chon lai.\n";
                            break;
                    }
                } while (luaChon != 0);
                // Giải phóng bộ nhớ sau khi sử dụng
                delete[] danhSachLopHoc;
                break;
            }
         case 4: {
            int luaChon;
            system("cls");
            do {
                cout << "\n=== MENU QUAN LY DIEM ==" << endl;
                cout << "1. Nhap diem\n2. Sua Diem\n3. Hien thi bang diem\n0. Quay lai\n";
                cout << "Nhap lua chon cua ban: ";
                cin >> luaChon;
                switch (luaChon) {
                case 1: {
                    system("cls");
                    cout << "Nhap so luong hoc sinh: ";
                    cin >> soHocSinh;
                    cin.ignore();
                    dsHocSinh = new Diem[soHocSinh];
                    for (int i = 0; i < soHocSinh; i++) {
                        cout << "Nhap thong tin hoc sinh thu " << i + 1 << ":\n";
                        dsHocSinh[i].nhapDiem();
                        cout << endl;
                    }
                    break;
                }
                case 2: {
                    int indexHocSinh;
                    cout << "Nhap so thu tu hoc sinh can sua diem (1-" << soHocSinh << "): ";
                    cin >> indexHocSinh;
                    indexHocSinh--;
                    string monSua;
                    float diemMoi;
                    cout << "Nhap mon hoc can sua diem: ";
                    cin >> monSua;
                    cout << "Nhap diem moi: ";
                    cin >> diemMoi;
                    dsHocSinh[indexHocSinh].suaDiem(monSua, diemMoi);
                    break;
                }
                case 3: {
                    cout << "Bang diem cua hoc sinh la:\n";
                    cout << left << setw(20) << "Ho ten"
                         << setw(10) << "Toan"
                         << setw(10) << "Van"
                         << setw(10) << "Anh"
                         << setw(10) << "Diem TB"
                         << setw(15) << "Xep loai" << endl;
                    for (int i = 0; i < soHocSinh; i++) {
                        dsHocSinh[i].hienThiDiem();
                    }
                    break;
                }
                case 0: {
                    system("cls");
                    cout << "Quay lai chuong trinh.";
                    break;
                }
                default:
                    cout << "Lua chon khong hop le. Vui long chon lai.";
                    break;
                }
            } while (luaChon != 0);
            // Giải phóng bộ nhớ sau khi sử dụng
                delete[] dsHocSinh;
                break;
            }  
















		
	    case 7:
            {
                system("cls");//Clear screen
                int luaChon;
                do
                {
                    cout << "\n=== MENU QUAN LY TAI LIEU TAI NGUYEN ===\n";
                    cout << "1. Them Tai Lieu Tai Nguyen\n";
                    cout << "2. Sua Thong Tin Tai Lieu Tai Nguyen\n";
                    cout << "3. Xoa Tai Lieu Tai Nguyen\n";
                    cout << "4. Tim Kiem Tai Lieu Tai Nguyen\n";
                    cout << "5. Sap Xep Danh Sach Tai Lieu Tai Nguyen\n";
                    cout << "0. Quay lai\n";
                    cout << "Nhap lua chon cua ban: ";
                    cin >> luaChon;
                    switch (luaChon)
                    {
                        case 1:
                        {
                            system("cls");//Clear screen
                            string tenTL;
                            int maSoTL;
                            string MonHocTL;
                            string LopHocTL;
                            cout << "Nhap ten tai lieu tai nguyen: ";
                            cin.ignore();
                            getline(cin, tenTL);
                            cout << "Nhap ma so tai lieu tai nguyen: ";
                            cin >> maSoTL;
                            cout << "Nhap mon hoc: ";
                            cin.ignore();
                            getline(cin, MonHocTL);
                            cout << "Nhap lop hoc: ";
                            getline(cin, LopHocTL);
                            danhsachTaiLieuTaiNguyen[soLuongTaiLieuTaiNguyen++] = TaiLieuTaiNguyen(tenTL, maSoTL, MonHocTL, LopHocTL);
                            break;
                        }
                        case 2:
                        {
                            system("cls");//Clear screen
                            int maSoTL;
                            cout << "Nhap ma so tai lieu can sua: ";
                            cin >> maSoTL;
                            int index = timKiemTaiLieuTaiNguyen(danhsachTaiLieuTaiNguyen, soLuongTaiLieuTaiNguyen, maSoTL);
                            if (index != -1)
                            {
                                string tenMoi, MonHocMoi, LopHocMoi;
                                cout << "Nhap ten moi cua tai lieu: ";
                                cin.ignore();
                                getline(cin, tenMoi);
                                cout << "Nhap mon hoc moi: ";
                                getline(cin, MonHocMoi);
                                cout << "Nhap lop hoc moi: ";
                                getline(cin, LopHocMoi);
                                danhsachTaiLieuTaiNguyen[index].suaThongTin(tenMoi, maSoTL, MonHocMoi, LopHocMoi);
                                cout << "Thong tin tai lieu sau khi sua: " << endl;
                                danhsachTaiLieuTaiNguyen[index].hienThiThongTin();
                            }
                            else
                            {
                                cout << "Khong tim thay tai lieu co ma so " << maSoTL << endl;
                            }
                            break;
                        }
                        case 3:
                        {
                            system("cls");//Clear screen
                            int maSoTL;
                            cout << "Nhap ma so tai lieu can xoa: ";
                            cin >> maSoTL;
                            int index = timKiemTaiLieuTaiNguyen(danhsachTaiLieuTaiNguyen, soLuongTaiLieuTaiNguyen, maSoTL);
                            if (index != -1)
                            {
                                for (int i = index; i < soLuongTaiLieuTaiNguyen - 1; ++i)
                                {
                                    danhsachTaiLieuTaiNguyen[i] = danhsachTaiLieuTaiNguyen[i + 1];
                                }
                                soLuongTaiLieuTaiNguyen--;
                                cout << "Da xoa tai lieu co ma so " << maSoTL << endl;
                            }
                            else
                            {
                                cout << "Khong tim thay tai lieu co ma so " << maSoTL << endl;
                            }
                            break;
                        }
                        case 4:
                        {
                            system("cls");//Clear screen
                            int maSoTL;
                            cout << "Nhap ma so tai lieu can tim: ";
                            cin >> maSoTL;
                            int index = timKiemTaiLieuTaiNguyen(danhsachTaiLieuTaiNguyen, soLuongTaiLieuTaiNguyen, maSoTL);
                            if (index != -1)
                            {
                                cout << "Thong tin tai lieu can tim: " << endl;
                                danhsachTaiLieuTaiNguyen[index].hienThiThongTin();
                            }
                            else
                            {
                                cout << "Khong tim thay tai lieu co ma so " << maSoTL << endl;
                            }
                            break;
                        }
                        case 5:
                        {
                            system("cls");//Clear screen

                            // Thực hiện sắp xếp danh sách tài liệu
                            sapXepDanhsachTaiLieuTaiNguyen(danhsachTaiLieuTaiNguyen, soLuongTaiLieuTaiNguyen);
                            cout << "Da sap xep danh sach tai lieu tai nguyen theo ten.\n";
                            break;
                        }
                        case 0:
                        {
                            system("cls");//Clear screen
                            cout << "Quay lai menu chinh.\n";
                            break;
                        }
                        default:
                            cout << "Lua chon khong hop le. Vui long chon lai.\n";
                            break;
                    }
                } while (luaChon != 0);
                // Giải phóng bộ nhớ sau khi sử dụng
                delete[] danhsachTaiLieuTaiNguyen;
                break;
            }
            case 8:
            {
                system("cls");//Clear screen
                int luaChon;
                do
                {
                    cout << "\n=== MENU QUAN LY PHU HUYNH ===\n";
                    cout << "1. Them moi phu huynh\n";
                    cout << "2. Hien thi danh sach phu huynh\n";
                    cout << "3. Xoa phu huynh\n";
                    cout << "4. Tim kiem phu huynh\n";
                    cout << "5. Sap xep danh sach phu huynh theo ten\n";
                    cout << "0. Quay lai\n";
                    cout << "Nhap lua chon cua ban: ";
                    cin >> luaChon;
                    switch (luaChon)
                    {
                        case 1:
                        {
                            system("cls");//Clear screen
                            themPhuHuynh(danhsachPhuHuynh, soLuongPhuHuynh);
                            break;
                        }
                        case 2:
                        {
                            system("cls");//Clear screen
                            hienThiDanhsachPhuHuynh(danhsachPhuHuynh, soLuongPhuHuynh);
                            break;
                        }
                        case 3:
                        {
                            system("cls");//Clear screen
                            string tenCanXoa;
                            cout << "Nhap ten phu huynh can xoa: ";
                            cin.ignore();
                            getline(cin, tenCanXoa);
                            xoaPhuHuynh(danhsachPhuHuynh, soLuongPhuHuynh, tenCanXoa);
                            break;
                        }
                        case 4:
                        {
                            system("cls");//Clear screen
                            string tenCanTim;
                            cout << "Nhap ten phu huynh can tim: ";
                            cin.ignore();
                            getline(cin, tenCanTim);
                            timKiemPhuHuynh(danhsachPhuHuynh, soLuongPhuHuynh, tenCanTim);
                            break;
                        }
                        case 5:
                        {
                            system("cls");//Clear screen
                            sapXepTheoTen(danhsachPhuHuynh, soLuongPhuHuynh);
                            break;
                        }
                        case 0:
                        {
                            system("cls");//Clear screen
                            cout << "Quay lai menu chinh.\n";
                            break;
                        }
                        default:
                            cout << "Lua chon khong hop le. Vui long nhap lai.\n";
                            break;
                    }
                } while (luaChon != 0);
                delete[] danhsachPhuHuynh;
                break;
            }
            case 9:
            {
                system("cls");//Clear screen
                int luaChon;
                QuanLy quanLy;
                do
                {
                    cout << "\n----- MENU QUAN LY THONG BAO VA LIEN LAC -----\n";
                    cout << "1. Tao thong bao\n";
                    cout << "2. Ghi nhan lien lac tu phu huynh\n";
                    cout << "3. Hien thi danh sach thong bao\n";
                    cout << "4. Hien thi danh sach lien lac\n";
                    cout << "5. Thoat\n";
                    cout << "0. Quay lai\n";
                    cout << "Lua chon cua ban: ";
                    cin >> luaChon;
                    cin.ignore();
                    switch (luaChon)
                    {
                        case 1:
                        {
                            system("cls");//Clear screen
                            string tieuDe, noiDung;
                            cout << "Nhap tieu de thong bao: ";
                            getline(cin, tieuDe);
                            cout << "Nhap noi dung thong bao: ";
                            getline(cin, noiDung);
                            quanLy.taoThongBao(tieuDe, noiDung);
                            break;
                        }
                        case 2:
                        {
                            system("cls");//Clear screen
                            string tenPhuHuynh, hinhThuc, noiDung;
                            cout << "Nhap ten phu huynh: ";
                            getline(cin, tenPhuHuynh);
                            cout << "Nhap hinh thuc (Cuoc goi/Tin nhan): ";
                            getline(cin, hinhThuc);
                            cout << "Nhap noi dung: ";
                            getline(cin, noiDung);
                            quanLy.ghiNhanLienLac(tenPhuHuynh, hinhThuc, noiDung);
                            break;
                        }
                        case 3:
                        {
                            system("cls");//Clear screen
                            quanLy.hienThiThongBao();
                            break;
                        }
                        case 4:
                        {
                            system("cls");//Clear screen
                            quanLy.hienThiLienLac();
                            break;
                        }
                        case 5:
                        {
                            system("cls");//Clear screen
                            cout << "Thoat chuong trinh.\n";
                            break;
                        }
                        case 0:
                        {
                            system("cls");//Clear screen
                            cout << "Quay lai menu chinh.\n";
                            break;
                        }
                        default:
                            cout << "Lua chon khong hop le, vui long chon lai.\n";
                            break;
                    }
                } while (luaChon != 0);
                break;
            }
            case 0:
            {
                system("cls");//Clear screen
                cout << "Ket thuc chuong trinh";
                break;
            }
            default:
                cout << "Lua chon khong hop le, vui long chon lai.\n";
                break;
        }
    } while (luaChon1 != 0);
    return 0;

    
}
