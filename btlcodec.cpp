#include <stdio.h>
#include <string.h>
#include <windows.h>
#define THONG_BAO 10
#define LIEN_LAC 20

// Khai báo struct HocSinh
typedef struct
{
    char ten[50];
    int maSo;
    float diemTK;
} HocSinh;

// Khai báo struct GiaoVien
typedef struct
{
    char ten[50];
    char monDay[50];
} GiaoVien;

// Hàm hiển thị thông tin học sinh
void hienThiThongTinHS(HocSinh hs)
{
    printf("Ten: %s, Ma so: %d, DiemTK: %.2f\n", hs.ten, hs.maSo, hs.diemTK);
}

// Hàm tìm kiếm học sinh
int timKiemHocSinh(HocSinh danhSach[], int soLuong, int maSo)
{
    for (int i = 0; i < soLuong; i++)
    {
        if (danhSach[i].maSo == maSo)
        {
            return i;
        }
    }
    return -1;
}

// Hàm sắp xếp danh sách học sinh
void sapXepDanhSachHocSinh(HocSinh danhSach[], int soLuong)
{
    for (int i = 0; i < soLuong - 1; i++)
    {
        for (int j = i + 1; j < soLuong; j++)
        {
            if (danhSach[i].diemTK < danhSach[j].diemTK)
            {
                HocSinh temp = danhSach[i];
                danhSach[i] = danhSach[j];
                danhSach[j] = temp;
            }
        }
    }
}

// Hàm thêm mới giáo viên
void themGiaoVien(GiaoVien danhSachGiaoVien[], int* soLuongGiaoVien)
{
    if (*soLuongGiaoVien < 100)
    {
        printf("Nhap ten giao vien: ");
        scanf("%s", danhSachGiaoVien[*soLuongGiaoVien].ten);
        printf("Nhap mon day cua giao vien: ");
        scanf("%s", danhSachGiaoVien[*soLuongGiaoVien].monDay);
        (*soLuongGiaoVien)++;
    }
    else
    {
        printf("Danh sach giao vien da day.\n");
    }
}

// Hàm hiển thị danh sách giáo viên
void hienThiDanhSachGiaoVien(GiaoVien danhSachGiaoVien[], int soLuongGiaoVien)
{
    printf("Danh sach giao vien:\n");
    for (int i = 0; i < soLuongGiaoVien; ++i)
    {
        printf("Ten: %s, Mon day: %s\n", danhSachGiaoVien[i].ten, danhSachGiaoVien[i].monDay);
    }
}

// Hàm sửa thông tin giáo viên
void suaGiaoVien(GiaoVien danhSachGiaoVien[], int soLuongGiaoVien, char* tenCanSua)
{
    for (int i = 0; i < soLuongGiaoVien; ++i)
    {
        if (strcmp(danhSachGiaoVien[i].ten, tenCanSua) == 0)
        {
            printf("Nhap ten moi cho giao vien: ");
            scanf("%s", danhSachGiaoVien[i].ten);
            printf("Nhap mon day moi cho giao vien: ");
            scanf("%s", danhSachGiaoVien[i].monDay);
            printf("Thong tin giao vien da duoc cap nhat.\n");
            return;
        }
    }
    printf("Khong tim thay giao vien co ten %s.\n", tenCanSua);
}

// Hàm xóa giáo viên khỏi danh sách
void xoaGiaoVien(GiaoVien danhSachGiaoVien[], int* soLuongGiaoVien, char* tenCanXoa)
{
    int viTriXoa = -1;
    for (int i = 0; i < *soLuongGiaoVien; ++i)
    {
        if (strcmp(danhSachGiaoVien[i].ten, tenCanXoa) == 0)
        {
            viTriXoa = i;
            break;
        }
    }
    if (viTriXoa != -1)
    {
        for (int i = viTriXoa; i < *soLuongGiaoVien - 1; ++i)
        {
            strcpy(danhSachGiaoVien[i].ten, danhSachGiaoVien[i + 1].ten);
            strcpy(danhSachGiaoVien[i].monDay, danhSachGiaoVien[i + 1].monDay);
        }
        (*soLuongGiaoVien)--;
        printf("Da xoa giao vien %s khoi danh sach.\n", tenCanXoa);
    }
    else
    {
        printf("Khong tim thay giao vien co ten: %s.\n", tenCanXoa);
    }
}

// Hàm tìm kiếm giáo viên
void timKiemGiaoVien(GiaoVien danhSachGiaoVien[], int soLuongGiaoVien, char* tenCanTim)
{
    int timThay = 0;
    printf("Ket qua tim kiem:\n");
    for (int i = 0; i < soLuongGiaoVien; ++i)
    {
        if (strcmp(danhSachGiaoVien[i].ten, tenCanTim) == 0)
        {
            printf("Ten: %s, Mon day: %s\n", danhSachGiaoVien[i].ten, danhSachGiaoVien[i].monDay);
            timThay = 1;
        }
    }
    if (!timThay)
    {
        printf("Khong tim thay giao vien co ten: %s.\n", tenCanTim);
    }
}

// Hàm sắp xếp giáo viên theo tên
void sapXepTheoTenGV(GiaoVien danhSachGiaoVien[], int soLuongGiaoVien)
{
    for (int i = 0; i < soLuongGiaoVien - 1; ++i)
    {
        for (int j = i + 1; j < soLuongGiaoVien; ++j)
        {
            if (strcmp(danhSachGiaoVien[i].ten, danhSachGiaoVien[j].ten) > 0)
            {
                GiaoVien temp = danhSachGiaoVien[i];
                danhSachGiaoVien[i] = danhSachGiaoVien[j];
                danhSachGiaoVien[j] = temp;
            }
        }
    }
    printf("Da sap xep danh sach giao vien theo ten.\n");
}

//Khai báo struct tài liệu tài nguyên
typedef struct
{
    int ma_so;
    char ten[50];
    char mon_hoc[50];
    char lop_hoc[10];
} TaiNguyenTaiLieu;

TaiNguyenTaiLieu tai_lieu[1000];
int so_luong = 0;
int ma_so_counter = 1;

void hien_thi_tai_lieu(TaiNguyenTaiLieu* tl)
{
    printf("Ma so: %d\n", tl->ma_so);
    printf("Ten: %s\n", tl->ten);
    printf("Mon hoc: %s\n", tl->mon_hoc);
    printf("Lop hoc: %s\n", tl->lop_hoc);
}

//Hàm hiển thị danh sách
void hien_thi_danh_sach()
{
    for (int i = 0; i < so_luong; i++)
    {
        hien_thi_tai_lieu(&tai_lieu[i]);
        printf("\n");
    }
}

//Hàm thêm tài liệu
void them_tai_lieu()
{
    if (so_luong >= 1000)
    {
        printf("Danh sach tai lieu da day.\n");
        return;
    }

    TaiNguyenTaiLieu* new_tl = &tai_lieu[so_luong];
    new_tl->ma_so = ma_so_counter++;
    printf("Nhap ten tai lieu: ");
    scanf(" %[^\n]", new_tl->ten);
    printf("Nhap mon hoc: ");
    scanf(" %[^\n]", new_tl->mon_hoc);
    printf("Nhap lop hoc: ");
    scanf(" %[^\n]", new_tl->lop_hoc);
    so_luong++;
    printf("Them tai lieu thanh cong.\n");
}

//Hàm sửa tài liệu
void sua_tai_lieu(int ma_so)
{
    for (int i = 0; i < so_luong; i++)
    {
        if (tai_lieu[i].ma_so == ma_so)
        {
            printf("Nhap ten tai lieu moi: ");
            scanf(" %[^\n]", tai_lieu[i].ten);
            printf("Nhap mon hoc moi: ");
            scanf(" %[^\n]", tai_lieu[i].mon_hoc);
            printf("Nhap lop hoc moi: ");
            scanf(" %[^\n]", tai_lieu[i].lop_hoc);
            printf("Sua tai lieu thanh cong.\n");
            return;
        }
    }
    printf("Khong tim thay tai lieu voi ma so: %d\n", ma_so);
}

//Hàm xóa tài liệu
void xoa_tai_lieu(int ma_so)
{
    int found = 0;
    for (int i = 0; i < so_luong; i++)
    {
        if (tai_lieu[i].ma_so == ma_so)
        {
            found = 1;
        }
        if (found && i < so_luong - 1)
        {
            tai_lieu[i] = tai_lieu[i + 1];
        }
    }
    if (found)
    {
        so_luong--;
        printf("Xoa tai lieu thanh cong.\n");
    }
    else
    {
        printf("Khong tim thay tai lieu voi ma so: %d\n", ma_so);
    }
}

//Hàm tìm kiếm tài liệu
void tim_kiem_tai_lieu(char* ten)
{
    for (int i = 0; i < so_luong; i++)
    {
        if (strstr(tai_lieu[i].ten, ten))
        {
            hien_thi_tai_lieu(&tai_lieu[i]);
            printf("\n");
        }
    }
}

//Hàm sắp xếp tài liệu
void sap_xep_tai_lieu()
{
    for (int i = 0; i < so_luong - 1; i++)
    {
        for (int j = i + 1; j < so_luong; j++)
        {
            if (strcmp(tai_lieu[i].ten, tai_lieu[j].ten) > 0)
            {
                TaiNguyenTaiLieu temp = tai_lieu[i];
                tai_lieu[i] = tai_lieu[j];
                tai_lieu[j] = temp;
            }
        }
    }
    printf("Sap xep tai lieu thanh cong.\n");
}

//Hàm struct lớp học
typedef struct
{
    char maLop[20];
    char tenGV[50];
} LopHoc;

//Hàm thêm lớp học
void themLopHoc(LopHoc danhSachLopHoc[], int* soLuongLopHoc)
{
    if (*soLuongLopHoc < 1000)
    {
        printf("Nhap ma lop hoc: ");
        scanf("%s", danhSachLopHoc[*soLuongLopHoc].maLop);
        printf("Nhap ten cua giao vien chu nhiem: ");
        scanf("%s", danhSachLopHoc[*soLuongLopHoc].tenGV);
        (*soLuongLopHoc)++;
        printf("Them lop hoc thanh cong.\n");
    }
    else
    {
        printf("Danh sach lop hoc da day.\n");
    }
}

//Hàm hiện thị danh sách lớp học
void hienThiDanhSachLopHoc(const LopHoc danhSachLopHoc[], int soLuongLopHoc)
{
    printf("Danh sach lop hoc:\n");
    for (int i = 0; i < soLuongLopHoc; ++i)
    {
        printf("Ma Lop: %s, Ten giao vien chu nhiem: %s\n", danhSachLopHoc[i].maLop, danhSachLopHoc[i].tenGV);
    }
}

//Hàm sửa lớp học
void suaLopHoc(LopHoc danhSachLopHoc[], int soLuongLopHoc, const char* tenCanSua)
{
    int timThay = 0;
    for (int i = 0; i < soLuongLopHoc; ++i)
    {
        if (strcmp(danhSachLopHoc[i].tenGV, tenCanSua) == 0)
        {
            printf("Nhap ma moi cho lop hoc: ");
            scanf("%s", danhSachLopHoc[i].maLop);
            printf("Nhap ten moi cho giao vien: ");
            scanf("%s", danhSachLopHoc[i].tenGV);
            printf("Thong tin lop hoc da duoc cap nhat.\n");
            timThay = 1;
            break;
        }
    }
    if (!timThay)
    {
        printf("Khong tim thay lop hoc co ten %s.\n", tenCanSua);
    }
}

//Hàm xóa lớp học
void xoaLopHoc(LopHoc danhSachLopHoc[], int* soLuongLopHoc, const char* tenCanXoa)
{
    int timThay = 0;
    for (int i = 0; i < *soLuongLopHoc; ++i)
    {
        if (strcmp(danhSachLopHoc[i].tenGV, tenCanXoa) == 0)
        {
            for (int j = i; j < *soLuongLopHoc - 1; ++j)
            {
                danhSachLopHoc[j] = danhSachLopHoc[j + 1];
            }
            (*soLuongLopHoc)--;
            printf("Da xoa lop hoc %s khoi danh sach.\n", tenCanXoa);
            timThay = 1;
            break;
        }
    }
    if (!timThay)
    {
        printf("Khong tim thay lop hoc co ten %s.\n", tenCanXoa);
    }
}

//Hàm tìm kiếm lớp học
void timKiemLopHoc(const LopHoc danhSachLopHoc[], int soLuongLopHoc, const char* tenCanTim)
{
    int timThay = 0;
    printf("Ket qua tim kiem:\n");
    for (int i = 0; i < soLuongLopHoc; ++i)
    {
        if (strcmp(danhSachLopHoc[i].tenGV, tenCanTim) == 0)
        {
            printf("Ma Lop: %s, Ten giao vien chu nhiem: %s\n", danhSachLopHoc[i].maLop, danhSachLopHoc[i].tenGV);
            timThay = 1;
        }
    }
    if (!timThay)
    {
        printf("Khong tim thay lop hoc co ten %s.\n", tenCanTim);
    }
}

//Hàm sắp xếp lớp học theo tên
void sapXepTheoTenLH(LopHoc danhSachLopHoc[], int soLuongLopHoc)
{
    for (int i = 0; i < soLuongLopHoc - 1; ++i)
    {
        for (int j = i + 1; j < soLuongLopHoc; ++j)
        {
            if (strcmp(danhSachLopHoc[i].tenGV, danhSachLopHoc[j].tenGV) > 0)
            {
                LopHoc temp = danhSachLopHoc[i];
                danhSachLopHoc[i] = danhSachLopHoc[j];
                danhSachLopHoc[j] = temp;
            }
        }
    }
    printf("Da sap xep danh sach lop hoc.\n");
}

//Hàm khai báo struct Diem
struct Diem
{
    char hoTen[50];
    float diemToan, diemVan, diemAnh;
    float diemTB;
    char xepLoai[15];
};

//Hàm tính điểm
void tinhDiemTB(struct Diem *d)
{
    d->diemTB = (d->diemToan + d->diemVan + d->diemAnh) / 3;
}

//Hàm xếp loại học lực
void xepLoaiHocLuc(struct Diem *d)
{
    if (d->diemTB >= 9)
        strcpy(d->xepLoai, "Xuat sac");
    else if (d->diemTB >= 8)
        strcpy(d->xepLoai, "Gioi");
    else if (d->diemTB >= 7)
        strcpy(d->xepLoai, "Kha");
    else if (d->diemTB >= 5)
        strcpy(d->xepLoai, "Trung binh");
    else
        strcpy(d->xepLoai, "Yeu");
}

//Hàm nhâp diêm
void nhapDiem(struct Diem *d)
{
    printf("Nhap ho ten hoc sinh: ");
    fgets(d->hoTen, 50, stdin);
    d->hoTen[strcspn(d->hoTen, "\n")] = '\0'; // Loai bo ky tu xuong dong
    printf("Nhap diem Toan: ");
    scanf("%f", &d->diemToan);
    printf("Nhap diem Van: ");
    scanf("%f", &d->diemVan);
    printf("Nhap diem Anh: ");
    scanf("%f", &d->diemAnh);
    getchar(); // Loai bo ky tu xuong dong sau khi doc diem Anh
    tinhDiemTB(d);
    xepLoaiHocLuc(d);
}

//Hàm hiển thị theo điểm của học sinh
void hienThiDiem(struct Diem d)
{
    printf("%-20s %-10.1f %-10.1f %-10.1f %-10.1f %-15s\n", d.hoTen, d.diemToan, d.diemVan, d.diemAnh, d.diemTB, d.xepLoai);
}

//Hàm sửa điểm
void suaDiem(struct Diem *d, char *mon, float diemMoi)
{
    if (strcmp(mon, "Toan") == 0)
        d->diemToan = diemMoi;
    else if (strcmp(mon, "Van") == 0)
        d->diemVan = diemMoi;
    else if (strcmp(mon, "Anh") == 0)
        d->diemAnh = diemMoi;
    tinhDiemTB(d);
    xepLoaiHocLuc(d);
}

//Khai báo struct phụ huynh
typedef struct
{
    char tenPH[50];
    char tenHS[50];
    char SDT[20];
} PhuHuynh;

// Hàm hiển thị thông tin phụ huynh
void hienThiThongTinPH(const PhuHuynh* ph)
{
    printf("Ten phu huynh: %s, Ten hoc sinh: %s, So dien thoai phu huynh: %s\n", ph->tenPH, ph->tenHS, ph->SDT);
}

// Hàm thêm mới phụ huynh vào danh sách
void themPhuHuynh(PhuHuynh danhsachPhuHuynh[], int* soLuongPhuHuynh)
{
    if (*soLuongPhuHuynh < 1000)
    {
        PhuHuynh ph;
        printf("Nhap ten phu huynh: ");
        fgets(ph.tenPH, sizeof(ph.tenPH), stdin);
        ph.tenPH[strcspn(ph.tenPH, "\n")] = '\0'; // Loại bỏ ký tự xuống dòng
        printf("Nhap ten hoc sinh: ");
        fgets(ph.tenHS, sizeof(ph.tenHS), stdin);
        ph.tenHS[strcspn(ph.tenHS, "\n")] = '\0';
        printf("Nhap so dien thoai: ");
        fgets(ph.SDT, sizeof(ph.SDT), stdin);
        ph.SDT[strcspn(ph.SDT, "\n")] = '\0';
        danhsachPhuHuynh[(*soLuongPhuHuynh)++] = ph;
    }
    else
    {
        printf("Danh sach phu huynh da day.\n");
    }
}

// Hàm hiển thị danh sách phụ huynh
void hienThiDanhsachPhuHuynh(const PhuHuynh danhsachPhuHuynh[], int soLuongPhuHuynh)
{
    printf("Danh sach phu huynh:\n");
    for (int i = 0; i < soLuongPhuHuynh; ++i)
    {
        hienThiThongTinPH(&danhsachPhuHuynh[i]);
    }
}

// Hàm xóa phụ huynh khỏi danh sách
void xoaPhuHuynh(PhuHuynh danhsachPhuHuynh[], int* soLuongPhuHuynh, const char* tenCanXoa)
{
    int viTriXoa = -1;
    for (int i = 0; i < *soLuongPhuHuynh; ++i)
    {
        if (strcmp(danhsachPhuHuynh[i].tenPH, tenCanXoa) == 0)
        {
            viTriXoa = i;
            break;
        }
    }
    if (viTriXoa != -1)
    {
        for (int i = viTriXoa; i < *soLuongPhuHuynh - 1; ++i)
        {
            danhsachPhuHuynh[i] = danhsachPhuHuynh[i + 1];
        }
        (*soLuongPhuHuynh)--;
        printf("Da xoa phu huynh %s khoi danh sach.\n", tenCanXoa);
    }
    else
    {
        printf("Khong tim thay phu huynh co ten %s.\n", tenCanXoa);
    }
}

// Hàm tìm kiếm phụ huynh trong danh sách
void timKiemPhuHuynh(const PhuHuynh danhsachPhuHuynh[], int soLuongPhuHuynh, const char* tenCanTim)
{
    int timThay = 0;
    printf("Ket qua tim kiem:\n");
    for (int i = 0; i < soLuongPhuHuynh; ++i)
    {
        if (strcmp(danhsachPhuHuynh[i].tenPH, tenCanTim) == 0)
        {
            hienThiThongTinPH(&danhsachPhuHuynh[i]);
            timThay = 1;
        }
    }
    if (!timThay)
    {
        printf("Khong tim thay phu huynh co ten %s.\n", tenCanTim);
    }
}

// Hàm sắp xếp danh sách phụ huynh theo tên phụ huynh
void sapXepTheoTenPH(PhuHuynh danhsachPhuHuynh[], int soLuongPhuHuynh)
{
    for (int i = 0; i < soLuongPhuHuynh - 1; ++i)
    {
        for (int j = i + 1; j < soLuongPhuHuynh; ++j)
        {
            if (strcmp(danhsachPhuHuynh[i].tenPH, danhsachPhuHuynh[j].tenPH) > 0)
            {
                PhuHuynh temp = danhsachPhuHuynh[i];
                danhsachPhuHuynh[i] = danhsachPhuHuynh[j];
                danhsachPhuHuynh[j] = temp;
            }
        }
    }
    printf("Da sap xep danh sach phu huynh theo ten.\n");
}

// Ham khai bao stuct ThongBao
typedef struct
{
    char tieuDe[100];
    char noiDung[500];
} ThongBao;

// Hàm khai báo struct LienLac
typedef struct
{
    char tenPhuHuynh[100];
    char hinhThuc[50];
    char noiDung[500];
} LienLac;

// Hàm khai báo struct QuanLy
typedef struct
{
    ThongBao danhSachThongBao[THONG_BAO];
    LienLac danhSachLienLac[LIEN_LAC];
    int soLuongThongBao;
    int soLuongLienLac;
} QuanLy;

// Hàm tao thông bao
void taoThongBao(QuanLy *quanLy, char *tieuDe, char *noiDung)
{
    if (quanLy->soLuongThongBao < THONG_BAO)
    {
        strcpy(quanLy->danhSachThongBao[quanLy->soLuongThongBao].tieuDe, tieuDe);
        strcpy(quanLy->danhSachThongBao[quanLy->soLuongThongBao].noiDung, noiDung);
        quanLy->soLuongThongBao++;
        printf("Thong bao da duoc gui: %s\n", tieuDe);
    }
    else
    {
        printf("Danh sach thong bao da day!\n");
    }
}

// Hàm ghi nhân liên lac
void ghiNhanLienLac(QuanLy *quanLy, char *tenPhuHuynh, char *hinhThuc, char *noiDung)
{
    if (quanLy->soLuongLienLac < LIEN_LAC)
    {
        strcpy(quanLy->danhSachLienLac[quanLy->soLuongLienLac].tenPhuHuynh, tenPhuHuynh);
        strcpy(quanLy->danhSachLienLac[quanLy->soLuongLienLac].hinhThuc, hinhThuc);
        strcpy(quanLy->danhSachLienLac[quanLy->soLuongLienLac].noiDung, noiDung);
        quanLy->soLuongLienLac++;
        printf("Da ghi nhan %s tu phu huynh: %s\n", hinhThuc, tenPhuHuynh);
    }
    else
    {
        printf("Danh sach lien lac da day!\n");
    }
}

// Hàm hiên thi thông báo
void hienThiThongBao(QuanLy *quanLy)
{
    printf("\nDanh sach thong bao:\n");
    for (int i = 0; i < quanLy->soLuongThongBao; i++)
    {
        printf("Tieu de: %s\nNoi dung: %s\n", quanLy->danhSachThongBao[i].tieuDe, quanLy->danhSachThongBao[i].noiDung);
    }
}
// Hàm hiên thi liên lac
void hienThiLienLac(QuanLy *quanLy)
{
    printf("\nDanh sach lien lac tu phu huynh:\n");
    for (int i = 0; i < quanLy->soLuongLienLac; i++)
    {
        printf("Phu huynh: %s\nHinh thuc: %s\nNoi dung: %s\n", quanLy->danhSachLienLac[i].tenPhuHuynh, quanLy->danhSachLienLac[i].hinhThuc, quanLy->danhSachLienLac[i].noiDung);
    }
}

typedef struct
{
    char NgaySuKien[20];
    char TenSuKien[20];
} Sukien;

// Hàm hiển thị thông tin sự kiện
void hienThiThongTin(const Sukien* sk)
{
    printf("Ngay dien ra su kien (dd/mm/yyyy): %s, Ten su kien: %s\n", sk->NgaySuKien, sk->TenSuKien);
}

// Hàm thêm mới sự kiện vào danh sách
void themSukien(Sukien listofSukien[], int* soSuKien)
{
    if (*soSuKien < 1000)
    {
        Sukien suKienMoi;
        printf("Nhap Ngay dien ra su kien (dd/mm/yyyy): ");
        scanf("%s", suKienMoi.NgaySuKien);
        printf("Nhap ten cua su kien: ");
        scanf("%s", suKienMoi.TenSuKien);
        listofSukien[(*soSuKien)++] = suKienMoi;
    }
    else
    {
        printf("Danh sach su kien da day.\n");
    }
}

// Hàm hiển thị danh sách sự kiện
void hienThiDanhSachSuKien(const Sukien listofSukien[], int soSuKien)
{
    printf("Danh sach su kien:\n");
    for (int i = 0; i < soSuKien; ++i)
    {
        hienThiThongTin(&listofSukien[i]);
    }
}

// Hàm sửa thông tin sự kiện
void suaSukien(Sukien listofSukien[], int soSuKien, const char* tenCanSua)
{
    for (int i = 0; i < soSuKien; ++i)
    {
        if (strcmp(listofSukien[i].TenSuKien, tenCanSua) == 0)
        {
            char maMoi[1000], tenMoi[1000];
            printf("Nhap ngay moi cho su kien: ");
            scanf("%s", maMoi);
            printf("Nhap ten moi cho su kien: ");
            scanf("%s", tenMoi);
            strcpy(listofSukien[i].NgaySuKien, maMoi);
            strcpy(listofSukien[i].TenSuKien, tenMoi);
            printf("Thong tin su kien da duoc cap nhat.\n");
            return;
        }
    }
    printf("Khong tim thay su kien co ten: %s.\n", tenCanSua);
}

// Hàm xóa sự kiện danh sách
void xoaSukien(Sukien listofSukien[], int* soSuKien, const char* tenCanXoa)
{
    int viTriXoa = -1;
    for (int i = 0; i < *soSuKien; ++i)
    {
        if (strcmp(listofSukien[i].TenSuKien, tenCanXoa) == 0)
        {
            viTriXoa = i;
            break;
        }
    }
    if (viTriXoa != -1)
    {
        for (int i = viTriXoa; i < *soSuKien - 1; ++i)
        {
            listofSukien[i] = listofSukien[i + 1];
        }
        (*soSuKien)--;
        printf("Da xoa su kien %s khoi danh sach.\n", tenCanXoa);
    }
    else
    {
        printf("Khong tim thay su kien co ten: %s.\n", tenCanXoa);
    }
}

// Hàm tìm kiếm sự kiện trong danh sách
void timKiemSukien(const Sukien listofSukien[], int soSuKien, const char* tenCanTim)
{
    int timThay = 0;
    printf("Ket qua tim kiem:\n");
    for (int i = 0; i < soSuKien; ++i)
    {
        if (strcmp(listofSukien[i].TenSuKien, tenCanTim) == 0)
        {
            hienThiThongTin(&listofSukien[i]);
            timThay = 1;
        }
    }
    if (!timThay)
    {
        printf("Khong tim thay su kien co ten: %s.\n", tenCanTim);
    }
}

// Hàm sắp xếp danh sách sự kiện theo tên
void sapXepTheoTen(Sukien listofSukien[], int soSuKien)
{
    for (int i = 0; i < soSuKien - 1; ++i)
    {
        for (int j = i + 1; j < soSuKien; ++j)
        {
            if (strcmp(listofSukien[i].TenSuKien, listofSukien[j].TenSuKien) > 0)
            {
                Sukien temp = listofSukien[i];
                listofSukien[i] = listofSukien[j];
                listofSukien[j] = temp;
            }
        }
    }
    printf("Da sap xep danh sach su kien.\n");
}

int main()
{
    HocSinh danhSachHocSinh[1000];
    GiaoVien danhSachGiaoVien[1000];
    int soLuongHocSinh = 0;
    int soLuongGiaoVien = 0;
    int choice, Choice;
    TaiNguyenTaiLieu tai_lieu[1000];
    int so_luong = 0;
    LopHoc danhSachLopHoc[1000];
    int soLuongLopHoc = 0;
    PhuHuynh danhsachPhuHuynh[1000];
    int soLuongPhuHuynh = 0;
    char tieuDe[100], noiDung[500], tenPhuHuynh[100];
    do
    {
        printf("\n=== MENU CHINH ===\n");
        printf("1. Quan ly hoc sinh.\n");
        printf("2. Quan ly giao vien.\n");
        printf("3. Quan ly lop hoc.\n");
        printf("4. Quan ly diem.\n");
        printf("5. Quan ly su kien.\n");
        printf("6. Quan ly tai lieu tai nguyen.\n");
        printf("7. Quan ly phu huynh.\n");
        printf("8. Quan ly thong bao / Lien lac.\n");;
        printf("0. Thoat.\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        if (choice == 0)
        {
            break;
        }
        switch (choice)
        {
            case 1:
            {
                system("cls");//Clear screen
                do
                {
                    printf("\n=== QUAN LY HOC SINH ===\n");
                    printf("1. Them hoc sinh.\n");
                    printf("2. Hien thi thong tin hoc sinh.\n");
                    printf("3. Tim kiem hoc sinh.\n");
                    printf("4. Sap xep danh sach hoc sinh.\n");
                    printf("0. Quay lai menu chinh.\n");
                    printf("Lua chon cua ban: ");
                    scanf("%d", &Choice);
                    switch (Choice)
                    {
                        case 1:
                        {
                            system("cls");//Clear screen
                            if (soLuongHocSinh < 1000)
                            {
                                printf("Nhap ten hoc sinh: ");
                                scanf("%s", danhSachHocSinh[soLuongHocSinh].ten);
                                printf("Nhap ma so hoc sinh: ");
                                scanf("%d", &danhSachHocSinh[soLuongHocSinh].maSo);
                                printf("Nhap diem tong ket: ");
                                scanf("%f", &danhSachHocSinh[soLuongHocSinh].diemTK);
                                soLuongHocSinh++;
                            }
                            else
                            {
                                printf("Danh sach hoc sinh da day.\n");
                            }
                            break;
                        }
                        case 2:
                        {
                            system("cls");//Clear screen
                            for (int i = 0; i < soLuongHocSinh; i++)
                            {
                                hienThiThongTinHS(danhSachHocSinh[i]);
                            }
                            break;
                        }
                        case 3:
                        {
                            system("cls");//Clear screen
                            int maSo;
                            printf("Nhap ma so hoc sinh can tim: ");
                            scanf("%d", &maSo);
                            int viTri = timKiemHocSinh(danhSachHocSinh, soLuongHocSinh, maSo);
                            if (viTri != -1)
                            {
                                hienThiThongTinHS(danhSachHocSinh[viTri]);
                            }
                            else
                            {
                                printf("Khong tim thay hoc sinh co ma so %d.\n", maSo);
                            }
                            break;
                        }
                        case 4:
                        {
                            system("cls");//Clear screen
                            sapXepDanhSachHocSinh(danhSachHocSinh, soLuongHocSinh);
                            printf("Da sap xep danh sach hoc sinh theo diem tong ket.\n");
                            break;
                        }
                        case 0:
                        {
                            system("cls");//Clear screen
                            printf("Quay lai menu chinh.\n");
                            break;
                        }
                        default:
                            printf("Lua chon khong hop le, vui long chon lai.\n");
                            break;
                    }
                } while(Choice != 0);
                break;
            }
            case 2:
            {
                system("cls");//Clear screen
                do
                    {
                    printf("\n=== QUAN LY GIAO VIEN ===\n");
                    printf("1. Them giao vien.\n");
                    printf("2. Hien thi danh sach giao vien.\n");
                    printf("3. Sua thong tin giao vien.\n");
                    printf("4. Xoa giao vien.\n");
                    printf("5. Tim kiem giao vien.\n");
                    printf("6. Sap xep giao vien theo ten.\n");
                    printf("0. Quay lai menu chinh.\n");
                    printf("Lua chon cua ban: ");
                    scanf("%d", &Choice);
                    switch (Choice)
                    {
                        case 1:
                        {
                            system("cls");//Clear screen
                            themGiaoVien(danhSachGiaoVien, &soLuongGiaoVien);
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
                            char tenCanSua[5000];
                            printf("Nhap ten giao vien can sua: ");
                            scanf("%s", tenCanSua);
                            suaGiaoVien(danhSachGiaoVien, soLuongGiaoVien, tenCanSua);
                            break;
                        }
                        case 4:
                        {
                            system("cls");//Clear screen
                            char tenCanXoa[5000];
                            printf("Nhap ten giao vien can xoa: ");
                            scanf("%s", tenCanXoa);
                            xoaGiaoVien(danhSachGiaoVien, &soLuongGiaoVien, tenCanXoa);
                            break;
                        }
                        case 5:
                        {
                            system("cls");//Clear screen
                            char tenCanTim[5000];
                            printf("Nhap ten giao vien can tim: ");
                            scanf("%s", tenCanTim);
                            timKiemGiaoVien(danhSachGiaoVien, soLuongGiaoVien, tenCanTim);
                            break;
                        }
                        case 6:
                        {
                            system("cls");//Clear screen
                            sapXepTheoTenGV(danhSachGiaoVien, soLuongGiaoVien);
                            break;
                        }
                        case 0:
                        {
                            system("cls");//Clear screen
                            printf("Quay lai menu chinh.\n");
                            break;
                        }
                        default:
                            printf("Lua chon khong hop le, vui long chon lai.\n");
                            break;
                    }
                } while (Choice != 0);
                break;
            }
            case 3:
            {
                system("cls");//Clear screen
                do
                {
                    char tenGV[500];
                    printf("\n=== QUAN LY LOP HOC ===\n");
                    printf("1. Them lop hoc.\n");
                    printf("2. Sua thong tin lop hoc.\n");
                    printf("3. Xoa lop hoc.\n");
                    printf("4. Hien thi danh sach lop hoc.\n");
                    printf("5. Tim kiem lop hoc.\n");
                    printf("6. Sap xep lop hoc theo ten.\n");
                    printf("0. Quay lai menu chinh.\n");
                    printf("Lua chon cua ban: ");
                    scanf("%d", &Choice);
                    switch (Choice)
                    {
                        case 1:
                        {
                            system("cls");//Clear screen
                            themLopHoc(danhSachLopHoc, &soLuongLopHoc);
                            break;
                        }
                        case 2:
                        {
                            system("cls");//Clear screen
                            printf("Nhap ten giao vien can sua: ");
                            scanf("%s", tenGV);
                            suaLopHoc(danhSachLopHoc, soLuongLopHoc, tenGV);
                            break;
                        }
                        case 3:
                        {
                            system("cls");//Clear screen
                            printf("Nhap ten giao vien can xoa: ");
                            scanf("%s", tenGV);
                            xoaLopHoc(danhSachLopHoc, &soLuongLopHoc, tenGV);
                            break;
                        }
                        case 4:
                        {
                            system("cls");//Clear screen
                            hienThiDanhSachLopHoc(danhSachLopHoc, soLuongLopHoc);
                            break;
                        }
                        case 5:
                        {
                            system("cls");//Clear screen
                            printf("Nhap ten giao vien can tim: ");
                            scanf("%s", tenGV);
                            timKiemLopHoc(danhSachLopHoc, soLuongLopHoc, tenGV);
                            break;
                        }
                        case 6:
                        {
                            system("cls");//Clear screen
                            sapXepTheoTenLH(danhSachLopHoc, soLuongLopHoc);
                            break;
                        }
                        case 0:
                        {
                            system("cls");//Clear screen
                            printf("Quay lai menu chinh.\n");
                            break;
                        }
                        default:
                            printf("Lua chon khong hop le, vui long chon lai.\n");
                            break;
                    }
                } while (Choice != 0);
                break;
            }
            case 4:
            {
                system("cls");//Clear screen
                do
                {
                    struct Diem d;
            		char mon[100];
                    float diemMoi;
                    printf("\n=== QUAN LY DIEM ===\n");
                    printf("1. Nhap diem hoc sinh.\n");
                    printf("2. Hien thi diem hoc sinh.\n");
                    printf("3. Sua diem hoc sinh.\n");
                    printf("0. Quay lai menu chinh.\n");
                    printf("Lua chon cua ban: ");
                    scanf("%d", &Choice);
                    getchar(); // Loai bo ky tu xuong dong
                    switch (Choice)
                    {
                        case 1:
                        {
                            system("cls");//Clear screen
                            nhapDiem(&d);
                            break;
                        }
                        case 2:
                        {
                            system("cls");//Clear screen
                            hienThiDiem(d);
                            break;
                        }
                        case 3:
                        {
                            system("cls");//Clear screen
                            printf("Nhap mon can sua (Toan/Van/Anh): ");
                            fgets(mon, 10, stdin);
                            mon[strcspn(mon, "\n")] = '\0'; // Loai bo ky tu xuong dong
                            printf("Nhap diem moi: ");
                            scanf("%f", &diemMoi);
                            getchar(); // Loai bo ky tu xuong dong
                            suaDiem(&d, mon, diemMoi);
                            break;
                        }
                        case 0:
                        {
                            system("cls");//Clear screen
                            printf("Quay lai menu chinh.\n");
                            break;
                        }
                        default:
                            printf("Lua chon khong hop le, vui long chon lai.\n");
                            break;
                    }
                } while (Choice != 0);
                break;
            }
            case 5:
            {
                system("cls");//Clear screen
                do
                {
                    Sukien danhSachSukien[1000];
                    int soSuKien = 0;
                    char tenCanTim[1000];
                    printf("\n=== QUAN LY SU KIEN ===:\n");
                    printf("1. Them su kien.\n");
                    printf("2. Hien thi danh sach su kien.\n");
                    printf("3. Sua thong tin su kien.\n");
                    printf("4. Xoa su kien.\n");
                    printf("5. Tim kiem su kien.\n");
                    printf("6. Sap xep danh sach su kien theo ten.\n");
                    printf("0. Quay lai menu chinh.\n");
                    printf("Lua chon cua ban: ");
                    scanf("%d", &Choice);
                    switch (Choice)
                    {
                        case 1:
                        {
                            system("cls");//Clear screen
                            themSukien(danhSachSukien, &soSuKien);
                            break;
                        }
                        case 2:
                        {
                            system("cls");//Clear screen
                            hienThiDanhSachSuKien(danhSachSukien, soSuKien);
                            break;
                        }
                        case 3:
                        {
                            system("cls");//Clear screen
                            printf("Nhap ten su kien can sua: ");
                            scanf("%s", tenCanTim);
                            suaSukien(danhSachSukien, soSuKien, tenCanTim);
                            break;
                        }
                        case 4:
                        {
                            system("cls");//Clear screen
                            printf("Nhap ten su kien can xoa: ");
                            scanf("%s", tenCanTim);
                            xoaSukien(danhSachSukien, &soSuKien, tenCanTim);
                            break;
                        }
                        case 5:
                        {
                            system("cls");//Clear screen
                            printf("Nhap ten su kien can tim: ");
                            scanf("%s", tenCanTim);
                            timKiemSukien(danhSachSukien, soSuKien, tenCanTim);
                            break;
                        }
                        case 6:
                        {
                            system("cls");//Clear screen
                            sapXepTheoTen(danhSachSukien, soSuKien);
                            break;
                        }
                        case 0:
                        {
                            system("cls");//Clear screen
                            printf("Quay lai menu chinh.\n");
                            break;
                        }
                        default:
                            printf("Lua chon khong hop le, vui long chon lai.\n");
                            break;
                    }
                } while (Choice != 0);
                break;
            }
            case 6:
            {
                system("cls");//Clear screen
                do
                {
                    int  ma_so;
                    printf("\n=== QUAN LY TAI LIEU ===\n");
                    printf("1. Them tai lieu.\n");
                    printf("2. Sua tai lieu.\n");
                    printf("3. Xoa tai lieu.\n");
                    printf("4. Hien thi danh sach tai lieu.\n");
                    printf("5. Tim kiem tai lieu.\n");
                    printf("6. Sap xep tai lieu.\n");
                    printf("0. Quay lai menu chinh.\n");
                    printf("Lua chon cua ban: ");
                    scanf("%d", &Choice);
                    switch (Choice)
                    {
                        char ten[5000];
                        case 1:
                        {
                            system("cls");//Clear screen
                            them_tai_lieu();
                            break;
                        }
                        case 2:
                        {
                            system("cls");//Clear screen
                            printf("Nhap ma so tai lieu can sua: ");
                            scanf("%d", &ma_so);
                            sua_tai_lieu(ma_so);
                            break;
                        }
                        case 3:
                        {
                            system("cls");//Clear screen
                            printf("Nhap ma so tai lieu can xoa: ");
                            scanf("%d", &ma_so);
                            xoa_tai_lieu(ma_so);
                            break;
                        }
                        case 4:
                        {
                            system("cls");//Clear screen
                            hien_thi_danh_sach();
                            break;
                        }
                        case 5:
                        {
                            system("cls");//Clear screen
                            printf("Nhap ten tai lieu can tim: ");
                            scanf(" %[^\n]", ten);
                            tim_kiem_tai_lieu(ten);
                            break;
                        }
                        case 6:
                        {
                            system("cls");//Clear screen
                            sap_xep_tai_lieu();
                            break;
                        }
                        case 0:
                        {
                            system("cls");//Clear screen
                            printf("Quay lai menu chinh.\n");
                            break;
                        }
                        default:
                            printf("Lua chon khong hop le, vui long chon lai.\n");
                            break;
                    }
                } while (Choice != 0);
                break;
            }
            case 7:
            {
                system("cls");//Clear screen
                do
                {
                    printf("\n=== QUAN LY PHU HUYNH ===\n");
                    printf("1. Them phu huynh.\n");
                    printf("2. Hien thi danh sach phu huynh.\n");
                    printf("3. Xoa phu huynh.\n");
                    printf("4. Tim kiem phu huynh.\n");
                    printf("5. Sap xep danh sach phu huynh theo ten.\n");
                    printf("0. Quay lai menu chinh.\n");
                    printf("Lua chon cua ban: ");
                    scanf("%d", &Choice);
                    getchar(); // Loại bỏ ký tự xuống dòng sau khi nhập số
                    switch (Choice)
                    {
                        case 1:
                        {
                            system("cls");//Clear screen
                            themPhuHuynh(danhsachPhuHuynh, &soLuongPhuHuynh);
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
                            char tenCanXoa[1000];
                            printf("Nhap ten phu huynh can xoa: ");
                            fgets(tenCanXoa, sizeof(tenCanXoa), stdin);
                            tenCanXoa[strcspn(tenCanXoa, "\n")] = '\0';
                            xoaPhuHuynh(danhsachPhuHuynh, &soLuongPhuHuynh, tenCanXoa);
                            break;
                        }
                        case 4:
                        {
                            system("cls");//Clear screen
                            char tenCanTim[1000];
                            printf("Nhap ten phu huynh can tim: ");
                            fgets(tenCanTim, sizeof(tenCanTim), stdin);
                            tenCanTim[strcspn(tenCanTim, "\n")] = '\0';
                            timKiemPhuHuynh(danhsachPhuHuynh, soLuongPhuHuynh, tenCanTim);
                            break;
                        }
                        case 5:
                        {
                            system("cls");//Clear screen
                            sapXepTheoTenPH(danhsachPhuHuynh, soLuongPhuHuynh);
                            break;
                        }
                        case 0:
                        {
                            system("cls");//Clear screen
                            printf("Quay lai menu chinh.\n");
                            break;
                        }
                        default:
                            printf("Lua chon khong hop le, vui long chon lai.\n");
                            break;
                    }
                } while (Choice != 0);
                break;
            }
            case 8:
         	{
                system("cls");//Clear screen
                do
                {
                    QuanLy quanLy;
                    system("cls"); // Clear screen
                    printf("\n=== QUAN LY THONG BAO VA LIEN LAC ===\n");
                    printf("1. Tao thong bao.\n");
                    printf("2. Ghi nhan lien lac tu phu huynh.\n");
                    printf("3. Hien thi danh sach thong bao.\n");
                    printf("4. Hien thi danh sach lien lac.\n");
                    printf("0. Quay lai menu chinh.\n");
                    printf("Lua chon cua ban: ");
                    scanf("%d", &Choice);
                    getchar(); // Đọc bỏ ký tự Enter sau khi nhập số
                    switch (Choice)
                    {
                        case 1:
                        {
                            system("cls"); // Clear screen
                            char tieuDe[100], noiDung[500];
                            printf("Nhap tieu de thong bao: ");
                            fgets(tieuDe, 100, stdin);
                            tieuDe[strcspn(tieuDe, "\n")] = '\0'; // Loại bỏ ký tự newline
                            printf("Nhap noi dung thong bao: ");
                            fgets(noiDung, 100, stdin);
                            noiDung[strcspn(noiDung, "\n")] = '\0'; // Loại bỏ ký tự newline
                            taoThongBao(&quanLy, tieuDe,noiDung);
                            break;
                        }
                        case 2:
                        {
                            system("cls"); // Clear screen
                            char hinhThuc[100];
                            printf("Nhap ten phu huynh: ");
                            fgets(tenPhuHuynh, 100, stdin);
                            tenPhuHuynh[strcspn(tenPhuHuynh, "\n")] = '\0'; // Loại bỏ ký tự newline
                            printf("Nhap hinh thuc (Cuoc goi/Tin nhan): ");
                            fgets(hinhThuc, 100, stdin);
                            hinhThuc[strcspn(hinhThuc, "\n")] = '\0'; // Loại bỏ ký tự newline
                            printf("Nhap noi dung: ");
                            fgets(noiDung, 100, stdin);
                            noiDung[strcspn(noiDung, "\n")] = '\0'; // Loại bỏ ký tự newline
                            ghiNhanLienLac(&quanLy,tenPhuHuynh, hinhThuc, noiDung);
                            break;
                        }
                        case 3:
                        {
                            system("cls"); // Clear screen
                            hienThiThongBao(&quanLy);
                            break;
                        }
                        case 4:
                        {
                            system("cls"); // Clear screen
                            hienThiLienLac(&quanLy);
                            break;
                        }
                        case 0:
                        {
                            system("cls");//Clear screen
                            printf("Quay lai menu chinh.\n");
                            break;
                        }
                        default:
                            printf("Lua chon khong hop le, vui long chon lai.\n");
                            break;
                    }
                } while (Choice != 0);
                break;
            }
            case 0:
            {
                system("cls");//Clear screen
                printf("Ket thuc chuong trinh.\n");
                break;
            }
            default:
                printf("Lua chon khong hop le, vui long chon lai.\n");
                break;
        }
    } while (choice != 0);
    return 0;
}
